#ifndef SECRETARY_H
#define SECRETARY_H

#include "driver.h"
#include "director.h"
#include "secguard.h"

namespace mesnyankin
{
    class Secretary : public Employee
    {
	public:
		Secretary();
		Secretary(const std::string&, const std::string&, const std::string&, int);
		Secretary(const sArray&, int);
		Secretary(const eTuple&);

		Secretary(const Secretary&);
		Secretary(Secretary&&) noexcept;

		Secretary& operator=(const Secretary&);
		Secretary& operator=(Secretary&&) noexcept;

		void showDirectorInfo(const mesnyankin::Director&) const;
		void showGuardsInfo(const mesnyankin::scgrdVec&);
		void showDriversInfo(const mesnyankin::drvrVec&);
    };
}

#endif
