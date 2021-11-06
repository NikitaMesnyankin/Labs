#ifndef DIRECTOR_H
#define DIRECTOR_H

#include "employee.h"

namespace mesnyankin
{
	class Director : public Employee
	{
	public:
		Director();
		Director(const std::string&, const std::string&, const std::string&, int, const eTVector&);
		Director(const sArray&, int, const eTVector&);
		Director(const eTuple&, const eTVector&);
		Director(const Director&);
		Director(Director&&) noexcept;

		Director& operator=(const Director&);
		Director& operator=(Director&&) noexcept;

		void add(const std::string&, const std::string&, const std::string&, int);
		void add(const sArray&, int);
		void add(const eTuple&);
		void add(const Employee&);

		void dismiss(const std::string&, const std::string&, const std::string&);
		void dismiss(const sArray&);
		void dismiss(const Employee&);

		eTVector getStaff() const;
		void setStaff(const eTVector&);
	private:
		eTVector staff_;
	};
}

#endif
