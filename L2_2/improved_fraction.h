#ifndef IMPROVED_FRACTION_H
#define IMPROVED_FRACTION_H

#include "basic_fraction.h"

namespace mesnyankin {
	class ImprovedFraction : public BasicFraction
	{
	public:
		ImprovedFraction(); //default constructor
		ImprovedFraction(int, int); //basic constructor
		ImprovedFraction(const ImprovedFraction&); //copy constructor
		ImprovedFraction(ImprovedFraction&&) noexcept; //move constructor

		ImprovedFraction& operator =(const ImprovedFraction&); //copy assignment operator
		ImprovedFraction& operator =(ImprovedFraction&&) noexcept; //move assignment operator

		ImprovedFraction operator +(const ImprovedFraction&); //increment operator overloading
		ImprovedFraction& operator +=(const ImprovedFraction&); //short increment operator overloading
		ImprovedFraction operator -(const ImprovedFraction&); //increment operator overloading
		ImprovedFraction& operator -=(const ImprovedFraction&); //short increment operator overloading
		
		ImprovedFraction operator *(const ImprovedFraction&); //increment operator overloading
		ImprovedFraction& operator *=(const ImprovedFraction&); //short increment operator overloading
		ImprovedFraction operator /(const ImprovedFraction&); //increment operator overloading
		ImprovedFraction& operator /=(const ImprovedFraction&); //short increment operator overloading
		~ImprovedFraction() = default;
	};
}

#endif
