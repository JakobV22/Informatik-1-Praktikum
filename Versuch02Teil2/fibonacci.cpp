//////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 MMXXIV
// Versuch 02
//
// Datei:  main.cpp
// Inhalt: Hauptprogramm
//////////////////////////////////////////////////////////////////////////////

#include <iostream>

int fibonacci(int n)
{
	int previousFib = 0; 				// statt = 1
	int currentFib = 1;
	if (n == 0)
	{
		return 0;
	}
	if (n == 1)
	{
		return 1;
	}
	for (int i = 2; i <= n; i++) 				// statt for(i = 0; i <= n, i++)
	{
		int newFib = previousFib + currentFib;
		previousFib = currentFib; 				//statt previousFib = newFib
		currentFib = newFib;				// statt currentFib = previousFib
	}
	return currentFib;
}

int main()
{
	std::cout << " Fibonacci - Zahlen von 0 bis 12:" << std::endl;
	for (int i = 0; i <= 47; i++)//fib(47) > 2^31 -1, somit nicht als 32 bit int darstellbar
	{											//fib(46) ist noch darstellbar
		std::cout << "f(" << i << ") = " << fibonacci(i) << std::endl;
	}
	return 0;
}
