#ifndef INITIALS_H
#define INITIALS_H

#include <string>

namespace mesnyankin
{
	class Initials
	{
	public:
		Initials();
		Initials(const std::string&, const std::string&, const std::string&);
		Initials(const Initials&);
		Initials(Initials&&);

		Initials& operator=(const Initials&);
		Initials& operator=(Initials&&);

		void setData(const std::string&, const std::string&, const std::string&);
		std::string getSurname() const;
		std::string getName() const;
		std::string getPatronymic() const;

	private:
		std::string surname;
		std::string name;
		std::string patronymic;
	};
}

#endif
