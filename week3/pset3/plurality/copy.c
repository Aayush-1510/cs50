#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <strings.h>

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
    int a = 0;
    for(int i = 0; i < candidate_count; i++)
    {
        if(strcasecmp(candidates[i].name, name) == 0)
        {
            a=10;
            candidates[i].votes+=1;
            return true;
        }
    }
    if(a!=10)
    {
        return false;
    }
    return false;
}

// Print the winner (or winners) of the election
void print_winner(void)
{

    for(int i = 0; i <= candidate_count; i++)
    {
        if(candidate_count == 1)
        {
            printf("%s\n",candidates[i].name);

        }
        else if(candidate_count == 2)
        {
            if(candidates[i].votes == candidates[i+1].votes)
            {
                printf("%s\n",candidates[i].name);
                printf("%s\n",candidates[i+1].name);
            }
            else if(candidates[i].votes > candidates[i+1].votes)
            {
                printf("%s\n",candidates[i].name);
            }
            else
            {
                printf("%s\n",candidates[i+1].name);
            }
        }
        else
        {
            int max = 0;
            for(int j = 0; j < candidate_count; j++)
            {
                if(candidates[i].votes > candidates[i+1].votes)
                {
                    max = candidates[i].votes;
                }
                else
                {
                    max = candidates[i+1].votes;
                }
            }
            if(candidates[i].votes == max)
            {
                printf("%s\n",candidates[i].name);
            }
        }
    }
    return;
}