/* Encryption by substitution */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int get_index_by_letter(char c)
/**
 * Returns the index of a given letter in the English alphabet.
 * 
 * @param c The letter to find the index for.
 * @return The index of the letter in the alphabet (0-indexed).
 */
{
    char str[26] = "abcdefghijklmnopqrstuvwxyz";
    int idx = 0;

    for(int i = 0; i < strlen(str); i++)
    {
        if(c == str[i])
        {
            idx = i;
            break;
        }
    }

    return idx;
}

void encrypt_substitution(char inp[])
/**
 * Encrypts a given input string using a substitution cipher.
 * 
 * @param inp The input string to be encrypted.
 */
{
    int len = strlen(inp);
    char out[50];
    int idx = 0;           // index of the output string
    int i = 0;

    char cipherstr[26] = "qwertyuiopasdfghjklzxcvbnm";

    for(i = 0; i < len; i++)
    {
        if(inp[i] != " ")
        {
            idx = get_index_by_letter(inp[i]);
            out[i] = cipherstr[idx];
        }

        if(inp[i] == " ")
        {
            out[i] = " ";
        }
    }

    out[i++] = '\0';

    // printing the output string
    printf("Encrypted string : %s\n", out);
}

void main()
/**
 * Encrypts a given input string using a substitution cipher.
 * 
 * @param inp The input string to be encrypted.
 */
{
    char input[8] = "srivaths";
    encrypt_substitution(input);
}