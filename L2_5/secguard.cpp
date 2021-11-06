#include "secguard.h"

mesnyankin::SecGuard::SecGuard() :
	mesnyankin::Employee()
{
}

mesnyankin::SecGuard::SecGuard(const std::string& surname, const std::string& name,
	const std::string& patronymic, int salary, const std::string& defence_item) :
	mesnyankin::Employee(surname, name, patronymic, salary),
	defence_item_(defence_item)
{
}

mesnyankin::SecGuard::SecGuard(const mesnyankin::sArray& sArr, int salary, const std::string& defence_item) :
	mesnyankin::Employee(sArr, salary),
	defence_item_(defence_item)
{
}

mesnyankin::SecGuard::SecGuard(const mesnyankin::eTuple& tupleData, const std::string& defence_item) :
	mesnyankin::Employee(tupleData),
	defence_item_(defence_item)
{
}

mesnyankin::SecGuard::SecGuard(const mesnyankin::SecGuard& rhs) :
	defence_item_(rhs.defence_item_)
{
	this->setInitials(rhs.getInitials());
	this->setSalary(rhs.getSalary());
}

mesnyankin::SecGuard::SecGuard(mesnyankin::SecGuard&& rhs) noexcept :
	defence_item_(std::move(rhs.defence_item_))
{
	this->setInitials(std::move(rhs.getInitials()));
	this->setSalary(std::move(rhs.getSalary()));
}

mesnyankin::SecGuard& mesnyankin::SecGuard::SecGuard::operator=(const mesnyankin::SecGuard& rhs)
{
	if (this != &rhs)
	{
		this->setInitials(rhs.getInitials());
		this->setSalary(rhs.getSalary());
		this->defence_item_ = rhs.defence_item_;
	}

	return *this;
}

mesnyankin::SecGuard& mesnyankin::SecGuard::SecGuard::operator=(mesnyankin::SecGuard&& rhs) noexcept
{
	if (this != &rhs)
	{
		this->setInitials(rhs.getInitials());
		this->setSalary(rhs.getSalary());
		this->defence_item_ = rhs.defence_item_;
	}

	return *this;
}

std::string mesnyankin::SecGuard::getItem() const
{
	return this->defence_item_;
}

void mesnyankin::SecGuard::setItem(const std::string& item)
{
	this->defence_item_ = item;
}

void mesnyankin::SecGuard::addItem(const std::string& item)
{
	this->defence_item_.append(" " + item);
}

void mesnyankin::SecGuard::clearItems()
{
	this->defence_item_.clear();
}
