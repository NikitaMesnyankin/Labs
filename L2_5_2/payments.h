#ifndef PAYMENTS_H
#define PAYMENTS_H

namespace mesnyankin
{
	class Payments
	{
	public:
		Payments() = default;
		Payments(int);
		Payments(const Payments&) = default;
		Payments(Payments&&) = default;

		Payments& operator=(const Payments&) = default;
		Payments& operator=(Payments&&) = default;

		void setSalary(int);
		int getSalary() const;
	private:
		int salary_;
	};
}

#endif
