/**************************************************
* Titre: Travail pratique #1 - panier.cpp
* Date: 20 janvier 2018
* Auteur: Benoit Brizard et Laurence Rousseau
**************************************************/
#include <stdio.h>
#include "panier.h"
#include <iostream>

Panier::Panier(int capacite) :contenuPanier_(new Produit*[capacite]), nombreContenu_(0), capaciteContenu_(capacite),
totalAPayer_(0) {};



Panier::~Panier()
{
	if (contenuPanier_ != nullptr)
	{
		delete[] contenuPanier_;
		contenuPanier_ = nullptr;
	}
}
// methodes d'acc�s
Produit **  Panier::obtenirContenuPanier() const
{
	return contenuPanier_;
}
int Panier::obtenirNombreContenu() const
{
	return nombreContenu_;
}
double Panier::obtenirTotalApayer() const
{
	return totalAPayer_;
}



// autres m�thodes
void Panier::ajouter(Produit* produit)
{
	if (nombreContenu_ == capaciteContenu_)
	{
		if (capaciteContenu_ == 0)
		{
			 //Si jamais la capacit� est nulle, on l'initialise � un pour ne pas faire d'erreur
			contenuPanier_ = new Produit*[1];
			capaciteContenu_ = 1;
		}
		else
		{	
			//On cr�e un nouveau tableau 2 fois plus gros
			Produit** tableauElargi = new Produit*[2 * capaciteContenu_];
			
			//On ins�re les �l�ments se trouvant d�j� dans le panier
			for (int i = 0; i < nombreContenu_; i++)
			{
				tableauElargi[i] = contenuPanier_[i];

			}

			//On lib�re l'espace allou� � l'ancien panier
			delete[] contenuPanier_;
			contenuPanier_ = tableauElargi;
			capaciteContenu_ = 2 * capaciteContenu_;
		}
	}

	//On ajoute le produit au panier ayant maintenant une plus grande capacit�
	contenuPanier_[nombreContenu_] = produit;
	nombreContenu_++;
	totalAPayer_ += produit->obtenirPrix();

}


void Panier::livrer()
{
	if (contenuPanier_ != nullptr)
	{
		delete[] contenuPanier_;
		contenuPanier_ = nullptr;
		totalAPayer_ = 0;
		nombreContenu_ = 0;
		capaciteContenu_ = 0;
	}
}



void Panier::afficher() const
{
	std::cout << "Affichage du panier en cours." << std::endl;
	std::cout << "Le panier contient " << nombreContenu_ << " items et a une capacite de " << capaciteContenu_ << " items." << std::endl;
	if (nombreContenu_ > 0)
	{
		std::cout << "Les items contenus dans le panier sont :" << std::endl;
		for (int i = 0; i < nombreContenu_; i++)
		{
			contenuPanier_[i]->afficher();
		}
	}
	std::cout << "Le cout total des items du panier est de " << totalAPayer_ << "$." << std::endl;

}