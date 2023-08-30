// lab3.3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <stdio.h>
double AverageNegativeValues(int values[], int length)
{
    int i, count;
    i = 0;
    double sum = 0;
    count = 0;

    while (i < length) {
        if (values[i] < 0) {
            sum = sum + values[i];
            count++;
        }
        i++;
    }

    return double(sum) / count;
}

int main()
{
    int values[5] = { -2.5,-6,-3,1,5 };
    int length = 5;
    double v = AverageNegativeValues(values, length);
    printf("%f", v);


}


