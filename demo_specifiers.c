#include <stdio.h>

int main() {
    unsigned int num = 42;
    char decimalStr[20];  // Assuming a maximum of 20 characters
    char octalStr[20];
    char lowercaseHexStr[20];
    char uppercaseHexStr[20];

    // Convert the numbers to strings using sprintf
    sprintf(decimalStr, "%u", num);
    sprintf(octalStr, "%o", num);
    sprintf(lowercaseHexStr, "%x", num);
    sprintf(uppercaseHexStr, "%X", num);

    // Print the converted strings
    printf("Decimal: %s\n", decimalStr);
    printf("Octal: %s\n", octalStr);
    printf("Lowercase Hex: %s\n", lowercaseHexStr);
    printf("Uppercase Hex: %s\n", uppercaseHexStr);

    return 0;
}
