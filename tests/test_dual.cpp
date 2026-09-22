#include <iostream>
#include <cassert> 
#include <string>
#include "dual.hpp"

using namespace std;

int main(){
	
	Dual x(3.0, 1.0);
	Dual y(5.0, 1.0);

	Dual sum = x+y;
	Dual difference = x-y;
	Dual product = x*y;
	Dual division = x/y;

	assert(sum.real_part == 8.0);
	assert(sum.derivative_part == 2.0);

	cout << "Addition Test of both Duals Passsed" << "\n";

	assert(difference.real_part == -2.0);
	assert(difference.derivative_part == 0.0);

	cout << "Subtraction Test of both Duals Passed" << "\n";

	assert(product.real_part == 15.0);
	assert(product.derivative_part == 8.0);

	cout << "Product Test of both Duals passed" << "\n";
	
	assert(division.real_part == 0.6);
	assert(division.derivative_part == 0.08);

	cout << "Division Test of both Duals passed" << "\n";

	cout << "All Tests Passed." << "\n";

	return 0;
}





