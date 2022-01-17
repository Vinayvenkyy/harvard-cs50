#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max number of candidates
#define MAX 9

// preferences[i][j] is number of voters who prefer i over j
int preferences[MAX][MAX];

// locked[i][j] means i is locked in over j
bool locked[MAX][MAX];

// Each pair has a winner, loser
typedef struct
{
    int winner;
    int loser;
}
pair;

// Array of candidates
string candidates[MAX];
pair pairs[MAX * (MAX - 1) / 2];

int pair_count;
int candidate_count;

// Function prototypes
bool vote(int rank, string name, int ranks[]);
void record_preferences(int ranks[]);
void add_pairs(void);
void sort_pairs(void);
void lock_pairs(void);
void print_winner(void);
bool forms_cycle(int winner, int loser);


int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: tideman [candidate ...]\n");
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
        candidates[i] = argv[i + 1];
    }

    // Clear graph of locked in pairs
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            locked[i][j] = false;
        }
    }

    pair_count = 0;
    int voter_count = get_int("Number of voters: ");

    // Query for votes
    for (int i = 0; i < voter_count; i++)
    {
        // ranks[i] is voter's ith preference
        int ranks[candidate_count];

        // Query for each rank
        for (int j = 0; j < candidate_count; j++)
        {
            string name = get_string("Rank %i: ", j + 1);

            if (!vote(j, name, ranks))
            {
                printf("Invalid vote.\n");
                return 3;
            }
        }

        record_preferences(ranks);

        printf("\n");
    }

    add_pairs();
    sort_pairs();
    lock_pairs();
    print_winner();
    return 0;
}

// Update ranks given a new vote
bool vote(int rank, string name, int ranks[])
{
    for (int i = 0 ; i < candidate_count ; i++)
    {
        if (strcmp(name, candidates[i]) == 0)
        {
            ranks[rank] = i ;
            return true ;
        }
    }
    return false;
}

// Update preferences given one voter's ranks
void record_preferences(int ranks[])
{
    int temp[candidate_count] ;
    for (int i = 0 ; i < candidate_count ; i++)
    {
        for (int j = 0 ; j < candidate_count ; j++)
        {
            if (ranks[i] == j)
            {
                temp[i] = j ;
                for (int k =0; k < candidate_count ; k++)
                {
                    preferences[j][k]++ ;
                    preferences[j][j] = 0;

                }
                for (int n = 0 ; n < i ; n++)
                {
                    preferences[j][temp[n]]-- ;
                }
            }
        }
    }
    return;
}

// Record pairs of candidates where one is preferred over the other
void add_pairs(void)
{
    int n = 0 ;
    int temp[MAX][MAX] = {0} ;
    for (int i = 0 ; i < candidate_count ; i++)
    {
        for (int j = 0 ; j < candidate_count ; j++)
        {
            if (preferences[i][j] > preferences[j][i])
            {
                if (temp[i][j] == 0 && temp[j][i] == 0)
                {
                    pairs[n].winner = i ;
                    pairs[n].loser = j ;
                    n++;
                    temp[i][j]++;
                    temp[j][i]++;
                }
            }
            else if (preferences[i][j] < preferences[j][i])
            {
                if (temp[i][j] == 0 && temp[j][i] == 0)
                {
                    pairs[n].winner = j ;
                    pairs[n].loser = i ;
                    n++;
                    temp[i][j]++;
                    temp[j][i]++;
                }

            }
        }
    }
    pair_count = n;
    return;
}

// Sort pairs in decreasing order by strength of victory
void sort_pairs(void)
{
    for (int i = 0 ; i < pair_count ; i++)
    {
        for (int j = i+1 ; j < pair_count ; j++)
        {
            int s1 = preferences[pairs[i].winner][pairs[i].loser] - preferences[pairs[i].loser][pairs[i].winner];
            int s2 = preferences[pairs[j].winner][pairs[j].loser] - preferences[pairs[j].loser][pairs[j].winner];
            if (s1 < s2)
            {
                int temp1 = pairs[i].winner;
                pairs[i].winner = pairs[j].winner ;
                pairs[j].winner = temp1 ;

                int temp2 = pairs[i].loser ;
                pairs[i].loser = pairs[j].loser;
                pairs[j].loser = temp2 ;
            }
        }
    }
    return;
}

// Lock pairs into the candidate graph in order, without creating cycles
void lock_pairs(void)
{
    for (int i = 0 ; i < pair_count ; i++)
    {
        if (!(forms_cycle(pairs[i].winner,pairs[i].loser)))
        {
            locked[pairs[i].winner][pairs[i].loser] = true ;
        }
    }
    return;
}

// Print the winner of the election
void print_winner(void)
{
    for (int i = 0; i < candidate_count; i++)
    {
        int num_false = 0 ;

        for (int j = 0 ; j < candidate_count ; j++)
        {
            if (locked[j][i] == false)
            {
                num_false++ ;
                if (num_false == candidate_count)
                {
                    printf("%s\n", candidates[i]) ;
                }
            }
        }
    }
    return;
}

//Something is wrong.
bool forms_cycle(int winner, int loser)
{
    for (int i = 0 ; i < candidate_count ; i++)
    {
        if (locked[loser][i])
        {
            if (locked[i][winner])
            {
                return true ;
            }
        }
    }
    return false ;
}