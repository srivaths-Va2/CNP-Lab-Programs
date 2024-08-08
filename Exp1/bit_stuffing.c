/* Bit stuffing program in C */

#include<stdio.h>
#include<stdlib.h>

void BitStuffing(int inp[], int N)
/**
 * Perform bit stuffing on the input array to ensure no more than 5 consecutive 1's.
 * 
 * @param inp[] The input array containing binary digits (0's and 1's).
 * @param N The number of elements in the input array.
 */
{
    int out[50];                // output array
    int idx = 0;                // pointer to output array
    int one_count = 1;          // variable to count number of 1's

    // loop to perform bit stuffing
    for(int i = 0; i < N; i++)
    {
        // Checking for 0
        if(inp[i] == 0)
        {
            out[idx] = inp[i];
            idx++;
        }

        // Checking for 1
        if(inp[i] == 1)
        {
            out[idx] = inp[i];
            idx++;
            one_count++;

            // Perform bit stuffing if input number of 1's is more than 5 continuously
            if(one_count >= 5)
            {
                idx++;
                out[idx] = 0;
                one_count = 1;
            }
        }
    }

    // printing the result
    for(int i = 0; i < (idx + 1); i++)
    {
        // Making sure that output to be printed is either 0 or 1 (post-processing)
        if(out[i] == 0 | out[i] == 1)
            printf("%d", out[i]);
    }
}

void main()
/**
 * Main function to demonstrate bit stuffing on a predefined input array.
 * Initializes an array with a sequence of binary digits and calls the BitStuffing function to perform bit stuffing.
 */
{
    int input[10] = {1, 1, 1, 1, 1, 1, 1, 0, 0, 0};
    int N = 10;

    BitStuffing(input, N);
}