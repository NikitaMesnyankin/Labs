#include "parser.h"

int main(int argc, char * argv[])
{
	char* buffer = NULL;
	size_t size = 0;
	FILE* inp;
	fopen_s(&inp, argv[1], "rb");
	fseek(inp, 0, SEEK_END);
	size = ftell(inp);
	rewind(inp);
	buffer = (char*)malloc((size + 2) * sizeof(*buffer));
	fread(buffer, size, 1, inp);
	buffer[size] = '!';
	buffer[size + 1] = '\0';
	std::cout << mesnyankin::parseText(buffer);
	system("pause");
	return 0;
}