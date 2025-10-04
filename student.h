#ifndef STUDENT_H_EXISTS
#define STUDENT_H

#include <string>
#include "date.h"
#include "address.h"

class Student{
	protected:
		std::string studentString;
		std::string firstName;
		std::string lastName;
		Date* birthDate;
		Date* gradDate;
		Address* address;
		int credHours;

	public:
		Student();
		Student(std::string studentString);
		~Student();
		void init(std::string studentString);
		void printStudent();
		std::string getLastFirst();
		std::string getLastName();
		std::string getFirstName();
		int getCredHours();
}; //end class def

#endif
