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
    int j, length = strlen(argv[i]);
    for (j = 0; j < length && argv[i][j] != '\0' && isalpha(argv[i][j]); j++)
    {
      candidates[i][j] = argv[i][j];
    }
    candidates[i][j] = '\0';
    printf("Candidate%d: %s\n", i, candidates[i]);
  }
  int votes;
  puts("Number of voters:");
  scanf("%d", &votes);
  for (int i = 0; i < votes; i++)
  {
    // Alice Bob Charlie
    char name[10];
    printf("Vote: ");
    scanf("%s", name);
    printf("%s\n", name);
    for (int j = 0; j < argc; j++)
    {
      if (strcmp(candidates[j], name) == 0)
      {
        puts("Valid vote");
        break;
      }
    }
  }
  return 0;
}