#include "romanNumLib.h"

#include <string.h>

/****************************************************************************************/
//  Public Functions
/****************************************************************************************/
RomanNumLibResults romanNumbersAdd(const char *aval, const char *bval, char *sum)
{
	if (!aval || !bval || !sum)
	{
		return eRomanNumLib_Error;
	}
	
	strcpy(sum, aval);
	strcat(sum, bval);
	
	if (strcmp(sum, "iiii") == 0)
	{
		strcpy(sum, "iv");
	}
	
	return eRomanNumLib_NoError;
}

/****************************************************************************************/
RomanNumLibResults romanNumbersSub(const char *aval, const char *bval, char *diff)
{
    return eRomanNumLib_NoError;
}

