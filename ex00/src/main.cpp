#include "Bureaucrat.hpp"
#include <iostream>

int main()
{
	try {
		Bureaucrat high("High", 2);
		std::cout << high << std::endl;
		high.incrementGrade();
		std::cout << high << std::endl;
		high.incrementGrade(); // Should throw High
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	try {
		Bureaucrat low("Low", 149);
		std::cout << low << std::endl;
		low.decrementGrade();
		std::cout << low << std::endl;
		low.decrementGrade(); // Should throw Low
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	try {
		Bureaucrat error("Error", 151); // Should throw Low on creation
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	return 0;
}
