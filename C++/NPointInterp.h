#ifndef NPOINT__INTERP_H
#define NPOINT__INTERP_H

// This class tries to find a polynomial that approximates function F(X)
// For degree = 5, the polynomial is of the form:
//	F = xCoef(0) * X^4 + xCoef(1) * X^3 + xCoef(2) * X^2 + xCoef(3) * X + xCoef(4)
// F: represented as a set of points ( <I>x-Source</I> ) and 
//	values at those points <I>y-Source</I>
//

#include "matrixfunctions/LUPartialPivot.h"

#include "Interpolation.h"
#include "LinearInterp.h"
#include "EnumTypesInterpolate.h"


namespace topeqx {

template<class X>
class NPointInterp : public Interpolation<X> {
private:
    QLNPInterpModeID mMode;
    mutable vector<double> mXCoefVec;

public:
    virtual ~NPointInterp() {}
 
protected:
	int mDegree;
	LinearInterp<X> mLinterp;

    NPointInterp(int degree = 5, QLNPInterpModeID mode = NP_CLOSEST_LOGLINEAR) 
        : mDegree( std::max(degree, 2) ), mMode(mode), mXCoefVec(mDegree) {}
		
	double basicInterpolate(const X& x_src, const X& y_src, double x_new, int idx) const;
	double firstOrderDeriv() const { return y1stDeriv; }
	double secondOrderDeriv() const { return y2ndDeriv; }
    
	mutable double y1stDeriv;
	mutable double y2ndDeriv;
};
}

#endif //NPOINT__INTERP_H
