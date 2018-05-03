/********************************************
* Titre: Travail pratique #5 - Client.cpp
* Date: 9 mars 2018
* Auteur: Benoit Brizard
*******************************************/
#include "Client.h"
#include "ProduitAuxEncheres.h"
#include <iostream>
#include "GestionnaireProduits.h"

Client::Client(unsigned int codeClient)
    : Usager(),
      codeClient_(codeClient), panier_(new GestionnaireProduits)
{
}
Client::~Client()
{

	delete panier_;
	panier_ = nullptr;
}
Client::Client(const string &nom, const string &prenom, int identifiant,
               const string &codePostal, unsigned int codeClient)
    : Usager(nom, prenom, identifiant, codePostal),
      codeClient_(codeClient), panier_(new GestionnaireProduits)
{
}
//constructeur par copie pour ne pas copier le pointeur de Gestionnaire de produit
Client::Client(const Client& client) : Usager(client.obtenirNom(), client.obtenirPrenom(), client.obtenirReference(), client.obtenirCodePostal()),
codeClient_(client.obtenirCodeClient())
{
	if (client.obtenirPanier() != nullptr)
	{
		panier_ = new GestionnaireProduits();
		multimap<int, Produit*>::iterator it = client.obtenirPanier()->obtenirConteneur().begin();
		while (it != client.obtenirPanier()->obtenirConteneur().end())
		{
			//si le produit est au enchere, on ne l'ajoute pas : sinon c'est comme si le client copié serait aussi l'encherisseur et
			//il y aurait alors 2 encherisseurs pour le meme produit 
		
			if (ProduitAuxEncheres * ptr = dynamic_cast<ProduitAuxEncheres *>(it->second))
			{
			}
			else
				ajouterProduit(it->second);
			it++;
		}
	}
	else
		panier_ = nullptr;
}
unsigned int Client::obtenirCodeClient() const
{
    return codeClient_;
}

GestionnaireProduits* Client::obtenirPanier() const
{

    return panier_;
}

double Client::obtenirTotalAPayer() const
{
	return panier_->obtenirTotalAPayer();
	
}

void Client::afficherPanier() const
{
	

    cout << "PANIER (de " << obtenirNom() << ")"
         << "\n";
	panier_->afficher();
	cout << endl;
}

void Client::afficher() const
{
    Usager::afficher();
	cout << "\t\tcode client:\t" << codeClient_ << endl
        << "\t\tpanier:\t\t" << panier_->obtenirConteneur().size() << " elements" << endl;
}

void Client::modifierCodeClient(unsigned int codeClient)
{
    codeClient_ = codeClient_;
}

void Client::enleverProduit(Produit *produit)
{	

	panier_->supprimer(produit);
}

void Client::ajouterProduit(Produit *produit)
{
	panier_->ajouter(produit);
}

void Client::reinitialiser()
{
	panier_->reinitialiserClient();
}

Produit* Client::trouverProduitPlusCher() const
{

	return panier_->trouverProduitPlusCher();

}
