#pragma once
#include "Task9.h"



void Answer6()
{
	
	// ======== ??????? ??????
	double arr_M_D[4] = {
		(142)/*(!x)*/,
		(150)/*(!y)*/,
		(28.2) /*(Dx)*/,
		(22.8) /*(Dy)*/
	};
	int n = 50, m = 50;
	double a = 0.01;
	// ???????? ??? ????????? ?????? ???????
	bool turn_on_first = false; 

	// ======== ????????? ?????? ???  ????????
	H value(arr_M_D[0], arr_M_D[1]);

	double use_Z = Z(arr_M_D, n, m), use_z = 0;
	

	// ======== ??????? ==========

	// ??????? 1
	if (value.Mx != value.My && turn_on_first)
	{
		cout << "??????? 1" << endl;
		// ?????? ??????????? ?????
		use_z = z_1(a);

		if (abs(use_Z) < use_z)
		{
			cout << "[Z](" << abs(use_Z) << ") < z(" << use_z << ")" << endl;
			//cout << "??? ????????? ?????????? ???????? ????????" << endl;
			cout << "??? ????????? ?????????? ??????? ????????" << endl;
			cout << "?????????? ??????? ??????????? ?????????" << endl;
		}
		else if (abs(use_Z) > use_z)
		{
			cout << "[Z](" << abs(use_Z) << ") > z(" << use_z << ")" << endl;
			//cout << "??? ????????? ?????????? ???????? ????????" << endl;
			cout << "??????? ???????? ?????????" << endl;
			cout << "?????????? ??????? ??????????? ???????" << endl;
		}
		else
		{
			cout << "Eror" << endl;
		}

	}
	// ??????? 2
	else if (value.Mx > value.My)
	{
		cout << "??????? 2" << endl;
		
		// ?????? ??????????? ?????
		use_z = z_2(a);
		cout << "??????????? ??????? - ??????????????" << endl;
		if (use_Z < use_z)
		{
			cout << "Z(" << use_Z << ") < z(" << use_z << ")" << endl;
			//cout << "??? ????????? ?????????? ???????? ????????" << endl;
			cout << "??? ????????? ?????????? ??????? ????????" << endl;
			cout << "?????????? ??????? ??????????? ?????????" << endl;
		}
		else if (use_Z > use_z)
		{
			cout << "Z(" << use_Z << ") > z(" << use_z << ")" << endl;
			//cout << "??? ????????? ?????????? ???????? ????????" << endl;
			cout << "??????? ???????? ?????????" << endl;
			cout << "?????????? ??????? ??????????? ???????" << endl;
		}
		else
		{
			cout << "Eror" << endl;
		}
	}
	else if (value.Mx < value.My)
	{
		cout << "??????? 3" << endl;
		// ?????? ??????????? ?????
		use_z = z_2(a);
		cout << "??????????? ??????? - ?????????????" << endl;
		if (use_Z > -use_z)
		{
			cout << "Z(" << use_Z << ") > -z(" << -use_z << ")" << endl;
			//cout << "??? ????????? ?????????? ???????? ????????" << endl;
			cout << "??? ????????? ?????????? ??????? ????????" << endl;
			cout << "?????????? ??????? !? ????????? ?????? ?????????? ??????? !?" << endl;
		}
		else if (use_Z < -use_z)
		{
			cout << "Z(" << use_Z << ") < -z(" << -use_z << ")" << endl;
			//cout << "??? ????????? ?????????? ???????? ????????" << endl;
			cout << "??????? ???????? ?????????" << endl;
			cout << "?????????? ??????? !? ??????? ?????? ?????????? ??????? !?" << endl;
			
		}
		else
		{
			cout << "Eror" << endl;
		}
	}

}