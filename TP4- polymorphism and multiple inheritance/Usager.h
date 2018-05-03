/********************************************
* Titre: Travail pratique #4 - Usager.h
* Date: 3 mars 2017
* Auteur: Benoit Brizard
*******************************************/
#ifndef USAGER_H
#define USAGER_H

#include "Produit.h"
#include <iostream>
#include <string>

using namespace std;

class Usager
{
  public:
    Usager(const string &nom = "Doe", const string &prenom = "John",
           int identifiant = 0, const string &codePostal = "A1A A1A");
	virtual ~Usager() {};
    string obtenirNom() const;
    string obtenirPrenom() const;
    int obtenirIdentifiant() const;
    string obtenirCodePostal() const;
	//Cette fonction dépend vraiment du type d'usager : on la met virtuelle pure
	virtual double obtenirTotalAPayer() const=0;
    virtual void afficherProfil() const;

    void modifierNom(const string &nom);
    void modifierPrenom(const string &prenom);
    void modifierIdentifiant(int identifiant);
    void modifierCodePostal(const string &codePostal);
	virtual void reinitialiser() = 0;
	//Cette fonction dépend vraiment du type d'usager : on la met virtuelle pure
    virtual void ajouterProduit(Produit *produit)=0;
	//Cette fonction dépend vraiment du type d'usager : on la met virtuelle pure
    virtual void enleverProduit(Produit *produit)=0;

  private:
    string nom_;
    string prenom_;
    int identifiant_;
    string codePostal_;
};

#endif
