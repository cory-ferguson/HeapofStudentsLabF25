#ifndef DATE_H_EXISTS
#define DATE_H_EXISTS

#include <string>

class Date{
	protected:
		std::string dateString;
		std::string month;
		std::string day;
		std::string year;

	public:
		Date();
		void init(std::string dateString);

		void printDate();
}; // end class def

#endif
