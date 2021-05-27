#include "stack.h"

int main()
{
	mesnyankin::TStack* StackTop1 = nullptr, * StackTop2 = nullptr, *StackTop3 = nullptr;
	char ch;
	do {

		printf("\nZ - CreateStack1; X - CreateStack2; C - OutputStack1; V - OutputStack2; B - OutputStack3; A - Solve; S - FreeStack1; D - FreeStack2; F - FreeStack3; E - end.\nYour choose?");
		fflush(stdin);
		ch = toupper(getchar());
		getchar();
		switch (ch) {
		case 'Z':
		{
			if (StackTop1) {
				printf("Error: clean memory first!");
				break;
			}
			StackTop1 = mesnyankin::create(StackTop1);
			break;
		}
		case 'X':
		{
			if (StackTop2) {
				printf("Error: clean memory first!");
				break;
			}
			StackTop2 = mesnyankin::create(StackTop2);
			break;
		}
		case 'C':
		{
			printf("Stack 1:\n");
			mesnyankin::output(StackTop1);
			break;
		}
		case 'V':
		{
			printf("Stack 2:\n");
			mesnyankin::output(StackTop2);
			break;
		}
		case 'B':
		{
			printf("Stack 3:\n");
			mesnyankin::output(StackTop3);
			break;
		}
		case 'A':
		{
			StackTop3 = mesnyankin::solve(&StackTop1, &StackTop2, StackTop3);
			break;
		}
		case 'S':
		{
			StackTop1 = mesnyankin::freeStack(StackTop1);
			printf("Stack1 memory cleaned!...\n");
			break;
		}
		case 'D':
		{
			StackTop1 = mesnyankin::freeStack(StackTop2);
			printf("Stack2 memory cleaned!...\n");
			break;
		}
		case 'F':
		{
			StackTop1 = mesnyankin::freeStack(StackTop3);
			printf("Stack3 memory cleaned!...\n");
			break;
		}
		case 'E':
		{
			return 0;
		}
		default:
		{
			printf("No such command...\n");
			break;
		}
		}
	} while (ch != 'E');
	_CrtDumpMemoryLeaks;
	return 0;
}
