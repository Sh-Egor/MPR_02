#include "Matrix.h"
#include <iostream>
using namespace std;

void Matrix::enter()
{
	double tmp;
	for (int i = 0; i < size; i++) {
		std::cout << i << ": ";
		for (int j = 0; j < size; j++) {
			cin >> tmp;
			mas[i][j] = tmp;
		}
	}
}

void Matrix::show(int num)
{
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			cout << mas[i][j] << " ";
		}
		cout << endl;
	}
	if (num >= 0 && num <= 7) {
		arr[num].show();
		cout << endl;
	}
	else {
		for (int i = 0; i < 8; i++) {
			arr[i].show();
			cout << endl;
		}
	}

}

int Matrix::min(double* L)
{
	double min = L[0];
	int ind = 0;
	for (int i = 1; i < size; i++) {
		if (L[i] < min) {
			min = L[i];
			ind = i;
		}
	}
	return ind;
}

int Matrix::max(double* L)
{
	double max = L[0];
	int ind = 0;
	for (int i = 1; i < size; i++) {
		if (L[i] > max) {
			max = L[i];
			ind = i;
		}
	}
	return ind;
}

double Matrix::maxCollum(int num)
{
	double max = mas[0][num];
	for (int i = 1; i < size; i++) {
		if (mas[i][num] > max) {
			max = mas[i][num];
		}
	}
	return max;
}

double Matrix::M(double* L, double* R)
{
	double res = 0;
	for (int i = 0; i < size; i++) {
		res += L[i] * R[i];
	}
	return res;
}

double Matrix::P(double* L)
{
	double res = 1;
	for (int i = 0; i < size; i++) {
		res *= L[i];
	}
	return res;
}

void Matrix::solve(int num)
{
	switch (num)
	{
	case 0: {
		cout << "Метод: Критерий " << arr[num].name << endl;
		for (int i = 0; i < size; i++) {
			arr[num].vec[i] = mas[i][min(mas[i])];
		}
		arr[num].ind = max(arr[num].vec);
		arr[num].value = arr[num].vec[arr[num].ind];
	}
		  break;
	case 1: {
		cout << "Метод: Критерий " << arr[num].name << endl;
		cout << "Введите вектор вероятностей каждого события" << endl;
		double* tmp = new double[size];
		for (int i = 0; i < size; i++) {
			cin >> tmp[i];
		}
		for (int i = 0; i < size; i++) {
			arr[num].vec[i] = M(mas[i], tmp);
		}
		arr[num].ind = max(arr[num].vec);
		arr[num].value = arr[num].vec[arr[num].ind];
		delete[] tmp;
	}
		  break;
	case 2: {
		cout << "Метод: Критерий " << arr[num].name << endl;
		double** tmp = new double* [size];
		for (int i = 0; i < size; i++) {
			tmp[i] = new double[size];
		}
		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size; j++) {
				tmp[i][j] = mas[i][j];
			}
		}

		for (int i = 0; i < size; i++) {
			double max = maxCollum(i);
			for (int j = 0; j < size; j++) {
				tmp[j][i] = max - tmp[j][i];
			}
		}
		for (int i = 0; i < size; i++) {
			arr[num].vec[i] = tmp[i][max(tmp[i])];
		}
		arr[num].ind = min(arr[num].vec);
		arr[num].value = arr[num].vec[arr[num].ind];

		for (int i = 0; i < size; i++) {
			delete[] tmp[i];
		}
		delete[] tmp;
	}
		  break;
	case 3: {
		cout << "Метод: Критерий " << arr[num].name << endl;
		double c;
		cout << "Введите весовой множитель:" << endl;
		cin >> c;
		for (int i = 0; i < size; i++) {
			arr[num].vec[i] = mas[i][min(mas[i])] * c + mas[i][max(mas[i])] * (1 - c);
		}
		arr[num].ind = max(arr[num].vec);
		arr[num].value = arr[num].vec[arr[num].ind];
	}
		  break;
	case 4: {
		cout << "Метод: Критерий " << arr[num].name << endl;
		double nu;
		double* tmp = new double[size];
		cout << "Введите значение ню:" << endl;
		cin >> nu;
		cout << "Введите вектор вероятностей каждого события" << endl;
		for (int i = 0; i < size; i++) {
			cin >> tmp[i];
		}
		for (int i = 0; i < size; i++) {
			arr[num].vec[i] = M(mas[i], tmp) * nu + mas[i][min(mas[i])] * (1 - nu);
		}
		arr[num].ind = max(arr[num].vec);
		arr[num].value = arr[num].vec[arr[num].ind];
		delete[] tmp;
	}
		  break;
	case 5: {
		cout << "Метод: Критерий " << arr[num].name << endl;
		double** tmp = new double* [size];
		for (int i = 0; i < size; i++) {
			tmp[i] = new double[size];
		}
		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size; j++) {
				tmp[i][j] = mas[i][j];
			}
		}

		double cur;
		cout << "Введите вектор вероятностей каждого события" << endl;
		for (int i = 0; i < size; i++) {
			cin >> cur;
			for (int j = 0; j < size; j++) {
				tmp[j][i] *= cur;
			}
		}
		for (int i = 0; i < size; i++) {
			arr[num].vec[i] = tmp[i][min(tmp[i])];
		}
		arr[num].ind = max(arr[num].vec);
		arr[num].value = arr[num].vec[arr[num].ind];

		for (int i = 0; i < size; i++) {
			delete[] tmp[i];
		}
		delete[] tmp;
	}
		  break;
	case 6: {
		double ed;
		cout << "Метод: Критерий " << arr[num].name << endl;
		cout << "Введите число Eдоп" << endl;
		cin >> ed;
		cout << "Введите вектор вероятностей каждого события" << endl;
		double* tmp = new double[size];
		for (int i = 0; i < size; i++) {
			cin >> tmp[i];
		}
		double Zmm = arr[0].value;
		cout << Zmm << endl;
		int maxind = arr[0].ind;
		double maxinrow = mas[maxind][max(mas[maxind])];
		bool* permit = new bool[size];
		int cnt = 0;
		for (int i = 0; i < size; i++) {
			double tmp = Zmm - mas[i][min(mas[i])];
			if (tmp <= ed && mas[i][max(mas[i])] - maxinrow >= tmp) {
				permit[i] = true;
			}
			else {
				permit[i] = false;
			}
			if (permit[i]) {
				cnt++;
			}
		}
		for (int i = 0; i < size; i++) {
			if (permit[i]) {
				arr[num].vec[i] = M(mas[i], tmp);
			}
			else {
				arr[num].vec[i] = 0.00020201;
			}
			
		}
		if (cnt) {
			double answ;
			int answind;
			int j = 0;
			while (!permit[j]) {
				j++;
			}
			answ = arr[num].vec[j];
			answind = j;
			for (int i = j; i < size; i++) {
				if (permit[i] && arr[num].vec[i] > answ) {
					answ = arr[num].vec[i];
					answind = i;
				}
			}
			arr[num].ind = answind;
			arr[num].value = answ;
		}
		else {
			cout << "Решений нет" << endl;
		}
		delete[] permit;
		delete[] tmp;
	}
		  break;
	case 7: {
		cout << "Метод: Критерий " << arr[num].name << endl;
		for (int i = 0; i < size; i++) {
			arr[num].vec[i] = P(mas[i]);
		}
		arr[num].ind = max(arr[num].vec);
		arr[num].value = arr[num].vec[arr[num].ind];
	}
		  break;
	default:
		break;
	}
}
