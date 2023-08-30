// lab3.4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <stdio.h>


int LastIndexOf(int search, int values[], int numValues)
{   
    int position = -1;
    for (int i = 0; i < numValues; i++) {
        if (values[i] == search) {
            position = i;
        }
    }
    return position;
}
int main()
{
    int values[5] = { 1,2,0,2,1 };
    int pos = LastIndexOf(2, values, 5);
    printf("%d", pos);

}
