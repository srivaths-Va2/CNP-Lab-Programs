/* Bit de-stuffing program in C */

#include<stdio.h>

void BitDestuffing(int inp[], int N)
/**
 * Perform bit de-stuffing on the input array to remove stuffed bits.
 * 
 * @param inp The input array containing stuffed bits
 * @param N The number of elements in the input array
 */
{
    int out[50];
    int idx = 0;
    int one_count = 0;

    for(int i = 0; i < N; i++)
    {
        if(inp[i] == 1)
        {
            one_count++;
        }

        else
        {
            one_count = 0;
        }

        out[idx++] = inp[i];

        if(one_count == 5)
        {
            i++;
            one_count = 0;
        }
    }

    for(int i = 0; i < idx; i++)
    {
        printf("%d", out[i]);
    }
}


void main()
/**
 * Main function to demonstrate bit destuffing on a predefined input array.
 * Initializes an array with a sequence of binary digits and calls the BitDestuffing function to perform bit destuffing.
 */
{
    int input[12] = {1,1,1,1,1,0,1,1,1,0,0,0};
    int N = 12;

    BitDestuffing(input, N);
}