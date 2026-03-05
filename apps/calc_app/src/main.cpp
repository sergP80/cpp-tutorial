// integral.cpp : Defines the entry point for the application.
//

#include "integral_app.h"

using namespace std;

double f1(const double& x)
{
	return x * x - 2;
}

double f2(const double& x)
{
	return log(x + 2)*sqrt(x+3);
}


int main()
{
	math::integral::LeftRect lr(-1, 2, 50);
	math::integral::CentralRect cr(-1, 2, 50);

	{
		cout << "F1" << endl;

		auto r = lr.compute(f1);

		cout << "Left rec:" << r << endl;

		r = cr.compute(f1);

		cout << "Central rec:" << r << endl;

	}

	{
		cout << "\nF2" << endl;

		auto r = lr(f2);

		cout << "Left rec:" << r << endl;

		r = cr(f2);

		cout << "Central rec:" << r << endl;
	}
	
}
