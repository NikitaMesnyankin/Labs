#include "improved_fraction.h"

int main() {
	mesnyankin::BasicFraction o1, o2;
	mesnyankin::ImprovedFraction o3, o4;
	char choice = '0';
	std::cout << "FRACTIONS CALCULATOR\n" << std::endl;
	do
	{
		std::cout << "Enter your choose" << std::endl;
		std::cout << "1: Set 2 basic fractions parameters" << std::endl
			<< "2: Sum 2 basic fractions" << std::endl
			<< "3: Subtract second fraction from first" << std::endl
			<< "4: View basic fractions parameters" << std::endl
			<< "5: Set 2 improved fractions parameters" << std::endl
			<< "6: Multiply improved fractions" << std::endl
			<< "7: Divide first improved fraction by second" << std::endl
			<< "8: View improved fractions parameters" << std::endl
			<< "9: Exit" << std::endl;
		std::cin >> std::setw(1) >> choice;
		switch (choice)
		{
			case '1':
			{
				int numerator, denominator;
				std::cout << "Enter numerator and denominator for first (obj1) fraction (int types by enter)" << std::endl;
				o1.setNumerator(mesnyankin::correctInput());
				o1.setDenominator(mesnyankin::correctInput());
				std::cout << "Enter numerator and denominator for second (obj2) fraction (int types by enter)" << std::endl;
				o2.setNumerator(mesnyankin::correctInput());
				o2.setDenominator(mesnyankin::correctInput());
				break;
			}
			case '2':
			{
				std::cout << "Result of sum: ";
				(o1 + o2).showFraction();
				break;
			}
			case '3':
			{
				std::cout << "Result of substr: ";
				(o1 - o2).showFraction();
				break;
			}
			case '4':
			{
				std::cout << "First fraction: ";
				o1.showFraction();
				std::cout << "Second fraction: ";
				o2.showFraction();
				break;
			}
			case '5':
			{
				int numerator, denominator;
				std::cout << "Enter numerator and denominator for first (obj3) fraction (int types by enter)" << std::endl;
				o3.setNumerator(mesnyankin::correctInput());
				o3.setDenominator(mesnyankin::correctInput());
				std::cout << "Enter numerator and denominator for second (obj4) fraction (int types by enter)" << std::endl;
				o4.setNumerator(mesnyankin::correctInput());
				o4.setDenominator(mesnyankin::correctInput());
				break;
			}
			case '6':
			{
				std::cout << "Result of multipl: ";
				(o3 * o4).showFraction();
				break;
			}
			case '7':
			{
				std::cout << "Result of divis: ";
				(o3 / o4).showFraction();
				break;
			}
			case '8':
			{
				std::cout << "First fraction: ";
				o3.showFraction();
				std::cout << "Second fraction: ";
				o4.showFraction();
				break;
			}
			case '9':
			{
				std::cout << "End commited..." << std::endl;
				break;
			}
			default:
			{
				std::cout << "Wrong input..." << std::endl;
				break;
			}
		}
	} while (choice != '9');
	system("pause");
	return 0;
}