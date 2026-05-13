/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abidaux <abidaux@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 16:16:34 by abidaux           #+#    #+#             */
/*   Updated: 2026/05/04 17:14:03 by abidaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <exception>

class MonErreur : public std::exception {
    public:
        virtual const char* what() const throw(){
            return "Voila mon message d'erreur";
        }
};

int main(){
    try {
        throw MonErreur();
    }
    catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }
}