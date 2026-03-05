#pragma once

namespace math::integral {

	typedef double (*integral_func_t)(const double& x);


	class LeftRect {
		double a;
		
		double b;

		int n_points;

		double h;
	public:
		LeftRect(const double& a_, const double& b_, const int& n_points_): a(a_), b(b_), n_points(n_points_)
		{
			this->h = (b - a) / (n_points - 1);
		}

		double compute(integral_func_t func) const;

		double operator()(integral_func_t f) const {
			return compute(f);
		}

	};

	class CentralRect {
		double a;

		double b;

		int n_points;

		double h;
	public:
		CentralRect(const double& a_, const double& b_, const int& n_points_): a(a_), b(b_), n_points(n_points_)
		{
			this->h = (b - a) / (n_points - 1);
		}

		double compute(integral_func_t func) const;

		double operator()(integral_func_t f) const {
			return compute(f);
		}

	};
}