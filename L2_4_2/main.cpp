#include "circular_list.h"

int main()
{
	auto mainItem = mesnyankin::CircularList<target_tuple>::CircularList();

	std::string s;
	int choice;
	std::cout << "TEMPLATE CLASS WORKER\n" << std::endl;
	do {
		std::cout << "1. Clear container..." << std::endl;
		std::cout << "2. Ready dataset initialization (full container)..." << std::endl;
		std::cout << "3. Add element to container..." << std::endl;
		std::cout << "4. Proceed search in container..." << std::endl;
		std::cout << "5. Output container data..." << std::endl;
		std::cout << "6. Exit..." << std::endl;

		std::getline(std::cin, s);
		//std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "GET:" << s << std::endl;
		choice =
			(s.compare("1") == 0) ? 1 :
			(s.compare("2") == 0) ? 2 :
			(s.compare("3") == 0) ? 3 :
			(s.compare("4") == 0) ? 4 :
			(s.compare("5") == 0) ? 5 :
			(s.compare("6") == 0) ? 6 : 7;
		switch (choice)
		{
		case 1:
		{
			mainItem.clear();
			break;
		}
		case 2:
		{
			mainItem = mesnyankin::CircularList<target_tuple>::CircularList(mesnyankin::generateDataSet());
			break;
		}
		case 3:
		{
			mainItem.push_back(mesnyankin::correctInput());
			break;
		}
		case 4:
		{
			mainItem.changeOnSearch();
			break;
		}
		case 5:
		{
			mainItem.showData();
			break;
		}
		case 6:
		{
			std::cout << "Exit commited..." << std::endl;
			break;
		}
		default:
		{
			std::cout << "No command found!..." << std::endl;
			break;
		}
		}
	} while (choice != 6);
	return 0;
}