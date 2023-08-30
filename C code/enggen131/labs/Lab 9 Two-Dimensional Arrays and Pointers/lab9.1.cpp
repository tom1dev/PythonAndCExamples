// lab9.1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include<stdio.h>

int LargestValue(int values[], int length) {
    int i, max;

    max = 0;
    for (i = 1; i < length; i++) {

        
        if (values[i] > max) {
            max = i;
            
        }
        
    }


    return values[max];
}
int main(void) {


    int values[7] = { 1, 3, 2, 4, 4, 3, 10};
    int length = 7;

    int v = LargestValue(values, length);
    printf("%d\n", v);
}


