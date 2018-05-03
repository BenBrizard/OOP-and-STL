/********************************************
* Titre: Travail pratique #4 - ProduitSolde.h
* Date: 3 mars 2017
* Auteur: Benoit Brizard
*******************************************/
#ifndef PRODUIT_SOLDE_H
#define PRODUIT_SOLDE_H

#include <string>
#include <iostream>
#include "Solde.h"
#include "Produit.h"

using namespace std;

class ProduitSolde : public Produit, public Solde
{
  public:
    ProduitSolde(int pourcentageRabais = 0);
    ProduitSolde(Fournisseur *fournisseur, const string &nom, int reference,
                 double prix, int pourcentageRabais = 0);
    virtual double obtenirPrix() const;
    virtual void afficher() const;
};

#endif
