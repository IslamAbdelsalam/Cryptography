#include <stdio.h>
#include <ctype.h>

/***
  * This program will encode and decode the Caesar Cipher
  * Attention please,
  * 1- to encode your message:
  *     Enter your message
  *     Enter the number of shifting times.
  *
  * 2- to decode your message:
  *     Enter your message
  *     Enter the negative number of the Encoding shifting number
  *
  */

//message Limits
#define MAX_LEN 1000

int main() {
    char message[MAX_LEN];
    int i, shift;

    printf("Enter a message to encrypt: ");
    scanf("%s",message);

    printf("Enter a shift value: ");
    scanf("%d", &shift);

    // English Alphabet consists of 26 letters
    shift = shift % 26;
    if (shift < 0) {
        shift += 26;
    }

    for (i = 0; message[i] != '\0'; i++) {
        char c = message[i];
        // to enhance our letter is it capital or small...
        if (isalpha(c)) {
            char base = islower(c) ? 'a' : 'A';
            c = base + (c - base + shift) % 26;
            message[i] = c;
        }
    }

    printf("The encrypted message is: %s\n", message);

    return 0;
}
