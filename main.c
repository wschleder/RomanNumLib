#include <stdio.h>
#include <string.h>
#include "src/romanNumLib.h"

static void _usage(const char *name);

int main(int argc, char *argv[])
{
	int bDoUsage = 1;
	
	if (argc == 4 && strlen(argv[2]) == 1)
	{
		char buf[32];
		RomanNumLibResults result;

		if (*argv[2] == '+')
		{
			result = romanNumbersAdd(argv[1], argv[3], buf);
		}
		else if (*argv[2] == '-')
		{
			result = romanNumbersSub(argv[1], argv[3], buf);
		}
		
		if (result == eRomanNumLib_NoError)
		{
			bDoUsage = 0;
			printf("%s %s %s = %s\n\n", argv[1], argv[2], argv[3], buf);
		}
		else
		{
			printf("Invalid inputs!\n\n");
		}
	}
	
	if (bDoUsage)
	{
		_usage(argv[0]);
	}
	
    return 0;
}

static void _usage(const char *name)
{
	printf("\nUsage: %s  a_str +|- b_str \n", name);
	printf("       Invokes the Roman Number Utility library\n");
	printf("       Performs addition or subtraction of the roman numeral strings \"a_str\" and \"b_str\"\n");
	printf("       Lower case is required.\n\n");
}


