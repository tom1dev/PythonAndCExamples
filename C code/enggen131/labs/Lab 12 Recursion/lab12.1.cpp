// lab12.1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
void PrintReverse(int number) {
    if (number < 10) {
        printf("%d", number);
    }
    else {
        printf("%d",number % 10);
        PrintReverse(number / 10);
    }
}
void ConvertToBinary(int number) {
    if (number==1) {
        printf("%d",number%2);
    }
    else {
        ConvertToBinary(number / 2);
            printf("%d", number % 2);
    }
}
int Choose(int n, int m) {
    int a;
    if ( m == 0) {
        return 1;
    }
    if (m == n) {
        return 1;
    }
    else {
        int a = Choose(n - 1, m)+Choose(n - 1, m - 1);
        return a;
       
    }
}
int main()
{
    int a = 157;
    printf("Result = %d", Choose(6, 2));
    int num = 2;
    printf("They said \"the value is %d\". ", num);
}


