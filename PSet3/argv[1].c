#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

int main(int argc, char *argv[])
{
  char candidates[argc - 1][10];
  printf("Arg Count: %d\n", argc);
  for (int i = 0; i < argc; i++)
  {
    printf("Argument%d: %s\n", i, argv[i]);
  }
  for (int i = 1; i < argc; i++)
  {
    for (int j = 0, length = strlen(argv[i]); j < length; j++)
    {
      candidates[i][j] = argv[i][j];
    }
    printf("Candidate%d: %s\n", i, candidates[i]);
  }
  int votes;
  puts("Number of voters:");
  scanf("%d", &votes);
  for (int i = 0; i < votes; i++)
  {
    char name[10];
    printf("Vote: ");
    fgets(name, sizeof(name), stdin);
    for (int j = 0; j < argc; j++)
    {
      if (strcmp(name, candidates[j]) == 0)
      {
        puts("Valid Vote");
      }
      else
      {
        puts("Invalid Vote");
      }
    }
  }
  return 0;
}