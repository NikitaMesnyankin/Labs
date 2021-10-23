#include "basic_fraction.h"

int mesnyankin::correctInput()
{
	int m = sqrt(INT_MIN), M = sqrt(INT_MAX), value;
	for (;;) {
		if ((std::cin >> value).good()) return std::ranges::clamp(value, m, M);
		if (std::cin.fail()) {
			std::cin.clear();
			std::cout << "Incorrect input! Repeat!..\n";
		}
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}
}

mesnyankin::BasicFraction::BasicFraction() :
	numerator_(0),
	denominator_(1)
{
}

mesnyankin::BasicFraction::BasicFraction(int numerator, int denominator) :
	numerator_(numerator),
	denominator_(denominator)
{
	if (denominator_ == 0)
	{
		throw std::invalid_argument("Denominator cannot be zero!");
	}
}

mesnyankin::BasicFraction::BasicFraction(const BasicFraction& source) :
	numerator_(source.numerator_),
	denominator_(source.denominator_)
{
}

mesnyankin::BasicFraction::BasicFraction(BasicFraction&& source) noexcept :
	numerator_(std::move(source.numerator_)),
	denominator_(std::move(source.denominator_))
{
}

mesnyankin::BasicFraction& mesnyankin::BasicFraction::operator =(const BasicFraction& rhs)
{
	if (this != &rhs)
	{
		this->numerator_ = rhs.numerator_;
		this->denominator_ = rhs.denominator_;
	}
	return *this;
}

mesnyankin::BasicFraction& mesnyankin::BasicFraction::operator =(BasicFraction&& rhs) noexcept
{
	this->numerator_ = std::move(rhs.numerator_);
	this->denominator_ = std::move(rhs.denominator_);
	return *this;
}

mesnyankin::BasicFraction mesnyankin::BasicFraction::operator +(const BasicFraction& rhs)
{
	int numerator = this->numerator_ * rhs.denominator_ + rhs.numerator_ * this->denominator_,
	denominator = this->denominator_ * rhs.denominator_;

	int gcd = std::gcd(numerator, denominator);
	numerator /= gcd;
	denominator /= gcd;
	return BasicFraction(numerator, denominator);
}

mesnyankin::BasicFraction& mesnyankin::BasicFraction::operator +=(const BasicFraction& rhs)
{
	this->numerator_ = this->numerator_ * rhs.denominator_ + rhs.numerator_ * this->denominator_;
	this->denominator_ = this->denominator_ * rhs.denominator_;

	int gcd = std::gcd(this->numerator_, this->denominator_);
	this->numerator_ /= gcd;
	this->denominator_ /= gcd;
	return *this;
}

mesnyankin::BasicFraction mesnyankin::BasicFraction::operator -(const BasicFraction& rhs)
{
	int numerator = this->numerator_ * rhs.denominator_ - rhs.numerator_ * this->denominator_,
		denominator = this->denominator_ * rhs.denominator_;

	int gcd = std::gcd(numerator, denominator);
	numerator /= gcd;
	denominator /= gcd;
	return BasicFraction(numerator, denominator);
}

mesnyankin::BasicFraction& mesnyankin::BasicFraction::operator -=(const BasicFraction& rhs)
{
	this->numerator_ = this->numerator_ * rhs.denominator_ - rhs.numerator_ * this->denominator_;
	this->denominator_ = this->denominator_ * rhs.denominator_;

	int gcd = std::gcd(this->numerator_, this->denominator_);
	this->numerator_ /= gcd;
	this->denominator_ /= gcd;
	return *this;
}

int mesnyankin::BasicFraction::getNumerator() const
{
	return numerator_;
}

int mesnyankin::BasicFraction::getDenominator() const
{
	return denominator_;
}

void mesnyankin::BasicFraction::setNumerator(int numerator)
{
	this->numerator_ = numerator;
}

void mesnyankin::BasicFraction::setDenominator(int denominator)
{
	if (denominator == 0) {
		throw std::invalid_argument("Denominator cannot be zero!");
	}
	this->denominator_ = denominator;
}

void mesnyankin::BasicFraction::showFraction() const
{
	std::cout << this->numerator_ << "/" << this->denominator_ << std::endl;
}

