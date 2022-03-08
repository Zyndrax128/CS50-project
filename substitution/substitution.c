#include <stdio.h>
#include <cs50.h> //libraries
#include <ctype.h>
#include <string.h>
#include <math.h>
int main(void)
{
    // Prompt user
    string text = get_string("Text: ");

    // String length
    int i = strlen(text);
    int letters = 0;
    int words = 0;
    int sentences = 0;

    // Loop pour compter
    for (int x = 0; x < i; x++) //boucle chaînes de caractères
    {
        // lettres à compter
        char c = text[x];
        if (isalpha(c) != 0) //vérifier si l'alphabet est présent ou non
        {
            letters++;
        }

        // Mots à compter
        if (c == ' ')
        {
            words++;
        }

        // Sentences à compter
        if (c == '.' || c == '!' || c == '?')
        {
            sentences++;
        }
    }

    // tenir compte du dernier mot
    words = words + 1;

    // Calculation
    float L = ((float)letters / (float)words) * 100;
    float s = ((float)sentences / (float)words) * 100;
    float subindex = 0.0588 * L - 0.296 * s - 15.8;
    int index = round(subindex);
    if (index > 16)
    {
        printf("Grade 16+\n");
    }
    else if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %i\n", index);
    }

}