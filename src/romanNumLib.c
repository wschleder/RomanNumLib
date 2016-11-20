#include "romanNumLib.h"

#include <string.h>

/****************************************************************************************/

#define MAXIMUM_ROMAN_NUMBER_DECIMAL	3999
#define DECIMAL_CONVERT_ERROR_VALUE		-1

typedef enum
{
	eSubtract = -1,
	eAdd = 1
} Operation;

/****************************************************************************************/
#define NBR_OF_LUT_DECADE_ENTRIES 		4
#define NBR_OF_LUT_ENTRIES_PER_DECADE 	10

static int DecadeValues[NBR_OF_LUT_DECADE_ENTRIES] = { 1000, 100, 10, 1 };
static char* ConvertDecimalToRomanByDecadeLUT[NBR_OF_LUT_DECADE_ENTRIES][NBR_OF_LUT_ENTRIES_PER_DECADE] =
	{
		{ "", "m", "mm", "mmm",   "",  "",   "",    "",     "",   "" },
		{ "", "c", "cc", "ccc", "cd", "d", "dc", "dcc", "dccc", "cm" },
		{ "", "x", "xx", "xxx", "xl", "l", "lx", "lxx", "lxxx", "xc" },
		{ "", "i", "ii", "iii", "iv", "v", "vi", "vii", "viii", "ix" }
	};


/****************************************************************************************/
typedef struct
{
	char* romanSymbol;
	int   decimalValue;
	int   maxSymbolRepeat;
} RomanToIntMapEntry;

static const RomanToIntMapEntry CovertRomanSymbolToIntMap[] =
{
	{  "m",   1000,      3  },
	{  "cm",   900,      1  },
	{  "d",    500,      1  },
	{  "cd",   400,      1  },
	{  "c",    100,      3  },
	{  "xc",    90,      1  },
	{  "l",     50,      1  },
	{  "xl",    40,      1  },
	{  "x",     10,      3  },
	{  "ix",    9,       1  },
	{  "v",     5,       1  },
	{  "iv",    4,       1  },
	{  "i",     1,       3  },
};

/****************************************************************************************/
//  Private Functions
/****************************************************************************************/
static int _tryToMatchToSymbolToTableEntry(const char *inputStr, const RomanToIntMapEntry *mapEntry)
{
	int matchCount = 0;
	int stringIndex = 0;
	int symbolRepeatCount = 0;
	
	do
	{
		int symbolLen = strlen(mapEntry->romanSymbol);
		if ( strncmp(&inputStr[stringIndex], mapEntry->romanSymbol, symbolLen) != 0 )
		{
			break;
		}
		
		stringIndex += symbolLen;
		++matchCount;
	}
	while (++symbolRepeatCount < mapEntry->maxSymbolRepeat);
	
	return matchCount;
}

/****************************************************************************************/
static int _convertRomanToDecimal(const char *roman)
{
	int decimal = 0;
	int mapSize = sizeof(CovertRomanSymbolToIntMap) / sizeof(CovertRomanSymbolToIntMap[0]);
	int mapIndex;
	int romanIndex = 0;
	
	for (mapIndex = 0; mapIndex < mapSize; mapIndex++)
	{
		const RomanToIntMapEntry *mapEntry = &CovertRomanSymbolToIntMap[mapIndex];
		
		int matchCount = _tryToMatchToSymbolToTableEntry(&roman[romanIndex], mapEntry);
		decimal += matchCount * mapEntry->decimalValue;
		romanIndex += matchCount * strlen(mapEntry->romanSymbol);
	}
	
	if (romanIndex != strlen(roman))
	{
		decimal = DECIMAL_CONVERT_ERROR_VALUE;
	}
	
	return decimal;
}

/****************************************************************************************/
static int _convertDecimalToRoman(int decimal, char *roman)
{
	int decadeIndex;
	int ret = 0;
	
	*roman = '\0';
	
	if (decimal >= 0 && decimal <= MAXIMUM_ROMAN_NUMBER_DECIMAL)
	{
		for (decadeIndex = 0; decadeIndex < NBR_OF_LUT_DECADE_ENTRIES; ++decadeIndex)
		{
			int decadeValue = decimal/DecadeValues[decadeIndex];
			const char *digitStr = ConvertDecimalToRomanByDecadeLUT[decadeIndex][decadeValue];
			strcat(roman, digitStr);
			decimal -= decadeValue * DecadeValues[decadeIndex];
		}
		
		ret = 1;
	}
	return ret;
}

/****************************************************************************************/
static RomanNumLibResults _doAddSubtractOperation(const char *aval, const char *bval, char *resultVal, Operation op)
{
	int adec, bdec, resdec;
	int result;
	RomanNumLibResults ret = eRomanNumLib_NoError;
	
	if (!aval || !bval || !resultVal)
	{
		return eRomanNumLib_Error;
	}
	
	adec = _convertRomanToDecimal(aval);
	bdec = _convertRomanToDecimal(bval);
	
	if (adec == DECIMAL_CONVERT_ERROR_VALUE || bdec == DECIMAL_CONVERT_ERROR_VALUE)
	{
		ret = eRomanNumLib_Error;
	}
	else
	{
		resdec = adec + op * bdec;
		result = _convertDecimalToRoman(resdec, resultVal);
		if (!result)
		{
			ret = eRomanNumLib_Error;
		}
	}
	
	return ret;
}

/****************************************************************************************/
//  Public Functions
/****************************************************************************************/
RomanNumLibResults romanNumbersAdd(const char *aval, const char *bval, char *sum)
{
	return _doAddSubtractOperation(aval, bval, sum, eAdd);
}

/****************************************************************************************/
RomanNumLibResults romanNumbersSub(const char *aval, const char *bval, char *diff)
{
	return _doAddSubtractOperation(aval, bval, diff, eSubtract);
}

/****************************************************************************************/
/****************************************************************************************/
