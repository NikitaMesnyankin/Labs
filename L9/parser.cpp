#include "parser.h"

const int mesnyankin::parseSentence(char * sentence, int begin, int end)
{
	unsigned int counter = 0, i = 0, sCounter;

	while (i < end - begin + 1)
	{
		sCounter = 0;
		while ((i < end - begin + 1) && (strchr(" .,!?:;\n\r\t", sentence[i]) == 0))
		{
			sCounter++;
			i++;
		}
		if (sCounter > 0)
		{
			counter++;
		}
		sCounter = 0;
		i++;
	}
	return counter;
}

const int mesnyankin::parseText(char* tlines)
{
	unsigned int i = 0, k = 0, wMax = 0;
	char* tPointer = tlines;

	while (i < strlen(tlines))
	{
		while ((i < strlen(tlines)) && (ispunct(tlines[i]) != 0) && (isspace(tlines[i]) != 0))
		{
			i++;
		}
		int parseEnd = strpbrk(tPointer, ".!?") - tlines;
		k = parseSentence(tPointer, i, parseEnd);
		if (k > wMax)
		{
			wMax = k;
		}
		i = parseEnd;
		tPointer = strpbrk(tPointer, ".!?") + 1;
		i++;
	}
	return wMax;
}
