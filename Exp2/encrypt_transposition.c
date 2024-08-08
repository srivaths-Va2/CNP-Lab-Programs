/* C program to perform encryption by transposition */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void encrypt_transposition(char inp[], int N)
/**
 * Encrypts a given input string using a transposition technique.
 * 
 * @param inp The input string to be encrypted
 * @param N The length of the input string
 */
{   
    int idx = 0;        // current index of output string
    char out[50];       // output array

    // for rail 1
    for(int i = 0; i < N; i = i + 3)
    {
        out[idx] = inp[i];
        idx++;
    }

    // for rail 2
    for(int i = 1; i < N; i = i + 3)
    {
        out[idx] = inp[i];
        idx++;
    }

    // for rail 3
    for(int i = 2; i < N; i = i + 3)
    {
        out[idx] = inp[i];
        idx++;
    }

    // adding null character
    out[idx++] = '\0';

    // printing the output
    printf("Encrypted string : %s", out);
}

void main()
/**
 * Encrypts a given input string using a transposition technique.
 * 
 * @param inp The input string to be encrypted
 * @param N The length of the input string
 */
{
    char input[8] = "srivaths";
    int len = 8;

    encrypt_transposition(input, len);
}