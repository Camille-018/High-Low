#ifndef CARTE_H
#define CARTE_H
#include <QLabel>

enum Color
{
    pique,
    coeur,
    carreau,
    trefle
};

class Carte
{
    public:
        Carte();

        //accesseur

        void setNom(char nom);
        void setColor(Color couleur);
        void setImage(QString image);
        void setValeur(int valeur);
        void setSize(int w, int h);

        char getNom();
        Color getColor();
        QString getImage();
        QLabel* getLabel();
        int getValeur();

    private:
        char nom;
        Color couleur;
        QString image;
        QLabel label;
        int valeur;

};


#endif // CARTE_H
