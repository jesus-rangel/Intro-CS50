// Caesar without CS50 library
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <stdbool.h>

bool key_is_valid(char *key);

int main(int argc, char *argv[])
{
  // Check Usage
  if (argc != 2 || !key_is_valid(argv[1]))
  {
    puts("Usage: ./caesar key");
    return 1;
  }

  // Get key, plain text and cyphered text in variables
  int key = atoi(argv[1]);
  char plain_text[256];
  char cypher_text[256];
  printf("plaintext: ");
  fgets(plain_text, sizeof(plain_text), stdin);
  for (int i = 0; plain_text[i] != '\0'; i++)
  {
    if (isalpha(plain_text[i]))
    {
      /*
       * So, regarding my difficulty with this thing...
       * If you wanna apply Caesar's algorithm
       * you need to account for the ASCII values of the alphabet
       * so before you get the remainder of 26, you need to substract
       * 65 if it's uppercase, 97 if it's lowercase, and
       * After getting the remainder, you need to add them again
       * So the answer can "find its place" back to the alphabet in ASCII values
       */

      if (isupper(plain_text[i]))
      {
        cypher_text[i] = ((plain_text[i] + key) - 65) % 26 + 65;
      }
      else
      {
        cypher_text[i] = ((plain_text[i] + key) - 97) % 26 + 97;
      }
    }
    else
    {
      cypher_text[i] = plain_text[i];
    }
  }
  /*
   * I don't understand why I could never include the end character
   * to be added inside the for loop, at the same index where it would
   * be found in the plain_text string, but I never could
   * (I did try with length = strlen(plain_text), didn't work)
   * so here's a suboptimal solution, I guess o.O
   */
  cypher_text[strlen(plain_text)] = '\0';
  printf("ciphertext: %s", cypher_text);
  return 0;
}

bool key_is_valid(char *key)
{
  for (int i = 0, length = strlen(key); i < length; i++)
  {
    if (!isdigit(key[i]))
    {
      return false;
    }
  }
  return true;
}