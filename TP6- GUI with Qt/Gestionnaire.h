/********************************************
* Titre: Travail pratique #6 - Gestionnaire.h
* Date: 10 avril 2018
* Auteur: Benoit Brizard
*******************************************/
#ifndef GESTIONNAIRE_H
#define GESTIONNAIRE_H

#include <vector>
#include "Usager.h"
#include "Client.h"

#include <QObject>

using namespace std;

class Gestionnaire: public QObject
{
    Q_OBJECT

  public:
    vector<Usager*> obtenirUsagers() const;
    int obtenirNombreUsager() const;
    Usager* obtenirUsager(int index);
    void ajouterUsager(Usager* usager);
    void supprimerUsager(Usager* usager);

signals:
    void usagerAjoute(Usager* usager);
    void usagerSupprime(Usager* usager);

  private:
    vector<Usager*> usagers_;
};

#endif
