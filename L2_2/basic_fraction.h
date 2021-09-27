#ifndef FRACTION_H
#define FRACTION_H

#include <iostream>
#include <numeric>
#include <type_traits>

namespace mesnyankin
{
	class BasicFraction
	{
	public:
		BasicFraction(); //default constructor
		BasicFraction(__int16, __int16); //basic constructor
		BasicFraction(const BasicFraction&); //copy constructor
		BasicFraction(BasicFraction&&) noexcept; //move constructor

		BasicFraction& operator =(const BasicFraction&); //copy assignment operator
		BasicFraction& operator =(BasicFraction&&) noexcept; //move assignment operator
		BasicFraction operator +(const BasicFraction&); //increment operator overloading
		BasicFraction& operator +=(const BasicFraction&); //short increment operator overloading
		template <typename T>
		BasicFraction operator +(const T& rhs)
		{
			std::cout << std::is_same<char, std::remove_reference<T>::type>() << std::endl;
			if (!(std::is_arithmetic<std::remove_reference<T>::type>::value))
			{
				throw std::invalid_argument("Invalid ariphmetic type!");
			}
			this->numerator_ = this->numerator_ + static_cast<__int16>(rhs) * this->denominator_;
			this->numerator_ /= std::gcd(this->numerator_, this->denominator_);
			this->denominator_ /= std::gcd(this->numerator_, this->denominator_);
			return *this;
		}

		BasicFraction operator -(const BasicFraction&);
		BasicFraction& operator -=(const BasicFraction&);
		template<typename T> BasicFraction operator -(const T&); //any type decrement

		__int16 getNumerator() const;
		__int16 getDenominator() const;
		~BasicFraction() = default;
	private:
		__int16 numerator_;
		__int16 denominator_;
	};

}


#endif 