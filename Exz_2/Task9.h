#pragma once
#include "Task7.h"

namespace t9 {
	class H
	{
		double p;
	public:
		H(double p)
		{
			this->p = p;
		}
		bool operator==(double p)
		{
			return this->p == p;
		}

		bool operator!=(double p)
		{
			return this->p != p;
		}

		bool operator>(double p)
		{
			return this->p > p;
		}
		bool operator<(double p)
		{
			return this->p < p;
		}
	};
}



double U(double m, double n, double p)
{
	double q = 1 - p;
	return ((m / n - p) * sqrt(n)) / sqrt(p * q);
}

double u_1(double a)
{
	HelloLaplaso hl;
	double uv = (1 - a) / 2;
	return hl.getX(uv);
}

double u_2(double a)
{
	HelloLaplaso hl;
	double uv = (1 - 2*a) / 2;
	return hl.getX(uv);
}

void Comment(int n, double p)
{
	double q = 1 - p;

	double rezult = q * p * n;
	if (rezult > 9)
	{
		cout << "n*p*q(" << rezult << ") > 9" << endl;
	}
	else if (rezult < 9)
	{
		cout << "n*p*q(" << rezult << ") < 9" << endl;
	}
	else
	{
		cout << "n*p*q(" << rezult << ") == 9" << endl;
	}
}


void Answer9()
{
	int n = 100;
	double m = 8;
	double a = 0.05;
	double p0 = 0.12;

	double Uv = U(m,n,p0), uv = 0.0;
	

	t9::H h0(0.12);
	t9::H h1(0.11);

	bool use1 = true;

	// ������������������ ���������� ������������ ���������� ����������� n*p*q > 9
	Comment(n,p0);


	//������� 1
	if (h0 == p0/*H0 : p == p0*/ && h1 != p0 /*H1 : p != p0*/ 
		&& use1/*�� ������ ��� ��� ������ �������� ������� ����*/)
	{
		uv = u_1(a);
		double modulUv = abs(Uv);

		if (modulUv > uv)
		{
			cout << "[U](" << modulUv << ") > u(" << uv << ")" << endl;
			cout << "������� �������� ���������" << endl;
			cout << "����������� ������������� ������� ������� ���������� �� �������������� �����������" << endl;
		}
		else if (modulUv < uv)
		{
			cout << "[U](" << modulUv << ") < u(" << uv << ")" << endl;
			cout << "��� ��������� ��������� ������� ��������" << endl;
			cout << "����������� ������������� ������� ��������� ���������� �� �������������� �����������" << endl;
		}
		else {cout << " Error " << endl;;}

	}
	// ������� 2
	else if (h1 > p0 /* H1 : p > p0*/)
	{
		uv = u_2(a);

		if (Uv > uv)
		{
			cout << "U(" << Uv << ") > u(" << uv << ")" << endl;
			cout << "������� �������� ���������" << endl;
			cout << "����������� ������������� ������� ������� ���������� �� �������������� �����������" << endl;
		}
		else if (Uv < uv)
		{
			cout << "U(" << Uv << ") < u(" << uv << ")" << endl;
			cout << "��� ��������� ��������� ������� ��������" << endl;
			cout << "����������� ������������� ������� ��������� ���������� �� �������������� �����������" << endl;
		}
		else { cout << " Error " << endl;; }
	}
	// ������� 3
	else if (h1 < p0 /* H1 : p < p0*/)
	{
		uv = u_2(a);

		if (Uv > -uv)
		{
			cout << "U(" << Uv << ") > u(" << -uv << ")" << endl;
			cout << "��� ��������� ��������� ������� ��������" << endl;
			cout << "����������� ������������� ������� ��������� ���������� �� �������������� �����������" << endl;
		}
		else if (Uv < -uv)
		{
			cout << "U(" << Uv << ") < u(" << -uv << ")" << endl;
			cout << "������� �������� ���������" << endl;
			cout << "����������� ������������� ������� ������� ���������� �� �������������� �����������" << endl;
		}
		else { cout << " Error " << endl;; }
	}




}