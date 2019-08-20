/*
Author:Sohaib Nadeem
Student Number: 100621437
Assignment 1 | INFR2140
*/
#include<iostream>
#include<string>
#include "ComplexNumber.h"

int main()
{
	//instantiate objects
	ComplexNumber c1(1, 1);
	ComplexNumber c2(2, 2);
	ComplexNumber c3(6, 9);
	ComplexNumber c4(5, 7);
	ComplexNumber c5(12, 3);
	ComplexNumber c6, c7; //instantiated as (0,0) as per constructor
	
	//ask user to enter complex number
	std::cout << "Please enter a complex number in the form 'a+bi' where a is the real portion, and b is the imaginary portion:   (1 of 2)" << std::endl;
	std::cin >> c6; //store complex number in c6

	//ask user to enter complex number
	std::cout << "Please enter a complex number in the form 'a+bi' where a is the real portion, and b is the imaginary portion:   (2 of 2)" << std::endl;
	std::cin >> c7; //store complex number in c6

	//manipulate user's inputed complex numbers and display results
	std::cout << "\n" << c6 << " + " << c7 << " = " << c6 + c7 << std::endl;
	std::cout << c6 << " - " << c7 << " = " << c6 - c7 <<std::endl;
	std::cout << c6 << " > " << c7 << " ?: " << std::boolalpha << (c6 > c7) << std::endl;
	std::cout << "++" << c6 << " = ";
	std::cout<< ++c6 << std::endl;
	std::cout << c7 << "--" << " = ";
	std::cout<< c7-- <<std::endl;

	//display total number of instantiations of complex objects in the program
	std::cout << "Total Number of complex numbers instantiated: " << ComplexNumber::countNumber() << "." <<std::endl;
	system("pause");
	return 0;
}