/********************************************
* Titre: Travail pratique #2 - Panier.cpp
* Date: 25 janvier 2018
* Auteur:Benoit Brizard et Laurence Rousseau
*******************************************/

#include "Panier.h"

//CONSTRUCTEUR ET DESTRUCTEUR
Panier::Panier() : totalAPayer_(0) {}
		

Panier::~Panier()
{
}

// methodes d'accès
const vector<Produit*>& Panier::obtenirContenuPanier() const
{	
	return contenuPanier_;	
}

double Panier::obtenirTotalApayer() const
{
	return totalAPayer_;
}

// méthodes de modification
void Panier::modifierTotalAPayer(double totalAPayer)
{
	totalAPayer_ = totalAPayer;
}


// autres méthodes
void Panier::ajouter(Produit * prod)
{
	contenuPanier_.push_back(prod);
	totalAPayer_+=prod->obtenirPrix();
}

void Panier::livrer()
{
	contenuPanier_.clear();
	totalAPayer_ = 0;
}


Produit* Panier::trouverProduitPlusCher() const
{
	Produit* temp=contenuPanier_[0];

	for (unsigned int i = 1; i <  contenuPanier_.size(); i++)
	{
		if (*contenuPanier_[i] > *temp)
			temp = contenuPanier_[i];
	}
	return temp;

}

/*******************************************************************/
/*               SURCHARGE DES OPÉRATEURS                          */
/*******************************************************************/

ostream& operator<<(ostream& os, const Panier& panier) 
{
	
	for (unsigned int i = 0; i < panier.contenuPanier_.size(); i++)
		os << *panier.contenuPanier_[i];

	os << "----> total a payer : " << panier.obtenirTotalApayer() << endl;
	return os;
}
