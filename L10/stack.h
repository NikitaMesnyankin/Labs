#ifndef STACK_H
#define STACK_H

#include <iostream>
#include <string.h>
#include <cctype>

namespace mesnyankin
{
	struct TStack
	{
		char charField[40];
		TStack* next;
	};

	TStack* create(TStack*);
	TStack* push(TStack*, char data[40]);
	char * pop(TStack**);
	void rebase(TStack**, TStack**);
	void output(TStack*&);
	TStack* freeStack(TStack*);
	TStack* solve(TStack**, TStack**, TStack*);

}

#endif
