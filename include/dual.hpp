#pragma once
#include <cassert>
#include <iostream> 
#include <cmath>

class Dual{

	public: 
		
		double real_part;
		double derivative_part;

		// Defining Constructor 

		Dual(double real_val=0.0, double  derivative_val=0.0) : real_part(real_val), derivative_part(derivative_val) {}

	
		// Defining Operators 

		Dual operator+(const Dual& other) const {
			
			double new_real = real_part + other.real_part;
			double new_derivative = derivative_part + other.derivative_part;

			return Dual(new_real, new_derivative);

		}

		
		Dual operator-(const Dual& other) const {
			
			double new_real = real_part - other.real_part;
			double new_derivative = derivative_part - other.derivative_part;

			return Dual(new_real, new_derivative);

		}


		Dual operator*(const Dual& other) const {
			
			double new_real = real_part*other.real_part;
			double new_derivative = (real_part*other.derivative_part) + (derivative_part*other.real_part);

			return Dual(new_real, new_derivative);

		}




		Dual operator/(const Dual& other) const {
			
			assert(other.real_part != 0 && "Cannot Divide by Zero.");
				
			double new_real = real_part/other.real_part;
				
			double numerator = (derivative_part*other.real_part) - (real_part*other.derivative_part);
			double denominator = other.real_part*other.real_part;

			double new_derivative = numerator/denominator; 

			return Dual(new_real, new_derivative);

		}

};


			
inline Dual operator+(double scaler, const Dual& dual){
	
	return Dual(scaler + dual.real_part, dual.derivative_part); // Addition is b/w only real parts.

}


inline Dual operator-(double scaler, const Dual& dual){
	
	return Dual(scaler - dual.real_part, -dual.derivative_part); // Subtraction is b/w only real parts.
	
}


inline Dual operator*(double scaler, const Dual& dual){
	
	return Dual(scaler*dual.real_part, scaler*dual.derivative_part);

}

inline Dual operator/(double scalar, const Dual& dual) {
   
  	assert(dual.real_part != 0.0 && "Cannot divide by zero.");
    
	double new_real = scalar / dual.real_part;
    double new_derivative = (-scalar * dual.derivative_part) / (dual.real_part * dual.real_part);
    
	return Dual(new_real, new_derivative);
}


// Defining Elementry and Transcedental Functions

// Sin, Cos, exp etc expects double as input they have no idea how to process Dual numbers so we need to tell them. 


inline Dual sin(const Dual& x){
	
	double real = std::sin(x.real_part);
	double derivative = std::cos(x.real_part)*x.derivative_part;

	return Dual(real, derivative);

}

inline Dual cos(const Dual& x){
	
	double real = std::cos(x.real_part);
	double derivative = -std::sin(x.real_part)*x.derivative_part;

	return Dual(real, derivative);

}

inline Dual exp(const Dual& x){
	
	double real = std::exp(x.real_part);
	double derivative = std::exp(x.real_part)*x.derivative_part;

	return Dual(real, derivative);

}
