#include "data.h"

int main()
{
	mesnyankin::doubleNumber o1, o2;
	mesnyankin::linkedList o3;
	char choice = '0';
	std::cout << "LIST AND DOUBLE WORKER\n" << std::endl;
	do
	{
		std::cout << "Enter your choose" << std::endl;
		std::cout << "1: Set 2 number parameters" << std::endl
			<< "2: Sum 2 number (friend function)" << std::endl
			<< "3: Subtract second number from first" << std::endl
			<< "4: View numbers parameters" << std::endl
			<< "5: Create container from double" << std::endl
			<< "6: Demostrate post- and pre- INCREMENTS" << std::endl
			<< "7: Demostrate post- and pre- DECREMENTS" << std::endl
			<< "8: View linked list data" << std::endl
			<< "9: Exit" << std::endl;
		std::cin.width(1);
		std::cin >> choice;
		switch (choice)
		{
		case '1':
		{
			double first_number, second_number;
			std::cout << "Enter data for first (obj1) number (double type)" << std::endl;
			o1.setNumber();
			std::cout << "Enter data for first (obj1) number (double type)" << std::endl;
			o2.setNumber();
			break;
		}
		case '2':
		{
			std::cout << "Result of sum: ";
			(o1 + o2).showNumber();
			break;
		}
		case '3':
		{
			std::cout << "Result of substr: ";
			(o1 - o2).showNumber();
			break;
		}
		case '4':
		{
			std::cout << "First number: ";
			o1.showNumber();
			std::cout << "Second number: ";
			o2.showNumber();
			break;
		}
		case '5':
		{
			std::cout << "Create list from double (enter double)" << std::endl;
			o3 = mesnyankin::linkedList(mesnyankin::correctInput());
			break;
		}
		case '6':
		{
			std::cout << "Processing post- and pre- increments...\n Post: " << std::endl;
			o3++;
			o3.showData();
			std::cout << "Pre: " << std::endl;
			++o3;
			o3.showData();
			break;
		}
		case '7':
		{
			std::cout << "Processing post- and pre- decrements...\nPOST: \nBefore post:" << std::endl;
			o3.showData();
			std::cout << "Attempting to POSTdecrement.." << std::endl;
			o3--;
			std::cout << "After POST: ";
			o3.showData();
			std::cout << "Attempting to PREdecrement.." << std::endl;
			--o3;
			std::cout << "After PRE: ";
			o3.showData();
			break;
		}
		case '8':
		{
			o3.showData();
			break;
		}
		case '9':
		{
			std::cout << "End commited..." << std::endl;
			break;
		}
		default:
		{
			std::cout << "No command found!..." << std::endl;
			break;
		}
		}
	} while (choice != '9');
	return 0;
}