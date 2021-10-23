#include "data.h"

double mesnyankin::correctInput()
{
	constexpr double m = std::numeric_limits<double>::lowest(), M = DBL_MAX;
	double value;
	for (;;) {
		if ((std::cin >> value).good()) return std::ranges::clamp(value, m, M);
		if (std::cin.fail()) {
			std::cin.clear();
			std::cout << "Incorrect input! Repeat!..\n";
		}
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}
}

mesnyankin::doubleNumber::doubleNumber() :
	number_(0.0)
{
}

mesnyankin::doubleNumber::doubleNumber(double value) :
	number_(value)
{
}

mesnyankin::doubleNumber::doubleNumber(const doubleNumber& rhs) :
	number_(rhs.number_)
{
}

mesnyankin::doubleNumber::doubleNumber(doubleNumber&& rhs) noexcept:
	number_(0.0)
{
	rhs.number_ = 0.0;
}

mesnyankin::doubleNumber& mesnyankin::doubleNumber::operator=(const doubleNumber& rhs)
{
	if (this != &rhs)
	{
		this->number_ = rhs.number_;
	}
	return *this;
}

mesnyankin::doubleNumber& mesnyankin::doubleNumber::operator=(doubleNumber&& rhs) noexcept
{
	if (this != &rhs)
	{
		this->number_ = std::move(rhs.number_);
	}
	return *this;
}

mesnyankin::doubleNumber mesnyankin::doubleNumber::operator-(const doubleNumber& rhs)
{
	return mesnyankin::doubleNumber(std::ranges::clamp(this->number_ - rhs.number_, std::numeric_limits<double>::lowest(), DBL_MAX));
}

mesnyankin::doubleNumber mesnyankin::operator+(const doubleNumber& fvalue, const doubleNumber& svalue)
{
	return doubleNumber(std::ranges::clamp(fvalue.number_ + svalue.number_, std::numeric_limits<double>::lowest(), DBL_MAX));
}

void mesnyankin::doubleNumber::showNumber() const
{
	std::cout << "Current number: " << this->number_ << std::endl;
}

void mesnyankin::doubleNumber::setNumber()
{
	this->number_ = correctInput();
}

mesnyankin::linkedList::linkedList()
{
	container_ = std::forward_list<double>();
}

mesnyankin::linkedList::linkedList(double value)
{
	container_ = std::forward_list({ value });
}

mesnyankin::linkedList::linkedList(const mesnyankin::linkedList& rhs)
{
	std::copy(std::begin(rhs.container_), std::end(rhs.container_), std::front_inserter(this->container_));
}

mesnyankin::linkedList::linkedList(mesnyankin::linkedList&& rhs) noexcept :
	container_(rhs.container_)
{
	rhs.container_.clear();
}

mesnyankin::linkedList& mesnyankin::linkedList::operator=(const mesnyankin::linkedList& rhs)
{
	if (this != &rhs)
	{
		mesnyankin::linkedList tmp(rhs);
		this->container_.swap(tmp.container_);
	}
	return *this;
}

mesnyankin::linkedList& mesnyankin::linkedList::operator=(mesnyankin::linkedList&& rhs) noexcept
{
	if (this != &rhs)
	{
		this->container_.clear();
		this->container_.splice_after(this->container_.before_begin(), rhs.container_);
	}
	return *this;
}

mesnyankin::linkedList& mesnyankin::linkedList::operator++()
{
	const auto before_end = std::next(this->container_.before_begin(), std::distance(this->container_.begin(), this->container_.end()));
	this->container_.insert_after(before_end, correctInput());
	return *this;
}

mesnyankin::linkedList mesnyankin::linkedList::operator++(int)
{
	mesnyankin::linkedList tmp(*this);
	operator++();
	return tmp;
}

mesnyankin::linkedList& mesnyankin::linkedList::operator--()
{
	if (!(this->container_.empty())) {
		this->container_.pop_front();
	}
	else {
		std::cout << "Container is empty!.." << std::endl;
	}
	return *this;
}

mesnyankin::linkedList mesnyankin::linkedList::operator--(int)
{
	mesnyankin::linkedList tmp(*this);
	operator--();
	return tmp;
}

void mesnyankin::linkedList::showData() const
{
	if (!(this->container_.empty())) {
		for (const double& i : this->container_)
		{
			std::cout << i << " ";
		}
		std::cout << std::endl;
	}
	else {
		std::cout << "Container is empty!.." << std::endl;
	}
}