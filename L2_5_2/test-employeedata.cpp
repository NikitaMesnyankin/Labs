#define BOOST_TEST_MODULE L2_5_2
#include <boost/test/included/unit_test.hpp>

#include "employeedata.h"

BOOST_AUTO_TEST_SUITE(EmployeeDataTestSuite)

BOOST_AUTO_TEST_CASE(InvalidEmployeeDataParameters)
{
	BOOST_CHECK_THROW(mesnyankin::EmployeeData("", "", "", 5), std::invalid_argument);
	BOOST_CHECK_THROW(mesnyankin::EmployeeData("A", "B", "C", 0), std::invalid_argument);
	BOOST_CHECK_THROW(mesnyankin::EmployeeData("A", "B", "C", -5), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(InvalidSetMethodInvoking)
{
	mesnyankin::EmployeeData obj1 = mesnyankin::EmployeeData("Ivanov", "Ivan", "Ivanovich", 100);

	BOOST_CHECK_THROW(obj1.setSalary(-200), std::invalid_argument); //checking setSalary method
	BOOST_CHECK_THROW(obj1.setInitials("", "", ""), std::invalid_argument); //checking setInitials method
	BOOST_CHECK_THROW(obj1.setData("K", "L", "M", -10), std::invalid_argument); //checking setData method
	BOOST_CHECK_THROW(obj1.setData("K", "L", "M", 0), std::invalid_argument); //checking setData method
	BOOST_CHECK_THROW(obj1.setData("", "", "", 10), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(CorrectSetMethodsInvoking)
{
	mesnyankin::EmployeeData obj1 = mesnyankin::EmployeeData("Ivanov", "Ivan", "Ivanovich", 100);
	
	obj1.setSalary(200); //checking setSalary method
	BOOST_CHECK_EQUAL(obj1.getSalary(), 200);

	obj1.setInitials("A", "B", "C"); //checking setInitials method
	BOOST_CHECK_EQUAL(obj1.getSurname(), "A");
	BOOST_CHECK_EQUAL(obj1.getName(), "B");
	BOOST_CHECK_EQUAL(obj1.getPatronymic(), "C");

	obj1.setData("K", "L", "M", 10); //checking setData method
	BOOST_CHECK_EQUAL(obj1.getSalary(), 10);
	BOOST_CHECK_EQUAL(obj1.getSurname(), "K");
	BOOST_CHECK_EQUAL(obj1.getName(), "L");
	BOOST_CHECK_EQUAL(obj1.getPatronymic(), "M");
}

BOOST_AUTO_TEST_SUITE_END()