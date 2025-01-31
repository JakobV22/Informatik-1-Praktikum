//////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 
// 
// Versuch 04: Einf�hrung Klasse
//
// Datei:  Vektor.cpp
// Inhalt: Sourcedatei der Klasse Vektor
//////////////////////////////////////////////////////////////////////////////

#include "Vektor.h"

Vektor::Vektor(double inX, double inY, double inZ) :
		x(inX), y(inY), z(inZ)
{

}

Vektor::~Vektor()
{

}

/**
 * @brief Function printing the components of the vector 
 */
void Vektor::ausgabe() const
{
	std::cout << "X-Komponente: " << x << std::endl;
	std::cout << "Y-Komponente: " << y << std::endl;
	std::cout << "Z-Komponente: " << z << std::endl << std::endl;
}
/**
 * @brief Function returning the length of the vector
 * @return
 */
double Vektor::laenge() const
{
	double length;
	length = sqrt(x * x + y * y + z * z);
	return length;
}
/**
 * @brief Function subtracting another vector from the vector and returning the resulting vector
 * @param input Vector that will be subtracted from the first vector
 * @return	Vector resulting from the subtraction
 */
Vektor Vektor::sub(const Vektor &input) const
{
	double newX = x - input.x;
	double newY = y - input.y;
	double newZ = z - input.z;
	Vektor newVector(newX, newY, newZ);
	return newVector;
}
/**
 * @brief Function calculating the scalar produkt of the vector and the input vector
 * @param input second vector
 * @return	scalar product of first and second vector
 */
double Vektor::skalarProd(const Vektor &input) const
{
	double scalar = 0;
	scalar += (x * input.x);
	scalar += (y * input.y);
	scalar += (z * input.z);

	return scalar;
}

/**
 * @brief calculates angle between vector and second vector
 * @param input second vector
 * @return angle in degrees
 */
double Vektor::winkel(const Vektor &input) const
{
	double angle = acos(skalarProd(input) / (laenge() * input.laenge()));
	angle *= (180 / M_PI);
	return angle;
}

/**
 * @brief rotates vector around z-axis
 * @param rad rotation angle
 */
void Vektor::rotiereUmZ(const double rad)
{
	double newX = cos(rad) * x - sin(rad) * y;
	double newY = sin(rad) * x + cos(rad) * y;
	x = newX;			//this-> nicht notwendig?
	y = newY;

}
