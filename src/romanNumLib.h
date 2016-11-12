#ifndef ROMANNUMLIB_H
#define ROMANNUMLIB_H

typedef enum
{
	eRomanNumLib_NoError = 0,
	eRomanNumLib_Error  = -1
	
} RomanNumLibResults;

RomanNumLibResults romanNumbersAdd(const char *aval, const char *bval, char *sum);
RomanNumLibResults romanNumbersSub(const char *aval, const char *bval, char *diff);

#endif
