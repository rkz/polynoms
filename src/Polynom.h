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
 * - le coefficient de plus haut degré est non nul ou le polynôme est nul
 * - les coefficients sont donnés du plus haut degré au plus bas
 * - le degré est >= 0
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

	// Élévation de degré
	Polynom raiseDegree (int delta) const;

};

// Printing
std::ostream& operator<< (std::ostream& os, Polynom& p);

// Two-operands operations between polynoms
Polynom operator+ (Polynom& p1, Polynom& p2);
Polynom operator* (double factor, Polynom& p2);
Polynom operator* (Polynom& p1, Polynom& p2);

#endif /* POLYNOM_H_ */
