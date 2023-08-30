

void PrintAverageRainfall(int values[])
{
    int length1 = *(&values + 1) - values;
    double sum = 0;
    int amountd = 0;
    for (int i = 0; i < length1; i++) {
        if (values[i] >= 0) {
            sum += values[i];
            amountd++;
        }
        if (values[i] == -999) {
            i = length1 - 1;
        }
    }

    if (amountd == 0) {
        printf("no rain");
    }
    if (amountd > 0) {
        double average = sum / amountd;
        printf("%.2f", average);
    }

}