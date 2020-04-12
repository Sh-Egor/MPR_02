#include <iostream>
#pragma once
class Resolve{
public:
	std::string name;
	double* vec;
	int size;
	int ind;
	double value;

	Resolve() {};
	void show();
	~Resolve() {};
};

