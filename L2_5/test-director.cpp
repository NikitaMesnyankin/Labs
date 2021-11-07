#define BOOST_TEST_MODULE L2_5
#include <boost/test/included/unit_test.hpp>

#include "director.h"

BOOST_AUTO_TEST_SUITE(DirectorTestSuite)

BOOST_AUTO_TEST_CASE(InvalidDirectorParameters)
{
	mesnyankin::sArray
		empty_sarray,
		sarray_filled_empty{ "", "", "" };

	mesnyankin::eTVector
		empty_etvector,
		etvector_filled_empty,
		etvector_filled_negative,
		etvector_filled_correctly;

	etvector_filled_empty.push_back(std::make_tuple("", "", "", 1));
	etvector_filled_negative.push_back(std::make_tuple("A", "B", "C", -5));
	etvector_filled_correctly.push_back(std::make_tuple("A", "B", "C", 5));

	BOOST_CHECK_THROW(mesnyankin::Director::Director("", "", "", 4, etvector_filled_correctly), std::invalid_argument);
	BOOST_CHECK_THROW(mesnyankin::Director::Director("A", "B", "C", -4, etvector_filled_correctly), std::invalid_argument);
	BOOST_CHECK_THROW(mesnyankin::Director::Director("A", "B", "C", 4, empty_etvector), std::invalid_argument);
	BOOST_CHECK_THROW(mesnyankin::Director::Director("A", "B", "C", 4, etvector_filled_empty), std::invalid_argument);
	BOOST_CHECK_THROW(mesnyankin::Director::Director("A", "B", "C", 4, etvector_filled_negative), std::invalid_argument);

	BOOST_CHECK_THROW(mesnyankin::Director::Director(empty_sarray, 100, etvector_filled_correctly), std::invalid_argument);
	BOOST_CHECK_THROW(mesnyankin::Director::Director(sarray_filled_empty, 100, etvector_filled_correctly), std::invalid_argument);

	BOOST_CHECK_THROW(mesnyankin::Director::Director(mesnyankin::Director::Director("", "", "", 4,
			etvector_filled_correctly)), std::invalid_argument);
	BOOST_CHECK_THROW(mesnyankin::Director::Director(mesnyankin::Director::Director("A", "B", "C", -4,
		etvector_filled_correctly)), std::invalid_argument);
	BOOST_CHECK_THROW(mesnyankin::Director::Director(mesnyankin::Director::Director("A", "B", "C", 4,
			empty_etvector)), std::invalid_argument);
	BOOST_CHECK_THROW(mesnyankin::Director::Director(mesnyankin::Director::Director("A", "B", "C", 4,
			etvector_filled_empty)), std::invalid_argument);
	BOOST_CHECK_THROW(mesnyankin::Director::Director(mesnyankin::Director::Director("A", "B", "C", 4,
			etvector_filled_negative)), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(InvalidEmployeeAdding)
{
	mesnyankin::sArray
		empty_sarray,
		sarray_filled_empty{ "", "", "" };

	mesnyankin::eTuple
		empty_etuple,
		etuple_filled_empty = std::make_tuple("", "", "", 1),
		etuple_filled_negative = std::make_tuple("A", "B", "C", -5);

	mesnyankin::eTVector
		correct_etvector;

	correct_etvector.push_back(std::make_tuple("A", "B", "C", 5));

	mesnyankin::Director obj1 = mesnyankin::Director("Ivanov", "Ivan", "Ivanovich", 100, correct_etvector);

	BOOST_CHECK_THROW(obj1.add("", "", "", 1), std::invalid_argument);
	BOOST_CHECK_THROW(obj1.add("A", "", "", -1), std::invalid_argument);
	BOOST_CHECK_THROW(obj1.add(empty_sarray, 5), std::invalid_argument);
	BOOST_CHECK_THROW(obj1.add(sarray_filled_empty, 5), std::invalid_argument);
	BOOST_CHECK_THROW(obj1.add(empty_etuple), std::invalid_argument);
	BOOST_CHECK_THROW(obj1.add(etuple_filled_empty), std::invalid_argument);
	BOOST_CHECK_THROW(obj1.add(etuple_filled_negative), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(CorrectEmployeeAdding)
{
	mesnyankin::sArray test_data{ "A", "B", "C" };
	mesnyankin::eTuple correct_etuple = std::make_tuple("A", "B", "C", 5);
	mesnyankin::eTVector correct_etvector;
	correct_etvector.push_back(correct_etuple);

	mesnyankin::Director obj1 = mesnyankin::Director("Ivanov", "Ivan", "Ivanovich", 100, correct_etvector);
	
	obj1.dismiss_all(); //clear before check
	obj1.add(obj1); //object adding check
	
	BOOST_CHECK_EQUAL(mesnyankin::compareData(obj1.getStaff()[0], obj1.getInitials()), true);
	
	obj1.dismiss_all(); //clear before check
	obj1.add(correct_etuple); //tuple adding check
	obj1.add(correct_etuple); //adding 2 tuples

	for (const auto& item : obj1.getStaff())
	{
		BOOST_CHECK_EQUAL(mesnyankin::compareData(item, test_data), true);
	}

	obj1.dismiss_all(); //clear before check
	obj1.add(test_data, 1); //adding sarray + int
	obj1.add(test_data, 5); //adding 2 times

	for (const auto& item : obj1.getStaff())
	{
		BOOST_CHECK_EQUAL(mesnyankin::compareData(item, test_data), true);
	}

	obj1.dismiss_all(); //clear before check
	obj1.add("Z", "X", "C", 10); //adding 3 strings and int
	obj1.add("Z", "X", "C", 15); //adding 2 times

	mesnyankin::sArray zxc{ "Z", "X", "C" };
	for (const auto& item : obj1.getStaff())
	{
		BOOST_CHECK_EQUAL(mesnyankin::compareData(item, zxc), true);
	}
}

BOOST_AUTO_TEST_CASE(CorrectEmployeeDismissing)
{
	mesnyankin::sArray test_data{ "A", "B", "C" };
	mesnyankin::eTuple correct_etuple = std::make_tuple("A", "B", "C", 5);
	mesnyankin::eTVector correct_etvector;
	correct_etvector.push_back(correct_etuple);

	mesnyankin::Director obj1 = mesnyankin::Director("Ivanov", "Ivan", "Ivanovich", 100, correct_etvector);

	obj1.dismiss_all(); //clear before check
	obj1.add(obj1); //object adding check
	obj1.dismiss(obj1);

	BOOST_CHECK_EQUAL(obj1.getStaff().empty(), true);

	obj1.dismiss_all(); //clear before check
	obj1.add(correct_etuple); //tuple adding check
	obj1.add(correct_etuple);
	obj1.add(correct_etuple); //adding 3 tuples

	obj1.dismiss(test_data); //now there should be 2 employees

	for (const auto& item : obj1.getStaff())
	{
		BOOST_CHECK_EQUAL(mesnyankin::compareData(item, test_data), true);
	}

	obj1.dismiss(test_data); //1 employee left
	obj1.dismiss(test_data); //clear before check

	BOOST_CHECK_EQUAL(obj1.getStaff().empty(), true); //check if empty

	obj1.add("G", "H", "I", 1); //adding sarray + int
	obj1.add("K", "L", "M", 5); //adding 2 times

	obj1.dismiss("G", "H", "I"); //dismiss one
	BOOST_CHECK_EQUAL(mesnyankin::compareData(obj1.getStaff()[0], mesnyankin::sArray{"K", "L", "M"}), true); //check left is KLM

	obj1.dismiss("K", "L", "M"); //dismiss last one
	BOOST_CHECK_EQUAL(obj1.getStaff().empty(), true); //check is empty
}

BOOST_AUTO_TEST_SUITE_END()
