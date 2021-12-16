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


double Mediana(const vector<double>& arr);
// �������������� �� ����������� ������ � ��������� ��������������� ���������� � �����������
void func_1(const double m, const double s, vector<double>& histogram) {

    // uncomment to use a non-deterministic seed
    //    random_device gen;
    //    mt19937 gen(rd());
    // ******************************
    // �� ��� � �� �������
    // ��������� ����������� �������
    // �� ���� ��� ��������
    // ******************************
    mt19937 gen(1701);
    normal_distribution<> distr(m, s);

    cout << endl;
    cout << "m() == " << fixed << setw(11) << setprecision(10) << distr.mean() << endl;
    cout << "s() == " << fixed << setw(11) << setprecision(10) << distr.stddev() << endl;

    // ������ ����� �� ����������� ������ � ������� � ������
    for (int i = 0; i < histogram.size(); ++i) {
        histogram[i] = distr(gen);
    }

    // ��������
    sort(histogram.begin(), histogram.end());

}

// ����� �������
void PrintVector(const vector<double>& histogram)
{
    // print results
    int counter = 0;
    cout << "Distribution for " << histogram.size() << " samples:" << endl;
    for (const auto& elem : histogram) {
        cout << fixed << setw(11) << ++counter << ": "
            << setw(14) << setprecision(10) << elem << endl;
    }
    cout << endl;
}

// ����������� 
// ��� ������������ ����� ��� ������� �������������� 
double MathWait(const vector<double>& arr)
{
    double mw = 0.0;
    for (size_t i = 0; i < arr.size(); i++)
    {
        mw += arr[i];
    }
    return mw / arr.size();
}

// ���������
double Dispersia(const vector<double>& arr)
{
    // ������� ����� �� �������� ���������������
    double diff_of_a_num_from_the_average = 0.0;
    /*temp,e-���������������*/
    double temp = 0.0;
    // ������� ��������������
    double average = MathWait(arr);

    // ----------- ������ ��������� ---------
    for (int j = 0; j < arr.size(); j++)
    {
        diff_of_a_num_from_the_average = arr[j] - average;
        temp += pow(diff_of_a_num_from_the_average, 2);
    }

    return temp /= arr.size();
}

// ========= �������� ===============
double dopQuartile(const vector<double>& arr, int percent)
{
    double temp = 0.0;
    int sizeA = arr.size();
    int firstIndex = 0, secondIndex = 0;
    // ���� ��� ������� ������� ����� �����, �� ����������� ��� � ����� � ���������
    // ���� ���, �� ���� ����� ��� ����� ���������� ��, �������� �� ���, � ������� ��������
    // ������ : ������ = 2.5, ����� ��� ����� ����� � �������� 2 � 3
    // ���������� �� � �����, � ���������� ��������, �������� �� 2, �� ��� ������� �������
    if ((sizeA / 100.0 * percent) != (int)(sizeA / 100.0 * percent))
    {
        firstIndex = sizeA / 100.0 * percent - 1;
        secondIndex = firstIndex + 1;
        temp = (arr[firstIndex] + arr[secondIndex]) / 2.0;
    }
    else
    {
        temp = arr[sizeA / 100.0 * percent - 1];
    }
    return temp;
}
void Quartile(const vector<double>& arr)
{
    cout << "������ ��������  (0.25) = " << dopQuartile(arr, 25) << endl;
    cout << "�������          (0.50) = " << Mediana(arr) << endl;
    cout << "������� �������� (0.75) = " << dopQuartile(arr, 75) << endl;
    cout << "������           (0.90) = " << dopQuartile(arr, 90) << endl;
    cout << "����������       (0.99) = " << dopQuartile(arr, 99) << endl;
}

double Mediana(const vector<double>& arr)
{
    if (arr.size() % 2 == 0) // ������
    {
        return (arr[arr.size() / 2 - 1] + arr[arr.size() / 2]) / 2.0;
    }
    else
    {
        return arr[arr.size() / 2];
    }
}


void Answer2()
{
    cout << " Task 2" << endl;
    double m = 4; // ������� ��� ��������
    double d = 1; // ������� ���������
    int setSize = 9;
    vector<double> arr(setSize);
    func_1(m, d, arr);

    PrintVector(arr);

    cout << "�����������             = " << MathWait(arr) << endl;
    Enter;
    cout << "���������               = " << Dispersia(arr) << endl;
    Enter;
    cout << "�������� : "  << endl;
    Quartile(arr);
    Enter;
    cout << "�������                 = " << Mediana(arr) << endl;
}