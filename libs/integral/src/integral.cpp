#include "integral.hpp"

double math::integral::LeftRect::compute(integral_func_t func) const {
	auto S = 0.0;

	for (auto x = a; x < b; x += h)
	{
		S += func(x);
	}

	return S * h;
}

double math::integral::CentralRect::compute(integral_func_t func) const {
	auto S = 0.0;

	for (auto x = a; x < b; x += h)
	{
		S += func(x + h/2.0);
	}

	return S * h;
}
