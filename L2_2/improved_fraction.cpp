#include "improved_fraction.h"

mesnyankin::ImprovedFraction::ImprovedFraction() :
	BasicFraction()
{
}

mesnyankin::ImprovedFraction::ImprovedFraction(int numerator, int denominator) :
	BasicFraction(numerator, denominator)
{
}

mesnyankin::ImprovedFraction::ImprovedFraction(const ImprovedFraction& source) :
	BasicFraction(source)
{
}

mesnyankin::ImprovedFraction::ImprovedFraction(ImprovedFraction&& source) noexcept :
	BasicFraction(source)
{
}

mesnyankin::ImprovedFraction& mesnyankin::ImprovedFraction::operator =(const ImprovedFraction& rhs)
{
	if (&rhs != this)
	{
		mesnyankin::BasicFraction::operator=(rhs);
	}
	return *this;
}

mesnyankin::ImprovedFraction& mesnyankin::ImprovedFraction::operator =(ImprovedFraction&& rhs) noexcept
{
	if (&rhs != this) {
		mesnyankin::BasicFraction::operator=(std::move(rhs));
	}
	return *this;
}

mesnyankin::ImprovedFraction mesnyankin::ImprovedFraction::operator +(const ImprovedFraction& rhs) {
	BasicFraction::operator+(rhs);
	return *this;
}

mesnyankin::ImprovedFraction& mesnyankin::ImprovedFraction::operator +=(const ImprovedFraction& rhs) {
	BasicFraction::operator+=(rhs);
	return *this;
}

mesnyankin::ImprovedFraction mesnyankin::ImprovedFraction::operator -(const ImprovedFraction& rhs) {
	BasicFraction::operator-(rhs);
	return *this;
}

mesnyankin::ImprovedFraction& mesnyankin::ImprovedFraction::operator -=(const ImprovedFraction& rhs) {
	BasicFraction::operator-=(rhs);
	return *this;
}

mesnyankin::ImprovedFraction mesnyankin::ImprovedFraction::operator *(const ImprovedFraction& rhs)
{
	int numerator = (this->getNumerator() * rhs.getNumerator()),
		denominator = (this->getDenominator() * rhs.getDenominator()),
		gcd = std::gcd(numerator, denominator);
	return mesnyankin::ImprovedFraction(numerator / gcd, denominator / gcd);
}

mesnyankin::ImprovedFraction& mesnyankin::ImprovedFraction::operator *=(const ImprovedFraction& rhs)
{
	this->setNumerator(this->getNumerator() * rhs.getNumerator());
	this->setDenominator(this->getDenominator() * rhs.getDenominator());
	long long gcd = std::gcd(this->getNumerator(), this->getDenominator());
	this->setNumerator(this->getNumerator() / gcd);
	this->setDenominator(this->getDenominator() / gcd);
	return *this;
}

mesnyankin::ImprovedFraction mesnyankin::ImprovedFraction::operator /(const ImprovedFraction& rhs)
{
	int numerator = (this->getNumerator() * rhs.getDenominator()),
		denominator = (this->getDenominator() * rhs.getNumerator()),
		gcd = std::gcd(numerator, denominator);
	return mesnyankin::ImprovedFraction(numerator / gcd, denominator / gcd);
}

mesnyankin::ImprovedFraction& mesnyankin::ImprovedFraction::operator /=(const ImprovedFraction& rhs)
{
	this->setNumerator(this->getNumerator() * rhs.getDenominator());
	this->setDenominator(this->getDenominator() * rhs.getNumerator());
	long long gcd = std::gcd(this->getNumerator(), this->getDenominator());
	this->setNumerator(this->getNumerator() / gcd);
	this->setDenominator(this->getDenominator() / gcd);
	return *this;
}
