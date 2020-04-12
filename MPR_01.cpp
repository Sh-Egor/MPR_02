#include <iostream>
#include "Matrix.h"
#include <locale.h>
using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	int size;
	double tmp;
	int num;
	cout << "Enter size:";
	cin >> size;
	Matrix mas(size);
	mas.enter();
	cout << "Выберите решение или введите любое другое число для вывода всех решений" << endl;
	for (int i = 0; i < 8; i++) {
		cout << i << ": " << mas.arr[i].name << endl;
	}
	cin >> num;
	if (num >= 0 && num <= 7) {
		mas.solve(num);
	}
	else {
		for (int i = 0; i < 8; i++) {
			mas.solve(i);
		}
	}
	mas.show(num);
}