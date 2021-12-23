#pragma once
#include "Task2.h"
#include <time.h>

using namespace std;



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




void Answer7()
{
    cout << " Task 7" << endl;
    srand(time(NULL));
    double a = 0.05;
 
    vector<double> arr1(100);
    vector<double> arr2(120);

    FillNumber(arr1);
    FillNumber(arr2);

    auto aZ = Z(arr1, arr2);
    auto az = z_2(a);

    if (aZ > az)
    {
        cout << "Z(" << aZ << ") > z(" << az << ")" << endl;

        cout << "Нулевую гипотизу отвергаем" << endl;
        cout << "Выборочные средние различаются значимо" << endl;
    }
    else if (aZ < az)
    {
        cout << "Z(" << aZ << ") < z(" << az << ")" << endl;
        cout << "Нулевую гипотизу не отвергаем" << endl;
        cout << "Выборочные средние различаются незначимо" << endl;
    }
    else
    {
        cout << "Error" << endl;
    }

   
}

void Answer7_2()
{
    cout << " Task 7" << endl;
    // ======== Условые задачи
    double arr_M_D[4] = {
        (32.4)/*(!x)*/,
        (30.1)/*(!y)*/,
        (15.0) /*(Dx)*/,
        (25.2) /*(Dy)*/
    };
    int n = 100, m = 120;
    double a = 0.05;
    auto aZ = Z(arr_M_D,n,m);
    auto az = z_2(a);

    if (arr_M_D[0] == arr_M_D[1] )
    {
        cout << "Ошибка М(Х) == М(У) по конкурирующей гипотезе (Н1)" << endl;
    }

    // Куда-то надо будет пристроить, наверное
    // && arr_M_D[0] > arr_M_D[1]/*M(X) > M(Y)*/
    //

    if (aZ > az )
    {
        cout << "Z(" << aZ << ") > z(" << az << ")" << endl;
       
        cout << "Нулевую гипотизу отвергаем" << endl;
        cout << "Выборочные средние различаются значимо" << endl;
    }
    else if (aZ < az)
    {
        cout << "Z(" << aZ << ") < z(" << az << ")" << endl;
        cout << "Нулевую гипотизу не отвергаем" << endl;
        cout << "Выборочные средние различаются незначимо" << endl;
    }
    else
    {
        cout << "Error" << endl;
    }

   
}

