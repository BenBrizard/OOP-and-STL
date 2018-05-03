/********************************************
* Titre: Travail pratique #4 - Fournisseur.h
* Date: 3 mars 2017
* Auteur: Benoit Brizard
*******************************************/
#ifndef FOURNISSEUR_H
#define FOURNISSEUR_H

#include <string>
#include <vector>
#include "Usager.h"
#include "Produit.h"

using namespace std;

class Fournisseur : public Usager
{
  public:
    Fournisseur();
	virtual ~Fournisseur();
    Fournisseur(const string &nom, const string &prenom, int identifiant, const string &codePostal);
	virtual double obtenirTotalAPayer() const;

    vector<Produit *> obtenirCatalogue() const;
    void afficherCatalogue() const;
	virtual void afficherProfil() const;

    virtual void reinitialiser();
	virtual void ajouterProduit(Produit *produit);
    virtual void enleverProduit(Produit *produit);

  private:
    vector<Produit *> catalogue_;
};

#endif
