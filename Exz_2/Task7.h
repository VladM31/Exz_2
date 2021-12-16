#pragma once
#include "Task2.h"
#include <time.h>

using namespace std;

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
        x[5] = 3.0, Fx[5] = 0.49865;
        x[6] = 3.5, Fx[6] = 0.49975;

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

// Случайнвя величина
double Z(vector<double>& arr1, vector<double>& arr2)
{
    double Ss1 = MathWait(arr1), Ss2 = MathWait(arr2); // Выборочный сренее (Selective srene)
    double D1 = Dispersia(arr1), D2 = Dispersia(arr2); // Выборочная дисперсия 

    return (Ss1 - Ss2) / (sqrt(D1 / arr1.size() + D2 / arr2.size()));
}

// Заполняем вектор числас
void FillNumber(vector<double>& arr)
{
    for (size_t i = 0; i < arr.size(); i++)
    {
        arr[i] = rand() % 18;
    }
}

double func_laplace(double a, double precision) {
    double result = 0;
    for (double i = 0; i < a; i += precision) {
        result += precision * fabs(pow(M_E, -.5 * pow(i, 2)) + pow(M_E, -.5 * pow((i + precision), 2))) / 2.0;
    }
    result *= 1.0 / pow(2 * M_PI, .5);
    return result;
}

// критическая область
double z_kr(double a, HelloLaplaso* hl)
{
    double magic = (1 - 2 * a) / 2;

    return hl->getX(magic);
}

void Answer7()
{
    cout << " Task 7" << endl;
    srand(time(NULL));
    double a = 0.05;
    HelloLaplaso* hl = new HelloLaplaso();
    vector<double> arr1(100);
    vector<double> arr2(120);

    FillNumber(arr1);
    FillNumber(arr2);

    auto aZ = fabs(Z(arr1, arr2));
    auto az = z_kr(a, hl);

    if (aZ > az)
    {
        cout << "Z(" << aZ << ") > z(" << az << ")" << endl;
        //cout << "Нет оснований отвергнуть основную гипотезу" << endl;
        cout << "Нулевую гипотизу отвергаем" << endl;
    }
    else if (aZ < az)
    {
        cout << "Z(" << aZ << ") < z(" << az << ")" << endl;
        cout << "Нулевую гипотизу не отвергаем" << endl;
        //cout << "Отвергают основную гипотезу" << endl;
    }
    else
    {
        cout << "Error" << endl;
    }

    delete hl;
}