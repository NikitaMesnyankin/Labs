#include "initials.h"
#include <stdexcept>

mesnyankin::Initials::Initials(const std::string& surname, const std::string& name, const std::string& patronymic) :
	surname_(surname),
	name_(name),
	patronymic_(patronymic)
{
	if ((surname_.empty()) || (name_.empty()) || (patronymic_.empty()))
	{
		throw std::invalid_argument("Initials strings can't be empty!");
	}
}

void mesnyankin::Initials::setInitials(const std::string& surname, const std::string& name, const std::string& patronymic)
{
	*this = mesnyankin::Initials(surname, name, patronymic);
}

std::string mesnyankin::Initials::getSurname() const
{
	return surname_;
}

std::string mesnyankin::Initials::getName() const
{
	return name_;
}

std::string mesnyankin::Initials::getPatronymic() const
{
	return patronymic_;
}