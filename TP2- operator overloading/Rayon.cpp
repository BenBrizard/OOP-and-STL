/********************************************
* Titre: Travail pratique #2 - Rayon.cpp
* Date: 25 janvier 2018
* Auteur: Benoit Brizard et Laurence Rousseau
*******************************************/

#include"Rayon.h"


//constructeur et destructeur
Rayon::Rayon(const string& cat) :
	categorie_{ cat },
	tousProduits_{ }
{
}

Rayon::~Rayon(){}

// Methodes d'acces
string Rayon::obtenirCategorie() const
{
	return categorie_;
}

const vector<Produit*>& Rayon::obtenirTousProduits() const
{
	return tousProduits_;
}


// Methodes de modification
void Rayon::modifierCategorie(const string& cat)
{
	categorie_ = cat;
}


//autre
int Rayon::compterDoublons(const Produit& produit) const 
{
	int counter = 0;
	for (unsigned int i = 0; i < tousProduits_.size(); i++)
	{
		if (tousProduits_[i]->obtenirNom() == produit.obtenirNom() && tousProduits_[i]->obtenirReference() == produit.obtenirReference() && tousProduits_[i]->obtenirPrix() == produit.obtenirPrix())
			counter++;
	}
	return counter;
}

/*******************************************************************/
/*               SURCHARGE DES OPÉRATEURS                          */
/*******************************************************************/
Rayon& Rayon::operator+=(Produit * produit)
{
	tousProduits_.push_back(produit);
	return *(this);
}



ostream& operator<<(ostream& os, const Rayon& rayon) 
{
	int pos = rayon.tousProduits_.size();
	os << "Le rayon " << rayon.categorie_ << ": " << endl;
	for (int i = 0; i < pos; i++) {
		os << "----> ";
		os<<*rayon.tousProduits_[i];
	}
	return os;
}
