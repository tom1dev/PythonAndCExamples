// lab2.2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <stdio.h>


int TimesTwo(int a) {
	int t2 = a * 2;
	return t2;
}

int result;
void main() {
	result = TimesTwo(5);
	printf("Result = %d", result);
}

