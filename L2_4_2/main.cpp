#include "circular_list.h"

int main()
{
	driverCard data = mesnyankin::correctInput();
	std::cout << data.number << " " << data.driverName << " " << data.marschruteNumber <<  " " 
		<< data.isOnWay << std::endl;
	return 0;
}