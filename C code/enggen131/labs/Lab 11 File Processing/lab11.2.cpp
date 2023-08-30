
// lab11.2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <stdio.h>
#include <stdlib.h>

int OneLetterDifference(char* word1, char* word2) {
	int wordL = 5;
	int worddif = 0;
	for (int i = 0; i < wordL; i++) {
		if (word1[i] != word2[i]) {
			worddif++;
		}
	}
	if (worddif == 1) {
		return true;
	}
	return false;
}

int main()
{

	char word1[5] = "able";
	char word2[5] = "able";

	if (OneLetterDifference(word1, word2)) {
		printf("The words differ by just one character");
	}
	else {
		printf("The words do not differ by just one character");
	}
}