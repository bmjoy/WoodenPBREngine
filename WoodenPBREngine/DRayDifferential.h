#pragma once

#include "pch.h"
#include "WoodenMathLibrarry/DRay.h"

WPBR_BEGIN
template<typename T, uint8_t alignment = sse_alignment_size_v<__m_t<T>>>
class alignas(alignment) DRayDifferential: public DRay<T>
{
public:
	DRayDifferential() = default;
	DRayDifferential(DPoint3f o, DVector3f dir):
		DRay(std::move(o), std::move(dir))
	{}

	DRayDifferential(DRay<T> ray) :
		DRay(std::move(ray))
	{}

	void scaleDifferentials(T s)
	{	
		difXRay.origin = mad(difXRay.origin - this->origin, s, this->origin);
		difXRay.dir = mad(difXRay.dir - this->dir, s, this->dir);

		difYRay.origin = mad(difYRay.origin - this->origin, s, this->origin);
		difYRay.dir = mad(difYRay.dir - this->dir, s, this->dir);
	}

	DRay<T> difXRay;
	DRay<T> difYRay;
};

using DRayDifferentialf = typename DRayDifferential<float>;
using DRayDifferentiald = typename DRayDifferential<double>;

WPBR_END

