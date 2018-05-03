/********************************************
* Titre: Travail pratique #2 - Client.cpp
* Date: 25 janvier 2018
* Auteur: Benoit Brizard et Laurence Rousseau
*******************************************/

#include "Client.h"

//constructeurs et destructeur

Client::Client(const string&  nom, const string& prenom, int identifiant, const string& codePostal, long date) :
	nom_{ nom },
	prenom_{ prenom },
	identifiant_{ identifiant },
	codePostal_{ codePostal },
	dateNaissance_{ date },
	monPanier_{ nullptr }
{
}

Client::~Client()
{
	if (monPanier_ != nullptr)
		delete monPanier_;
}

Client::Client(const Client& client)
{
	nom_ = client.nom_;
	prenom_ = client.prenom_;
	identifiant_ = client.identifiant_;
	codePostal_ = client.codePostal_;
	dateNaissance_ = client.dateNaissance_;
	if (client.monPanier_ != nullptr)
	{
		
		monPanier_ = new Panier;
		for (unsigned int i = 0; i < client.monPanier_->obtenirContenuPanier().size(); i++)
			monPanier_->ajouter(client.obtenirPanier()->obtenirContenuPanier()[i]);
	
	}
	else
		monPanier_ = client.monPanier_;

	monPanier_->modifierTotalAPayer(client.obtenirPanier()->obtenirTotalApayer());

}

/*******************************************************************/
/*               SURCHARGE DES OPÉRATEURS                          */
/*******************************************************************/

Client& Client::operator=(const Client& client)
{
	if (this != &client)
	{
		delete monPanier_;
		nom_ = client.nom_;
		prenom_ = client.prenom_;
		identifiant_ = client.identifiant_;
		codePostal_ = client.codePostal_;
		dateNaissance_ = client.dateNaissance_;
		
		monPanier_ = new Panier;
		for (unsigned int i = 0; i < client.monPanier_->obtenirContenuPanier().size(); i++)
			monPanier_->ajouter(client.monPanier_->obtenirContenuPanier()[i]);
		monPanier_->modifierTotalAPayer(client.obtenirPanier()->obtenirTotalApayer());

	}

	return *this;
		
}

bool Client::operator==(int id) const
{
	bool b = 0;
	if (identifiant_ == id)
		b = 1;
	return b;

}

bool operator==(int id, const Client& client)
{
	bool b = 0;
	if (id == client.identifiant_)
		b = 1;
	return b;
}

ostream& operator<<(ostream& os, const Client& client)
{
	if (client.monPanier_ != nullptr) {
		os << "Le panier de " << client.prenom_ << ": " << endl;

		os << *(client.monPanier_);
	}
	else {
		os << "Le panier de " << client.prenom_ << " est vide !" << endl;
	}
	return os;
}


// Methodes d'acces
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

Panier * Client::obtenirPanier() const
{
	return monPanier_;
}

// Methodes de modification
void  Client::modifierNom(const string& nom)
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

// Autres méthodes
void Client::acheter(Produit * prod)
{
	if (monPanier_ == nullptr)
		monPanier_ = new Panier;
	monPanier_->ajouter(prod);
}

void Client::livrerPanier()
{
	monPanier_->livrer();
	delete monPanier_;
	monPanier_ = nullptr;
}

