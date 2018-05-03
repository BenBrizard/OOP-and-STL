/********************************************
* Titre: Travail pratique #5 - GestionnaireProduits.h
* Date: 9 mars 2018
* Auteur: Benoit Brizard
*******************************************/

#pragma once

#include <utility>
#include "Produit.h"
#include "GestionnaireGenerique.h"
#include <vector>
using namespace std;

class GestionnaireProduits: public GestionnaireGenerique<Produit, multimap<int,Produit*>, AjouterProduit, SupprimerProduit>
{
public:
	
	void reinitialiserClient();
	void reinitialiserFournisseur();
	void afficher() const;
	double obtenirTotalAPayer() const;
	double obtenirTotalApayerPremium() const;
	Produit* trouverProduitPlusCher() const;
	vector<pair<int,Produit*>>  obtenirProduitsEntre(double, double) const;
	Produit* obtenirProduitSuivant(Produit*) const;

};

