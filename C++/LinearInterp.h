#ifndef __LINEARINTERP_H__
#define __LINEARINTERP_H__

#include "Interpolation.h"


namespace topeqx {

template<class X>
class LinearInterp : public Interpolation<X> {
public:
    explicit LinearInterp(bool do_extrapolate = true) : 
		mIsExtrap(do_extrapolate) {};
    
	virtual double interpolate( const X& x_src, const X& y_src, double x_new ) const;
	double firstOrderDeriv()  const { return mSlope; }
	double secondOrderDeriv() const { return 0.0; }
  

private:
	bool mIsExtrap; // extrapolate for points outside the range
	mutable double mSlope{0.0};

};
}
#endif // __LINEARINTERP_H__










