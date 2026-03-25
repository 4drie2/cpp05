#include "../include/Bureaucrat.hpp"
#include "../include/Form.hpp"
#include <iostream>

int main()
{
	std::cout << "--- Test 1: Bureaucrats and Exceptions (ex00 recap) ---" << std::endl;
	try {
		Bureaucrat high("High", 2);
		std::cout << high << std::endl;
		high.incrementGrade();
		std::cout << high << std::endl;
		high.incrementGrade();
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << "\n--- Test 2: Construction bounds pour Formulaire ---" << std::endl;
	try {
		Form f1("ValidForm", 100, 100);
		std::cout << f1 << std::endl;
		Form f2("InvalidForm", 0, 100); // Grade too high!
	} catch (std::exception &e) {
		std::cerr << "Caught exception creating Form: " << e.what() << std::endl;
	}

	std::cout << "\n--- Test 3: SignForm avec Succes ---" << std::endl;
	try {
		Bureaucrat bob("Bob", 42); // Grade 42
		Form form("Tax form", 50, 50); // Necessite 50 pour signer (<= 50)

		std::cout << bob << std::endl;
		std::cout << form << std::endl;

		bob.signForm(form); // Devrait reussir

		std::cout << form << std::endl; // Signed doit etre "yes"
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << "\n--- Test 4: SignForm avec Echec ---" << std::endl;
	try {
		Bureaucrat alice("Alice", 100); // Grade 100
		Form form("Secret form", 50, 50); // Necessite 50 pour signer

		std::cout << alice << std::endl;
		std::cout << form << std::endl;

		alice.signForm(form); // Alice 100 est > 50, devrait echouer

		std::cout << form << std::endl; // Signed doit etre "no"
	} catch (std::exception &e) {
		std::cerr << "Exception inattendue ici: " << e.what() << std::endl;
	}

	return 0;
}

