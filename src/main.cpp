#include "Polynom.h"
#include <iostream>
#include <vector>

int main (int argc, char** argv)
{
	std::vector<double> coefs = std::vector<double>();
	coefs.push_back(-1.0);
	coefs.push_back(1);
	coefs.push_back(-5.1);
	coefs.push_back(1);

	Polynom p = Polynom(coefs);
	std::cout << "P = " << p << std::endl;
	Polynom pd = p.derivative();
	std::cout << "P' = " << pd << std::endl;
}
