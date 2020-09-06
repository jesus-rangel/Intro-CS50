#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

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
  get_names(argv[1]);

  int voter_count;
  printf("Number of voters: ");
  scanf("%d", &voter_count);
  // Loop over all voters
  for (int i = 0; i < voter_count; i++)
  {
    char name[20];
    printf("Vote: ");
    fgets(name, sizeof(name), stdin);
    /*Puts("Name variable: ")
    for (int i = 0; i < strlen(name), i++)
    {
      printf("%c", name[i])
    }
    Puts("Candidate name variable: ")
    for (int = 0; i < candidate_count; i++
    {
      for (int j = 0; j < strlen(candidate[i].name); j++)
      printf("%c", candidate[i].name[j]);
    })*/
    // Check for invalid vote
    if (!vote(name))
    {
      printf("Invalid vote.\n");
    }
    return 0;
    // Display winner of election
    print_winner();
  }
}

// Get names of candidates from argument list
void get_names(char argv[1])
{
  int j = 0, k = 0;
  // Iterating through characters in argument string of voters
  for (int i = 0, length = strlen(argv[1]); i < length; i++)
  {
    // Iterate through each letter in the string
    if (isalpha(argv[1][i]))
    {
      candidates[j].name[k] = argv[1][i];
      k++;
    }
    // If we run into something other than a letter
    // Input end of string character
    // Reset k to zero (characters in the candidate name)
    // And increase j to go get next candidate's name
    else
    {
      candidates[j].name[k] = '\0';
      k = 0;
      j++;
    }
  }
}

// Update vote totals given a new vote
bool vote(char name[20])
{
  // Simple iteration through array
  for (int i = 0; i < candidate_count; i++)
  {

    for (int j = 0, length = strlen(name); j < length; j++)
    {
      if (candidates[i] name[j] != name[j])
      {
        return false
      }
    }
    else
    {
      candidates[i].votes++;
      return true;
    }
  }
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
