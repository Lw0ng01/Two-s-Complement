#include <stdio.h>

int subtract2sc_issafe(int x, int y)
{
    int z, bitSize, ySign, xSign, total, totalSign, flippedVal; 
    float f = 0;

    bitSize = sizeof(int) * 8; //find bit width
    xSign = x >> (bitSize -1); //shifting bits to right to find sign for x
    ySign = y >> (bitSize - 1); //shifting bits to right to find sign for y

    //flippedVal = ~y; //flipping bits of subtrahend

    if (xSign == ySign)
    {
        return 1; //returns 1 if there is no overflow (both x and y are same sign)
    }   
    else 
    {
        z = ~y + 1; //finding twos complement for y
        total = x + z; // adding x to z
        totalSign = total >> (bitSize - 1); //finding sign for the total value

        if (xSign == totalSign)
        {
            return 1;
        }
        else
        {
            return 0;
        }

    }

}
