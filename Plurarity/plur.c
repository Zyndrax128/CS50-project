// Nombre maxi de candidats
#define MAX 9

// Candidats nom et votes
typedef struct
{
    string name;
    int votes;
}
candidate;

// Tableaux des candidats
candidate candidates[MAX];

// Nombres des candidats
int candidate_count;

// Function prototypes
bool vote(string name);
void print_winner(void);

int main(int argc, string argv[])
{
    // check pour invalide
    if (argc < 2)
    {
        printf("Usage: plurality [candidate ...]\n");
        return 1;
    }

    // Remplir le tableaux des candidats
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

    // Boucles sur tout les électeurs
    for (int i = 0; i < voter_count; i++)
    {
        string name = get_string("Vote: ");

        // Check pour vote invalide
        if (!vote(name))
        {
            printf("Invalid vote.\n");
        }
    }

    // Afficher le vainqueur de l'élection
    print_winner();
}

// Mettre à jour les totaux des votes compte tenu d'un nouveau vote
bool vote(string name)
{
    //Boucle pour les comptes des candidats
    for(int i = 0; i < candidate_count ; i++)
    {
        if (strcmp(candidates[i].name, name)== 0)
        {
            candidates[i].vote++;
            return true;
        }
    }
      
    return false;
}

void print_winner (void)
    int maximum_vote = 0

    for (int i = 0 ; i < candidate_count ; i++)
    {
        if (candidates[i].votes, maximum_vote)
        {
            maximum_vote = candidates[i].votes;
        }
    }

    for (int i = 0; i < candidates_count; i++)
    {
        printf("%s\n", candidates[i].names)
    }