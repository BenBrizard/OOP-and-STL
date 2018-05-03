/********************************************
* Titre: Travail pratique #5 - Fournisseur.cpp
* Date: 9 mars 2018
* Auteur: Benoit Brizard
*******************************************/
#include "Fournisseur.h"
#include "GestionnaireGenerique.h"
#include "Foncteur.h"
#include <iostream>

Fournisseur::Fournisseur()
    : Usager(),catalogue_(new GestionnaireProduits)
{
}

Fournisseur::Fournisseur(const string &nom, const string &prenom, int identifiant,
	const string &codePostal)
	: Usager(nom, prenom, identifiant, codePostal), catalogue_(new GestionnaireProduits)
{
}
//constructeur par copie pour ne pas copier le pointeur de Gestionnaire de produit
Fournisseur::Fournisseur(const Fournisseur & fourni): Usager(fourni.obtenirNom(), fourni.obtenirPrenom(), fourni.obtenirReference(), fourni.obtenirCodePostal())
{
	if (fourni.obtenirCatalogue() != nullptr)
	{
		catalogue_ = new GestionnaireProduits();
		multimap<int, Produit*>::iterator it = fourni.obtenirCatalogue()->obtenirConteneur().begin();
		while (it != fourni.obtenirCatalogue()->obtenirConteneur().end())
		{
			ajouterProduit(it->second);
			it++;
		}
	}

}

Fournisseur::~Fournisseur()
{ 
	delete catalogue_; 
	catalogue_ = nullptr; 
}
GestionnaireProduits* Fournisseur::obtenirCatalogue() const
{
    return catalogue_;
}

void Fournisseur::afficherCatalogue() const
{
	cout << "CATALOGUE (de " << obtenirNom() << ")"
		<< "\n";
	multimap<int, Produit*>::iterator it = catalogue_->obtenirConteneur().begin();
	multimap<int, Produit*>::iterator fin = catalogue_->obtenirConteneur().end();
	for (it; it != fin; it++)
	{
		it->second->afficher();
		cout << "\t\texemplaires : \t" << catalogue_->obtenirConteneur().count(it->first) << endl;
	}

       
    cout << endl;
}

void Fournisseur::afficher() const
{
    Usager::afficher();
	cout << "\t\tcatalogue:\t" << catalogue_->obtenirConteneur().size() << " elements" << endl;
}

void Fournisseur::reinitialiser()
{
	catalogue_->reinitialiserFournisseur();
}

void Fournisseur::ajouterProduit(Produit * produit)
{
	//on vérifie si le produit s'y trouve déjà	
	multimap<int, Produit*>::iterator fin = catalogue_->obtenirConteneur().end();
	multimap<int, Produit*>::iterator it = find_if(catalogue_->obtenirConteneur().begin(), fin, FoncteurEgal<Produit>(produit));
	if (it!= fin)
	{
		return;
	}
	//mise a jour du fournisseur
	Fournisseur *fournisseur = produit->obtenirFournisseur();
    if (fournisseur != nullptr && fournisseur != this)
        fournisseur->enleverProduit(produit);
	produit->modifierFournisseur(this);
    catalogue_->ajouter(produit);
}

void Fournisseur::enleverProduit(Produit *produit)
{
	//on vérifie si le produit s'y trouve avant de modifier son fournisseur
	multimap<int, Produit*>::iterator it = find_if(catalogue_->obtenirConteneur().begin(), catalogue_->obtenirConteneur().end(), FoncteurEgal<Produit>(produit));
	if (it != catalogue_->obtenirConteneur().end())
	{
		produit->modifierFournisseur(nullptr);
		catalogue_->supprimer(produit);
	}
}

Produit* Fournisseur::trouverProduitPlusCher() const
{
	Produit* prod = catalogue_->trouverProduitPlusCher();
	return prod;
	
}
void Fournisseur::DiminuerPrix(int pourcent) 
{
	catalogue_->pourChaqueElement(FoncteurDiminuerPourcent(pourcent));
}