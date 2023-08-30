// lab3.2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include<stdio.h>
int CountZeros(int values[], int length)
{
    int i, count;

    count = 0;
    for (i = 0; i < length; i++) {
        if (values[i] == 0) {
            count++;
        }
    }

    return count;
}

int main()
{
    int length = 10;
    int values[10] = {0,3,0,0,3,1,0,0,-1,2};
    int v = CountZeros(values, length);
    printf("%d", v);




}

