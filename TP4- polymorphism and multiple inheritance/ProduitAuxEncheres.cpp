/********************************************
* Titre: Travail pratique #4 - ProduitAuxEncheres.cpp
* Date: 3 mars 2017
* Auteur: Benoit Brizard
*******************************************/
#include "ProduitAuxEncheres.h"
#include "Client.h"

ProduitAuxEncheres::ProduitAuxEncheres(double prix)
    : Produit(),
      prixInitial_(prix),
      encherisseur_(nullptr)
{
}


ProduitAuxEncheres::ProduitAuxEncheres(Fournisseur *fournisseur, const string &nom,
                                       int reference, double prix)
    : Produit(fournisseur, nom, reference, prix),
      prixInitial_(prix),
      encherisseur_(nullptr)
{
}

double ProduitAuxEncheres::obtenirPrixInitial() const
{
    return prixInitial_;
}

Client* ProduitAuxEncheres::obtenirEncherisseur() const
{
    return encherisseur_;
}

void ProduitAuxEncheres::afficher() const
{
	Produit::afficher();
	cout << "\t\t prix initial:\t" << prixInitial_ << endl;
	cout << "\t\t encherisseur:\t" << encherisseur_->obtenirNom() << endl;

}

void ProduitAuxEncheres::modifierPrixInitial(double prixInitial)
{
    prixInitial_ = prixInitial;
}

void ProduitAuxEncheres::mettreAJourEnchere(Client* encherisseur, double nouveauPrix)
{
	if (encherisseur_ != encherisseur)
	{
		prix_ = nouveauPrix;
		if (encherisseur != nullptr)
		{
			encherisseur->ajouterProduit(this);
		}
		if (encherisseur_ != nullptr)
		{
			encherisseur_->enleverProduit(this);
		}
		encherisseur_ = encherisseur;
	}
}
