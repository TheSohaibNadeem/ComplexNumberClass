/*
Author:Sohaib Nadeem
Student Number: 100621437
Assignment 1 | INFR2140
*/
#include<iostream>
#include<string>
#include<stdlib.h>
#include "ComplexNumber.h"

int ComplexNumber::complexNo = 0; //set number of objects as zero only the first time the class is run

//overload input/output definitions
std::ostream& operator<<(std::ostream& output, const ComplexNumber& complexNumber)
{
	output << "("<< complexNumber.getReal() << "+" << complexNumber.getImaginary() << "i)";
	return output;
}
std::istream& operator>>(std::istream& input, ComplexNumber& complexNumber)
{
	std::string userIn;
	input >> userIn;
	double real = cleanReal(userIn);
	double imaginary = cleanImaginary(userIn);
	complexNumber.setReal(real);
	complexNumber.setImaginary(imaginary);
	return input;
}

//MEMBER FUNCTION DEFINITIONS

//constructor definiton
ComplexNumber::ComplexNumber(double newReal, double newImaginary) :real(newReal), imaginary(newImaginary) { complexNo++; }

//getter definitions
double ComplexNumber::getReal() const
{
	return real;
}
double ComplexNumber::getImaginary() const
{
	return imaginary;
}
int ComplexNumber::countNumber()
{
	return complexNo;
}

//setter definitions
void ComplexNumber::setReal(double newReal)
{
	real = newReal;
}
void ComplexNumber::setImaginary(double newImaginary)
{
	imaginary = newImaginary;
}

//overload math operator definitons
ComplexNumber ComplexNumber::operator+(const ComplexNumber& number)
{
	return ComplexNumber(real + number.real, imaginary + number.imaginary);
}
ComplexNumber ComplexNumber::operator-(const ComplexNumber& number)
{
	return ComplexNumber(real - number.real, imaginary - number.imaginary);
}
ComplexNumber & ComplexNumber::operator++()
{
	ComplexNumber(++real, imaginary);
	return *this;

}
ComplexNumber ComplexNumber::operator--(int)
{
	return ComplexNumber(real--, imaginary);
}

//overload logic operator definitons
bool ComplexNumber::operator==(const ComplexNumber& number)
{
	if (real == number.real && imaginary == number.imaginary)
	{
		return true;
	}
	else
		return false;
}
bool ComplexNumber::operator>(const ComplexNumber& number)
{
	if (real > number.real && imaginary > number.imaginary)
	{
		return true;
	}
	else
		return false;
}

//string cleaner functions: Functions take input from user in form 'a+bi' where a is real and b is imaginary, and extract the number values of a and b and return as double
double cleanReal(std::string& inputStr) {
	std::string cleanString = "";
	int length = inputStr.length();
	for (int i = 0; i < length; i++) {
		char currentChar = inputStr.at(i);
		if (currentChar != '+'&&currentChar != ' ') 
		{
			cleanString += currentChar;
		}
		if (currentChar == '+' || currentChar == ' ')
		{
			break;
		}
	}
	double cleanReal = std::stod(cleanString);
	return cleanReal;
}
double cleanImaginary(std::string& inputStr)
{
	std::string cleanString = "";
	bool imaginaryPart = false;
	int length = inputStr.length();
	for (int i = 0; i < length; i++) {
		char currentChar = inputStr.at(i);
		if (currentChar == '+'|| currentChar == ' ')
		{
			imaginaryPart = true;
		}
		if (currentChar != '+' && currentChar != ' ' &&currentChar != 'i' && imaginaryPart)
		{
			cleanString += currentChar;
		}
	}
	double cleanImaginary = std::stod(cleanString);
	return cleanImaginary;
}
