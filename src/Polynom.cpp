/*
 * Polynom.cpp
 *
 *  Created on: 24 sept. 2013
 *      Author: raphael
 */

#include "Polynom.h"

#include <cmath>
#include <sstream>
#include <algorithm>

Polynom::Polynom (std::vector<double> p_coefficients)
{
	// Move forward until the first non-null coefficient
	std::vector<double>::const_iterator i = p_coefficients.begin();
	while (*i == 0)
		i++;

	// Initialize the coefficients
	_coefficients = std::vector<double>();
	while (i != p_coefficients.end()) {
		_coefficients.push_back(*i);
		i++;
	}
}

int Polynom::degree () const
{
	return _coefficients.size() - 1;
}

std::vector<double> Polynom::coefficients () const
{
	return _coefficients;
}

double Polynom::coefficient (int coeffDegree) const
{
	return _coefficients.at(degree() - coeffDegree);
}

double Polynom::eval (double x) const
{
	double result = 0;

	for (int k = degree(); k >= 0; k--) {
		result += coefficient(k) * pow(x, k);
	}

	return result;
}

bool Polynom::operator== (Polynom& p2) const
{
	if (degree() != p2.degree()) return false;

	for (int k = 0; k <= degree(); k++)
		if (coefficient(k) != p2.coefficient(k)) return false;

	return true;
}

bool Polynom::operator!= (Polynom& p2) const
{
	if (degree() != p2.degree()) return true;

	for (int k = 0; k <= degree(); k++)
		if (coefficient(k) != p2.coefficient(k)) return true;

	return false;
}

Polynom Polynom::derivative () const
{
	std::vector<double> d_coeffs = std::vector<double>();

	if (degree() > 0) {
		for (int k = degree(); k >= 1; k--)
			d_coeffs.push_back((double)k * coefficient(k));
	}
	else
		d_coeffs.push_back(0);

	return Polynom(d_coeffs);
}

Polynom Polynom::derivative (int degree) const
{
	// Recursive computation of n-th derivatives

	if (degree == 1) return derivative();
	else return derivative(degree - 1).derivative();
}

Polynom operator+ (Polynom& p1, Polynom& p2)
{
	std::vector<double> resultCoeffs;

	// Sum p1's and p2's coefficient up to the highest degree
	for (int k = 0; k <= p1.degree() || k <= p2.degree(); k++) {
		double c = 0;
		if (k <= p1.degree()) c += p1.coefficient(k);
		if (k <= p2.degree()) c += p2.coefficient(k);
		resultCoeffs.push_back(c);
	}

	// resultCoeffs are ordered from lowest to highest degree; reverse them
	// to make the sum polynom
	std::reverse(resultCoeffs.begin(), resultCoeffs.end());

	return Polynom(resultCoeffs);
}

std::ostream& operator<< (std::ostream& os, Polynom& p)
{
	std::ostringstream result;

	for (int k = p.degree(); k >= 0; k--) {
		double value = p.coefficient(k);

		if (value != 0) {
			// Display sign
			if (k == p.degree()) {
				if (value < 0) result << "-";
			}
			else {
				if (value > 0) result << " + ";
				else result << " - ";
			}

			// Display coeff, X and power
			if (abs(value) != 1 || (abs(value) == 1 && k == 0))
				result << (value >= 0 ? value : -value);

			if (k > 1)
				result << "X^" << k;
			if (k == 1)
				result << "X";
		}
	}

	os << result.str();
	return os;
}
