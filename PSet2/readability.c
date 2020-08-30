// Readability without CS50 libraries, tested with local compiler
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

// Floats used for precision since in my testing environment rounding was getting freaky
float get_coleman_liau(int letter_count, int sentence_count, int word_count);
int print_grading(float coleman_liau_index);

int main(void)
{
  // Retrieve text from user input
  char text[1024];
  puts("Text: ");
  fgets(text, sizeof(text), stdin);

  // We are initializing word count at 1 because we're assuming the text begins with a word
  int letter_count = 0,
      sentence_count = 0,
      word_count = 1;

  // Iterate through each character in the text(string)
  for (int i = 0, length = strlen(text); i < length; i++)
  {
    // If it is an alpha-numeric character, increase letter count
    if (isalpha(text[i]))
    {
      letter_count++;
    }
    // Words are what comes before a space
    // Words also come before punctuation marks. But what comes after a punctuation mark?
    // A space!
    if (text[i] == ' ')
    {
      word_count++;
    }
    // If text[i] is a punctuation mark, whatever came before was a sentence
    // The problem with ispunct() is that it will include apostrophes and commas
    if (text[i] == '.' || text[i] == '!' || text[i] == '?')
    {
      sentence_count++;
    }
  }

  // Coleman-Liau Index
  float coleman_liau_index = get_coleman_liau(letter_count, sentence_count, word_count);

  // Print Grading Level
  print_grading(coleman_liau_index);
  return 0;
}

// Coleman-Liau Math
float get_coleman_liau(int letter_count, int sentence_count, int word_count)
{
  float letter_average = (((double)letter_count) / word_count) * 100.0;
  float sentence_average = (((double)sentence_count) / word_count) * 100.0;
  return round(0.0588 * letter_average - 0.296 * sentence_average - 15.8);
}

int print_grading(float coleman_liau_index)
{
  if (coleman_liau_index < 1)
  {
    puts("Before Grade 1");
  }
  else if (coleman_liau_index > 15)
  {
    puts("Grade 16+");
  }
  else
  {
    printf("Grade %1g\n", coleman_liau_index);
  }
  return 0;
}