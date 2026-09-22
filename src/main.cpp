#include <iostream> 
#include "dual.hpp"

using namespace std;


int main(){
	
	Dual x(3.0, 1.0);
	Dual y(5.0, 1.0); 

	Dual sum = x+y;
	Dual difference = x-y;
	Dual product = x*y;
	Dual division = x/y;

	cout << "Addition Real Part is: " << sum.real_part << "\n";
	cout << "Addition Derivative Part is: " << sum.derivative_part<< "\n";

	cout << "Difference Real Part is: " << difference.real_part << "\n";
	cout << "Difference Derivative Part is: " << difference.derivative_part <<"\n";

	cout << "Product Real Part is: " << product.real_part  << "\n";
	cout << "Product Derivative Part is: " << product.derivative_part << "\n";

	cout << "Division Real Part is: " << division.real_part << "\n";
	cout << "Division Derivative Part is: " << division.derivative_part << "\n";

	cout << "\n";

	cout << "Checking for Inline Operators" << "\n";

	Dual add = 4 + x;
	Dual subtract = 4 - x;
	Dual multiply = 4*x;
	Dual divide = 4/x;


	cout << "Addition Real Part is: " << add.real_part << "\n";
	cout << "Addition Derivative Part is: " << add.derivative_part<< "\n";

	cout << "Difference Real Part is: " << subtract.real_part << "\n";
	cout << "Difference Derivative Part is: " << subtract.derivative_part <<"\n";

	cout << "Product Real Part is: " << multiply.real_part  << "\n";
	cout << "Product Derivative Part is: " << multiply.derivative_part << "\n";

	cout << "Division Real Part is: " << divide.real_part << "\n";
	cout << "Division Derivative Part is: " << divide.derivative_part << "\n";
	

	return 0;
}
