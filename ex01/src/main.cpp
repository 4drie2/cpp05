#include "Bureaucrat.hpp"
#include <iostream>

int main()
{
	try {
		Bureaucrat high("High", 2);
		std::cout << high << std::endl;
		high.incrementGrade();
		std::cout << high << std::endl;
		high.incrementGrade();
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	try {
		Bureaucrat low("Low", 149);
		std::cout << low << std::endl;
		low.decrementGrade();
		std::cout << low << std::endl;
		low.decrementGrade();
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	try {
		Bureaucrat error("Error", 151);
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	return 0;
}
