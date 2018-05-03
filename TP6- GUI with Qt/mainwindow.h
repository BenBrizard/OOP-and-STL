/********************************************
* Titre: Travail pratique #6 - MainWindow.h
* Date: 10 avril 2018
* Auteur: Benoit Brizard
*******************************************/
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QListWidget>
#include <QLineEdit>
#include <QRadioButton>
#include <QPushButton>

#include <list>
#include "Gestionnaire.h"
#include "Usager.h"

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:

    explicit MainWindow(QWidget *parent = 0);
    explicit MainWindow(Gestionnaire* gestionnaire, QWidget *parent = 0);
    ~MainWindow();

public slots:

    void filtrerListe(int);
    void selectionnerUsager(QListWidgetItem*);
    void nettoyerVue();
    void changerTypeUsager(int);
    void supprimerTousLesUsagers();
    void supprimerUsagerSelectionne();
    void ajouterUsager();
    void usagerAEteAjoute(Usager*);
    void usagerAEteSupprime(Usager*);

private:
    // Fonctions Locales

    void setup();
    void setConnections();
    void setMenu();
    void setUI();
    void afficherMessage(QString msg);
    void chargerUsagers();
    bool filtrerMasque(Usager* usager);

    // Attributs Locals

    Gestionnaire* gestionnaire_;

    //Il s’agit de la liste des usagers qui seront créés à partir de la vue.
    vector<Usager*> ajoute_;
    int indexCourantDuFiltre_;

    // Attributs Locals QObjects

    //Liste contenant les usagers qui sont affichés sur le panneau de gauche.
    QListWidget* listUsager;
    QLineEdit* editeurNom;
    QLineEdit* editeurPrenom;
    QLineEdit* editeurIdentifiant;
    QLineEdit* editeurCodePostal;
    QLineEdit* editeurJoursRestants;

    //Représente les boutons des trois types d’usager (Client, ClientPremium, Fournisseur)
    list<QRadioButton*> boutonRadioTypeUsager;
    QPushButton* boutonAjouter;
    QPushButton* boutonSupprimer;
};

#endif // MAINWINDOW_H
