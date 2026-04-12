
#ifndef NPOINTINTERPBASIC_H
#define NPOINTINTERPBASIC_H

#include "NPointInterp.h"

namespace topeqx {

template <class X>
class NPointInterpBasic : public NPointInterp<X> {
 public:
    NPointInterpBasic(int degree =5, QLNPInterpModeID mode = NP_CLOSEST_LOGLINEAR) 
      :  NPointInterp<X>(degree, mode) {}
    virtual ~NPointInterpBasic() {}
	
    double interpolate(const X & x_src, const X & y_src, double x_new ) const;
};
}
#endif //NPOINTINTERPBASIC_H
