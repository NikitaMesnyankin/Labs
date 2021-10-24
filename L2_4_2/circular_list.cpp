#include "circular_list.h"

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
	nw = false;
	return std::make_tuple(nmbr, drvrnm, mrschrt, nw);
}



