#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void character_destuffing(char input[], int N)
/**
 * Perform character destuffing on the input array to remove stuffed DLE sequences.
 * 
 * @param input The input character array containing stuffed and unstuffed characters.
 * @param N The total number of characters in the input array.
 */
{
    char output[100];
    int k = 0;
    int flag = 0;

    for(int i = 6; i < (N - 6); i++)
    {
        if(flag == 1 && input[i] == 'E' && input[i + 1] == 'D' && input[i + 2] == 'L' && input[i + 3] == 'E')
        {
            // Skip the stuffed DLE sequence
            i += 3;
            flag = 0;
            continue;
        }

        if(input[i] == 'D' && input[i + 1] == 'L' && input[i + 2] == 'E')
        {
            flag = 1;  // DLE sequence detected
        }

        output[k] = input[i];
        k++;
    }

    output[k] = '\0';

    // print the output string
    printf("Output string: %s\n", output);
}

void main()
/**
 * Main function to demonstrate character destuffing on a predefined input array.
 * 
 * Initializes an input array with a stuffed character sequence, calculates its length, and calls the character_destuffing function.
 * 
 */
{
    char inp[100] = "DLESTXSRIVATHSDLEETX";
    int N = strlen(inp);
    character_destuffing(inp, N);
}
