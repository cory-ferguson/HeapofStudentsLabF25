#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include "date.h"
#include "address.h"
#include "student.h"

void testAddress();
void testDate();
void testStudent();

void loadStudents(std::vector<Student*>& students){
        std::ifstream inFile;
        std::string currentLine;

        inFile.open("students.csv");
        while(getline(inFile, currentLine)){
                Student* s = new Student;
                s->init(currentLine);
                students.push_back(s);
        }// end while
        inFile.close();
}// end loadStudents

void printStudents(std::vector<Student*>& students){
        for(Student* student: students){
                student->printStudent();
        }// end for
} // end printStdents

void showStudentNames(std::vector<Student*>& students){
        for(Student* student: students){
                std::cout << student->getLastFirst();
                std::cout << "____________________________________";
                std::cout << std::endl;
        }// end for
}// end showStudentNames

void findStudent(std::vector<Student*>& students){
	std::cin.ignore();
	std::cout << "Last name of student: ";
	std::string target;
	std::getline(std::cin, target);
	
	bool found = false;
        for(Student* student: students){
		std::string last = student->getLastName();
		if (last.find(target) != std::string::npos){
                       student->printStudent();
		       found = true;
		}// end if
        }// end for
	
	if (found = false){
		std::cout << "Student not found." << std::endl;
	}// end if

}// end findStudent


void delStudents(std::vector<Student*>& students){
        for(Student* student: students){
                delete student;
        }// end for
}// end delStudents


int  menu(){
        int x;
        std::cout << "0) quit" << std::endl;
        std::cout << "1) print all student names" << std::endl;
        std::cout << "2) print all student data" << std::endl;
	std::cout << "3) find a student" << std::endl;
        std::cout << std::endl;
        std::string input;
        std::cout << "please choose 0-3" << std::endl;
        std::cin >> input;
	
        if (input == "0"){
		x = 0;
        } else if (input == "1"){
                x = 1;
        } else if (input == "2"){
                x = 2;
        } else if (input == "3"){
                x = 3;
        } else{
		x = 0;
	}// end if 

        return x;
}// end menu

int main(){
        std::vector<Student*> students;
        loadStudents(students);

	bool keepGoing = true;
	
	while (keepGoing){
		int choice = menu();
		if (choice == 0){
                	keepGoing = false;
        	} else if (choice == 1){
			showStudentNames(students);
        	} else if (choice == 2){
			printStudents(students);
        	} else if (choice == 3){
			findStudent(students);
        	} else {
			std::cout << "invalid input" << std::endl;
		}// end if 
	
	}// end while

        delStudents(students);

  /*
  std::cout << "Hello!" << std::endl;
  testAddress();
  testDate();
  testStudent();
  return 0;
  */
} // end main


void testAddress(){
  Address a;
  a.init("123 W Main St", "Muncie", "IN", "47303");
  a.printAddress();
} // end testAddress


void testDate(){
 Date d;
 d.init("01/27/1997");
 d.printDate();
} // end testDate


void testStudent(){
  std::string studentString = "Danielle,Johnson,32181 Johnson Course Apt. 389,New Jamesside,IN,59379,02/17/2004,05/15/2027,65";
  Student* student = new Student();
  student->init(studentString);
  student->printStudent();
  std::cout << std::endl;
  std::cout << student->getLastFirst();
  delete student;
} // end testStudent

