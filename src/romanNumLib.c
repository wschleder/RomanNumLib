#include "romanNumLib.h"

#include <string.h>

/****************************************************************************************/
#define NBR_OF_LUT_DECADE_ENTRIES 		2
#define NBR_OF_LUT_ENTRIES_PER_DECADE 	10

static char* ConvertDecimalToRomanByDecadeLUT[NBR_OF_LUT_DECADE_ENTRIES][NBR_OF_LUT_ENTRIES_PER_DECADE] =
	{
		{ "", "i", "ii", "iii", "iv", "v", "vi", "vii", "viii", "ix" },
		{ "", "x", "xx", "xxx", "xl", "l", "lx", "lxx", "lxxx", "xc" }
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
	
	return decimal;
}

/****************************************************************************************/
static void _convertDecimalToRoman(int decimal, char *roman)
{
	int tens = decimal/10;
	int ones = decimal - tens*10;
	
	if (decimal >= 0 && tens < 10)
	{
		const char *digitStr;
		digitStr = ConvertDecimalToRomanByDecadeLUT[1][tens];
		strcpy(roman, digitStr);
		digitStr = ConvertDecimalToRomanByDecadeLUT[0][ones];
		strcat(roman, digitStr);
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

