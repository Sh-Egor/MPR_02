#include "Resolve.h"

void Resolve::show()
{
	std::cout << name;
	std::cout << "(";
	for (int i = 0; i < size-1; i++) {
		std::cout << vec[i] << ",";
	}
	std::cout << vec[size - 1] << ")" << std::endl;
	std::cout << "Choose is: " << ind << " (" << value << ")" << std::endl;
}
