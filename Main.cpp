#include "Plateau.hpp"
#include <iostream>

int main()
{
    Plateau p;
    std::cout << "Entrez la largeur du plateau : ";
    int largeur;
    std::cin >> largeur;
    p.SetLargeur(largeur);
    std::cout << "Entrez la longueur du plateau : ";
    int longueur;
    std::cin >> longueur;
    p.SetLongueur(longueur);
    std::cout << "Le plateau est-il torique ? (1 pour oui, autre pour non) : ";
    int torique;
    std::cin >> torique;
    if (torique == 1){
        p.SetTore(true);
    }
    else{
        p.SetTore(false);
    }
    std::cout << "Comment voulez-vous remplir le plateau ? (1 vide , 2 remplie , 3 damier , 4 via une liste ) : ";
    int remplissage;
    std::cin >> remplissage;
    if (remplissage == 1){
        p.SetCelluleVide();
    }
    else if (remplissage == 2){
        p.SetCelluleRemplie();
    }
    else if (remplissage == 3){
        p.SetCelluleDamier();
    }
    else if (remplissage == 4){
        int *liste = new int[largeur * longueur];
        for (int i = 1; i <= largeur * longueur; i++){
            std::cout << "Entrez le statut de la cellule " << i << " : ";
            int status;
            std::cin >> status;
            while(status != 0 && status != 1){
                std::cout << "Erreur de saisie, veuillez entrer 0 ou 1 : ";
                std::cin >> status;
            }
            liste[i] = status;
        }
        p.SetCelluleListe(liste);
    }
    else{
        std::cout << "Erreur de saisie";
    }
    //afficher le plateau
    p.affiche();
    //demander si il veut faire une étape ou plusieurs
    std::cout << "Combien d'étapes voulez-vous faire ? : ";
    int etapes;
    std::cin >> etapes;
    for (int i = 0; i < etapes; i++){
        p.refresh();
        printf("\n\n");
        p.affiche();
    }
    return 0;
}