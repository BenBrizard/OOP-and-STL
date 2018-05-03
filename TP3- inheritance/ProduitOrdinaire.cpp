/********************************************
* Titre: Travail pratique #3 - ProduitOrdinaire.cpp
* Date: 13 février 2017
* Auteur: Benoit Brizard et Laurence Rousseau
*******************************************/

#include <string>
#include <iostream>
#include "ProduitOrdinaire.h"
#include "Fournisseur.h"
using namespace std;

ProduitOrdinaire::ProduitOrdinaire(Fournisseur& fournisseur,
	const string& nom, int reference,
	double prix, TypeProduit type, bool estTaxable) : Produit(fournisseur, nom, reference, prix, type), estTaxable_(estTaxable){}

bool ProduitOrdinaire::obtenirEstTaxable() const
{
	return estTaxable_;
}

void ProduitOrdinaire::modifierEstTaxable(bool estTaxable)
{
	estTaxable_ = estTaxable;
}

ostream& operator<<(ostream& os, const ProduitOrdinaire& produit)
{
	os << "ProduitOrdinaire " << static_cast<Produit>(produit)<<endl
	<<"\t est Taxable : " << boolalpha << produit.obtenirEstTaxable() << endl;
	return os;
}



istream& operator>>(istream& is, ProduitOrdinaire& produit)
{
	cout << "Entrer produit.nom_ >> produit.reference_ >> produit.prix_ >> produit.type_ >>  produit.estTaxable_ " << endl;
	is  >> static_cast<Produit&>(produit) >> produit.estTaxable_;

	return is;
}