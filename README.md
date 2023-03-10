# Jeu de la Vie

Le Jeu de la vie est un automate cellulaire imaginé par John Horton Conway en 1970. Malgré des règles très simples, il est Turing-complet. C'est un jeu de simulation au sens mathématique. Ce programme implémente donc le Jeu de la Vie en C++.

## Installation

1. Cloner le dépôt Git :

    git clone  https://github.com/Noa-Fish/GameOfLife.git

2. Compiler le programme :
    
          g++ -c Main.cpp
          gcc Main.cpp -o Main.exe 

3. Exécuter le programme :

           gcc c -o Main.exe Main.cpp


## Utilisation

Le programme affiche une grille de cellules qui évoluent en fonction de règles simples. Les cellules peuvent être dans un état "vivant" ou "mort". À chaque itération, l'état de chaque cellule est mis à jour en fonction des états de ses voisins :

1. Une cellule morte avec exactement trois voisines vivantes devient une cellule vivante.

2. Une cellule vivante avec deux ou trois voisines vivantes reste vivante.

3. Dans tous les autres cas, la cellule meurt ou reste morte.

##Crédit

Ce programme a été réalisé par Noa Watel.
