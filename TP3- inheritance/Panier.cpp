/********************************************
* Titre: Travail pratique #3 - Panier.cpp
* Date: 13 février 2017
* Auteur: Benoit Brizard et Laurence Rousseau
*******************************************/

#include "Panier.h"

using namespace std;

Panier::Panier(int idClient): idClient_(idClient), totalAPayer_(0) {}


Panier::~Panier()
{
	contenuPanier_.clear();
}

// methodes d'accès
vector<Produit*>  Panier::obtenirContenuPanier()const
{
	return contenuPanier_;
}

unsigned int Panier::obtenirNombreContenu() const
{
	return contenuPanier_.size();
}


int Panier::obtenirIdClient() const {
	return idClient_;
}

double Panier::obtenirTotalApayer() const {
	return totalAPayer_;
}


double Panier::calculerTotalApayer() const
{
	double total=this->obtenirTotalApayer();
	for (unsigned int i = 0; i < this->obtenirNombreContenu(); i++)
	{
		if (contenuPanier_[i]->retournerType() == TypeProduitAuxEncheres)
			if (static_cast<ProduitAuxEncheres*>(contenuPanier_[i])->obtenirIdentifiantClient() == idClient_)
				total += static_cast<ProduitAuxEncheres*>(contenuPanier_[i])->obtenirPrixBase();
		
	}

	return total;
}



void Panier::modifierTotalAPayer(double totalAPayer)
{
	totalAPayer_ = totalAPayer;
}


void Panier::modifierIdClient(int idClient) {
	idClient_ = idClient;
}




void Panier::ajouter(Produit * prod)
{
	if (prod==nullptr)
	{
		return;
	}
	if (prod->retournerType() == TypeProduitOrdinaire)
	{
		if (static_cast<ProduitOrdinaire*>(prod)->obtenirEstTaxable())
		{
			totalAPayer_ += prod->obtenirPrix()*(1 + TAUX_TAXE);
		}
		else
			totalAPayer_ += prod->obtenirPrix();
	}


	contenuPanier_.push_back(prod);
}

void Panier::livrer()
{
	totalAPayer_ = 0;
	contenuPanier_.clear();
}

Produit* Panier::trouverProduitPlusCher()
{
	if (contenuPanier_.empty())
		return nullptr;

	Produit* prodPlusChere = contenuPanier_[0];
	for (unsigned int i = 1; i < contenuPanier_.size(); i++)
		if (*contenuPanier_[i] > *prodPlusChere)
			prodPlusChere = contenuPanier_[i];

	return prodPlusChere;
}

ostream & operator<<(ostream & os,  const Panier & panier)
{
	
	for (unsigned int i = 0; i < panier.obtenirNombreContenu(); i++)
	{
		if (panier.contenuPanier_[i]->retournerType() == TypeProduitOrdinaire)
			os<< *(static_cast<ProduitOrdinaire*>(panier.contenuPanier_[i])) << endl;
		else
			os << *(static_cast<ProduitAuxEncheres*>(panier.contenuPanier_[i])) << endl;
	}

	os << "----> total a payer : " << panier.obtenirTotalApayer() << endl;
	return os;
}
