#include "military.h"

mesnyankin::Military::Military(const std::string& surname, const std::string& name,
		const std::string& patronymic, int salary)
{
	this->setInitials(surname, name, patronymic);
	this->setSalary(salary);
	this->setItem("Dubinka");
	this->addLicense("B");
	this->addTruck("AutoZAK");
}