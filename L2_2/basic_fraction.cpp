#include "basic_fraction.h"

mesnyankin::BasicFraction::BasicFraction() :
	numerator_(0),
	denominator_(1)
{
	std::cout << "Created default basic fraction 0/1" << std::endl;
}

mesnyankin::BasicFraction::BasicFraction(__int16 numerator, __int16 denominator) :
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
	std::cout << "Worked copy assignment constructor!" << std::endl;
}

mesnyankin::BasicFraction::BasicFraction(BasicFraction&& source) noexcept :
	numerator_(std::move(source.numerator_)),
	denominator_(std::move(source.denominator_))
{
	std::cout << "Worked move assignment constructor!" << std::endl;
}

mesnyankin::BasicFraction& mesnyankin::BasicFraction::operator =(const BasicFraction& rhs)
{
	if (this != &rhs)
	{
		this->numerator_ = rhs.numerator_;
		this->denominator_ = rhs.denominator_;
	}

	std::cout << "Worked copy assignment!" << std::endl;
	return *this;
}

mesnyankin::BasicFraction& mesnyankin::BasicFraction::operator =(BasicFraction&& rhs) noexcept
{
	this->numerator_ = std::move(rhs.numerator_);
	this->denominator_ = std::move(rhs.denominator_);
	std::cout << "Worked noexcept move assignment!" << std::endl;
	return *this;
}

mesnyankin::BasicFraction mesnyankin::BasicFraction::operator +(const BasicFraction& rhs)
{
	this->numerator_ = this->numerator_ * rhs.denominator_ + rhs.numerator_ * this->denominator_;
	this->denominator_ = this->denominator_ * rhs.denominator_;

	this->numerator_ /= std::gcd(this->numerator_, this->denominator_);
	this->denominator_ /= std::gcd(this->numerator_, this->denominator_);
	return *this;
}

mesnyankin::BasicFraction& mesnyankin::BasicFraction::operator +=(const BasicFraction& rhs)
{
	this->numerator_ = this->numerator_ * rhs.denominator_ + rhs.numerator_ * this->denominator_;
	this->denominator_ = this->denominator_ * rhs.denominator_;

	this->numerator_ /= std::gcd(this->numerator_, this->denominator_);
	this->denominator_ /= std::gcd(this->numerator_, this->denominator_);
	return *this;
}

mesnyankin::BasicFraction mesnyankin::BasicFraction::operator -(const BasicFraction& rhs)
{
	this->numerator_ = this->numerator_ * rhs.denominator_ - rhs.numerator_ * this->denominator_;
	this->denominator_ = this->denominator_ * rhs.denominator_;

	this->numerator_ /= std::gcd(this->numerator_, this->denominator_);
	this->denominator_ /= std::gcd(this->numerator_, this->denominator_);
	return *this;
}

mesnyankin::BasicFraction& mesnyankin::BasicFraction::operator -=(const BasicFraction& rhs)
{
	this->numerator_ = this->numerator_ * rhs.denominator_ - rhs.numerator_ * this->denominator_;
	this->denominator_ = this->denominator_ * rhs.denominator_;

	this->numerator_ /= std::gcd(this->numerator_, this->denominator_);
	this->denominator_ /= std::gcd(this->numerator_, this->denominator_);
	return *this;
}

__int16 mesnyankin::BasicFraction::getNumerator() const
{
	return numerator_;
}

__int16 mesnyankin::BasicFraction::getDenominator() const
{
	return denominator_;
}



template<typename T>
inline mesnyankin::BasicFraction mesnyankin::BasicFraction::operator -(const T &rhs)
{
	if (!(std::is_arithmetic(rhs)))
	{
		throw std::invalid_argument("Invalid ariphmetic type!");
	}
	this->numerator_ = this->numerator_ - static_cast<__int16>(rhs) * this->denominator_;
	this->numerator_ /= std::gcd(this->numerator_, this->denominator_);
	this->denominator_ /= std::gcd(this->numerator_, this->denominator_);

	return *this;
}