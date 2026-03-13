#include "Bureaucrat.hpp"
#include <iostream>

void testBureaucrat(const std::string& name, int grade)
{
	std::cout << "--- Testing Bureaucrat: " << name << " (" << grade << ") ---" << std::endl;
	try
	{
		Bureaucrat b(name, grade);
		std::cout << "Successfully created: " << b << std::endl;

		std::cout << "Incrementing..." << std::endl;
		b.incrementGrade();
		std::cout << "After increment: " << b << std::endl;

		std::cout << "Decrementing twice..." << std::endl;
		b.decrementGrade();
		b.decrementGrade();
		std::cout << "After decrementing: " << b << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
	}
	std::cout << std::endl;
}

int main()
{
	std::cout << "=== Bureaucrat Valid Tests ===" << std::endl;
	testBureaucrat("Alice", 2);
	testBureaucrat("Bob", 149);

	std::cout << "=== Bureaucrat Invalid Instantiation Tests ===" << std::endl;
	testBureaucrat("TooHigh", 0);
	testBureaucrat("TooLow", 151);

	std::cout << "=== Copy & Assignation Test ===" << std::endl;
	try
	{
		Bureaucrat original("Original", 42);
		Bureaucrat copy(original);
		std::cout << "Copy: " << copy << std::endl;

		Bureaucrat assigned("Assigned", 100);
		assigned = original;
		std::cout << "Assigned (grade copied, name remains): " << assigned << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
	}

	return 0;
}
