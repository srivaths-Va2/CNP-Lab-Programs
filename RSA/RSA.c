/*
C program to implement RSA algorithm
*/

#include<stdio.h>
#include<stdlib.h>
#include<math.h>

// function to compute GCD
int gcd(int a, int b)
/**
 * Recursive function to calculate the greatest common divisor (GCD) of two integers.
 * 
 * @param a The first integer
 * @param b The second integer
 * @return The GCD of the two input integers
 */
{
    if(b == 0)
    {
        return a;
    }

    else
    {
        return gcd(b, a % b);
    }
}

// function to perform modular exponentiation
long long mod_pow(long long base, long long exponent, long long mod)
/**
 * Calculate the modular exponentiation of a base to an exponent with a given modulus.
 * 
 * @param base: The base value for the exponentiation.
 * @param exponent: The exponent value.
 * @param mod: The modulus value.
 * @return The result of (base^exponent) % mod.
 */
{
    long long result = 1;
    while(exponent > 0)
    {
        if(exponent % 2 == 1)
        {
            result = (result * base) % mod;
        }

        exponent = exponent >> 1;
        base = (base * base) % mod;
    }

    return result;
}

// function to compute modular inverse of e mod phi_n
int mod_inverse(int e, int phi_n)
/**
 * Calculate the modular inverse of a given integer 'e' modulo 'phi_n'.
 * 
 * @param e The integer for which the modular inverse is to be calculated.
 * @param phi_n The modulus value.
 * @return The modular inverse of 'e' modulo 'phi_n', or -1 if no inverse exists.
 */
{
    int d;
    for(d = 1; d < phi_n; d++)
    {
        if((e * d) % phi_n == 1)
        {
            return d;
        }
    }

    return -1;
}

int main()
/**
 * Main function to implement the RSA encryption and decryption process.
 * 
 * This function prompts the user to enter two prime numbers, calculates the public and private keys,
 * encrypts and decrypts a message using the RSA algorithm, and displays the results.
 * 
 * @return 0 upon successful execution
 */
{
    int p;
    int q;
    int n;
    int phi_n;
    int e;
    int d;
    int M;

    long long C;
    long long decrypted_M;

    printf("Enter the two primes p and q :");
    scanf("%d %d", &p, &q);

    n = p * q;

    phi_n = (p - 1) * (q - 1);

    printf("Enter the value of e (1 < e < %d):", phi_n);
    scanf("%d", &e);

    while(gcd(e, phi_n) != 1)
    {
        printf("Invalid value of e! Enter a different value of e : ");
        scanf("%d", &e);
    }

    d = mod_inverse(e, phi_n);

    if(d == -1)
    {
       printf("Modular inverse does not exist!"); 
       return -1;
    }

    printf("Public key (e = %d, n = %d)\n", e, n);
    printf("Private key (d = %d, n = %d)\n");

    printf("Enter the message to be encrypted : ");
    scanf("%d", &M);

    C = mod_pow(M, e, n);

    printf("Encrypted message : %ld\n", C);
    decrypted_M = mod_pow(C, d, n);
    printf("Decrypted message : %ld", decrypted_M);

    return 0;
}