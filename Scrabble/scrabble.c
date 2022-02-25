#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Points attribués à chaque lettre de l'alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};


int compute_score(string word);


int main(void)
{
    // Obtenir des mots d'entrée des deux joueurs
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    // Score des deux mots
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    // Print les gagnants
 if (score1 > score2)
{
    printf("Player 1 wins!\n");
}

else if (score1 < score2)
{
    printf("Player 2 wins!\n");
}

else
{
    printf("Tie !");

}

int compute_score(string word)
{
    // Calculer et retourner le score de la chaîne de caractères
    int score = 0

    for(int i = 0, longueur = strlen(word); i < longueur; i++)
    {
         if (isupper(word[i]))
        {
            score += POINTS[word[i] - 'A'];
        }
        else if (islower(word[i]))
        {
            score += POINTS[word[i] - 'a'];
        }
    }
    return score;
}
