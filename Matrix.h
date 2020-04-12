#include "Resolve.h"
class Matrix{
private:
	double** mas;
	int size;
public:
	Resolve* arr = nullptr;
	Matrix(int n) {
		size = n;
		mas = new double* [n];
		for (int i = 0; i < n; i++) {
			mas[i] = new double[n];
		}
		arr = new Resolve[8];
		for (int i = 0; i < 8; i++) {
			arr[i].name = " ";
			arr[i].vec = new double[size];
			arr[i].size = size;
			arr[i].ind = 0;
			arr[i].value = 0;
		}
		arr[0].name = "МинМаксный критерий";
		arr[1].name = "Байеса-Лапласса";
		arr[2].name = "Севведжа";
		arr[3].name = "Гурвица";
		arr[4].name = "Ходжа-Лемана";
		arr[5].name = "Гермейра";
		arr[6].name = "Байеса-Лапласса минимальный";
		arr[7].name = "Произведений";
	}
	void enter();
	void show(int);

	int min(double*);
	int max(double*);
	double maxCollum(int);
	double M(double*, double*);
	double P(double*);
	void solve(int);
	~Matrix() {
		for (int i = 0; i < size; i++) {
			delete[] mas[i];
		}
		delete[] mas;
		for (int i = 0; i < 8; i++) {
			delete[] arr[i].vec;
		}
		delete[] arr;
	}
};
