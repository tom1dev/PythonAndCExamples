// lab10.2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <stdio.h>
void Censor(char* phrase, int left, int right) {
    for (int i = left; i < right + 1; i++) {
        phrase[i] = 'X';
    }
}
int main()
{
    char censor[100] = "ENGGEN131";
    Censor(censor, 6, 8);
    printf("%s\n", censor);
}
