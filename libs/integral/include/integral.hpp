#pragma once

#include <iostream>

namespace math::integral {
	//double f1(const double& x)
	
	typedef double (*IntegralFunc)(const double& x);


	class LeftRect {
	private:
		double a;
		
		double b;

		int n_points;

		double h;
	public:
		LeftRect(const double& a, const double& b, const int& n_points)
		{
			this->a = a;

			this->b = b;
			
			this->n_points = n_points;

			this->h = (b - a) / (n_points - 1);
		}

		const double compute(IntegralFunc func) const;
		
		const double operator()(IntegralFunc func) const
		{
			return compute(func);
		}

	};

	class CentralRect {
	private:
		double a;

		double b;

		int n_points;

		double h;
	public:
		CentralRect(const double& a, const double& b, const int& n_points)
		{
			this->a = a;

			this->b = b;

			this->n_points = n_points;

			this->h = (b - a) / (n_points - 1);
		}

		const double compute(IntegralFunc func) const;

		const double operator()(IntegralFunc func) const
		{
			return compute(func);
		}

	};
}