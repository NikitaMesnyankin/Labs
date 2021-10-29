#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <regex>
#include <variant>

//static const std::regex INT_TYPE("[+-]?[0-9]+");
//static const std::regex DOUBLE_TYPE("[+-]?[0-9]+[.]?[0-9]+");
static const std::regex UNSIGNED_INT_TYPE("[+]?[0-9]+");

namespace mesnyankin
{
	size_t correctedInput()
	{
		while (true)
		{
			std::string matching_string;
			std::getline(std::cin, matching_string);
			std::cout << "Entered: " << matching_string << std::endl;
			if (std::regex_match(matching_string, UNSIGNED_INT_TYPE))
			{
				return std::stoi(matching_string);
			}
			else {
				std::cout << "Wrong input! Repeat..." << std::endl;
			}
		}
	}

	template <typename T>
	T correctInput()
	{
		T m = std::numeric_limits<T>::lowest() + 1, M = std::numeric_limits<T>::max(), value;
		for (;;) {
			if ((std::cin >> value).good()) return std::ranges::clamp(value, m, M);
			if (std::cin.fail()) {
				std::cin.clear();
				std::cout << "Incorrect input! Repeat!..\n";
			}
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
	}

	template<typename T>
	void fillContainer(std::vector<T>& container, size_t count)
	{
		std::cout << "You have to input " << count << " times " << typeid(T).name() << " variable "
			<< std::endl << "or even write them in one row. Inputs are truncated if first part is correct"
			<< std::endl << "or asked to be reentered if input wrong at all. Example: " << std::endl
			<< "5 c c c c -> 5 WILL BE added to container, proceed to CONTINUE till all container won't be filled..." << std::endl
			<< "c 4 3 2 1 -> NOTHING will be added to container, container is empty..." << std::endl;
		for (unsigned int i = 0; i < count; i++)
		{
			container.emplace_back(correctInput<T>());
		}
	}

	template <typename T>
	unsigned int countZeros(std::vector<T>& container)
	{
		unsigned int counter = 0;
		for (const T& item : container)
		{
			if (item == 0)
			{
				counter++;
			}
		}
		return counter;
	}

	template <typename T>
	T countSumAfterMinimum(std::vector<T>& container)
	{
		T sum = 0;
		auto minimum = std::min_element(container.begin(), container.end());
		auto distance = std::distance(container.begin(), minimum);
		if (minimum == container.end())
		{
			std::cout << "Minimum is on the last position, returned 0" << std::endl;
			return 0;
		}
		for (auto it = std::next(container.begin() + distance); it < container.end(); it++)
		{
			sum += *it;
		}
		return sum;
	}

	template <typename T>
	void showData(std::vector<T> container)
	{
		for (const T& item : container)
		{
			std::cout << item << " ";
		}
		std::cout << std::endl;
	}

	template <typename T>
	void selectionSort(std::vector<T>& container)
	{
		unsigned int vectorSize = container.size();
		for (unsigned int j = 0; j < vectorSize - 1; ++j)
		{
			unsigned int min = j;
			for (unsigned int i = j + 1; i < vectorSize; ++i)
			{
				if (container.at(min) > container.at(i))
				{
					min = i;
				}
			}
			if (min != j)
			{
				std::swap(container[j], container[min]);
			}
		}
	}

	template <typename T>
	void proceedWithContainer(std::vector<T>& container)
	{
		int choice;
		do
		{
			std::cout << "1: Show container data..." << std::endl
				<< "2: Count zeros in container..." << std::endl
				<< "3: Count sum after minimum..." << std::endl
				<< "4: Selection container sort..." << std::endl
				<< "5: Back to element type select..." << std::endl;
			std::cin.width(1);
			std::cin >> choice;
			switch (choice)
			{
			case 1:
			{
				mesnyankin::showData(container);
				break;
			}
			case 2:
			{
				std::cout << "Container zero count: " << mesnyankin::countZeros(container) << std::endl;
				break;
			}
			case 3:
			{
				std::cout << "Sum of elements after minimum: " << mesnyankin::countSumAfterMinimum(container) << std::endl;
				break;
			}
			case 4:
			{
				mesnyankin::selectionSort(container);
				break;
			}
			case 5:
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
		} while (choice != 5);
	}
}