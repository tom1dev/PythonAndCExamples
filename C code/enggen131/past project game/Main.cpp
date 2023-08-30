// task3.cpp : This file contains the 'main' function. Program execution begins and ends there.
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
void InitialiseStory(char* paragraph) {
    //max of sixty charaters per line, story must be below 1999 char and above 100 char
    char temppara[] = "OH NOOOOOO!\nYou have been trapped in a cave by an evil witch!\nFind the treasure and escape the cave\nBUT BEWARE of the bottomless pits\n ";
    int i = 0;
    while (temppara[i] != '\0') {
        paragraph[i] = temppara[i];
        i++;
    }
    paragraph[i] = '\0';

}

#define CAVE_SIZE 10
void PrintCave(int cave[CAVE_SIZE][CAVE_SIZE]) {
    //prints out corrent possitions in the cave
    int w, i;
    for (i = 0; i < CAVE_SIZE; i++) {
        for (w = 0; w < CAVE_SIZE; w++) {
            if (cave[i][w] == 0) {
                printf(" ");
            }
            if (cave[i][w] == 1) {
                printf("#");
            }
            if (cave[i][w] == char('E')) {
                printf(" ");
            }
            if (cave[i][w] == 'X') {
                printf("X");
            }
            if (cave[i][w] == '*') {
                printf("*");
            }
            if (cave[i][w] == 'O') {
                printf("O");
            }
            if (cave[i][w] == char('+')) {
                printf("+");
            }
        }
 
        if (w == CAVE_SIZE) {
            if (cave[i][w] == 0 || cave[i][w] == 1|| cave[i][w] == char('E') || cave[i][w] == char('O')) {
                printf("\n");
            }
        }
    }
    printf("\n");
}
void InitialiseCave(int cave[CAVE_SIZE][CAVE_SIZE], char* layout) {
    //initalises the cave
    int layoutpos = 0;
    for (int i = 0; i < CAVE_SIZE; i++) {

        for (int w = 0; w < CAVE_SIZE; w++){
            if (layout[layoutpos] == '1') {
                cave[i][w] = 1;
            };
            if (layout[layoutpos] == '0') {
                cave[i][w] = 0;
            };
            if (layout[layoutpos] == 'E') {
                cave[i][w] = char('E');
            };
            layoutpos++;
        }
    }

}

int IsBorderComplete(int cave[CAVE_SIZE][CAVE_SIZE]) {
    //checks if the border is complete
    int i, w;
    for (i = 0; i < CAVE_SIZE; i++) {
        for (w = 0; w < CAVE_SIZE; w++) {
            if (i==0||i==CAVE_SIZE-1 || w == 0 || w == CAVE_SIZE-1){
                //if empty space value is seen on edges return false 
                if (cave[i][w] ==0) {
                    return false;
                    
                }

            }

            
        }
        
    }
    return true;
}
int IsExitUnique(int cave[CAVE_SIZE][CAVE_SIZE]) {
    //make sure there is only one exit
    int exitcount = 0;
    int i, w;
    for (i = 0; i < CAVE_SIZE; i++) {
        for (w = 0; w < CAVE_SIZE; w++) {
            if (cave[i][w] == char('E')) {
                exitcount++;
            }

        }
    }
    if (exitcount ==1) {
        return true;
    }
    return false;
}

int IsExitAccessible(int cave[CAVE_SIZE][CAVE_SIZE]) {
    //makes sure that the caves exit is accessable
    int founde = 0;
    for (int i = 0; i < CAVE_SIZE; i++) {
        for (int w = 0; w < CAVE_SIZE; w++) {
            //if exit value is seen not on the boarder return false
            if (i != 0) {
                if (i != CAVE_SIZE - 1) {
                    if (w != 0) {
                        if (w != CAVE_SIZE - 1) {
                            if (cave[i][w] == 'E') {
                                return false;
                            }
                        }
                    }
                }
            }
            if (i == 0|| i == CAVE_SIZE - 1||w == 0 || w == CAVE_SIZE - 1) {
                if (cave[i][w] == 'E') {
                    founde++;
                }
            }
            //if exit values is seen on the boarder but not on the corners and hasn't come up before return true
            if (cave[i][w] == 'E') {
                if (cave[0][CAVE_SIZE - 1] == 'E' || cave[0][0] == 'E' || cave[CAVE_SIZE - 1][0] == 'E' || cave[CAVE_SIZE - 1][CAVE_SIZE - 1] == 'E') {
                    return false;

                }
            }

        }
    }
    if (founde == 0) {
        return false;
    }
    return true;
}

void AddItem(int cave[CAVE_SIZE][CAVE_SIZE], int row, int col, char* element) {
    int playercount = 0;
    char pcheck[] = "player";
    char hcheck[] = "hole";
    char tcheck[] = "treasure";
    char bcheck[] = "boulder";
    int lp = 6;
    int lh = 4;
    int lt = 8;
    int lb = 7;
    
    int le = 0;
    while (element[le] != '\0') {
        le++;
    }

    int pgate = 1;
    int hgate = 1;
    int tgate = 1;
    int bgate = 1;
    for (int w = 0; w < le; w++) {
        if (element[w] != pcheck[w] && w<=lp) {
            pgate = 0;
        }
        if (element[w] != hcheck[w] && w <= lh) {
            hgate = 0;
        }
        if (element[w] != tcheck[w] && w <= lt) {
            tgate = 0;
        }
        if (element[w] != bcheck[w] && w <= lb) {
            bgate = 0;
        }
    }
    for (int i = 0; i < CAVE_SIZE; i++) {
        for (int z = 0; z < CAVE_SIZE; z++) {
            if (cave[i][z] == 'X'){
                playercount++;
            }
        }
    }
    
    
    if (row < CAVE_SIZE && col < CAVE_SIZE && row > -1 && col > -1) {
        if (cave[row][col] == 0) {
            if (pgate == 1) {

                if (playercount == 0) {
                    cave[row][col] = 'X';
                } 
            }
            if (hgate == 1) {
                cave[row][col] = '*';

            }

            if (tgate == 1) {
                cave[row][col] = '+';

            }
            if (bgate == 1) {
                cave[row][col] = 'O';

            }
        }



    }

}
void RotateCave(int cave[CAVE_SIZE][CAVE_SIZE]) {
    int temp[CAVE_SIZE][CAVE_SIZE];
    //temporary storage array appeaded cave values
    for (int i = 0; i < CAVE_SIZE; i++) {
        for (int j = 0; j < CAVE_SIZE; j++) {
            temp[i][j] = cave[i][j];
        }
    }

    if (CAVE_SIZE % 2 == 0) {
        //every value can only have 4 positions, one in each quater of the array therefore relationships in these positions used to switch them.
        for (int w = 0; w < CAVE_SIZE / 2; w++) {
            for (int z = 0; z < CAVE_SIZE / 2; z++) {

                //q4 -> q1
                cave[w][z] = temp[CAVE_SIZE - 1 - z][w];
                //q1 ->q2
                cave[z][CAVE_SIZE - 1 - w] = temp[w][z];
                //q3 -> q4
                cave[CAVE_SIZE - 1 - z][w] = temp[CAVE_SIZE - 1 - w][CAVE_SIZE - 1 - z];
                //q2 ->q3
                cave[CAVE_SIZE - 1 - w][CAVE_SIZE - 1 - z] = temp[z][CAVE_SIZE - 1 - w];

            }
        }
    }

    //if the length of the cave is odd loop to find positions one more time as middle row/colum is in nither q1 or q2 but between them
    if (CAVE_SIZE % 2 != 0) {
        for (int w = 0; w < CAVE_SIZE / 2+1; w++) {
            for (int z = 0; z < CAVE_SIZE / 2+1; z++) {

                
                    //q4 -> q1
                    cave[w][z] = temp[CAVE_SIZE - 1 - z][w];
                    //q1 ->q2
                    cave[z][CAVE_SIZE - 1 - w] = temp[w][z];
                    //q3 -> q4
                    cave[CAVE_SIZE - 1 - z][w] = temp[CAVE_SIZE - 1 - w][CAVE_SIZE - 1 - z];
                    //q2 ->q3
                    cave[CAVE_SIZE - 1 - w][CAVE_SIZE - 1 - z] = temp[z][CAVE_SIZE - 1 - w];
                


            }
        }

    }
    

}
int MakeMove(int cave[CAVE_SIZE][CAVE_SIZE], char move) {
    int rowp,colp;
    int amountroll = 0;
    for (int i = 0; i < CAVE_SIZE; i++) {
        for (int z = 0; z < CAVE_SIZE; z++) {
            if (cave[i][z] == 'X') {
                rowp = i;
                colp = z;
            }
        }
    }
    char tempitem;

 
    if (move == 'w') {
        
        if (cave[rowp - 1][colp] == 0 || cave[rowp - 1][colp] == '+') {
            tempitem = cave[rowp - 1][colp];
            cave[rowp - 1][colp] = cave[rowp][colp];
            cave[rowp][colp] = 0;
            return 0;
        }
        if (cave[rowp - 1][colp] == 1) {
            return 0;
        }
        if (cave[rowp - 1][colp] == 'E') {
            cave[rowp - 1][colp] = cave[rowp][colp];
            cave[rowp][colp] = 0;
            return 2;
        }
        if (cave[rowp - 1][colp] == '*') {
            cave[rowp][colp] = 0;
            return 1;
        }
        if (cave[rowp - 1][colp] == 'O') {
            amountroll = rowp - 1;
            for (int j = 0; j < amountroll; j++) {
                if (cave[rowp - 2-j][colp] == 1|| cave[rowp - 2 - j][colp] == '+'|| cave[rowp - 2 - j][colp] == 'O' || cave[rowp - 2 - j][colp] == 'E') {
                    j = amountroll;
                }
                if (cave[rowp - 2 - j][colp] == 0) {
                    tempitem = cave[rowp - 2-j][colp];
                    cave[rowp - 2-j][colp] = cave[rowp-1-j][colp];
                    cave[rowp-1-j][colp] = tempitem;
                }
                if (cave[rowp - 2 - j][colp] == '*') {
                    cave[rowp - 2 - j][colp] = 0;
                    cave[rowp - 1 - j][colp] = 0;
                }
            }   
        }   
    }
    if (move == 'a') {
        if (cave[rowp][colp-1] == 0 || cave[rowp][colp-1] == '+') {
            tempitem = cave[rowp][colp-1];
            cave[rowp][colp-1] = cave[rowp][colp];
            cave[rowp][colp] = 0;
            return 0;
        }
        if (cave[rowp][colp-1] == 1) {
            return 0;
        }
        if (cave[rowp][colp-1] == 'E') {
            cave[rowp][colp-1] = cave[rowp][colp];
            cave[rowp][colp] = 0;
            return 2;
        }
        if (cave[rowp][colp-1] == '*') {
            cave[rowp][colp] = 0;
            return 1;
        }
        if (cave[rowp][colp-1] == 'O') {
            amountroll = colp-1;
            for (int j = 0; j < amountroll; j++) {
                if (cave[rowp][colp - 2 - j] == 1 || cave[rowp][colp - 2 - j] == '+' || cave[rowp][colp - 2 - j] == 'O' || cave[rowp][colp - 2 - j] == 'E') {
                    j = amountroll;
                }
                if (cave[rowp][colp - 2 - j] == 0) {
                    tempitem = cave[rowp][colp - 2 - j];
                    cave[rowp][colp - 2 - j] = cave[rowp][colp - 1 - j];
                    cave[rowp][colp - 1 - j] = tempitem;
                }
                if (cave[rowp][colp - 2 - j] == '*') {
                    cave[rowp][colp - 2 - j] = 0;
                    cave[rowp][colp - 1 - j] = 0;
                }
            }
        }
    }
    if (move == 's') {
        if (cave[rowp + 1][colp] == 0 || cave[rowp + 1][colp] == '+') {
            tempitem = cave[rowp + 1][colp];
            cave[rowp + 1][colp] = cave[rowp][colp];
            cave[rowp][colp] = 0;
            return 0;
        }
        if (cave[rowp + 1][colp] == 1) {
            return 0;
        }
        if (cave[rowp + 1][colp] == 'E') {
            cave[rowp + 1][colp] = cave[rowp][colp];
            cave[rowp][colp] = 0;
            return 2;
        }
        if (cave[rowp + 1][colp] == '*') {
            cave[rowp][colp] = 0;
            return 1;
        }
        if (cave[rowp + 1][colp] == 'O') {
            amountroll = CAVE_SIZE;
            for (int j = 0; j < amountroll; j++) {
                if (cave[rowp + 2 + j][colp] == 1 || cave[rowp + 2 + j][colp] == '+' || cave[rowp + 2 + j][colp] == 'O' || cave[rowp +2+ j][colp] == 'E') {
                    j = amountroll;
                }
                if (cave[rowp + 2 + j][colp] == 0) {
                    tempitem = cave[rowp + 2 + j][colp];
                    cave[rowp + 2 + j][colp] = cave[rowp + 1 + j][colp];
                    cave[rowp + 1 + j][colp] = tempitem;
                }
                if (cave[rowp + 2 + j][colp] == '*') {
                    cave[rowp + 2 + j][colp] = 0;
                    cave[rowp + 1 + j][colp] = 0;
                }
            }
        }
    } 
    if (move == 'd') {
        if (cave[rowp][colp + 1] == 0 || cave[rowp][colp+1] == '+') {
            tempitem = cave[rowp][colp + 1];
            cave[rowp][colp + 1] = cave[rowp][colp];
            cave[rowp][colp] = 0;
            return 0;
        }
        if (cave[rowp][colp + 1] == 1) {
            return 0;
        }
        if (cave[rowp][colp + 1] == 'E') {
            cave[rowp][colp + 1] = cave[rowp][colp];
            cave[rowp][colp] = 0;
            return 2;
        }
        if (cave[rowp][colp + 1] == '*') {
            cave[rowp][colp] = 0;
            return 1;
        }
        if (cave[rowp][colp + 1] == 'O') {
            amountroll = CAVE_SIZE;
            
            for (int j = 0; j < amountroll; j++) {
                if (cave[rowp][colp + 2 + j] == 1|| cave[rowp][colp + 2 + j] == '+' || cave[rowp ][colp + 2 + j] == 'O' || cave[rowp][colp + 2 + j] == 'E') {
                    j = amountroll;
                }
                if (cave[rowp][colp + 2 + j] == 0) {
                    tempitem = cave[rowp][colp+2+j];
                    cave[rowp][colp + 2 + j] = cave[rowp][colp + 1 + j];
                    cave[rowp][colp + 1 + j] = tempitem;
                }
                if (cave[rowp][colp + 2 + j] == '*') {
                    cave[rowp][colp + 2 + j] = 0;
                    cave[rowp][colp + 1 + j] = 0;
                }
            }
        }
    }
    return 0;
}


/* GetMove() returns the entered character. Invalid characters ignored */
char GetMove(void)
{
    char move;
    printf("\nEnter move: ");
    scanf("%c", &move);
    // Ignore any characters that are invalid
    while ((move != 'w') && (move != 'a') && (move != 's') && (move != 'd')) {
        scanf("%c", &move);
    }
    return move;
}

/* The Boulder Break simulation */
int main(void)
{
    char story[2000];
    int gameOver = 0;
    char a[] = "boulder";
    char b[] = "hole";
    char c[] = "treasure";
    char d[] = "player";


    char layout[200] = "1111111E11111000000110000000011000011111100000111110000001111000000001111000000110000000011111111111";

    int cave[CAVE_SIZE][CAVE_SIZE];
    InitialiseCave(cave, layout);
    AddItem(cave, 7, 8, d);
    AddItem(cave, 3, 1, b);
    AddItem(cave, 3, 2, b);
    AddItem(cave, 3, 3, b);
    AddItem(cave, 3, 4, b);
    AddItem(cave, 7, 7, a);
    AddItem(cave, 7, 5, a);
    AddItem(cave, 5, 5, a);
    AddItem(cave, 2, 2, c);
    AddItem(cave, 1, 6, c);



    printf("ENGGEN131 - C Project 2022\n");
    printf("                          ... presents ...\n");
    printf("______   _____  _     _        ______  _______  ______\n");
    printf("|_____] |     | |     | |      |     \\ |______ |_____/\n");
    printf("|_____] |_____| |_____| |_____ |_____/ |______ |    \\_\n");
    printf("______   ______ _______ _______ _     _\n");
    printf("|_____] |_____/ |______ |_____| |____/ \n");
    printf("|_____] |    \\_ |______ |     | |    \\_\n");
    printf("\n");
    InitialiseStory(story);
    printf("%s\n", story);
    printf("\nMove the player (X) using the keys 'w', 'a', 's', 'd'\n");
    printf("Good luck!\n\n\n");

    /* Main game loop */
    PrintCave(cave);
    printf("Accessible? %d\n", IsExitAccessible(cave));
    printf("Unique? %d\n", IsExitUnique(cave));
    printf("Complete? %d\n", IsBorderComplete(cave));

    while (!gameOver) {
        gameOver = MakeMove(cave, GetMove());
        PrintCave(cave);
        if (gameOver == 1) {
            printf("\n\nGAME OVER!! \nYou died!\n\n");
        }
        else if (gameOver == 2) {
            printf("\n\nCONGRATULATIONS!! \nYou escaped!\n\n");
        }
    }

    return 0;
}