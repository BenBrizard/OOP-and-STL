/********************************************
* Titre: Travail pratique #2 -Rayon.h
* Date: 25 janvier 2018
* Auteur: Timothée CHAUVIN
*******************************************/

#pragma once

#include <string>
#include <vector>
#include "Produit.h"

using namespace std;

class Rayon
{
	
public:

	// Constructeurs et destructeurs
	Rayon(const string& cat = "inconnu");
	~Rayon();

	//méthodes d'accès
	string obtenirCategorie() const;
	const vector<Produit*>& obtenirTousProduits() const;
	
	//méthodes de modification
	void modifierCategorie(const string& cat);

	//surcharge opérateurs
	Rayon& operator+=(Produit * produit);
	
	//autres
	int compterDoublons(const Produit& produit) const;
	friend ostream& operator<<(ostream& os, const Rayon&);

private:
	string categorie_;
	vector<Produit*> tousProduits_;
};
