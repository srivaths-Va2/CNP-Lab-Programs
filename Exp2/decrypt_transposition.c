/* C program to perform decryption by transposition */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void decrypt_transposition(char inp[], int N)
/**
 * Decrypts a string using a transposition technique.
 * 
 * @param inp The input string to be decrypted
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
    printf("Decrypted string : %s", out);
}

void main()
/**
 * Decrypts a string using a transposition technique.
 * 
 * @param inp The input string to be decrypted
 * @param N The length of the input string
 */
{
    char input[8] = "svhrasit";
    int len = 8;

    decrypt_transposition(input, len);
}