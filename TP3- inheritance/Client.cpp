/********************************************
* Titre: Travail pratique #3 - Client.cpp
* Date: 13 février 2017
* Auteur: Benoit Brizard et Laurence Rousseau
*******************************************/
#include "Client.h"
#include "Fournisseur.h"
#include <string>
 



Client::Client(const string&  nom, const string& prenom, int identifiant, const string& codePostal, long date):
	Usager(nom, prenom, identifiant, codePostal), dateNaissance_(date),monPanier_(nullptr)
{}

Client::Client(const Client & client) :
	Usager(client.obtenirNom(), client.obtenirPrenom(), client.obtenirIdentifiant(), client.obtenirCodePostal()),
	dateNaissance_{ client.dateNaissance_ }
{
	if (client.monPanier_ == nullptr)
		monPanier_ = nullptr;
	else {
		monPanier_ = new Panier(client.obtenirIdentifiant());
		for (unsigned int i = 0; i < client.monPanier_->obtenirNombreContenu(); i++) {
			monPanier_->ajouter(client.monPanier_->obtenirContenuPanier()[i]);
		}
		int idClient = this->obtenirIdentifiant();
		monPanier_->modifierTotalAPayer(client.monPanier_->obtenirTotalApayer());
	}
}



Client::~Client()
{
	if (monPanier_ != nullptr)
		delete monPanier_;
}

// Methodes d'acces
long Client::obtenirDateNaissance() const
{
	return dateNaissance_;
}

Panier * Client::obtenirPanier() const
{
	return monPanier_;
}


// Methodes de modification
void Client::modifierDateNaissance(long date)
{
	dateNaissance_ = date;
}

// Autres méthodes
void Client::acheter(ProduitOrdinaire * prod)
{
	if (monPanier_ == nullptr)
		monPanier_ = new Panier(this->obtenirIdentifiant());
	monPanier_->ajouter(prod);
	// obtenir une note aléatoire
	// faire la mise à jour de la satisfaction au fournisseur	
	if(prod!=nullptr)
		prod->obtenirFournisseur().noter(rand() % 5);
}

void Client::livrerPanier()
{
	if (monPanier_ != nullptr)
	{
		monPanier_->livrer();
		delete monPanier_;
		monPanier_ = nullptr;
	}
}


void Client::miserProduit(ProduitAuxEncheres* produitAuxEncheres, double montantMise)
{
	if(produitAuxEncheres==nullptr)
	{
		return;
	}
	if (montantMise > produitAuxEncheres->obtenirPrixBase())
	{
		produitAuxEncheres->modifierPrixBase(montantMise);
		produitAuxEncheres->modifierIdentifiantClient(this->obtenirIdentifiant());
	}
	
	if (monPanier_ == nullptr)
		monPanier_ = new Panier(this->obtenirIdentifiant());
	
	monPanier_->ajouter(produitAuxEncheres);
	
}

Client & Client::operator=(const Client & client)
{
	if (this != &client) 
	{
		this->Usager::operator=(client);
		dateNaissance_ = client.dateNaissance_;
		if (client.monPanier_ != nullptr) 
		{
			delete monPanier_;
			monPanier_ = new Panier(obtenirIdentifiant());
			for (unsigned int i = 0; i < client.monPanier_->obtenirNombreContenu(); i++) 
			{
				monPanier_->ajouter(client.monPanier_->obtenirContenuPanier()[i]);
			}
		}

		else
			monPanier_ = nullptr;
	}
	return *this;
}

/*
ostream & operator<<(ostream & os, const Client & client)
{
	os << "Client : " << static_cast<Usager>(client) << endl;
	if (client.monPanier_ == nullptr || client.monPanier_->obtenirNombreContenu() == 0)
	{
		os << "Le panier de " << client.obtenirPrenom() << " est vide !" << endl;
		return os;
	}
	else{
	os << "Le panier de " << client.obtenirPrenom() << ":" << endl;
		os << *(client.monPanier_);
		return os;
	}
}
*/
