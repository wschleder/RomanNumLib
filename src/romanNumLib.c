#include "romanNumLib.h"

#include <string.h>

static char* DecimalToRomanLUT[] =
	{
		"",  "i", "ii", "iii", "iv", "v", "vi", "vii", "viii", "ix",
		"x", "xi", "xii", "xiii", "xiv", "xv", "xvi", "xvii", "xiii", "xix"
	};

/****************************************************************************************/
//  Private Functions
/****************************************************************************************/

static int _convertRomanToDecimal(const char *roman)
{
	int decimal = 0;
	int lutSize = sizeof(DecimalToRomanLUT)/sizeof(DecimalToRomanLUT[0]);
	int index;
	
	for (index = 0; index < lutSize; index++)
	{
		if ( strcmp(roman, DecimalToRomanLUT[index]) ==  0 )
		{
			decimal = index;
			break;
		}
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

