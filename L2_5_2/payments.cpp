#include "payments.h"
#include <stdexcept>

mesnyankin::Payments::Payments(int salary) :
	salary_(salary)
{
	if (salary_ <= 0)
	{
		throw std::invalid_argument("Salary must be positive non-zero value!");
	}
}

void mesnyankin::Payments::setSalary(int salary)
{
	*this = mesnyankin::Payments::Payments(salary);
}

int mesnyankin::Payments::getSalary() const
{
	return salary_;
}