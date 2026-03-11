#pragma once

#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>

struct Employee {
	int id;
	double salary;
	std::string name;
};

bool operator<(const Employee e1, const Employee e2)
{
	//return e1.salary < e2.salary;
	return e1.name.size() < e2.name.size();
}

bool operator>(const Employee e1, const Employee e2)
{
	//return e1.salary > e2.salary;
	return e1.name.size() > e2.name.size();
}


std::ostream& operator<<(std::ostream& os, const Employee& e)
{
	os << "Employee {";
	os << "id: " << e.id;
	os << ", name: " << e.name;
	os << ", salary: " << e.salary;
	os << "}";
	return os;
}

template<typename T>
T min(T* a, const int& sz)
{
	T res = a[0];

	for (int i = 1; i < sz; ++i)
	{
		if (a[i] < res)
		{
			res = a[i];
		}
	}

	return res;
}

template<typename T, int sz>
T min(T (&a)[sz])
{
	T res = a[0];

	for (int i = 1; i < sz; ++i)
	{
		if (a[i] < res)
		{
			res = a[i];
		}
	}

	return res;
}


template<typename T>
T max(T* a, const int& sz)
{
	T res = a[0];

	for (int i = 1; i < sz; ++i)
	{
		if (a[i] > res)
		{
			res = a[i];
		}
	}

	return res;
}

template<typename T, int sz>
T max(T (&a)[sz])
{
	T res = a[0];

	for (int i = 1; i < sz; ++i)
	{
		if (a[i] > res)
		{
			res = a[i];
		}
	}

	return res;
}

template<typename T>
void min_max(T* a, const int& sz, T& min, T& max)
{
	min = a[0], max = a[0];

	for (int i = 1; i < sz; ++i)
	{
		if (a[i] < min)
		{
			min = a[i];
		}

		if (a[i] > max)
		{
			max = a[i];
		}
	}
}

template<typename T, int sz>
void min_max(T (&a)[sz], T& min, T& max)
{
	min = a[0], max = a[0];

	for (int i = 1; i < sz; ++i)
	{
		if (a[i] < min)
		{
			min = a[i];
		}

		if (a[i] > max)
		{
			max = a[i];
		}
	}
}