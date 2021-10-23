#ifndef CIRCULAR_H
#define CIRCULAR_H

#include <list>
#include <iterator>
#include <string>
#include <iostream>
#include <boost/circular_buffer.hpp>

struct driverCard
{
	std::string number;
	std::string driverName;
	std::string marschruteNumber;
	bool isOnWay;
};

namespace mesnyankin
{
	driverCard correctInput()
	{
		driverCard data;
		std::cout << "Enter autobus number..." << std::endl;
		std::cin >> data.number;
		std::cout << "Enter driver name..." << std::endl;
		std::cin >> data.driverName;
		std::cout << "Enter marschrute number..." << std::endl;
		std::cin >> data.marschruteNumber;
		data.isOnWay = false;
		return data;
	}

	template <typename T>
	class CircularList
	{
	public:
		CircularList();
		CircularList(const CircularList&);
		CircularList(CircularList&&);

		CircularList& operator=(const CircularList&);
		CircularList& operator=(CircularList&&) noexcept;

		void showData() const;
		~CircularList() = default;
	private:
		boost::circular_buffer<T> buffer_;
	};
}

#endif
