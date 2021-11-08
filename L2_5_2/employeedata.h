#ifndef EMPLOYEEDATA_H
#define EMPLOYEEDATA_H

#include "initials.h"
#include "payments.h"

namespace mesnyankin
{
	class EmployeeData : public Initials, public Payments
	{
		EmployeeData();
		EmployeeData(const std::string&, const std::string&, const std::string&, int);
		EmployeeData(const EmployeeData&);
		EmployeeData(EmployeeData&&);

		EmployeeData& operator=(const EmployeeData&);
		EmployeeData& operator=(EmployeeData&&);
	};
}


