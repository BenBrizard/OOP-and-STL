/********************************************
* Titre: Travail pratique #4 - Gestionnaire.cpp
* Date: 3 mars 2017
* Auteur: Benoit Brizard
*******************************************/
#include "Gestionnaire.h"

vector<Usager *> Gestionnaire::obtenirUsagers() const
{
    return usagers_;
}

void Gestionnaire::afficherLesProfils() const
{
	cout << "PROFILS" << endl;
		for (unsigned int i=0;i<usagers_.size();i++)
		{
			usagers_[i]->afficherProfil();			
		}
		cout << "\n";
}

double Gestionnaire::obtenirChiffreAffaires() const
{
	double total = 0;
	for (unsigned int i = 0; i < usagers_.size(); i++)
	{
		total += usagers_[i]->obtenirTotalAPayer();
	}
	return total;
}

void Gestionnaire::ajouterUsager(Usager* usager)
{
	for (unsigned int i = 0; i < usagers_.size(); i++)
	{
		if (usagers_[i] == usager)
			return;
	}
	usagers_.push_back(usager);
}

void Gestionnaire::reinitialiser()

{
	for (unsigned int i = 0; i < usagers_.size(); i++)
	{		
		usagers_[i]->reinitialiser();				
	}
}


void Gestionnaire::encherir(Client* client, ProduitAuxEncheres *produit, double montant) const
{
	if (montant > produit->obtenirPrix())
	{
		produit->mettreAJourEnchere(client, montant);
	}
}
