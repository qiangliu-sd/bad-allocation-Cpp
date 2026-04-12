#include "InterpFactory.h"

#include <iostream>

using namespace std;
using namespace topeqx;

struct InterpWrapper {
	DblVec mY;
	unique_ptr<Interpolation<DblVec> > mInterp;

	InterpWrapper(const DblVec& y) : mY(y),
		mInterp(InterpFactory::create(N_POINT_INTERP,5, NP_FOLLOWING)) {}

	void get_y(const DblVec& x_src, double x_new) {		
		auto y_new_ = mInterp->interpolate(x_src, mY, x_new);
		cout << "Interpolated value at x = " << x_new << " is y = " << y_new_ << endl;
		cout << "dy-dx at x = " << mInterp->firstOrderDeriv() << endl;
		cout << "ddy-dxx at x = " << mInterp->secondOrderDeriv() << endl;
	}
};


void generate_x_y(int sz, DblVec &x, DblVec & y) {
	for (size_t i = 0; i < sz; ++i) {
		x.push_back( i * 0.5); // x = 0, 0.5, 1.0, ...
		y.push_back( x[i] * x[i] + 5.0 * x[i] + 1.0); // y = x^2 + 5x + 1
	}
}


int main() {
	DblVec x_vec, y_vec;
	generate_x_y(70, x_vec, y_vec);

	DblVec x_n{ 10.75, 20.25, 30.5, 40.75, 50.125, 60.625, 70, 80 };
	for (auto & x : x_n) {
		InterpWrapper wrapper(y_vec);
		wrapper.get_y(x_vec, x);
	}

	return 0;
}
