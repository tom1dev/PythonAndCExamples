#include<stdio.h>
void Capitalise(char* phrase) {
    int i = 0;
    while (phrase[i] != '\0') {
        i++;
    }


    for (int j = 0; j < i; j++) {
        char temp[1000];
        temp[0] = phrase[0];
        temp[j] = phrase[j];
        if (phrase[0] > 96 && phrase[0] < 123) {
            phrase[0] = phrase[0] - 32;
        }
        if (phrase[j] > 96 && phrase[j] < 123) {
            if (temp[j - 1]==32){
                    phrase[j] = phrase[j] - 32;
                }
           

        }
    }

}

int main() {
    char phrase[100] = "zzzzz";
    Capitalise(phrase);
    printf("%s", phrase);
    char phrase1[100] = "god of nations at thy feet";
    Capitalise(phrase1);
    printf("%s", phrase1);

    char phrase3[100] = "The University of Auckland";
    Capitalise(phrase3);
    printf("%s", phrase3);
    char phrase4[100] = "p";
    Capitalise(phrase4);
    printf("%s", phrase4);

    int x = 6;
    int array[6] = { 1,2,3,4,5,6 };
    for (int i = 0; i < x; i++) {
        printf("%d", array[i]);
    }
}
