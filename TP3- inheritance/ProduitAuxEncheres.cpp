/********************************************
* Titre: Travail pratique #3 - ProduitAuxEncheres.cpp
* Date: 13 février 2017
* Auteur: Benoit Brizard et Laurence Rousseau
*******************************************/

#include "ProduitAuxEncheres.h"

ProduitAuxEncheres::ProduitAuxEncheres(Fournisseur& fournisseur, const string& nom, int reference, double prix , TypeProduit type) :
	Produit(fournisseur, nom, reference, prix, type), prixBase_(0), identifiantClient_(0) {}

int ProduitAuxEncheres::obtenirIdentifiantClient() const
{
	return identifiantClient_;
}

double ProduitAuxEncheres::obtenirPrixBase() const
{
	return prixBase_;
}

void ProduitAuxEncheres::modifierIdentifiantClient(int identifiantClient)
{
	identifiantClient_ = identifiantClient;
}

void ProduitAuxEncheres::modifierPrixBase(double prixBase)
{
	prixBase_ = prixBase;
}


istream& operator>>(istream& is, ProduitAuxEncheres& produit)
{
	cout << "Entrer le nom, la reference, le prix, le type, le prix de base et l'identifiant du client   :" << endl;
	is >> static_cast<Produit&>(produit) >> produit.prixBase_ >> produit.identifiantClient_  ;
	return is;
}

ostream& operator<<(ostream& os, const ProduitAuxEncheres& produit)
{
	os << "Produit aux encheres " << static_cast<Produit>(produit) << endl
		<< "\t Prix de base " << produit.obtenirPrixBase() << endl
		<< "\t Identifiant Client " << produit.obtenirIdentifiantClient() << endl;
	return os;
}