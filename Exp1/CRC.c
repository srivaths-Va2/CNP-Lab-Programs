#include <stdio.h>
#include <string.h>

#define MAX_DATA_LEN 200 // Maximum data length
#define MAX_GEN_LEN 100  // Maximum generator polynomial length

void xorOperation(char *data, char *gen, int len)
/**
 * Performs XOR operation between the data and generator strings of a specified length.
 * 
 * @param data The data string to perform XOR operation on
 * @param gen The generator string used for XOR operation
 * @param len The length of the strings to process
 */
{
    for (int i = 0; i < len; i++) {
        data[i] = (data[i] == gen[i]) ? '0' : '1';
    }
}

void calculateCRC(char *data, char *gen, int dataLen, int genLen) 
/**
 * Calculates the CRC value for the given data using the specified generator polynomial.
 * 
 * @param data The data string for CRC calculation
 * @param gen The generator polynomial used for CRC calculation
 * @param dataLen The length of the data string
 * @param genLen The length of the generator polynomial
 */
{
    // Allocate arrays with sufficient sizes
    char temp[MAX_DATA_LEN + MAX_GEN_LEN];
    strcpy(temp, data);
    
    // Append zeros equal to the length of the generator polynomial minus 1
    for (int i = 0; i < genLen - 1; i++) {
        temp[dataLen + i] = '0';
    }
    temp[dataLen + genLen - 1] = '\0';
    
    // Perform division using XOR
    for (int i = 0; i <= dataLen - 1; i++) {
        if (temp[i] == '1') {
            xorOperation(temp + i, gen, genLen);
        }
    }
    
    // The CRC value is the last genLen-1 bits of temp
    printf("CRC value: ");
    for (int i = dataLen; i < dataLen + genLen - 1; i++) {
        printf("%c", temp[i]);
    }
    printf("\n");
    
    // Append CRC to the data
    for (int i = dataLen; i < dataLen + genLen - 1; i++) {
        data[i] = temp[i];
    }
    data[dataLen + genLen - 1] = '\0';
}

int main()
/**
 * Main function to calculate and verify CRC for data transmission.
 */
{
    char data[MAX_DATA_LEN], gen[MAX_GEN_LEN], received[MAX_DATA_LEN + MAX_GEN_LEN];
    int dataLen, genLen;

    // Input data sequence and generator polynomial
    printf("Enter the data sequence in binary: ");
    scanf("%s", data);
    printf("Enter the generator polynomial in binary: ");
    scanf("%s", gen);

    dataLen = strlen(data);
    genLen = strlen(gen);

    // Calculate CRC
    calculateCRC(data, gen, dataLen, genLen);

    // Output the data to be transmitted (data + CRC)
    printf("Data to be transmitted: %s\n", data);

    // Input the data received at the receiver
    printf("Enter the received data: ");
    scanf("%s", received);

    // Check if received data is the same as transmitted data
    if (strcmp(data, received) == 0) {
        printf("Data transmission successful!\n");
    } else {
        printf("Data was corrupted during transmission!\n");
    }

    return 0;
}
