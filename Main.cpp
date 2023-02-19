#include "Plateau.hpp"
#include <iostream>

int main()
{
    Plateau p;
    p.SetLargeur(25);
    p.SetLongueur(25);
    p.SetTore(true);
    p.SetCelluleRandom();
    p.affiche();
    printf("\n\n\n\n\n");
    p.refresh();
    p.affiche();
    return 0;
}