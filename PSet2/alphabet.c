// Substitution without CS50 libraries, using struct instead of array index manipulation
// And finally with no math inside the array index
// I swear to God I'm doing this on a Saturday morning 4:30 am

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include <math.h>

struct letter
{
  char uppercase;
  char lowercase;
  char crypted_lowercase;
  char crypted_uppercase;
};

bool key_is_valid(int argc, char *argv[]);

typedef struct letter letter;
letter alphabet[26];

int main(int argc, char *argv[])
{

  if (!key_is_valid(argc, argv))
  {
    return 1;
  }

  // So we create an alphabet of letters and those letters have different 'versions'
  // Uppercase, lowercase, and their encrypted versions
  // And in the following few lines we'll assign those alphabet letters
  // Including the encrypted ones to argv[1]
  // For some reason, the line char key[26] = argv[1]; never worked for me
  for (int i = 0; i < 26; i++)
  {
    // I hate array index manipulation
    // Here is the simplest solution that matches nothing I could find online
    // Yet it is so much easier to read
    alphabet[i].lowercase = 'a' + i;
    alphabet[i].uppercase = 'A' + i;
    alphabet[i].crypted_lowercase = tolower(argv[1][i]);
    alphabet[i].crypted_uppercase = toupper(argv[1][i]);
  }

  printf("plaintext: ");
  char plain_text[256];
  fgets(plain_text, sizeof(plain_text), stdin);
  char cypher_text[256];
  // int j will be iterating through plaintext
  for (int j = 0, length = strlen(plain_text); j < length; j++)
  {
    cypher_text[j] = plain_text[j];
    if (isalpha(plain_text[j]))
    {
      // int k will be iterating through the alphabets
      for (int k = 0; k < 26; k++)
      {
        if (plain_text[j] == alphabet[k].uppercase)
        {
          cypher_text[j] = alphabet[k].crypted_uppercase;
        }
        else if (plain_text[j] == alphabet[k].lowercase)
        {
          cypher_text[j] = alphabet[k].crypted_lowercase;
        }
      }
    }
  }
  cypher_text[strlen(plain_text)] = '\0';
  printf("ciphertext: %s\n", cypher_text);
  return 0;
}

bool key_is_valid(int argc, char *argv[])
{
  if (argc != 2)
  {
    puts("Too few arguments. Usage ./ substitution key");
    return false;
  }
  if (strlen(argv[1]) != 26)
  {
    puts("Number of letters in cypher alphabet must be 26");
    return false;
  }
  // Frequency and validity of characters check
  int frequency[26] = {0};
  for (int i = 0, length = strlen(argv[1]); i < length; i++)
  {
    if (!isalpha(argv[1][i]))
    {
      puts("Cypher alphabet must include only letters");
      return false;
    }
    if (frequency[toupper(argv[1][i]) - 65] > 0)
    {
      puts("Characters in cypher alphabet cannot repeat themselves");
      return false;
    }
    frequency[toupper(argv[1][i]) - 65]++;
  }
  return true;
}