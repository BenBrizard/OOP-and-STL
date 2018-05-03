/********************************************
* Titre: Travail pratique #3 - Panier.h
* Date: 13 février 2017
* Auteur: Benoit Brizard et Laurence Rousseau
*******************************************/

#ifndef PANIER_H
#define PANIER_H

#include <string>
#include <vector>
#include "Produit.h"
#include "ProduitOrdinaire.h"
#include "ProduitAuxEncheres.h"
const double TAUX_TAXE = 0.15;
using namespace std;
class Panier
{

public:
	
	Panier(int idClient=0);
	~Panier();

	vector<Produit*>  obtenirContenuPanier()const;
	unsigned int obtenirNombreContenu() const;
	double obtenirTotalApayer() const;
	double calculerTotalApayer() const;
	int obtenirIdClient() const;

	void modifierTotalAPayer(double totalAPayer);
	void modifierIdClient(int idClient);

	// TODO : Cette methode est a modifier
	void ajouter(Produit * prod);
	void livrer();

	Produit* trouverProduitPlusCher();
	friend ostream& operator<<(ostream& os, const Panier & panier);

private:
	double totalAPayer_;
	int idClient_;
	vector<Produit*> contenuPanier_;
	

};

#endif