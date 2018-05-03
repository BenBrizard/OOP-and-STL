/**************************************************
* Titre: Travail pratique #1 - client.cpp
* Date: 20 janvier 2018
* Auteur: Benoit Brizard et Laurence Rousseau
**************************************************/
#include <stdio.h>
#include "client.h"



Client::~Client()
{
	if(monPanier_!=nullptr)
		delete monPanier_;
}

Client::Client(const string&  nom, const string& prenom, int identifiant, const string& codePostal, long date) : nom_(nom), prenom_(prenom),
identifiant_(identifiant), codePostal_(codePostal), dateNaissance_(date), monPanier_(nullptr) {};

string Client::obtenirNom() const
{
	return nom_;
}
string Client::obtenirPrenom() const
{
	return prenom_;
}
int Client::obtenirIdentifiant() const
{
	return identifiant_;
}
string Client::obtenirCodePostal() const
{
	return codePostal_;
}
long Client::obtenirDateNaissance() const
{
	return dateNaissance_;
}




// methodes de modification
void Client::modifierNom(const string& nom)
{
	nom_ = nom;
}
void Client::modifierPrenom(const string& prenom)
{
	prenom_ = prenom;
}
void Client::modifierIdentifiant(int identifiant)
{
	identifiant_ = identifiant;
}
void Client::modifierCodePostal(const string& codePostal)
{
	codePostal_ = codePostal;
}
void Client::modifierDateNaissance(long date)
{
	dateNaissance_ = date;
}

// autres méthodes
void Client::acheter(Produit * produit)
{
	if (monPanier_ == nullptr)
		monPanier_ = new Panier(CAPACITE_CLIENT);
	monPanier_->ajouter(produit);
	
}


void Client::afficherPanier() const
{	
	//On s'assure de ne pas faire d'erreur, si le pointeur est nul on veut afficher que le panier du client est vide.
	//Son panier en fait n'est alors pas encore initialisé.
	if (monPanier_ == nullptr)
		cout << "Ce panier est vide." << endl;
	else if (monPanier_->obtenirNombreContenu() > 0)
			monPanier_->afficher();

}

void Client::livrerPanier()
{
	delete monPanier_;
	monPanier_ = nullptr;
}