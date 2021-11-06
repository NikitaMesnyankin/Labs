#ifndef SECGUARD_H
#define SECGUARD_H

#include "employee.h"

namespace mesnyankin
{
	class SecGuard : public Employee
	{
	public:
		SecGuard();
		SecGuard(const std::string&, const std::string&, const std::string&, int, const std::string&);
		SecGuard(const sArray&, int, const std::string&);
		SecGuard(const eTuple&, const std::string&);
		SecGuard(const SecGuard&);
		SecGuard(SecGuard&&) noexcept;

		SecGuard& operator=(const SecGuard&);
		SecGuard& operator=(SecGuard&&) noexcept;

		std::string getItem() const;
		void setItem(const std::string&);
		void addItem(const std::string&);
		void clearItems();
	private:
		std::string defence_item_;
	};

	typedef std::vector<mesnyankin::SecGuard> scgrdVec;
}

#endif
