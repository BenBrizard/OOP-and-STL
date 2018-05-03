/********************************************
* Titre: Travail pratique #4 - Gestionnaire.h
* Date: 3 mars 2017
* Auteur: Benoit Brizard
*******************************************/
#ifndef GESTIONNAIRE_H
#define GESTIONNAIRE_H

#include <vector>
#include "Usager.h"
#include "Client.h"
#include "ClientPremium.h"
#include "ProduitAuxEncheres.h"
#include "Fournisseur.h"


using namespace std;

class Gestionnaire
{
  public:
    vector<Usager *> obtenirUsagers() const;
    void afficherLesProfils() const;
    double obtenirChiffreAffaires() const;

    void ajouterUsager(Usager *usager);
    void reinitialiser();
    void encherir(Client* client, ProduitAuxEncheres *produit, double montant) const;

  private:
    vector<Usager *> usagers_;
};

#endif
