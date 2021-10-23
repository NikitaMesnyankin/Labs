#ifndef FRACTION_H
#define FRACTION_H

#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <type_traits>
#include <numeric>
#include <limits>
#include <iomanip>

namespace mesnyankin
{
	int correctInput();

	class BasicFraction
	{
	public:
		BasicFraction(); //default constructor
		BasicFraction(int, int); //basic constructor
		BasicFraction(const BasicFraction&); //copy constructor
		BasicFraction(BasicFraction&&) noexcept; //move constructor

		BasicFraction& operator =(const BasicFraction&); //copy assignment operator
		BasicFraction& operator =(BasicFraction&&) noexcept; //move assignment operator
		BasicFraction operator +(const BasicFraction&); //increment operator overloading
		BasicFraction& operator +=(const BasicFraction&); //short increment operator overloading
		BasicFraction operator -(const BasicFraction&);
		BasicFraction& operator -=(const BasicFraction&);

		/*template <typename T>
		inline BasicFraction operator +(T rhs)
		{
			if (!(std::is_arithmetic<std::remove_reference<T>>::type::value))
			{
				throw std::invalid_argument("Invalid entered type!..");
			}

			this->numerator_ = this->numerator_  + dynamic_cast<int>(rhs) * this->denominator_;

			long long gcd = std::gcd(this->numerator_, this->denominator_);
			this->numerator_ /= gcd;
			this->denominator_ /= gcd;
			return *this;
		}*/

		int getNumerator() const;
		int getDenominator() const;
		void setNumerator(int);
		void setDenominator(int);
		void showFraction() const;

		~BasicFraction() = default;
	private:
		int numerator_;
		int denominator_;
	};

}

#endif 