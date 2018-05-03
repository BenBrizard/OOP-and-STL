/********************************************
* Titre: Travail pratique #5 - Fournisseur.h
* Date: 9 mars 2018
* Auteur: Benoit Brizard
*******************************************/
#ifndef FOURNISSEUR_H
#define FOURNISSEUR_H

#include <string>
#include <vector>
#include "Usager.h"
#include "Produit.h"
#include "GestionnaireProduits.h"


using namespace std;


class Fournisseur : public Usager
{
  public:

    Fournisseur();
    Fournisseur(const string &nom, const string &prenom, int identifiant, const string &codePostal);
	Fournisseur(const Fournisseur & fourni);
	~Fournisseur(); 
    GestionnaireProduits * obtenirCatalogue() const;
    void afficherCatalogue() const;
    virtual void afficher() const;
    virtual void reinitialiser();
    virtual void ajouterProduit(Produit *produit);
    virtual void enleverProduit(Produit *produit);   
	Produit* trouverProduitPlusCher() const;
	void DiminuerPrix(int pourcent);

  private:
   GestionnaireProduits * catalogue_;
};

#endif
