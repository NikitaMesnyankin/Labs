#ifndef DRIVER_H
#define DRIVER_H

#include "utilits.h"
#include "employee.h"

namespace mesnyankin
{
	class Driver : public Employee
	{
	public:
		Driver();
		Driver(const std::string&, const std::string&, const std::string&, int,
				const sVector&, const sVector&);
		Driver(const sArray&, int, const sVector&, const sVector&);
		Driver(const eTuple&, const sVector&, const sVector&);

		Driver(const Driver&);
		Driver(Driver&&) noexcept;

		Driver& operator=(const Driver&);
		Driver& operator=(Driver&&) noexcept;
		
		void addLicense(const std::string&);
		void removeLicense(const std::string&);
		sVector getLicences() const;

		void addTruck(const std::string&);
		void removeTruck(const std::string&);
		sVector getTrucks() const;

		void revokeLicences();
		void revokeTrucks();
	private:
		sVector licences_;
		sVector trucks_;
	};
}

#endif
