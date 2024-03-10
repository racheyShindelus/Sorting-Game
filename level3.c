#include <stdio.h>
#include <stdlib.h>
#include <time.h>

bool isSorted(int numArr[], int boardSize)
{
    for(int i = 0; i < boardSize - 1; i++)
    {
        if(numArr[i] > numArr[i + 1])
        {
            return false;
        }
    }
    return true;    // else
}

void reverseArr(int numArr[], int reverse)
{
    int start = 0;
    int end = reverse - 1;
    while(start < end)
    {
        int temp = numArr[start];
        numArr[start] = numArr[end];
        numArr[end] = temp;
        start++;
        end--;
    }
}

void printBoard(int numArr[], int boardSize)
{
    printf("Board:  ");
    for(int i = 0; i < boardSize; i++)
    {
        printf("%d ", numArr[i]);
    }
    printf("\n");
}

int main()  
{
    int boardSize = 0;
    while(boardSize <= 1)    
    {
        printf("Enter size of board: ");
        scanf("%d", &boardSize);
    }

    srand(time(NULL));
    int numArr[boardSize];
    for(int i = 0; i < boardSize; i++)
    {
        numArr[i] = i + 1;
    }

    for(int i = 0; i < boardSize; i++)
    {
        int j;
        j = rand() % (i+1);
        int temp;
        temp = numArr[i];
        numArr[i] = numArr[j];
        numArr[j] = temp;
    }

    printBoard(numArr, boardSize);

    int numGames = 0;
    int reverse = 0;
    while (isSorted(numArr, boardSize) == false)
    {
            printf("How many to reverse? ");
            scanf("%d", &reverse);
            reverseArr(numArr, reverse);
            printBoard(numArr, boardSize);
            numGames++;                
    }
    printf("\n");
    printf("You won in ");
    printf("%d", numGames);
    printf(" moves!\n");
}