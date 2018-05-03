/********************************************
* Titre: Travail pratique #2 - Client.h
* Date: 25 janvier 2018
* Auteur: Mohammed Esseddik BENYAHIA & Timothée CHAUVIN
*******************************************/

#pragma once

#include <string>
#include <iostream>
#include "panier.h"
using namespace std;

using namespace std;

class Client
{

public:
	// Constructeurs et destructeurs
	Client(const string&  nom="", const string& prenom="", int identifiant=0, const string& codePostal="", long date=0);
	~Client();
	Client(const Client&);

	//méthodes d'accès

	string obtenirNom() const;
	string obtenirPrenom() const;
	int obtenirIdentifiant() const;
	string obtenirCodePostal() const;
	long obtenirDateNaissance() const;
	Panier* obtenirPanier() const;

	//méthodes de modification
	void modifierNom(const string& nom);
	void modifierPrenom(const string& prenom);
	void modifierIdentifiant(int identifiant);
	void modifierCodePostal(const string& codePostal);
	void modifierDateNaissance(long date);

	//autres
	void acheter(Produit * prod);
	void livrerPanier();
	Client& operator=(const Client&);
	bool operator==(int) const;
	friend ostream& operator<<(ostream& os, const Client& client) ;
	friend bool operator==(int id, const Client&);

private:
	string nom_;
	string prenom_;
	int identifiant_;
	string codePostal_;
	long dateNaissance_;
	Panier * monPanier_;

};
