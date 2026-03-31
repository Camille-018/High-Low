#include "jeudecarte.h"
#include <ctime>
#include <cstdlib>

JeuDeCarte::JeuDeCarte()
{
    srand(time(nullptr)); //aleatoire
    //cette procedure affecte les propriétés des 52 carte. Une partie du code a été enlevé
   char rang[13]={'1','2','3','4','5','6','7','8','9','X','V','D','R'}; // X=10, V=Valet, D=Dame, R=Roi

   for(int i=0;i<13;i++) //couleur trefle
   {
       sabot[i].setNom(rang[i%13]);
       sabot[i].setColor(trefle);
       sabot[i].setImage(":/Jeu_de_cartes/"+QString::number(i+1)+".png");
       sabot[i].setValeur(i%13+1);
       sabot[i].setSize(100,145);


   }
   for(int i=13;i<26;i++) //couleur carreau
   {
       sabot[i].setNom(rang[i%13]);
       sabot[i].setColor(carreau);
       sabot[i].setImage(":/Jeu_de_cartes/"+QString::number(i+1)+".png");
       sabot[i].setValeur(i%13+1);
       sabot[i].setSize(100,145);
       //sabot[i].label->adjustSize();
   }
   for(int i=26;i<39;i++) //couleur coeur
   {
       sabot[i].setNom(rang[i%13]);
       sabot[i].setColor(coeur);
       sabot[i].setImage(":/Jeu_de_cartes/"+QString::number(i+1)+".png");
       sabot[i].setValeur(i%13+1);
       sabot[i].setSize(100,145);
   }
   for(int i=39;i<52;i++) //couleur pique
   {
       sabot[i].setNom(rang[i%13]);
       sabot[i].setColor(pique);
       sabot[i].setImage(":/Jeu_de_cartes/"+QString::number(i+1)+".png");
       sabot[i].setValeur(i%13+1);
       sabot[i].setSize(100,145);
   }

}

void JeuDeCarte::battre()
{


    intermediaire.clear();
    for (int i=0;i<52;i++) intermediaire.append(&sabot[i]);
    jeu.clear();
     unsigned short aleatoire;
     while (intermediaire.size()>0)  //tant que le tableau dynamique n'est pas vide

        {
          aleatoire=rand()%intermediaire.size(); //génère un nombre entre 0 et la taille du tableau
          jeu.append(intermediaire[aleatoire]); //on place la valeur aléatoire
          intermediaire.removeAt(aleatoire); //on supprime du tableau intermédiaire la valeur

        }

        qDebug() << " Jeu battu " << jeu.size();

}

Carte* JeuDeCarte::donner()
{
        if (jeu.isEmpty()) return nullptr;//sabot vide
        Carte* c= jeu.first();
        QString log = "carte donnée : " + QString(c->getNom()) + " ";
        switch(c->getColor())
        {
            case pique: log += "pique"; break;
            case coeur: log += "coeur"; break;
            case carreau: log += "carreau"; break;
            case trefle: log += "trefle"; break;
        }
        log += " " + c->getImage() + " valeur : " + QString::number(c->getValeur());
        qDebug() << log;
        jeu.removeFirst();
        return c;
}

bool JeuDeCarte::estVide() const {
    return jeu.isEmpty();
}


void JeuDeCarte::reinitialiser()
{
    // on efface les valeurs des tableaux
    intermediaire.clear();
    jeu.clear();
    //garde le sabot, juste on melange
    battre();
    qDebug() << "Jeu réinitialisé et battu";
}
