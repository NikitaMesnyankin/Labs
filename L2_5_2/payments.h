#ifndef PAYMENTS_H
#define PAYMENTS_H

namespace mesnyankin
{
	class Payments
	{
	public:
		Payments();
		Payments(int);
		Payments(const Payments&);
		Payments(Payments&&);

		Payments& operator=(const Payments&);
		Payments& operator=(Payments&&);

		void setSalary(int);
		int getSalary() const;
	private:
		int salary_;
	};
}

#endif
