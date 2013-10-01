/*
 * Polynom.h
 *
 *  Created on: 24 sept. 2013
 *      Author: raphael
 */

#ifndef POLYNOM_H_
#define POLYNOM_H_

#include <vector>
#include <iostream>

/**
 * Invariants :
 * - le coefficient de plus haut degr� est non nul ou le polyn�me est nul
 * - les coefficients sont donn�s du plus haut degr� au plus bas
 * - le degr� est >= 0
 */
class Polynom
{
private:
	std::vector<double> _coefficients;

public:
	Polynom(std::vector<double> coefficients);

	// Getters
	int degree () const;
	std::vector<double> coefficients () const;
	double coefficient (int degree) const;

	// Evaluation
	double eval (double x) const;

	// Comparison
	bool operator== (Polynom& p2) const;
	bool operator!= (Polynom& p2) const;

	// Derivation
	Polynom derivative () const;
	Polynom derivative (int degree) const;

	// �l�vation de degr�
	Polynom raiseDegree (int delta) const;

};

// Printing
std::ostream& operator<< (std::ostream& os, Polynom& p);

// Two-operands operations between polynoms
Polynom operator+ (Polynom& p1, Polynom& p2);
Polynom operator* (double factor, Polynom& p2);
Polynom operator* (Polynom& p1, Polynom& p2);

#endif /* POLYNOM_H_ */
