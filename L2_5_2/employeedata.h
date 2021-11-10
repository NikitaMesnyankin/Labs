#ifndef EMPLOYEEDATA_H
#define EMPLOYEEDATA_H

#include "initials.h"
#include "payments.h"
#include <tuple>


namespace mesnyankin
{
	typedef std::tuple<std::string, std::string, std::string, int> DTuple;
	class EmployeeData : public Initials, public Payments
	{
	public:
		EmployeeData() = default;
		EmployeeData(const std::string&, const std::string&, const std::string&, int);
		EmployeeData(const EmployeeData&) = default;
		EmployeeData(EmployeeData&&) = default;

		EmployeeData& operator=(const EmployeeData&) = default;
		EmployeeData& operator=(EmployeeData&&) = default;

		DTuple getData() const;
		void setData(const std::string&, const std::string&, const std::string&, int);
	};
}

#endif
