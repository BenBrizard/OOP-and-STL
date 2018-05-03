/********************************************
* Titre: Travail pratique #4 - Client..cpp
* Date: 3 mars 2017
* Auteur: Benoit Brizard
*******************************************/
#include "Client.h"
#include <iostream>

Client::Client(unsigned int codeClient)
    : Usager(),
      codeClient_(codeClient)
{
}

Client::~Client()
{
	reinitialiser();
}

Client::Client(const string &nom, const string &prenom, int identifiant,
               const string &codePostal, unsigned int codeClient)
    : Usager(nom, prenom, identifiant, codePostal),
      codeClient_(codeClient)
{
}

unsigned int Client::obtenirCodeClient() const
{
    return codeClient_;
}

vector<Produit *> Client::obtenirPanier() const
{
    return panier_;
}

double Client::obtenirTotalAPayer() const
{
	double total=0;
	for (unsigned int i = 0; i < panier_.size(); i++)
	{
		total +=panier_[i]->obtenirPrix();
	}
	return total;
}

void Client::afficherPanier() const
{
	cout << "PANIER (de " << obtenirNom() << ")"
		<< "\n";
	
	for (unsigned int i = 0; i < panier_.size(); i++)
	{
		panier_[i]->afficher();
		cout << endl;		
	}

}

void Client::afficherProfil() const
{
	Usager::afficherProfil();
	cout << "\t\t" << "code client:     " << codeClient_ << endl;
	cout << "\t\t" << "panier:          " << panier_.size() << " elements" << endl;
}

void Client::modifierCodeClient(unsigned int codeClient)
{
    codeClient_ = codeClient_;
}

void Client::enleverProduit(Produit *produit)
{
    for (unsigned int i = 0; i < panier_.size(); i++)
    {
        if (panier_[i] == produit)
        {
            panier_[i] = panier_[panier_.size() - 1];
            panier_.pop_back();
            return;
        }
    }
}

void Client::ajouterProduit(Produit *produit)
{
    for (unsigned int i = 0; i < panier_.size(); i++)
        if (panier_[i] == produit)
            return;
    panier_.push_back(produit);
}

void Client::reinitialiser()
{
		
	if (panier_.size() > 0)
	{
		
		
		for (unsigned int i =0; i < panier_.size(); i++)
		{	//Vérification du type du pointeur : on ne met à jour que si c'est un produit aux enchères
			if (ProduitAuxEncheres * ptr=dynamic_cast<ProduitAuxEncheres *>(panier_[i]))
			{
				ptr->mettreAJourEnchere(nullptr, ptr->obtenirPrixInitial());
			}
			
		}
		panier_.clear();
	}
	
	
}

