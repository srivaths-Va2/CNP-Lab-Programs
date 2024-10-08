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
    int idx = 0;        // current index for reading the encrypted string
    char out[50];       // output array for decrypted string

    int rail_1_size = (N + 2) / 3; // Number of characters in the 1st rail
    int rail_2_size = (N + 1) / 3; // Number of characters in the 2nd rail
    int rail_3_size = N / 3;       // Number of characters in the 3rd rail

    // For rail 1 (positions 0, 3, 6, ...)
    for(int i = 0; i < rail_1_size; i++) {
        out[i * 3] = inp[idx++];
    }

    // For rail 2 (positions 1, 4, 7, ...)
    for(int i = 0; i < rail_2_size; i++) {
        out[i * 3 + 1] = inp[idx++];
    }

    // For rail 3 (positions 2, 5, 8, ...)
    for(int i = 0; i < rail_3_size; i++) {
        out[i * 3 + 2] = inp[idx++];
    }

    // adding null character
    out[N] = '\0';

    // printing the output
    printf("Decrypted string : %s\n", out);
}

void main()
/**
 * Decrypts a string using a transposition technique.
 * 
 * @param inp The input string to be decrypted
 * @param N The length of the input string
 */
{
    char input[50] = "Hehgdnrhtei eo d erdt luet e";
    int len = strlen(input);

    decrypt_transposition(input, len);
}