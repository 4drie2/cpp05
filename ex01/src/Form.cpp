/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abidaux <abidaux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 03:25:27 by abidaux           #+#    #+#             */
/*   Updated: 2026/03/25 04:34:07 by abidaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Form.hpp"

Form::Form() : _name("Default"), _isSigned(false), _requireSignGrade(150), _requireExecGrade(150)
{
}

Form::Form(const std::string& name, int signGrade, int execGrade)
	: _name(name), _isSigned(false), _requireSignGrade(signGrade), _requireExecGrade(execGrade)
{
	if (signGrade < 1 || execGrade < 1)
		throw Form::GradeTooHighException();
	if (signGrade > 150 || execGrade > 150)
		throw Form::GradeTooLowException();
}

Form::Form(const Form& other)
	: _name(other._name), _isSigned(other._isSigned), _requireSignGrade(other._requireSignGrade), _requireExecGrade(other._requireExecGrade)
{
}

Form& Form::operator=(const Form& other)
{
	if (this != &other)
	{
		_isSigned = other._isSigned;
	}
	return *this;
}

Form::~Form()
{
}

const std::string& Form::getName() const
{
	return _name;
}

bool Form::getIsSigned() const
{
	return _isSigned;
}

int Form::getRequireSignGrade() const
{
	return _requireSignGrade;
}

int Form::getRequireExecGrade() const
{
	return _requireExecGrade;
}

void Form::beSigned(const Bureaucrat& bureaucrat)
{
	if (bureaucrat.getGrade() > _requireSignGrade)
		throw Form::GradeTooLowException();
	_isSigned = true;
}

const char* Form::GradeTooHighException::what() const throw()
{
	return "Form grade is too high!";
}

const char* Form::GradeTooLowException::what() const throw()
{
	return "Form grade is too low!";
}

std::ostream& operator<<(std::ostream& os, const Form& form)
{
	os << "Form " << form.getName()
	   << ", signed: " << (form.getIsSigned() ? "yes" : "no")
	   << ", required sign grade: " << form.getRequireSignGrade()
	   << ", required exec grade: " << form.getRequireExecGrade() << ".";
	return os;
}

