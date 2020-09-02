// Substitution without CS50 libraries. Tested in local compiler.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include <math.h>

int validate_key(int argc, char *argv[]);

int main(int argc, char *argv[])
{
  if (validate_key(argc, argv) > 0)
  {
    return 1;
  }

  // Mapping of cypehred alphabet letters
  char mapped_alphabet[26];
  for (int i = 0, length = strlen(argv[1]); i < length; i++)
  {
    mapped_alphabet[i] = toupper(argv[1][i]);
  }

  printf("plaintext: ");
  char plain_text[256];
  fgets(plain_text, sizeof(plain_text), stdin);

  // Print cyphered letters
  char cypher_text[256];
  for (int i = 0, length = strlen(plain_text); i < length; i++)
  {
    cypher_text[i] = plain_text[i];
    if (isalpha(plain_text[i]))
    {
      if (isupper(plain_text[i]))
      {
        cypher_text[i] = mapped_alphabet[plain_text[i] - 65];
      }
      else
      {
        cypher_text[i] = tolower(mapped_alphabet[plain_text[i] - 97]);
      }
    }
  }
  cypher_text[strlen(plain_text)] = '\0';
  printf("ciphertext: %s\n", cypher_text);
  return 0;
}

int validate_key(int argc, char *argv[])
{
  if (argc != 2)
  {
    puts("Too few arguments. Usage ./substitution key");
    return 1;
  }
  if (strlen(argv[1]) != 26)
  {
    puts("Number of letters in cypher alphabet must be 26");
    return 2;
  }
  // Frequency and validity of characters Check
  int frequency[26] = {0};
  for (int i = 0, length = strlen(argv[1]); i < length; i++)
  {
    if (!isalpha(argv[1][i]))
    {
      puts("Cypher alphabet must include only letters");
      return 3;
    }
    if (frequency[toupper(argv[1][i]) - 65] > 0)
    {
      puts("Characters in cypher alphabet cannot repeat themselves");
      return 4;
    }
    frequency[toupper(argv[1][i]) - 65]++;
  }
  return 0;
}