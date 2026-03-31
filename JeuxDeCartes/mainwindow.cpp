#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QDebug"
#include <QTimer>
#include <QMessageBox>



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    jeuDeCarte.battre();

    // bloque tout sauf le choix du nombre de tours / demarrer
    ui->pushButton_piocher->setEnabled(false);
    ui->pushButton_plus->setEnabled(false);
    ui->pushButton_moins->setEnabled(false);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_piocher_clicked()
{

    // Bloque le bouton piocher pour éviter plusieurs clics
    ui->pushButton_piocher->setEnabled(false);
    ui->pushButton_plus->setEnabled(true);
    ui->pushButton_moins->setEnabled(true);

    viderTable();

    carteActuelle = jeuDeCarte.donner();
    if (!carteActuelle) return; // sécurité si plus de cartes

    QLabel* label = carteActuelle->getLabel();
    label->setParent(nullptr);  // s’assure qu’il n’a plus d’ancien parent
    label->show();              // le rend visible
    ui->layoutTable->addWidget(label);

    ui->labelJoueur->setText(QString("C’est au joueur %1 de deviner ! (cliquez sur + OU -)").arg(devineur));

}


void MainWindow::on_pushButton_plus_clicked()
{
    predictionPlus = true;
    ui->pushButton_plus->setEnabled(false);
    ui->pushButton_moins->setEnabled(false);
    ui->pushButton_piocher->setEnabled(true);
    jouerTour();
}


void MainWindow::on_pushButton_moins_clicked()
{
    predictionPlus = false;
    ui->pushButton_plus->setEnabled(false);
    ui->pushButton_moins->setEnabled(false);
    ui->pushButton_piocher->setEnabled(true);
    jouerTour();
}

void MainWindow::jouerTour()
{
    // Empêche les clics multiples
    ui->pushButton_plus->setEnabled(false);
    ui->pushButton_moins->setEnabled(false);

    // Tire la carte suivante
    carteSuivante = jeuDeCarte.donner();
    if (!carteSuivante) return; // sécurité si plus de cartes

    // Affiche la carte sur la table
    QLabel* labelSuiv = carteSuivante->getLabel();
    labelSuiv->setParent(nullptr);
    labelSuiv->show();
    ui->layoutTable->addWidget(labelSuiv);

    // Compare les valeurs
    bool gagne = false;
    QString resultatTour;
    if ((predictionPlus && carteSuivante->getValeur() > carteActuelle->getValeur()) ||
        (!predictionPlus && carteSuivante->getValeur() < carteActuelle->getValeur())) {
        gagne = true;
    }

    // Mise à jour des scores
    if (gagne) {
        if (devineur == 1) scoreJ1++;
        else scoreJ2++;
    }

    // Affiche le résultat du tour
    ui->labelJoueur->setText(resultatTour);
    tourActuel++;
    // Mise à jour du tour
    majAffichage();

    // Vérifie fin de partie
    if (tourActuel >= toursMax || jeuDeCarte.estVide()) {
        // petit délai pour afficher le score avant la boîte de dialogue
        QTimer::singleShot(200, this, [this]() {
            QString message;
            if (scoreJ1 > scoreJ2) message = "Fin de partie ! Joueur 1 gagne !";
            else if (scoreJ2 > scoreJ1) message = "Fin de partie ! Joueur 2 gagne !";
            else message = "Fin de partie ! Égalité !";

            message += QString("\n\nScore final :\nJ1 = %1\nJ2 = %2\n\nRejouer ?")
                           .arg(scoreJ1).arg(scoreJ2);

            auto reply = QMessageBox::question(this, "Fin de partie", message,
                                               QMessageBox::Yes | QMessageBox::No);

            if (reply == QMessageBox::Yes) {
                reinitialiserPartie();
            } else {
                close();
            }
        });
        return;
    }

    // Continue la partie après un délai
    QTimer::singleShot(1500, this, [this]() {
        viderTable();

        // Réinitialisation des cartes (évite crash)
        carteActuelle = nullptr;
        carteSuivante = nullptr;

        // Inverse les rôles
        int tmp = joueurActuel;
        joueurActuel = devineur;
        devineur = tmp;

        ui->labelJoueur->setText(QString("Piocher une carte"));

        //Réactive les bons boutons
        ui->pushButton_plus->setEnabled(false);
        ui->pushButton_moins->setEnabled(false);
        ui->pushButton_piocher->setEnabled(true);

    });
}



void MainWindow::majAffichage()
{
    ui->labelTours->setText(QString("Tour: %1 / %2").arg(tourActuel).arg(toursMax)); //tours actuel/tours max
    ui->labelScoreJ1->setText(QString("Joueur 1 : %1").arg(scoreJ1));
    ui->labelScoreJ2->setText(QString("Joueur 2 : %1").arg(scoreJ2));
    ui->labelJoueur->setText(QString("Tour du joueur %1").arg(joueurActuel));
}

void MainWindow::viderTable()

{
    QLayoutItem* item;
    while ((item = ui->layoutTable->takeAt(0)) != nullptr) {
        QWidget* w = item->widget();
        if (w) {
            w->hide();          // cache d’abord le widget
            w->setParent(nullptr);// détache du layout
            // ne pas delete ici si c’est un QLabel provenant du sabot statique
        }
        delete item;
    }
}

void MainWindow::reinitialiserPartie()
{

    jeuDeCarte.reinitialiser();
    ui->labelJoueur->setText("Demarrer la partie! (changer le nombre de tours)");

    scoreJ1 = 0;
    scoreJ2 = 0;
    tourActuel = 0;
    joueurActuel = 1;
    devineur = 2;
    carteActuelle = nullptr;
    carteSuivante = nullptr;

    viderTable();

    ui->labelScoreJ1->setText("Joueur 1 : 0");
    ui->labelScoreJ2->setText("Joueur 2 : 0");
    ui->labelTours->setText(QString("Tour: 0 / %1").arg(toursMax));


    //desactive piocher/+/-; active demarrer/nombre tours
    ui->pushButton_piocher->setEnabled(false);
    ui->pushButton_plus->setEnabled(false);
    ui->pushButton_moins->setEnabled(false);
    ui->pushButton_demarrer->setEnabled(true);
    ui->spinBoxTours->setEnabled(true);
}



void MainWindow::on_pushButton_demarrer_clicked()
{
    // Récupère le nombre de tours
    toursMax = ui->spinBoxTours->value();

    // Initialise la partie
    reinitialiserPartie();

    ui->labelJoueur->setText("Piocher une carte");

    // Active  le bouton piocher
    ui->pushButton_piocher->setEnabled(true);
    // Désactive le bouton/spinbox
    ui->pushButton_demarrer->setEnabled(false);
    ui->spinBoxTours->setEnabled(false);

}

