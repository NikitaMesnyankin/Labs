#ifndef MILITARY_H
#define MILITARY_H

#include "driver.h"
#include "secguard.h"

namespace mesnyankin
{
	class Military : public Driver, public SecGuard
	{
	public:
		Military(const std::string&, const std::string&, const std::string&, int);
	};
}




#endif
