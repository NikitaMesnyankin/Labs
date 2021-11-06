#include "director.h"

mesnyankin::Director::Director() :
	mesnyankin::Employee()
{
}

mesnyankin::Director::Director(const std::string& surname, const std::string& name,
		const std::string& patronymic, int salary, const eTVector& staff) :
	mesnyankin::Employee(surname, name, patronymic, salary)
{
	staff_ = staff;
	if (!(mesnyankin::verificateETVector(staff_)))
	{
		throw std::invalid_argument("Invalid eTVector data!");
	}
}

mesnyankin::Director::Director(const mesnyankin::sArray& sArr, int salary, const mesnyankin::eTVector& staff) :
	mesnyankin::Employee(sArr, salary)
{
	staff_ = staff;
	if (!(mesnyankin::verificateETVector(staff_)))
	{
		throw std::invalid_argument("Invalid eTVector data!");
	}
}

mesnyankin::Director::Director(const mesnyankin::eTuple& tupleData, const eTVector& staff) :
	mesnyankin::Employee(tupleData)
{
	staff_ = staff;
	if (!(mesnyankin::verificateETVector(staff_)))
	{
		throw std::invalid_argument("Invalid eTVector data!");
	}
}

mesnyankin::Director::Director(const mesnyankin::Director& rhs) :
	staff_(rhs.staff_)
{
	this->setInitials(rhs.getInitials());
	this->setSalary(rhs.getSalary());
}

mesnyankin::Director::Director(mesnyankin::Director&& rhs) noexcept :
	staff_(std::move(rhs.staff_))
{
	this->setInitials(std::move(rhs.getInitials()));
	this->setSalary(std::move(rhs.getSalary()));
	rhs.staff_.clear();
}

mesnyankin::Director& mesnyankin::Director::Director::operator=(const mesnyankin::Director& rhs)
{
	if (this != &rhs)
	{
		this->setInitials(rhs.getInitials());
		this->setSalary(rhs.getSalary());
		this->staff_ = rhs.staff_;
	}

	return *this;
}

mesnyankin::Director& mesnyankin::Director::Director::operator=(mesnyankin::Director&& rhs) noexcept
{
	if (this != &rhs)
	{
		this->setInitials(rhs.getInitials());
		this->setSalary(rhs.getSalary());
		for (const auto& item : rhs.staff_)
		{
			this->staff_.push_back(item);
		}
	}
	rhs.staff_.clear();

	return *this;
}

void mesnyankin::Director::add(const mesnyankin::eTuple& item)
{
	if (!(mesnyankin::verificateETuple(item)))
	{
		throw std::invalid_argument("Invalid eTuple item!");
	}

	this->staff_.push_back(item);
}

void mesnyankin::Director::add(const mesnyankin::sArray& sArr, int salary)
{
	if (!(mesnyankin::verificateSArray(sArr)) || salary <= 0)
	{
		throw std::invalid_argument("Invalid sArray or negative/zero salary!");
	}
	this->staff_.push_back(mesnyankin::make_tuple(sArr, salary));
}

void mesnyankin::Director::add(const std::string& surname, const std::string& name,
	const std::string& patronymic, int salary)
{
	mesnyankin::eTuple data_tuple = std::make_tuple(surname, name, patronymic, salary);
	if (!(mesnyankin::verificateETuple(data_tuple)))
	{
		throw std::invalid_argument("Invalid data!");
	}

	this->staff_.push_back(data_tuple);
}

void mesnyankin::Director::add(const Employee& employee)
{
	this->staff_.push_back(mesnyankin::make_tuple(employee.getInitials(), employee.getSalary()));
}

void mesnyankin::Director::dismiss(const std::string& surname, const std::string& name, const std::string& patronymic)
{
	mesnyankin::sArray sArr{ surname, name, patronymic };
	mesnyankin::erase_from_eTVector(this->staff_, sArr);
}

void mesnyankin::Director::dismiss(const sArray& sArr)
{
	mesnyankin::erase_from_eTVector(this->staff_, sArr);
}

void mesnyankin::Director::dismiss(const Employee& empl)
{
	mesnyankin::erase_from_eTVector(this->staff_, empl.getInitials());
}

void mesnyankin::Director::setStaff(const mesnyankin::eTVector& etv)
{
	if (mesnyankin::verificateETVector)
	{
		this->staff_ = etv;
	}
}

mesnyankin::eTVector mesnyankin::Director::getStaff() const
{
	return this->staff_;
}

void mesnyankin::Director::showStaff() const
{
	outputETVector(this->staff_);
}