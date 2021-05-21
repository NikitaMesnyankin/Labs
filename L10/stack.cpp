#include "stack.h"

mesnyankin::TStack* mesnyankin::push(mesnyankin::TStack* stack, char data[40])
{
	mesnyankin::TStack * Elem = new mesnyankin::TStack;
	Elem->next = stack;
	strcpy_s(Elem->charField, 40, data);
	return Elem;
}

char * mesnyankin::pop(mesnyankin::TStack** pstack) {
	mesnyankin::TStack * Elem = *pstack;
	char * data = new char[40];
	strcpy_s(data, 40, Elem->charField);
	*pstack = Elem->next;
	delete Elem;
	return data;
}

mesnyankin::TStack* mesnyankin::create(mesnyankin::TStack* stack) {
	int kol = 0;
	char* n;
	char data[40];

	while (1) {
		printf("Enter data...\n");
		fgets(data, 40, stdin);
		fflush(stdin);
		n = strchr(data, '\n');
		
		if (n)
		{
			data[n - data] = '\0';
		}

		if (strncmp(data, "**", 2) == 0)
		{
			break;
		}
		stack = mesnyankin::push(stack, data);
		kol++;
	}
	printf("Created stack with %d elements...\n", kol);
	system("pause");
	return stack;
}

void mesnyankin::rebase(mesnyankin::TStack** PSt1, mesnyankin::TStack** PSt2) {
	mesnyankin::TStack* Elem, * StTop = *PSt1, * Dop = *PSt2;
	Elem = StTop;
	StTop = StTop->next;
	Elem->next = Dop;
	Dop = Elem;
	*PSt1 = StTop; *PSt2 = Dop;
	return;
}

void mesnyankin::output(mesnyankin::TStack*& stack) {
	mesnyankin::TStack* Dop = nullptr;

	if (!stack) printf("Empty stack...\n");
	while (stack) {
		char * inf;
		inf = mesnyankin::pop(&stack);
		printf("%s\n", inf);
		Dop = mesnyankin::push(Dop, inf);
		delete[] inf;
	}
	while (Dop) mesnyankin::rebase(&Dop, &stack);

	printf("Press any key to continue");
	system("pause");
	return;
}

mesnyankin::TStack* mesnyankin::freeStack(mesnyankin::TStack* stack) {
	while (stack) {
		char * tmp = mesnyankin::pop(&stack);
		delete[] tmp;
	}
	return stack;
}

mesnyankin::TStack* mesnyankin::solve(mesnyankin::TStack** PSt1, \
	mesnyankin::TStack** PSt2, mesnyankin::TStack* St3)
{
	mesnyankin::TStack * St1 = *PSt1, * St2 = *PSt2, * Dop = NULL;
	St3 = mesnyankin::freeStack(St3);

	while (St1) {
		if (toupper(St1->charField[0]) == toupper(St1->charField[strlen(St1->charField) - 1]))
		{
			St3 = mesnyankin::push(St3, St1->charField);
		}
		rebase(&St1, &Dop);
	}
	while (Dop) rebase(&Dop, &St1);

	while (St2) {
		if (toupper(St2->charField[0]) == toupper(St2->charField[strlen(St2->charField) - 1]))
		{
			St3 = mesnyankin::push(St3, St2->charField);
		}
		rebase(&St2, &Dop);
	}
	while (Dop) rebase(&Dop, &St2);
	*PSt1 = St1;
	*PSt2 = St2;
	return St3;
}

