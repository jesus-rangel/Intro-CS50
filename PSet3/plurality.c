#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

// Max number of candidates
#define MAX 9

// Candidates have name and vote count
typedef struct
{
  char name[20];
  int votes;
} candidate;

// Array of candidates
candidate candidates[MAX];

// Number of candidates
int candidate_count;

// Function prototypes
void get_names(char argv[1]);
bool vote(char name[]);
void print_winner(void);

int main(int argc, char *argv[])
{
  // Check for invalid usage
  if (argc < 2)
  {
    printf("Usage: plurality [candidate ...]\n");
    return 1;
  }

  // Populate array of candidates
  candidate_count = argc - 1;
  if (candidate_count > MAX)
  {
    printf("Maximum number of candidates is %i\n", MAX);
    return 2;
  }

  // Get names of candidates from argument list
  for (int i = 1; i < argc; i++)
  {
    // I also tried strcpy(candidate[i - 1].name, argv[i]);
    // Didn't work, just as well as the next solution didn't work
    int j, length = strlen(argv[i]);
    for (j = 0; j < length && argv[i][j] != '\0' && isalpha(argv[i][j]); j++)
    {
      candidates[i].name[j] = argv[i][j];
    }
    candidates[i].name[j] = '\0';
    // printf("Candidate%d: %s\n", i, candidates[i]);
  }

  int voter_count;
  printf("Number of voters: ");
  scanf("%d", &voter_count);
  // Loop over all voters
  for (int i = 0; i < voter_count; i++)
  {
    char name[20];
    printf("Vote: ");
    scanf("%s", name);
    if (!vote(name))
    {
      printf("Invalid vote.\n");
    }
    // Display winner of election
    print_winner();
  }
  return 0;
}

// Update vote totals given a new vote
bool vote(char name[20])
{
  for (int i = 0; i < candidate_count; i++)
  {
    if (strcmp(candidates[i].name, name) == 0)
    {
      return true;
    }
  }
  return false;
}

// Print the winner (or winners) of the election
void print_winner(void)
{
  // This following bet gets us which candidates' votes match
  // The highest amount of votes
  int most_votes = candidates[0].votes;
  for (int i = 0; i < candidate_count; i++)
  {
    if (candidates[i].votes > most_votes)
    {
      most_votes = candidates[i].votes;
    }
  }

  // But since several people can win
  // We need to print them in a for loop in case there's more than one
  for (int i = 0; i < candidate_count; i++)
  {
    if (candidates[i].votes == most_votes)
    {
      printf("%s\n", candidates[i].name);
    }
  }
  return;
}
