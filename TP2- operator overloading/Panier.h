/********************************************
* Titre: Travail pratique #2 - Panier.h
* Date: 25 janvier 2018
* Auteur: Mohammed Esseddik BENYAHIA & Timothée CHAUVIN
*******************************************/

#pragma once

#include <string>
#include <vector>
#include "Produit.h"

using namespace std;

class Panier
{

public:
	// Constructeurs et destructeurs
	Panier();
	~Panier();

	//méthodes d'accès
	const vector<Produit*>& obtenirContenuPanier() const;
	double obtenirTotalApayer() const;

	//méthodes de modification et autres
	void modifierTotalAPayer(double totalAPayer);
	void ajouter(Produit * prod);
	void livrer();
	Produit* trouverProduitPlusCher() const;
	friend ostream& operator<<(ostream& os, const Panier& panier);

private:
	double totalAPayer_;	
	vector<Produit*> contenuPanier_;

	

};
