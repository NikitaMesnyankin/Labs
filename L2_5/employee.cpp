#include "employee.h"


mesnyankin::Employee::Employee() :
	initials_({"DefSurname", "DefName", "DefPartonymic"}),
	salary_(1)
{
}

mesnyankin::Employee::Employee(const std::string& surname, const std::string& name,
		const std::string& patronymic, int salary) :
	initials_({ surname, name, patronymic }),
	salary_(salary)
{
	if (salary_ <= 0)
	{
		throw std::invalid_argument("Salary must be positive value!");
	}
	else
	{
		if (!(mesnyankin::verificateSArray(initials_)))
		{
			throw std::invalid_argument("At least one initial value must be non-empty!");
		}
	}
}

mesnyankin::Employee::Employee(const sArray& initials, int salary) :
	initials_(initials),
	salary_(salary)
{
	if (salary_ <= 0)
	{
		throw std::invalid_argument("Salary must be positive non-zero value!");
	} else {
		if ((initials_.empty()) || (mesnyankin::verificateSArray(initials_))) {
			throw std::invalid_argument("Initials vector is empty or filled with empty strings!");
		}
	}
}

mesnyankin::Employee::Employee(const eTuple& tupleData) :
	salary_(std::get<3>(tupleData))
{
	mesnyankin::tie(tupleData, initials_);
	if (salary_ <= 0)
	{
		throw std::invalid_argument("Salary must be positive value!");
	}
	else
	{
		if (!(mesnyankin::verificateSArray(initials_)))
		{
			throw std::invalid_argument("At least one initial value must be non-empty!");
		}
	}
}

mesnyankin::sArray mesnyankin::Employee::getInitials() const
{
	return initials_;
}

int mesnyankin::Employee::getSalary() const
{
	return salary_;
}

mesnyankin::eTuple mesnyankin::Employee::getData() const
{
	return std::make_tuple(initials_[0], initials_[1], initials_[2], salary_);
}

void mesnyankin::Employee::setInitials(const std::string& surname,
		const std::string& name, const std::string& patronymic)
{
	if ((surname.empty()) && (name.empty()) && (patronymic.empty()))
	{
		throw std::invalid_argument("At least one initial value must be non-empty!");
	}

	initials_ = { surname, name, patronymic };
}

void mesnyankin::Employee::setInitials(const mesnyankin::sArray& initVector)
{
	if (initVector.empty() || (mesnyankin::verificateSArray(initials_))) {
		throw std::invalid_argument("Initials vector is empty!");
	}

	initials_ = initVector;
}

void mesnyankin::Employee::setSalary(int salary)
{
	if (salary <= 0) {
		throw std::invalid_argument("Salary must be positive non-zero value!");
	}

	salary_ = salary;
}

void mesnyankin::Employee::setData(const mesnyankin::eTuple& tupleData)
{
	mesnyankin::sArray tmpArr;
	mesnyankin::tie(tupleData, tmpArr);
	int salary = std::get<3>(tupleData);

	if (salary <= 0)
	{
		throw std::invalid_argument("Salary must be positive value!");
	}
	else
	{
		if ((mesnyankin::verificateSArray(tmpArr)))
		{
			throw std::invalid_argument("At least one initial value must be non-empty!");
		}
	}

	salary_ = salary;
	initials_ = tmpArr;
}
