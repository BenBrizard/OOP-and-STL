/********************************************
* Titre: Travail pratique #2 - Produit.cpp
* Date: 25 janvier 2018
* Auteur: Benoit Brizard et Laurence Rousseau
*******************************************/

#include "Produit.h"

//CONSTRUCTEUR ET DESTRUCTEUR
Produit::Produit(const string& nom, int reference, double prix) :
	nom_{ nom },
	reference_{ reference },
	prix_{ prix }
{ }


Produit::~Produit() {};

// Methodes d'acces
string Produit::obtenirNom() const
{
	return nom_;
}

int Produit::obtenirReference() const
{
	return reference_;
}

double Produit::obtenirPrix() const
{
	return prix_;
}

/*******************************************************************/
/*               SURCHARGE DES OPÉRATEURS                          */
/*******************************************************************/


bool Produit::operator>(const Produit& produit) const
{
	if (prix_ > produit.prix_ )
		return 1;
	else
		return 0;

}

bool Produit::operator<(const Produit& produit) const
{
	if (prix_ < produit.prix_)
		return 1;
	else
		return 0;

}

bool Produit::operator==(const Produit& produit) const
{
	if (prix_ == produit.prix_ && nom_ == produit.nom_ && reference_ == produit.reference_)
		return 1;
	else
		return 0;

}


istream& operator>>(istream& is, Produit& produit)
{
	
	std::cout << "Saisissez les attributs pour un produit : ";
	is >> produit.nom_ >> produit.reference_ >> produit.prix_;
	cout << "\n";
	return is;

}
ostream& operator<<(ostream& os, const Produit& produit)
{
	return os <<"nom : "<< produit.nom_
		<< "\t ref : " << produit.reference_
		<< "\t prix : " << produit.prix_ << endl;

}


// Methodes de modification
void Produit::modifierNom(const string& nom)
{
	nom_ = nom;
}

void Produit::modifierReference(int reference)
{
	reference_ = reference;
}

void Produit::modifierPrix(double prix)
{
	prix_ = prix;
}


