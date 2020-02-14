#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max number of candidates
#define MAX 9

// Candidates have name and vote count
typedef struct
{
    string name;
    int votes;
}
candidate;

// Array of candidates
candidate candidates[MAX];

// Number of candidates
int candidate_count;

// Function prototypes
bool vote(string name);
void print_winner(void);

int main(int argc, string argv[])
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
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
    }

    int voter_count = get_int("Number of voters: ");

    // Loop over all voters
    for (int i = 0; i < voter_count; i++)
    {
        string name = get_string("Vote: ");

        // Check for invalid vote
        if (!vote(name))
        {
            printf("Invalid vote.\n");
        }
    }

    // Display winner of election
    print_winner();
}

// Update vote totals given a new vote
bool vote(string name)
{
    for (int i = 0; i < candidate_count; i++)
    {
        if (strcmp(candidates[i].name, name) == 0)
        {
            candidates[i].votes++;
            return true;
        }
    }
    return false;
}

// Print the winner (or winners) of the election
void print_winner(void)
{
    // make variable where we will store the winner
    string winner;
    // if only 1 candidate then print out his name as a winner
    if (candidate_count == 1)
    {
        printf("%s\n", candidates[0].name);
    }

    // if more than 1 candidate then compare who has more votes
    for (int i = 0; i < candidate_count - 1; i++)
    {
        for (int j = i + 1; j < candidate_count; j++)
        {
            if (candidates[i].votes > candidates[j].votes)
            {
                // Assign winner with the highest number
                winner = candidates[i].name;
                if (i == candidate_count - 2)
                {
                    printf("%s\n", winner);
                    // Check if there are no candidates with same number of votes
                    for (j = 0; j < candidate_count; j++)
                    {
                        // Omit comparing to the winner already picked
                        if (j == i)
                        {
                            return;
                        }

                        // If there is a winner with same number of votes - print him
                        if (candidates[i].votes == candidates[j].votes)
                        {
                            printf("%s\n", candidates[j].name);
                        }
                    }
                }

            }
            // Print all if there is a draw
            else if (candidates[i].votes == candidates[j].votes)
            {
                if (i == candidate_count - 2)
                {
                    for (i = 0; i < candidate_count; i++)
                    {
                        printf("%s\n", candidates[i].name);
                    }
                }
            }
        }
    }
    return;
}

