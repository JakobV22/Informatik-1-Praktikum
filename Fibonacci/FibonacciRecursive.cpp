/*
 * FibonacciRecursive.cpp
 *
 *  Created on: 08.05.2024
 *      Author: vogel
 */
#include <iostream>
#include <string>


int fibonacciFunc(int a){
	if (a == 0){
		return 0;
	}
	else if (a == 1){
		return 1;
	}
	else{
		return fibonacciFunc(a-1) + fibonacciFunc(a-2);
	}
}


int main() {

	for (int n =0; n <= 42; n++){
	std::cout << n << ": " << fibonacciFunc(n)<< "\n" << std::endl;
	}
}



