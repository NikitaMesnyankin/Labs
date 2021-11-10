#ifndef INITIALS_H
#define INITIALS_H

#include <string>

namespace mesnyankin
{
	class Initials
	{
	public:
		Initials() = default;
		Initials(const std::string&, const std::string&, const std::string&);
		Initials(const Initials&) = default;
		Initials(Initials&&) = default;

		Initials& operator=(const Initials&) = default;
		Initials& operator=(Initials&&) = default;

		void setInitials(const std::string&, const std::string&, const std::string&);
		std::string getSurname() const;
		std::string getName() const;
		std::string getPatronymic() const;

	private:
		std::string surname_;
		std::string name_;
		std::string patronymic_;
	};
}

#endif
