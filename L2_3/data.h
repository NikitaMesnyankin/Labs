#ifndef DATA_H
#define DATA_H

#include <iostream>
#include <limits>
#include <algorithm>
#include <forward_list>
#include <iterator>

namespace mesnyankin
{
	double correctInput();
	class doubleNumber
	{
		friend doubleNumber operator+(const doubleNumber&, const doubleNumber&);
	public:
		doubleNumber();
		doubleNumber(double);
		doubleNumber(const doubleNumber&);
		doubleNumber(doubleNumber&&) noexcept;

		void showNumber() const;
		void setNumber();

		doubleNumber& operator=(const doubleNumber&);
		doubleNumber& operator=(doubleNumber&&) noexcept;
		doubleNumber operator-(const doubleNumber&);
		~doubleNumber() = default;
	private:
		double number_;
	};
	
	class linkedList
	{
	public:
		linkedList();
		linkedList(double);
		linkedList(const linkedList&);
		linkedList(linkedList&&) noexcept;

		linkedList& operator=(const linkedList&);
		linkedList& operator=(linkedList&&) noexcept;
		linkedList& operator++();
		linkedList operator++(int);

		linkedList& operator--();
		linkedList operator--(int);

		void showData() const;
		~linkedList() = default;
	private:
		std::forward_list<double> container_;
	};
}

#endif
