#pragma once
#include <random>
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>

#define Enter (std::cout << std::endl);
#define _USE_MATH_DEFINES
#define M_PI 3.14159265358979323846
#define M_E 2.71828182845904523536
using namespace std;


// ======== 6-7 =================
// Функция Лапласа
double func_laplace(double a, double precision) {
    double result = 0;
    for (double i = 0; i < a; i += precision) {
        result += precision * fabs(pow(M_E, -.5 * pow(i, 2)) + pow(M_E, -.5 * pow((i + precision), 2))) / 2.0;
    }
    result *= 1.0 / pow(2 * M_PI, .5);
    return result;
}

class HelloLaplaso
{
private:
    const int size = 10;
    double* x, * Fx;

    // Функция лапласа
    double func_laplace(double a, double precision) {
        double result = 0;
        for (double i = 0; i < a; i += precision) {
            result += precision * fabs(pow(M_E, -.5 * pow(i, 2)) + pow(M_E, -.5 * pow((i + precision), 2))) / 2.0;
        }
        result *= 1.0 / pow(2 * M_PI, .5);
        return result;
    }

public:
    HelloLaplaso()
    {
        // Создаем масиви
        // И заполняем их табличними значениями функции лапласа
        x = new double[size];
        Fx = new double[size];
        x[0] = 0.5, Fx[0] = 0.19145;
        x[1] = 1.0, Fx[1] = 0.34135;
        x[2] = 1.5, Fx[2] = 0.4332;
        x[3] = 2.0, Fx[3] = 0.47725;
        x[4] = 2.5, Fx[4] = 0.4938;

        x[5] = 2.33, Fx[5] = 0.49;
        x[6] = 2.58, Fx[6] = 0.495;
        x[7] = 1.64, Fx[7] = 0.45;
        x[8] = 1.65, Fx[8] = 0.45055;
        x[9] = 1.96, Fx[9] = 0.475;
    }

    // Возращает х если дано F(x) из функции Лапласа
    double getX(double Fxv)
    {
        for (size_t i = 0; i < size; i++)
        {
            if (HelloLaplaso::Fx[i] == Fxv)
            {
                return HelloLaplaso::x[i];
            }
        }

        for (double temp = 0.0; temp <= 5; temp += 0.01)
        {
            auto temp2 = round(func_laplace(temp, 2));
            if (temp2 > Fxv)
            {
                return temp2;
            }
        }
    }

    // Возращает F(x) если дано x из функции Лапласа
    double getFx(double xv)
    {
        for (size_t i = 0; i < size; i++)
        {
            if (HelloLaplaso::x[i] == xv)
            {
                return HelloLaplaso::Fx[i];
            }
        }
        return func_laplace(xv, 2);
    }

    ~HelloLaplaso()
    {
        delete x, Fx;
    }
};
// Случайнaя величина
double Z(double* arr, int n, int m)
{
	return (arr[0] - arr[1]) / sqrt(arr[2] / n + arr[3] / m);
}
// критическая область
double z_1(double a)
{
	HelloLaplaso hl;
	double uv = (1 - a) / 2;
	return hl.getX(uv);
}
// критическая область
double z_2(double a)
{
	HelloLaplaso hl;
	double uv = (1 - 2 * a) / 2;
	return hl.getX(uv);
}

struct H
{
    double Mx, My;

    H(double Mx, double My)
    {
        this->Mx = Mx;
        this->My = My;
    }


};