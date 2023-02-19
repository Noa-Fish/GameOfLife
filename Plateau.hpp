#ifndef PLATEAU_HPP
#define PLATEAU_HPP


class Plateau
{
private:
    int largeur;
    int longueur;
    int * cellule;
    bool tore;

public:
    Plateau();
    Plateau(int largeur , int longueur,bool tore );
    Plateau(Plateau &p);
    int GetLargeur();
    int GetLongueur();
    int GetTore();
    void SetTore(bool tore);
    void SetLargeur(int largeur);
    void SetLongueur(int longueur);
    void SetCelluleDamier();
    void SetCelluleRandom();
    void SetCelluleVide();
    void SetCelluleListe(int * liste);
    void SetCelluleRemplie();
    void SetCellule(int largeur , int longueur,int status);
    int GetCellule(int largeur ,int longueur);
    int GetNbVoisin(int larg,int longu);
    void refresh();
    void affiche();
    ~Plateau();
};

#endif //PLATEAU_HPP