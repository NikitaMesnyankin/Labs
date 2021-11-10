#include "employeedata.h"

mesnyankin::EmployeeData::EmployeeData(const std::string& surname, const std::string& name,
		const std::string& patronymic, int salary) :
	mesnyankin::Initials::Initials(surname, name, patronymic),
	mesnyankin::Payments::Payments(salary)
{
}

mesnyankin::DTuple mesnyankin::EmployeeData::getData() const
{
	return std::make_tuple(this->getSurname(), this->getName(), this->getPatronymic(), this->getSalary());
}

void mesnyankin::EmployeeData::setData(const std::string& surname, const std::string& name,
		const std::string& patronymic, int salary)
{
	this->setInitials(surname, name, patronymic);
	this->setSalary(salary);
}