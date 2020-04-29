#pragma once

#ifdef MYLIBRARY_EXPORTS
#define MYLIBRARYAPI __declspec(dllexport)
#else
#define MYLIBRARYAPI __declspec(dllimport)
#endif

#include <String>

using namespace std;

extern "C" MYLIBRARYAPI string concatStringAlphabetically(string str1, string str2);
