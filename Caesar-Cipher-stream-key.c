#include <stdio.h>
#include <ctype.h>
#include <cstring>

/***
  * This program will encode and decode the Caesar Cipher with Key Stream
  * Attention please,
  * 1- to encode your message:
  *     Enter your message
  *     Enter the number of shifting times for every character.
  *
  * 2- to decode your message:
  *     Enter your message
  *     Enter the negative number of the Encoding shifting number for every character.
  *
  *     Author: Islam Abdelslam.
  */

//message Limits
#define MAX_LEN 1000

int main() {
    char message[MAX_LEN];
    int i;

    printf("Enter a message to encrypt: ");
    scanf("%s", message);

    int len = strlen(message);
    int shift[len];

    printf("Enter a shift values: ");
    for (i = 0; message[i] != '\0'; i++)
        scanf("%d", &shift[i]);

    //English Alphabets have 26 number....
    // Normalize the shift value to the range [0, 25]
    for (i = 0; i < len; i++) {
        shift[i] = shift[i] % 26;
        if (shift[i] < 0) {
            shift[i] += 26;
        }

        char c = message[i];
        // to enhance our letter is it capital or small...
        if (isalpha(c)) {
            char base = islower(c) ? 'a' : 'A';
            c = base + (c - base + shift[i]) % 26;
            message[i] = c;
        }

    }
    printf("The encrypted message is: %s\n", message);

    return 0;
}
