#pragma once
#include "Task7.h"


double U(double m, double n, double p)
{
	double q = 1 - p;
	return ((m / n - p) * sqrt(n)) / sqrt(p * q);
}

double u(double a)
{
	HelloLaplaso hl;
	double uv = (1 - a) / 2;
	return hl.getX(uv);
}

void Answer9()
{
	int n = 100;
	double m = 8;
	double a = 0.05;
	double p = 0.12;

	double Uv = fabs(U(m,n,p)), uv = u(a);

	if (Uv > uv)
	{
		cout << "U(" << Uv << ") > u(" << uv << ")" << endl;
		cout << "Нулевую гипотизу отвергают" << endl;
	}
	else if (Uv < uv)
	{
		cout << "U(" << Uv << ") < u(" << uv << ")" << endl;
		cout << "Нет основаный отвергать нулевую гипотизу" << endl;
	}
	else
	{
		cout << " Error " << endl;
	}


}