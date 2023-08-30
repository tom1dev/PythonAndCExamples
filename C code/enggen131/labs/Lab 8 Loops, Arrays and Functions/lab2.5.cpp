
#include <stdio.h>


void PrintSummary(int values[]);
int main()
{
    int values[] = { 1,2,3,4 };
    PrintSummary(values);
}

void PrintSummary(int values[])
{
    int length1 = 2;
    int value = 0;
    printf("%d", length1);
    for (int i = 0; i < length1; i++) {
        while (values[i] != 0) {
            if (values[i] < 0) {
                value -= 1;
            }
            if (values[i] > 0) {
                value += 1;
            }
        }
    }
    if (value > 0) {
        printf("Positive");
    }
    if (value < 0) {
        printf("Negitive");
    }
    if (value == 0) {
        printf("Equal");
    }



}
