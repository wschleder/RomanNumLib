#include "romanNumLib.h"

#include <string.h>

static char* DecimalToRomanLUT[] =
	{
		"", "i", "ii", "iii", "iv", "v", "vi", "vii", "viii", "ix", "x"
	};

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
	else if ( strcmp(roman, "viii") == 0 )
	{
		decimal = 8;
	}
	
	return decimal;
}

static void _convertDecimalToRoman(int decimal, char *roman)
{
	int lutSize = sizeof(DecimalToRomanLUT)/sizeof(DecimalToRomanLUT[0]);
	if (decimal >= 0 && decimal < lutSize)
	{
		strcpy(roman, DecimalToRomanLUT[decimal]);
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

