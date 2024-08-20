#include<stdio.h>
#include<string.h>

char check_val[100];
char gen_poly[100];
char data[100];

int N;  // Length of the generator polynomial
int data_length;

int i;
int j;

void XOR()
/**
 * Perform XOR operation bitwise on check_val array based on gen_poly array.
 * 
 * @param N The length of the arrays
 */ 
{
    // Perform the XOR operation bitwise
    for (i = 1; i < N; i++) {
        check_val[i] = (check_val[i] == gen_poly[i]) ? '0' : '1';
    }
}

void crc() 
/**
 * Perform Cyclic Redundancy Check (CRC) on the data using the specified polynomial.
 * 
 * Initialize the check value with the initial data segment and perform modulo 2 division to obtain the remainder.
 * 
 * @param N The length of the arrays
 * @param data_length The length of the data
 */
{
    // Initialize the check value with the initial data segment
    for (i = 0; i < N; i++) {
        check_val[i] = data[i];
    }

    // Perform the modulo 2 division to obtain the remainder
    for (i = N; i <= data_length + N - 1; i++) {
        // Check if the first bit is 1. If it is 1, call the XOR function
        if (check_val[0] == '1') {
            XOR();
        }

        // Shift the bits one position to the left for the next computation
        for (j = 0; j < N - 1; j++) {
            check_val[j] = check_val[j + 1];
        }

        // Append a bit from the data (or '0' if we've gone past the data length)
        check_val[j] = (i < data_length) ? data[i] : '0';
    }
}

void receiver()
/**
 * Receive the data, perform cyclic redundancy check, and check for transmission errors.
 */
{
    // Obtain the received data
    printf("Enter the received data: ");
    scanf("%s", data);
    printf("\n");

    // Perform the cyclic redundancy check
    crc();

    // Check the output to see if an error occurred during transmission
    for (i = 0; i < N - 1; i++) {
        if (check_val[i] == '1') {
            printf("Error occurred during transmission!\n");
            return;
        }
    }
    printf("No Error in transmission\n");
}

int main()
/**
 * Main function to handle the transmission of data using CRC (Cyclic Redundancy Check).
 * Prompts user to enter data and generator polynomial, pads zeros to data, performs CRC, 
 * computes check value, appends data with check value, and calls receiver to check for errors.
 * 
 * @return 0 indicating successful execution
 */ 
{
    printf("Enter the data to be transmitted: ");
    scanf("%s", data);

    printf("Enter the Generator polynomial: ");
    scanf("%s", gen_poly);

    N = strlen(gen_poly);  // Calculate the length of the generator polynomial
    data_length = strlen(data);

    // Append N-1 zeros to data
    for (i = data_length; i < data_length + N - 1; i++) {
        data[i] = '0';
    }
    data[i] = '\0';  // Null-terminate the string

    printf("Data with padded zeros: %s\n", data);
    printf("--------------------------------------\n");

    // Perform CRC
    crc();

    // Print the computed check value
    printf("CRC check value: ");
    for (i = 0; i < N - 1; i++) {
        printf("%c", check_val[i]);
    }
    printf("\n--------------------------------------\n");

    // Append data with the check value
    for (i = data_length; i < data_length + N - 1; i++) {
        data[i] = check_val[i - data_length];
    }
    data[i] = '\0';  // Null-terminate the string

    // Print final data to be sent
    printf("Data to be transmitted: %s\n", data);
    printf("--------------------------------------\n");

    // Calling receiver to check for errors
    receiver();

    return 0;
}
