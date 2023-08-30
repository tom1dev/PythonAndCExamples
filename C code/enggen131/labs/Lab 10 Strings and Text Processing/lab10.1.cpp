// lab10.1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <stdio.h>
int IsPalindrome(char* word) {
    int i = 0;
    while (word[i] != '\0') {
        i++;
    }
    for (int w = 0; w < i; w++) {
        printf("%d,%d\n", w, i);
        if (word[w] != word[i - 1 - w] && w < (i / 2 + i % 2)) {
            int b = 0;
            return b;
        }

    }
    return 1;

}


int main()
{

    char word[100] = "shirts";
    printf("%d", IsPalindrome(word));
}

