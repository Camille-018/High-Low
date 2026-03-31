#ifndef JEUDECARTE_H
#define JEUDECARTE_H
//type de carte avec son nom, son image et sa valeur

#include "carte.h"


class JeuDeCarte
{

public:
    JeuDeCarte();
    void battre();
    Carte* donner();
    bool estVide() const;
    void reinitialiser();


private:
    //Déclaration des trois tableaux
     Carte sabot[52];//Sabot de cartes.
     QVector<Carte*> jeu, intermediaire; //notre tableau intermédiaire


};

#endif // JEUDECARTE_H
