#include "Plateau.hpp"
#include <iostream>
#include <random>


Plateau::Plateau(){
    this->largeur=15;
    this->longueur=15;
    this->cellule=new int[largeur*longueur];
    for (int i=0;i<(longueur*largeur);i++){
        this->cellule[i]=0;
    }
    this->tore=false;
}

Plateau::Plateau(int larg,int longu,bool tore){
    this->largeur=larg;
    this->longueur=longu;
    this->cellule=new int[largeur*longueur];
    for (int i=0;i<(longueur*largeur);i++){
        this->cellule[i]=0;
    }
    this->tore=tore;
}

Plateau::Plateau(Plateau &p){
    this->largeur=p.largeur;
    this->longueur=p.longueur;
    this->cellule=new int[largeur*longueur];
    for (int i=0;i<(longueur*largeur);i++){
        this->cellule[i]=0;
    }
}

int Plateau::GetLargeur(){
    return this->largeur;
}

int Plateau::GetLongueur(){
    return this->longueur;
}

int Plateau::GetTore(){
    return this->tore;
}

void Plateau::SetTore(bool tore){
   this->tore=tore;
}


void Plateau::SetLargeur(int larg){
   this->largeur=larg;
}

void Plateau::SetLongueur(int longu){
    this->longueur=longu;
}

void Plateau::SetCelluleDamier()
{
    for(int i=0 ; i<(this->largeur*this->longueur);i++){
        if(i%2==0){
            this->cellule[i]=1;
        }
        else{
            this->cellule[i]=0;
        }
    }
}

void Plateau::SetCelluleRandom(){
    srand(time(0));
        for(int i = 0; i < this->longueur * this->largeur; i++){
                this->cellule[i] = rand() % 2;
        }
}

void Plateau::SetCelluleVide(){
    for(int i=0 ; i<(this->largeur*this->longueur);i++){
    this->cellule[i]=0;
    }
}

void Plateau::SetCelluleRemplie(){
    for(int i=0 ; i<(this->largeur*this->longueur);i++){
    this->cellule[i]=1;
    }
}

void Plateau::SetCelluleListe(int * liste){
    for(int i=0 ; i<(this->largeur*this->longueur);i++){
    this->cellule[i]=liste[i];
    }
}

void Plateau::SetCellule(int larg,int longu , int status){
    this->cellule[(larg)+((longu)*(this->longueur))]=status;
}

int Plateau::GetCellule(int larg,int longu)
{
    if ((larg<0)){
        return 0;
    }
    if ((longu<0)){
        return 0;
    }
    if ((longu>=this->longueur)){
        return 0;
    }
    if ((larg>=this->largeur)){
        return 0;
    }

    return  this->cellule[(larg)+((longu)*(this->longueur))];
}


int Plateau::GetNbVoisin(int larg,int longu){
    int nb_voisins = 0;
    if(this->tore==true){
        for (int i = -1 ; i < 2; i++){
            for(int j = -1; j< 2; j++){
                if ((larg + i) % this->longueur + ((longu + j) % this->largeur) * this->largeur != larg + longu * this->largeur){
                    if(this->cellule[(larg + i) % this->longueur + ((longu + j) % this->largeur) * this->largeur] == 1){
                        nb_voisins = nb_voisins + 1;
                    }        
                }
            }
        }
    }
    else{
        nb_voisins += GetCellule(larg+1%(this->largeur*this->longueur), longu%(this->largeur*this->longueur));
        nb_voisins += GetCellule(larg-1%(this->largeur*this->longueur), longu%(this->largeur*this->longueur));
        nb_voisins += GetCellule(larg+1%(this->largeur*this->longueur), longu+1%(this->largeur*this->longueur));
        nb_voisins += GetCellule(larg-1%(this->largeur*this->longueur), longu+1%(this->largeur*this->longueur));
        nb_voisins += GetCellule(larg%(this->largeur*this->longueur), longu+1%(this->largeur*this->longueur));
        nb_voisins += GetCellule(larg+1%(this->largeur*this->longueur), longu-1%(this->largeur*this->longueur));
        nb_voisins += GetCellule(larg-1%(this->largeur*this->longueur), longu-1%(this->largeur*this->longueur));
        nb_voisins += GetCellule(larg%(this->largeur*this->longueur), longu-1%(this->largeur*this->longueur));
    }    
    return nb_voisins;
}

void Plateau::refresh(){
    int *clone;
    clone=new int[this->largeur*this->longueur];
    for(int larg=0;larg<this->largeur; larg++){
        for(int longu=0;longu<this->longueur; longu++){
            clone[(larg)+((longu)*(this->longueur))]=GetNbVoisin(larg,longu);
        }
    }
    for(int larg=0;larg<this->largeur; larg++){
        for(int longu=0;longu<this->longueur; longu++){
            if (clone[(larg)+((longu)*(this->longueur))]==3){
                SetCellule(larg,longu,1);
            }
            else if (clone[(larg)+((longu)*(this->longueur))]==2){
                if((GetCellule(larg,longu))==1){
                    SetCellule(larg,longu,1);
                }
                else{
                     SetCellule(larg,longu,0);
                }
            }
            else{
                SetCellule(larg,longu,0);
            }
        }
    }
    
}

void Plateau::affiche(){
    for (int i=0;i<(this->longueur*this->largeur);i++){
        if((i+1)%this->largeur==0){
            std::cout <<this->cellule[i]<< std::endl;
        }
        else{
            std::cout <<this->cellule[i];
        }
    }
    
}

Plateau::~Plateau()
{}

