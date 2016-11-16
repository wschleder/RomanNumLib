#include "romanNumLib.h"

#include <string.h>

#define LOCAL_BUFFER_SIZE		64

/****************************************************************************************/
//  Private Functions
/****************************************************************************************/
int _compareStringsAndReplace(char *inputString,
							  char *compareString,
							  char *replaceString,
							  char *outputString)
{
	int retval = 0;
	
	int compareLen = strlen(compareString);
	int result = strncmp(inputString, compareString, compareLen);
	if (result == 0)
	{
		strcpy(outputString, replaceString);
		strcat(outputString, &(inputString[compareLen]));
		retval = 1;
	}
	else
	{
		strcpy(outputString, inputString);
	}
	
	return retval;
}

/****************************************************************************************/
//  Public Functions
/****************************************************************************************/
RomanNumLibResults romanNumbersAdd(const char *aval, const char *bval, char *sum)
{
	char buf[LOCAL_BUFFER_SIZE];
	int compareResult;
	
	if (!aval || !bval || !sum)
	{
		return eRomanNumLib_Error;
	}
	
	strcpy(buf, aval);
	strcat(buf, bval);
	
	compareResult = _compareStringsAndReplace(buf, "iiiii", "v", sum);
	if (!compareResult) _compareStringsAndReplace(buf, "iiii", "iv", sum);
	
	return eRomanNumLib_NoError;
}

/****************************************************************************************/
RomanNumLibResults romanNumbersSub(const char *aval, const char *bval, char *diff)
{
    return eRomanNumLib_NoError;
}

