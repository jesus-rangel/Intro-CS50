// Encrypt stuff WWII Style!
#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

bool validateKey(string s);

int main(int argc, string argv[])
{
  // Validate Command Line Input when running program
  if (argc != 2)
  {
    printf("Usage: ./substitution key\n");
    return 1;
  }
  // Run Key validation
  if (!validateKey(argv[1]))
  {
    printf("Key must contain 26 characters\n");
    return 1;
  }

  // Get text to cipher
  string s = get_string("plaintext: "),
         // Difference between key and normal letters
      difference = argv[1];

  // Calculate the difference
  for (int i = 'A'; i <= 'Z'; i++)
  {
    difference[i - 'A'] = toupper(difference[i - 'A']) - i;
  }

  // Print Cyphered letters
  printf("ciphertext: ");

  for (int i = 0, len = strlen(s); i < len; i++)
  {
    if (isalpha(s[i]))
    {
      s[i] = s[i] + difference[s[i] - (isupper(s[i]) ? 'A' : 'a')];
    }
    printf("%c", s[i]);
  }
  printf("\n");
  return 0;
}

// Validate Cipher Key
bool validateKey(string s)
{
  // Get and validate length of key
  int len = strlen(s);
  if (len != 26)
  {
    return false;
  }
  // Check for character repetition
  int freq[26] = {0};
  for (int i = 0; i < len; i++)
  {
    if (!isalpha(s[i]))
    {
      return false;
    }
    int j = toupper(s[i]) - 'A';
    if (freq[j] > 0)
    {
      return false;
    }
    freq[j]++;
  }
  return true;
}
