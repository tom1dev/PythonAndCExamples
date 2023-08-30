// lab1.3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
int main()
{
    float x;
    float y;
    float z;
    printf("Enter the first value in the sequence: ");
    scanf("%f", &x);
    printf("Enter the difference between consecutive values: ");
    scanf("%f", &y);
    printf("Enter the number of values in the sequence:  ");
    scanf("%f", &z);

    float w = z * x + (z / 2) * (y * z - y);
    printf("%.0f", w);

    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
