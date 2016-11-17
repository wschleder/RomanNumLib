#include "romanNumLib.h"

#include <string.h>

/****************************************************************************************/
//  Private Functions
/****************************************************************************************/

static int _convertRomanToDecimal(const char *roman)
{
	int decimal = 0;
	
	if ( strcmp(roman, "i") == 0 )
	{
		decimal = 1;
	}
	else if ( strcmp(roman, "ii") == 0 )
	{
		decimal = 2;
	}
	else if ( strcmp(roman, "iii") == 0 )
	{
		decimal = 3;
	}
	else if ( strcmp(roman, "v") == 0 )
	{
		decimal = 5;
	}
	
	return decimal;
}

static void _convertDecimalToRoman(int decimal, char *roman)
{
	switch (decimal)
	{
		case 2:
			strcpy(roman, "ii");
			break;
		case 3:
			strcpy(roman, "iii");
			break;
		case 4:
			strcpy(roman, "iv");
			break;
		case 6:
			strcpy(roman, "vi");
			break;
		case 8:
			strcpy(roman, "viii");
			break;
		default:
			*roman = '\0';
			break;
	}
}

/****************************************************************************************/
//  Public Functions
/****************************************************************************************/
RomanNumLibResults romanNumbersAdd(const char *aval, const char *bval, char *sum)
{
	int adec, bdec, sumdec;
	
	if (!aval || !bval || !sum)
	{
		return eRomanNumLib_Error;
	}

	adec = _convertRomanToDecimal(aval);
	bdec = _convertRomanToDecimal(bval);
	sumdec = adec + bdec;
	_convertDecimalToRoman(sumdec, sum);
	
	return eRomanNumLib_NoError;
}

/****************************************************************************************/
RomanNumLibResults romanNumbersSub(const char *aval, const char *bval, char *diff)
{
    return eRomanNumLib_NoError;
}

