#include "circular_list.h"
#include <functional>
#include <random>

target_tuple mesnyankin::correctInput()
{
	std::string nmbr, drvrnm, mrschrt;
	bool nw;
	std::cout << "Enter autobus number..." << std::endl;
	std::cin >> nmbr;
	std::cout << "Enter driver name..." << std::endl;
	std::cin >> drvrnm;
	std::cout << "Enter marschrute number..." << std::endl;
	std::cin >> mrschrt;
	while (true) {
		std::string matching_string;
		std::cout << "Enter isOnWay: t(true) or f(false) to proceed..." << std::endl;
		std::getline(std::cin, matching_string);
		std::cout << "Entered: " << matching_string << std::endl;
		if ((matching_string.compare("t") == 0) || (matching_string.compare("f") == 0))
		{
			nw = (matching_string == "t") ? true : false;
			break;
		}
		else {
			std::cout << "Wrong input! Repeat..." << std::endl;
		}
	}

	return std::make_tuple(nmbr, drvrnm, mrschrt, nw);
}

boost::circular_buffer<target_tuple> mesnyankin::generateDataSet()
{
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> distrib(1, 5);
	auto genb = std::bind(std::uniform_int_distribution<>(0, 1), std::default_random_engine());

	const std::string autoNumbers[5] = { "10", "10A", "10B", "10C", "11" };
	const std::string initials[5] = { "Driver1", "Driver2", "Driver3", "Driver4", "Driver5" };
	const std::string routeNumbers[5] = { "5", "6", "7", "8", "9" };

	boost::circular_buffer<target_tuple> buffer(5);
	for (unsigned int i = 0; i < 5; i++)
	{
		buffer.push_back(std::make_tuple(autoNumbers[distrib(gen) - 1], initials[distrib(gen) - 1], routeNumbers[distrib(gen) - 1], genb()));
	}
	std::cout << "Dataset successfully generated, processing..." << std::endl;
	return buffer;
}





