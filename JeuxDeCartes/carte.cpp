#include "carte.h"

Carte::Carte()
{

}




//accesseur

void Carte::setNom(char nom){this->nom = nom;}
void Carte::setColor(Color couleur){this->couleur = couleur;}
void Carte::setImage(QString image)
{
    this->image = image;
    label.setPixmap(QPixmap(image));
    label.setScaledContents(true);
}
void Carte::setValeur(int valeur){this->valeur = valeur;}
void Carte::setSize(int w, int h){label.setFixedSize(w,h);}
char Carte::getNom(){return nom;}
Color Carte::getColor(){return couleur;}
QString Carte::getImage(){return image;}

QLabel* Carte::getLabel(){return &label;}

int Carte::getValeur(){return valeur;}
