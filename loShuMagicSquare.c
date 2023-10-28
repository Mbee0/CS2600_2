#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void main()
{
    // Init variables
    int loShuSquare[3][3] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int attempts = 0;
    // Declarations
    int indexRowOne, indexColumnOne,
        indexRowTwo, indexColumnTwo, tempNumber,
        sumRowOne, sumRowTwo, sumRowThree,
        sumColmOne, sumColmTwo, sumColmThree,
        sumDiagnolOne, sumDiagnolTwo;
    time_t t;

    srand((unsigned)time(&t));

    // Create new squares until Lo Shu Magic Square is prodcued
    do
    {
        // add to count
        attempts++;
        for (int i = 0; i < 3; i++)
        {
            indexRowOne = rand() % 3;
            do
            {
                indexRowTwo = rand() % 3;
            } while (indexRowOne == indexRowTwo);

            indexColumnOne = rand() % 3;
            do
            {
                indexColumnTwo = rand() % 3;
            } while (indexColumnOne == indexColumnTwo);

            // swap numbers at two locations in the array
            tempNumber = loShuSquare[indexRowOne][indexColumnOne];
            loShuSquare[indexRowOne][indexColumnOne] = loShuSquare[indexRowTwo][indexColumnTwo];
            loShuSquare[indexRowTwo][indexColumnTwo] = tempNumber;
        }
        // find the sum of all rows, columns, and the two diagnols
        sumRowOne = loShuSquare[0][0] + loShuSquare[0][1] + loShuSquare[0][2];
        sumRowTwo = loShuSquare[1][0] + loShuSquare[1][1] + loShuSquare[1][2];
        sumRowThree = loShuSquare[2][0] + loShuSquare[2][1] + loShuSquare[2][2];
        sumColmOne = loShuSquare[0][0] + loShuSquare[1][0] + loShuSquare[2][0];
        sumColmTwo = loShuSquare[0][1] + loShuSquare[1][1] + loShuSquare[2][1];
        sumColmThree = loShuSquare[0][2] + loShuSquare[1][2] + loShuSquare[2][2];
        sumDiagnolOne = loShuSquare[0][0] + loShuSquare[1][1] + loShuSquare[2][2];
        sumDiagnolTwo = loShuSquare[0][2] + loShuSquare[1][1] + loShuSquare[2][0];

        // continue loop until all sums are = 15
    } while ((sumRowOne != 15) || (sumRowTwo != 15) || (sumRowThree != 15) ||
             (sumColmOne != 15) || (sumColmTwo != 15) || (sumColmThree != 15) ||
             (sumDiagnolOne != 15) || (sumDiagnolTwo != 15));

    // Print number of attempts
    printf("Squares generated and tested before success: %d\n", attempts);

    // Print the square
    for (int row = 0; row < 3; row++)
    {
        printf("[ ");
        for (int colm = 0; colm < 3; colm++)
        {
            printf("%d ", loShuSquare[row][colm]);
        }
        printf("]\n");
    }
}