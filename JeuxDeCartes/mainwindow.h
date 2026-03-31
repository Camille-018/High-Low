#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "jeudecarte.h"



QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_piocher_clicked();
    void on_pushButton_plus_clicked();
    void on_pushButton_moins_clicked();

    void on_pushButton_demarrer_clicked();

private:
    Ui::MainWindow *ui;
    JeuDeCarte jeuDeCarte;
    QVector<Carte> table;

    Carte* carteActuelle = nullptr;
    Carte* carteSuivante = nullptr;

    int joueurActuel = 1; // celui qui pioche
    int devineur = 2;     // celui qui devine
    bool predictionPlus = false; // choix du joueur qui devine
    int scoreJ1 = 0;
    int scoreJ2 = 0;

    void afficherCarte(Carte* c);
    void majAffichage();
    void jouerTour();
    void viderTable();
    void reinitialiserPartie();



    int toursMax = 5;
    int tourActuel = 0;



};
#endif // MAINWINDOW_H
