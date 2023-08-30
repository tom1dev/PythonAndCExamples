// lab10.3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <stdio.h>

int IsSuffix(char* suffix, char* word) {
    int i = 0;
    while (suffix[i] != '\0') {
        i++;
    }
    int j = 0;
    while (word[j] != '\0') {
        j++;
    }

    for (int k = 0; k <i; k++) {
        printf("%d %d %d %c %c\n",j,k,j+k-i, word[j+k-i], suffix[k]);
        if (word[j+k-i] != suffix[k]) {
            return 0;
        }
    }
    return 1;
}

int main()
{
    char apple[6] = "apple";
    char ear[4] = "ear";
    char shear[6] = "shear";
    printf("Result = %d\n", IsSuffix(apple, apple));
    printf("Result = %d\n", IsSuffix(ear, shear));
}


