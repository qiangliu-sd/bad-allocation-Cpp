#ifndef INTERPFACTORY_H
#define INTERPFACTORY_H

#include "LinearInterp.h"
#include "NPointInterpBasic.h"
#include "CubicSpline.h"

#include "EnumTypesInterpolate.h"

#include <memory>
#include <vector>

namespace topeqx {
using DblVec = std::vector<double>;

struct InterpFactory 
{
    static std::unique_ptr<Interpolation<DblVec> > create(QLInterpID interp_id, int degrees=5, 
		QLNPInterpModeID mode= NP_FOLLOWING, double y1stP1 = 1.0e30, double y1stPn = 1.0e30) 
	{
	  switch (interp_id) {
		case LINEAR_INTERP:
			return std::make_unique<LinearInterp<DblVec> >();
		case N_POINT_INTERP:
			return std::make_unique<NPointInterpBasic<DblVec> >(degrees, mode);
		case CUBIC_SPLINE:
			return std::make_unique<CubicSpline<DblVec> >(y1stP1, y1stPn);
		default:
			return std::make_unique<NPointInterpBasic<DblVec>>();
		}
	}
};
}

#endif   // INTERPFACTORY_H
