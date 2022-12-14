#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define KEY_LENGTH 8

void encrypt(char* message, char* key) {
  int i, j;
  for (i = 0, j = 0; i < strlen(message); i++, j++) {
    if (j == KEY_LENGTH) {
      j = 0;
    }
    message[i] ^= key[j];
  }
}

int main(int argc, char* argv[]) {
  if (argc != 3) {
    printf("Usage: %s <message> <key>\n", argv[0]);
    return 1;
  }

  char* message = argv[1];
  char* key = argv[2];

  if (strlen(key) < KEY_LENGTH) {
    printf("Error: key must be at least %d characters long\n", KEY_LENGTH);
    return 1;
  }

  encrypt(message, key);
  printf("Encrypted message: %s\n", message);

  return 0;
}
