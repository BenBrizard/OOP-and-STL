/********************************************
* Titre: Travail pratique #1 - Produit.h
* Date: 20 janvier 2018
* Auteur: Mohammed Esseddik BENYAHIA
*******************************************/

#ifndef PRODUIT_H
#define PRODUIT_H

#include <string>
#include <iostream>
using namespace std;

class Produit
{
public:

	// Constructeurs par defaut et par parametres fusionnés
	Produit(const string& nom= "outil", int reference=0, double prix=0);

	// Methodes d'acces
	string obtenirNom() const;
	int obtenirReference() const;
	double obtenirPrix() const;

	// Methodes de modification
	void modifierNom(const string& nom);
	void modifierReference(int reference);
	void modifierPrix(double prix);
   
    // autres methodes
    void afficher() const;
   
private:

	// attributs prives
	string nom_;
	int reference_;
    double prix_;
};

#endif
