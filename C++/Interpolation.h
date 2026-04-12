
// Interface for 1D interpolation on point values.  

#ifndef INTERPOLATION_H
#define INTERPOLATION_H

namespace topeqx {

template< class X >	// X: Containers such as vector<double>
class Interpolation {
  public:
    virtual ~Interpolation() {}; 
    virtual double interpolate(const X& x_src, const X& y_src, double x_new) const = 0;
    virtual double firstOrderDeriv() const = 0;
    virtual double secondOrderDeriv() const = 0;

};
}
#endif // INTERPOLATION_H
