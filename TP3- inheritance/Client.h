/********************************************
* Titre: Travail pratique #3 - Client.h
* Date: 13 février 2017
* Auteur: Benoit Brizard et Laurence Rousseau
*******************************************/

#ifndef CLIENT_H
#define CLIENT_H

#include <string>
#include "Usager.h"
#include "Panier.h"
#include "ProduitOrdinaire.h"
#include "ProduitAuxEncheres.h"

using namespace std;
class Client : public Usager
{

public:
	Client(const string&  nom="", const string& prenom="", int identifiant=0, const string& codePostal="", long date=0);
	~Client();
	Client(const Client& client);
	
	long obtenirDateNaissance() const;
	Panier* obtenirPanier() const;

	void modifierDateNaissance(long date);

	void acheter(ProduitOrdinaire * prod);
	void livrerPanier();
	void miserProduit(ProduitAuxEncheres* produitAuxEncheres, double montantMise);

	Client& operator=(const Client& client);
	friend ostream& operator<<(ostream& os, const Client& client) {
		os << "Client : " << static_cast<Usager>(client) << endl;
		if (client.monPanier_ == nullptr || client.monPanier_->obtenirNombreContenu() == 0)
		{
			os << "Le panier de " << client.obtenirPrenom() << " est vide !" << endl;
			return os;
		}
		else {
			os << "Le panier de " << client.obtenirPrenom() << ":" << endl;
			os << *(client.monPanier_);
			return os;
		}
	}

private:
	long dateNaissance_;
	Panier *  monPanier_;

};

#endif