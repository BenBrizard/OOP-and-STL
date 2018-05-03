/********************************************
* Titre: Travail pratique #4 - Fournisseur.cpp
* Date: 3 mars 2017
* Auteur: Benoit Brizard
*******************************************/
#include "Fournisseur.h"
#include <iostream>

Fournisseur::Fournisseur()
	: Usager()
{
}

Fournisseur::~Fournisseur()
{
	reinitialiser();
}

Fournisseur::Fournisseur(const string &nom, const string &prenom, int identifiant,
	const string &codePostal)
	: Usager(nom, prenom, identifiant, codePostal)
{
}

double Fournisseur::obtenirTotalAPayer() const
{
	return 0;
}
vector<Produit *> Fournisseur::obtenirCatalogue() const
{
	return catalogue_;
}

void Fournisseur::afficherCatalogue() const
{
	cout << "CATALOGUE (de " << obtenirNom() << ")"
		<< "\n";
	for (unsigned int i = 0; i < catalogue_.size(); i++)
		catalogue_[i]->afficher();
	cout << endl;
}

void Fournisseur::afficherProfil() const
{
	Usager::afficherProfil();
	cout << "\t\t" << "catalogue:       " << catalogue_.size() << " elements" << endl;
}

void Fournisseur::reinitialiser()
{
		unsigned int length = catalogue_.size();

	if (catalogue_.size() > 0)
	{
		for (unsigned i = catalogue_.size() - 1; length > i; --i)
		{
			catalogue_[i]->modifierFournisseur(nullptr);
			catalogue_.pop_back();
		}
	}
}

void Fournisseur::ajouterProduit(Produit *produit)
{
	for (unsigned int i = 0; i < catalogue_.size(); i++)
	{	//On vérifie que le produit ne se trouve pas déjà dans le catalogue
		if (catalogue_[i] == produit)
			return;
	}
	//On enlève le produit du catalogue de l'ancien fournisseur
    Fournisseur *fournisseur = produit->obtenirFournisseur();
    if (fournisseur != nullptr)
        fournisseur->enleverProduit(produit);
	produit->modifierFournisseur(this);
    catalogue_.push_back(produit);
}


void Fournisseur::enleverProduit(Produit *produit)
{
	for (unsigned int i = 0; i < catalogue_.size(); i++)
	{
		if (catalogue_[i] == produit)
		{
			produit->modifierFournisseur(nullptr);
			catalogue_[i] = catalogue_[catalogue_.size() - 1];
			catalogue_.pop_back();
			return;
		}
	}
}
