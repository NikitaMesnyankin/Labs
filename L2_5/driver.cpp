#include "driver.h"

mesnyankin::Driver::Driver() :
	mesnyankin::Employee()
{
}

mesnyankin::Driver::Driver(const std::string& surname, const std::string& name,
		const std::string& patronymic, int salary,
				const sVector& licenses, const sVector& trucks) :
	mesnyankin::Employee(surname, name, patronymic, salary)
{
	licences_ = licenses;
	trucks_ = trucks;
	if (!(mesnyankin::verificateSVector(licences_)) || !(mesnyankin::verificateSVector(trucks_)))
	{
		throw std::invalid_argument("Invalid sVectors data!");
	}
}

mesnyankin::Driver::Driver(const mesnyankin::sArray& sArr, int salary,
		const sVector& licenses, const sVector& trucks) :
	mesnyankin::Employee(sArr, salary)
{
	licences_ = licenses;
	trucks_ = trucks;
	if (!(mesnyankin::verificateSVector(licences_)) || !(mesnyankin::verificateSVector(trucks_)))
	{
		throw std::invalid_argument("Invalid sVectors data!");
	}
}

mesnyankin::Driver::Driver(const mesnyankin::eTuple& tupleData,
		const sVector& licenses, const sVector& trucks) :
	mesnyankin::Employee(tupleData)
{
	licences_ = licenses;
	trucks_ = trucks;
	if (!(mesnyankin::verificateSVector(licences_)) || !(mesnyankin::verificateSVector(trucks_)))
	{
		throw std::invalid_argument("Invalid sVectors data!");
	}
}

mesnyankin::Driver::Driver(const mesnyankin::Driver& rhs) :
	licences_(rhs.licences_),
	trucks_(rhs.trucks_)
{
	this->setInitials(rhs.getInitials());
	this->setSalary(rhs.getSalary());
}

mesnyankin::Driver::Driver(mesnyankin::Driver&& rhs) noexcept :
	licences_(std::move(rhs.licences_)),
	trucks_(std::move(rhs.trucks_))
{
	this->setInitials(std::move(rhs.getInitials()));
	this->setSalary(std::move(rhs.getSalary()));
	rhs.licences_.clear();
	rhs.trucks_.clear();
}

mesnyankin::Driver& mesnyankin::Driver::Driver::operator=(const mesnyankin::Driver& rhs)
{
	if (this != &rhs)
	{
		this->setInitials(rhs.getInitials());
		this->setSalary(rhs.getSalary());
		this->licences_ = rhs.licences_;
		this->trucks_ = rhs.trucks_;
	}

	return *this;
}

mesnyankin::Driver& mesnyankin::Driver::Driver::operator=(mesnyankin::Driver&& rhs) noexcept
{
	if (this != &rhs)
	{
		this->setInitials(rhs.getInitials());
		this->setSalary(rhs.getSalary());
		for (const auto& item : rhs.licences_)
		{
			this->licences_.push_back(item);
		}
		
		for (const auto& item : rhs.trucks_)
		{
			this->trucks_.push_back(item);
		}
	}
	rhs.licences_.clear();
	rhs.trucks_.clear();

	return *this;
}

mesnyankin::sVector mesnyankin::Driver::getLicences() const
{
	return this->licences_;
}

mesnyankin::sVector mesnyankin::Driver::getTrucks() const
{
	return this->trucks_;
}

void mesnyankin::Driver::revokeLicences()
{
	this->licences_.clear();
}

void mesnyankin::Driver::revokeTrucks()
{
	this->trucks_.clear();
}

void mesnyankin::Driver::addLicense(const std::string& license)
{
	if (!(license.empty()))
	{
		this->licences_.push_back(license);
	}
}

void mesnyankin::Driver::addTruck(const std::string& truck)
{
	if (!(truck.empty()))
	{
		this->trucks_.push_back(truck);
	}
}

void mesnyankin::Driver::removeLicense(const std::string& licence)
{
	mesnyankin::erase_from_sVector(this->licences_, licence);
}

void mesnyankin::Driver::removeTruck(const std::string& truck)
{
	mesnyankin::erase_from_sVector(this->trucks_, truck);
}
