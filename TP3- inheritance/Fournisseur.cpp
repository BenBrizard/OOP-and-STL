/********************************************
* Titre: Travail pratique #3 - Fournisseur.cpp
* Date: 13 février 2017
* Auteur: Benoit Brizard et Laurence Rousseau
*******************************************/
#include "Fournisseur.h"

Fournisseur::Fournisseur(const string&  nom, const string& prenom, int identifiant, const string& codePostal) :
	Usager(nom, prenom, identifiant, codePostal) 
{	
	for(int i =0; i<NIVEAUX_SATISFACTION; i++)
		satisfaction_.niveaux_[i] = 0;
}

Fournisseur::~Fournisseur()
{
	contenuCatalogue_.clear();
}
const vector<Produit*>& Fournisseur::obtenirCatalogue() const
{
	return contenuCatalogue_;
}


const Satisfaction & Fournisseur::obtenirSatisfaction() const
{
	return satisfaction_;
}

void Fournisseur::modifierSatisfaction(const Satisfaction& satisfaction)
{
	for (int i = 0; i < NIVEAUX_SATISFACTION; i++)
		satisfaction_.niveaux_[i] = satisfaction.niveaux_[i];
}

void Fournisseur::noter(int appreciation)
{
	satisfaction_.niveaux_[appreciation]++;
}

void Fournisseur::ajouterProduit(Produit* produit)
{
	contenuCatalogue_.push_back(produit);
}

void Fournisseur::enleverProduit(Produit* produit)
{
	for (unsigned int i = 0; i < contenuCatalogue_.size(); i++)
	{
		if (contenuCatalogue_[i] == produit)
		{
			contenuCatalogue_[i] = contenuCatalogue_[contenuCatalogue_.size() - 1];
			contenuCatalogue_.pop_back();
		}

	}
}

Fournisseur& Fournisseur::operator=(const Fournisseur& fournisseur)
{
	if (this != &fournisseur)
	{
		this->Usager::operator=(fournisseur);
		satisfaction_ = fournisseur.satisfaction_;
		contenuCatalogue_ = fournisseur.contenuCatalogue_;

	}

	return *this;
}

ostream& operator<<(ostream & os, Fournisseur& fournisseur)
{
	
	os << "Fournisseur : " << static_cast<Usager&>(fournisseur) <<endl<< "\t notes "<< 0 << ": " << fournisseur.satisfaction_.niveaux_[0]<<endl;
	for (unsigned int i = 1; i < NIVEAUX_SATISFACTION; i++)
	{
		os << "\t "<< i << ": " << fournisseur.satisfaction_.niveaux_[i] << endl;

	}

		return os;
}