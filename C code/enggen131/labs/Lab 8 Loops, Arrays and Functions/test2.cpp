#include <stdio.h>


void PrintSummary(int values[]);
int main()
{
    int values[] = {2,2,3};
    PrintSummary(values);
}

void PrintSummary(int values[])
{
    int length1 = *(&values + 1) - values;
    printf("%d", length1);
    int value = 0;
    for (int i = 0; i < length1; i++) {
        if (values[i] != 0) {
            if (values[i] < 0) {
                value += -1;
            }
            if (values[i] > 0) {
                value += 1;
            }
            printf("%d \n", i);

        }
        if (values[i] == 0) {
            i = length1;
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

void PrintAverageRainfall(void) {

}


