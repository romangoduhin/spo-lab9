#include "MyLibrary.h"
#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include <Windows.h>
int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	string str1;

	cin >> str1;

	string str2;

	cin >> str2;

	string str = concatStringAlphabetically(str1, str2);

	cout << str << endl;
	system("pause");
}
