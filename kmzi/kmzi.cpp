#include <iostream>
#include "OLSGenerator.h"
#include <ctime>
#include <cstdlib>

int main()
{
	srand(static_cast<unsigned int>(time(0)));
	vector<vector<int>> firstM;
	vector<vector<int>> secondM;
	generateOLS(firstM, secondM);
	std::cout << "Hello, World!" << std::endl;
}