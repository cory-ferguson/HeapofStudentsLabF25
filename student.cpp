#include <string>
#include <iostream>
#include <sstream>
#include "student.h"
#include "date.h"
#include "address.h"

Student::Student(){
	studentString = "";
	firstName = "";
	lastName = "";
	birthDate = new Date();
	gradDate = new Date();
	address = new Address();
	credHours = 0;
} //end constructor

Student::Student(std::string studentString){
	Student::init(studentString);
}

Student::~Student(){
	delete birthDate;
	delete gradDate;
	delete address;
} //end destructor

void Student::init(std::string studentString){
	Student::studentString = studentString;

	std::stringstream ss;
	ss.clear();
	ss.str(studentString);

	std::string street;
	std::string city;
	std::string state;
	std::string zip;
	std::string sBirthDate;
	std::string sGradDate;
	std::string sCredHours;

	getline(ss, firstName, ',');
	getline(ss, lastName, ',');
	getline(ss, street, ',');
	getline(ss, city, ',');
	getline(ss, state, ',');
	getline(ss, zip, ',');
	getline(ss, sBirthDate, ',');
	getline(ss, sGradDate, ',');
	getline(ss, sCredHours);

	address->init(street, city, state, zip);
	birthDate->init(sBirthDate);
	gradDate->init(sGradDate);

	ss.clear();
	ss.str(sCredHours);
	ss >> credHours;

} //end init

void Student::printStudent(){
	std::cout << firstName << " " << lastName << std::endl;
	address->printAddress();
	std::cout << "DOB: ";
	birthDate->printDate();
	std::cout << "Grad: ";
	gradDate->printDate();
	std::cout << "Credits: " << credHours << std::endl;
	std::cout << "____________________________________";
	std::cout << std::endl;

} //end printStudent

std::string Student::getLastFirst(){
	std::stringstream ss;
	ss.clear();
	ss << lastName << ", " << firstName << std::endl;
	return ss.str();
} //end getLastFirst

std::string Student::getLastName(){
	return lastName;
} //end getLastName

std::string Student::getFirstName(){
	return firstName;
} //end getFirstName

int Student::getCredHours(){
	return credHours;
} //end getCredHours
