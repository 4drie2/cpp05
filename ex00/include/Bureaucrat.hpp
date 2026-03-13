/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abidaux <abidaux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 13:40:36 by abidaux           #+#    #+#             */
/*   Updated: 2026/03/13 14:00:35 by abidaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <iostream>
# include <string>
# include <exception>

class Bureaucrat
{
	public:
		class GradeTooHighException;
		class GradeTooLowException;

		Bureaucrat();
		Bureaucrat(const std::string& name, int grade);
		Bureaucrat(const Bureaucrat& other);
		Bureaucrat& operator=(const Bureaucrat& other);
		~Bureaucrat();

		const std::string&	getName() const;
		int					getGrade() const;

		void				incrementGrade();
		void				decrementGrade();

	private:
		const std::string	_name;
		int					_grade;

};

class Bureaucrat::GradeTooHighException : public std::exception
{
	public:
		virtual const char* what() const throw();
};

class Bureaucrat::GradeTooLowException : public std::exception
{
	public:
		virtual const char* what() const throw();
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat);
