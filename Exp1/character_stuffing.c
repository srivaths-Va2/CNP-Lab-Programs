/* C program to implement character stuffing */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void character_stuffing(char input[], int N)
/**
 * Perform character stuffing on the input string to handle special characters.
 * 
 * @param input The input string to be processed.
 * @param N The length of the input string.
 */
{
    char output[100];
    int k = 0;          // k is the index to the output string, which is used for referencing at a particular index
    char dle[3] = "DLE";
    char stx[3] = "STX";
    char etx[3] = "ETX";

    int flag = 0;       // flag to stay active when DLE sequence is going on

    // adding the DLE and STX at the start of the frame
    for(int i = 0; i < 3; i++)
    {
        output[k] = dle[i];
        k++;
    }

    for(int i = 0; i < 3; i++)
    {
        output[k] = stx[i];
        k++;
    }

    // adding elements from input to output, till a D comes up in the text
    for(int i = 0; i < N; i++)
    {
        if(input[i] != 'D' || (input[i] == 'E' && flag == 0))
        {
            output[k] = input[i];
            k++;
        }

        if(input[i] == 'D')
        {
            if(input[i + 1] == 'L' && input[i + 2] == 'E')
            {
                flag = 1;               // DLE flag is set. Character stuff the bits
            }

            output[k] = input[i];
            k++;
        }

        if(flag == 1 && input[i] == 'E')
        {
            output[k] = input[i];
            k++;

            // perform character stuffing
            output[k] = 'D';
            k++;
            output[k] = 'L';
            k++;
            output[k] = 'E';
            k++;

            // force flag to 0
            flag = 0;           // character stuffing over

        }
    }

    // append DLE ETX to the output
    for (int i = 0; i < 3; i++) {
        output[k] = dle[i];
        k++;
    }
    
    for (int i = 0; i < 3; i++) {
        output[k] = etx[i];
        k++;
    }

    output[k] = '\0';

    printf("Stuffed string : %s", output);
}

void main()
/**
 * Main function to demonstrate character stuffing on a given input string.
 * 
 * @param None
 * @return None
 */
{
    char inp[20] = "DOODLE";
    int N = 6;
    character_stuffing(inp, N);
}