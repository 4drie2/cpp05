/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abidaux <abidaux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 02:29:00 by abidaux           #+#    #+#             */
/*   Updated: 2026/03/25 04:25:45 by abidaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "Bureaucrat.hpp"

class Form
{
	public:
		class GradeTooHighException : public std::exception {
			public:
				virtual const char* what() const throw();
		};

		class GradeTooLowException : public std::exception {
			public:
				virtual const char* what() const throw();
		};

		Form();
		Form(const std::string& name, int signGrade, int execGrade);
		Form(const Form& other);
		Form& operator=(const Form& other);
		~Form();

		const std::string&	getName() const;
		bool				getIsSigned() const;
		int					getRequireSignGrade() const;
		int					getRequireExecGrade() const;

		void				beSigned(const Bureaucrat& bureaucrat);

	private:
		const std::string	_name;
		bool				_isSigned;
		const int			_requireSignGrade;
		const int			_requireExecGrade;

};

std::ostream& operator<<(std::ostream& os, const Form& form);

