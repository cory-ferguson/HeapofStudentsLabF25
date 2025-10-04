#include <string>
#include <iostream>
#include "address.h"

Address::Address(){
	street = "";
	city = "";
	state = "";
	zip = "";
}

void Address::init(std::string street, std::string city, std::string state, std::string zip){
	Address::street = street;
	Address::city = city;
	Address::state = state;
	Address::zip = zip;
}//end init

void Address::printAddress(){
	std::cout << street << std::endl;
	std::cout << city << " " << state << ", " << zip << std::endl;
}//end print
