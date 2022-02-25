#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    float dollar;
    do
    {
    dollar = get_float ("saisissez votre monnaie: ");
    }
    while (dollar <= 0);

    int cents = round (dollar*100);
    int coins = 0;

    while (cent >= 0)
    {
        cents -= 25;
        coins++;
    }
    while (cents >= 10)
    {
        cents-= 10;
        coins++;
    }
    while (cents >= 5)
    {
        cents-=5;
        coins++;
    }
    while (cents >= 1)
    {
        cents-=1;
        coins++;
    }

    printf("Tu as besoin à la fin %i coins", coins);
}