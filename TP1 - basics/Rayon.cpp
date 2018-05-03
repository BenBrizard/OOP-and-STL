/**************************************************
* Titre: Travail pratique #1 - Rayon.cpp
* Date: 20 janvier 2018
* Auteur: Benoit Brizard et Laurence Rousseau
**************************************************/
#include <stdio.h>
#include "Rayon.h"

// Constructeurs par defaut et par parametres (ils sont fusionnés : voir Rayon.h)

Rayon::Rayon(const string& categorie): categorie_(categorie), tousProduits_(nullptr), capaciteProduits_(0), nombreProduits_(0) {};

Rayon::~Rayon()
{
	delete[] tousProduits_;
	tousProduits_ = nullptr;
}

// Methodes d'acces
string Rayon::obtenirCategorie() const
{
	return categorie_;
}
Produit ** Rayon::obtenirTousProduits() const
{
	return tousProduits_;
}
int Rayon::obtenirCapaciteProduits() const
{
	return capaciteProduits_;
}
int Rayon::obtenirNombreProduits() const
{
	return nombreProduits_;
}


// Methodes de modification
void Rayon::modifierCategorie(const string& categorie)
{
	categorie_ = categorie;
}

// autres methodes
void Rayon::ajouterProduit(Produit * produit)
{

	if (nombreProduits_ == capaciteProduits_)
	{
		if (capaciteProduits_ == 0)
		{	
			//Si jamais la capacité est nulle, on initialise le tableau
			tousProduits_ = new Produit*[CAPACITE_RAYON];
			capaciteProduits_ = CAPACITE_RAYON;
		}
		else
		{
			//Si la capacité est atteinte, on crée un tableau plus large
			Produit** tableauElargi = new Produit*[CAPACITE_RAYON + capaciteProduits_];


			//On insère les éléments se trouvant déjà dans le rayon
			for (int i = 0; i < nombreProduits_; i++)
			{
				tableauElargi[i] = tousProduits_[i];
			}

			//On libère l'espace alloué à l'ancien rayon
			delete[] tousProduits_;
			tousProduits_ = tableauElargi;
			capaciteProduits_ = CAPACITE_RAYON + capaciteProduits_;

		}

	}
		
		tousProduits_[nombreProduits_] = produit;
		nombreProduits_++;
			
}


void Rayon::afficher() const
{
	std::cout << "Affichage du rayon en cours." << std::endl;
	std::cout << "Le rayon a comme categorie : " << categorie_ << "." << endl;
		
	if (nombreProduits_ > 0)
	{
		std::cout <<"Ce rayon a une capacite de " << capaciteProduits_ << " produits et contient actuellement " << nombreProduits_<< " produits."<< std::endl;
	
		std::cout << "Les items contenus dans le rayon sont :" << std::endl;
		for (int i = 0; i < nombreProduits_; i++)
		{
			tousProduits_[i]->afficher();
		}
	}
	else
		std::cout << "Le rayon ne contient actuellement aucun produit."<< std::endl;
}

