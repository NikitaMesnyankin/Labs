#include "function_template.h"

int main()
{
	size_t arraySize;
	int choice = 0;
	std::cout << "TEMPLATE WORKER\n" << std::endl;
	do {
		std::cout << "1. Enter the array size..." << std::endl;
		std::cout << "2. Exit" << std::endl;
		std::cin.width(1);
		std::cin >> choice;
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		switch (choice)
		{
		case 1:
		{
			std::cout << "Enter array size (positive number)..." << std::endl;
			arraySize = mesnyankin::correctedInput();
			std::cout << "Entered size = " << arraySize << std::endl;
			do
			{
				std::cout << "Enter the type you intend to work with..." << std::endl;
				std::cout << "1: Integer" << std::endl
					<< "2: Double" << std::endl
					<< "3: Float" << std::endl
					<< "4: Back to set new array size..." << std::endl;
				std::cin.width(1);
				std::cin >> choice;
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				switch (choice)
				{
				case 1:
				{
					std::vector<int> container;
					mesnyankin::fillContainer(container, arraySize);
					mesnyankin::proceedWithContainer(container);
					break;
				}
				case 2:
				{
					std::vector<double> container;
					mesnyankin::fillContainer(container, arraySize);
					mesnyankin::proceedWithContainer(container);
					break;
				}
				case 3:
				{
					std::vector<float> container;
					mesnyankin::fillContainer(container, arraySize);
					mesnyankin::proceedWithContainer(container);
					break;
				}
				case 4:
				{
					std::cout << "Returning to array size setter..." << std::endl;
					break;
				}
				default:
				{
					std::cout << "No command found!..." << std::endl;
					break;
				}
				}
			} while (choice != 4);
			break;
		}
		case 2:
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
	} while (choice != 2);
	return 0;
}