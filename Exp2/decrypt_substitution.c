/* Decryption with substitution */

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
    char str[26] = "qwertyuiopasdfghjklzxcvbnm";
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

void decrypt_substitution(char inp[])
/**
 * Decrypts a given input string using a substitution cipher.
 * Replaces each character in the input string with its corresponding character from the cipher.
 * Spaces in the input string are preserved in the output.
 * 
 * @param inp The input string to decrypt.
 */
{
    int len = strlen(inp);
    char out[50];
    int idx = 0;           // index of the output string
    int i = 0;

    char cipherstr[26] = "abcdefghijklmnopqrstuvwxyz";

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
    printf("Decrypted string : %s\n", out);
}

void main()
/**
 * Decrypts a given input using a substitution cipher.
 * 
 * The input is decrypted using a substitution cipher algorithm.
 * 
 * @param input The string to be decrypted.
 */
{
    char input[12] = "lkocqzil";
    decrypt_substitution(input);
}