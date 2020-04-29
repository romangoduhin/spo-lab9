#include "MyLibrary.h"

extern "C" string concatStringAlphabetically(string str1, string str2)
{
	if (str1 <= str2)
		return str1 + str2;
	else
		return str2 + str1;
}