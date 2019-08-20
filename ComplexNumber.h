/*
Author:Sohaib Nadeem
Student Number: 100621437
Assignment 1 | INFR2140
*/
#ifndef COMPLEXNUMBER_H
#define COMPLEXNUMBER_H
#include<iostream>
#include<string>

//Class Declaration: This class handles Complex Numbers in the expected (mathematical) way

class ComplexNumber {
	//input/output operator overloading
	friend std::ostream& operator<<(std::ostream&, const ComplexNumber&);
	friend std::istream& operator>>(std::istream&, ComplexNumber&);
	//friend functions to manipulate user input
	friend double cleanReal(std::string&); //takes form 'a+bi' and returns a
	friend double cleanImaginary(std::string&); //takes form 'a+bi' and returns b

public:
	explicit ComplexNumber(double = 0, double = 0); //(Real, Imaginary)

	//getter functions
	double getReal() const; //returns real part of ComplexNumber object
	double getImaginary() const; //returns imaginary part of ComplexNumber object
	static int countNumber(); // returns number of ComplexNumber objects created

	//setter functions
	void setReal(double); //sets real part of ComplexNumber object
	void setImaginary(double);//sets imaginary part of ComplexNumber object

	//math operator overloading
	ComplexNumber operator+(const ComplexNumber&); //allows for mathematically common addition of ComplexNumber objects
	ComplexNumber operator-(const ComplexNumber&);//allows for mathematically common subtraction of ComplexNumber objects

	//logic operator overloading 
	bool operator==(const ComplexNumber&); //checks real and imaginary parts of two ComplexNumber Objects, if (real.c1 == real.c2 && imaginary.c1 == imaginary.c2) returns true, else false
	bool operator>(const ComplexNumber&);  //checks real and imaginary parts of two ComplexNumber Objects, if (real.c1 > real.c2 && imaginary.c1 > imaginary.c2) returns true, else false

	//increment/decrement operator overloading
	ComplexNumber &operator++(); //pre-increment operator increases real part of ComplexNumber object by 1 - prefix
	ComplexNumber operator--(int); //post-decrement operator decreases real part of ComplexNumber by 1 - postfix

private:
	//variables  // WHERE ComplexNumber Object is of form 'a+bi'
	double real; //real part of ComplexNumber object (a)
	double imaginary; //imaginary part of ComplexNumber object (b)
	static int complexNo; //tracks number of ComplexNumber objects created
};
#endif
