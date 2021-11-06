#include "secretary.h"

mesnyankin::Secretary::Secretary() :
	mesnyankin::Employee()
{
}

mesnyankin::Secretary::Secretary(const std::string& surname, const std::string& name,
	const std::string& patronymic, int salary) :
	mesnyankin::Employee(surname, name, patronymic, salary)
{
}

mesnyankin::Secretary::Secretary(const mesnyankin::sArray& sArr, int salary) :
	mesnyankin::Employee(sArr, salary)
{
}

mesnyankin::Secretary::Secretary(const mesnyankin::eTuple& tupleData) :
	mesnyankin::Employee(tupleData)
{
}

mesnyankin::Secretary::Secretary(const mesnyankin::Secretary& rhs)
{
	this->setInitials(rhs.getInitials());
	this->setSalary(rhs.getSalary());
}

mesnyankin::Secretary::Secretary(mesnyankin::Secretary&& rhs) noexcept
{
	this->setInitials(std::move(rhs.getInitials()));
	this->setSalary(std::move(rhs.getSalary()));
}

mesnyankin::Secretary& mesnyankin::Secretary::Secretary::operator=(const mesnyankin::Secretary& rhs)
{
	if (this != &rhs)
	{
		this->setInitials(rhs.getInitials());
		this->setSalary(rhs.getSalary());
	}

	return *this;
}

mesnyankin::Secretary& mesnyankin::Secretary::Secretary::operator=(mesnyankin::Secretary&& rhs) noexcept
{
	if (this != &rhs)
	{
		this->setInitials(rhs.getInitials());
		this->setSalary(rhs.getSalary());
	}

	return *this;
}

void mesnyankin::Secretary::showDirectorInfo(const mesnyankin::Director& director) const
{
	mesnyankin::outputTuple(director.getData());
}

void mesnyankin::Secretary::showDriversInfo(const mesnyankin::drvrVec& drVec)
{
	for (const mesnyankin::Driver& item : drVec)
	{
		mesnyankin::outputTuple(item.getData());
	}
}

void mesnyankin::Secretary::showGuardsInfo(const mesnyankin::scgrdVec& sgVec)
{
	for (const mesnyankin::SecGuard& item : sgVec)
	{
		mesnyankin::outputTuple(item.getData());
	}
}
