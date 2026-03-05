#include "integral.h"

const double math::integral::LeftRect::compute(IntegralFunc func) const
{
	auto S = 0.0;

	for (auto x = a; x < b; x += h)
	{
		S += func(x);
	}

	return S * h;
}

const double math::integral::CentralRect::compute(IntegralFunc func) const
{
	auto S = 0.0;

	for (auto x = a; x < b; x += h)
	{
		S += func(x + h/2.0);
	}

	return S * h;
}
