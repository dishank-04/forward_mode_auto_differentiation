#include <iostream>
#include <cmath>
#include "dual.hpp"

// Defining a function f1(x) = exp(sin(x))
// x is going to be a dual number

Dual f1(const Dual& x){
	
	return exp(sin(x));

}

// Defining Function f2(x) = x^2 + sin(x) 

Dual f2(const Dual& x){
	
	return (x*x) + sin(x);

}

int main(){
	
	double x_val = 0.0;
	Dual x(x_val, 1.0); // Converting x_val to Dual x

	Dual result1 = f1(x); // Giving Dual x as input to function f
	
	assert(result1.real_part == 1.0);
	assert(result1.derivative_part == 1.0);

	std::cout << "Test-1 Passed" << "\n";

	Dual result2 = f2(x);

	assert(result2.real_part == 0.0);
	assert(result2.derivative_part == 1.0);

	std::cout << "Test-2 Passed" << "\n";
	
	return 0;
}
