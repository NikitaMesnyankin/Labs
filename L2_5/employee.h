#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include "utilits.h"

namespace mesnyankin
{
	class Employee
	{
	public:
		sArray getInitials() const;
		int getSalary() const;
		void setInitials(const std::string&, const std::string&, const std::string&);
		void setInitials(const sArray&);
		void setData(const eTuple&);
		void setSalary(int);
	protected:
		Employee();
		Employee(const std::string&, const std::string&, const std::string&, int);
		Employee(const sArray&, int);
		Employee(const eTuple&);
		~Employee() = default;
	private:
		sArray initials_;
		int salary_;
	};
}

#endif
