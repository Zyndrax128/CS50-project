//Simuler l'héritage génétique du groupe sanguin

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Chaque personne a deux parents et deux allèles
typedef struct person
{
    struct person *parents[2];
    char alleles[2];
}
person;

const int GENERATIONS = 3;
const int INDENT_LENGTH = 4;

person *create_family(int generations);
void print_family(person *p, int generation);
void free_family(person *p);
char random_allele();

int main(void)
{
    // Générateur de nombres aléatoires
    srand(time(0));

    // Créer une nouvelle famille avec trois générations
    person *p = create_family(GENERATIONS);

    // Imprimer l'arbre généalogique des groupes sanguins
    print_family(p, 0);

    // Mémoire libre
    free_family(p);
}

// Créer un nouvel individu avec générations
person *create_family(int generations)
{
    // Allouer de la mémoire pour la nouvelle personne
    person *n = malloc(sizeof(person));
    if (n == NULL)
    {
        return NULL;
    }

    // Génération avec les données parentales
    if (generations > 1)
    {
        // Créer récursivement des historiques de groupes sanguins pour les parents
        n->parents[0] = create_family(generations - 1);
        n->parents[1] = create_family(generations - 1);

        // Assigner aléatoirement les allèles des enfants en fonction des parents
        n->alleles[0] = n->parents[0]->alleles[rand() % 2];
        n->alleles[1] = n->parents[1]->alleles[rand() % 2];
    }

    // Génération sans données sur les parents
    else
    {
        //Mettre les pointeurs des parents à NULL
        n->parents[0] = NULL;
        n->parents[1] = NULL;

        // Attribuer des allèles de façon aléatoire
        n->alleles[0] = random_allele();
        n->alleles[1] = random_allele();
    }

    // Retourner la personne nouvellement créée
    return n;
}

// Libérez 'p' et tous les ancêtres de 'p'.
void free_family(person *p)
{
    // Traiter le cas de base
    if (p == NULL){
        return;
    }
    
    // Parents libres
    free_family(p->parents[0]);
    free_family(p->parents[1]);

    // Enfants libres
    free(p);
}

// Imprimer chasque membres de la familles et leurs alleles
void print_family(person *p, int generation)
{
    // Manipuler le cas ce base
    if (p == NULL)
    {
        return;
    }

    // Imprimer les indentations
    for (int i = 0; i < generation * INDENT_LENGTH; i++)
    {
        printf(" ");
    }

    // imprimer les personnes
    printf("Generation %i, blood type %c%c\n", generation, p->alleles[0], p->alleles[1]);
    print_family(p->parents[0], generation + 1);
    print_family(p->parents[1], generation + 1);
}

// Choisie au hasard un groupe sanguin ou un allele
char random_allele()
{
    int r = rand() % 3;
    if (r == 0)
    {
        return 'A';
    }
    else if (r == 1)
    {
        return 'B';
    }
    else
    {
        return 'O';
    }
}