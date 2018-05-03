/**************************************************
* Titre: Travail pratique #1 - Produit.cpp
* Date: 20 janvier 2018
* Auteur: Benoit Brizard et Laurence Rousseau
**************************************************/
#include <stdio.h>
#include "Produit.h"

Produit::Produit(const string& nom, int reference, double prix):nom_(nom), reference_(reference), prix_(prix) {};

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

// autres methodes
void Produit::afficher() const
{
	std::cout << nom_ << ". Prix : " << prix_ << "$. Numero de reference : " << reference_<< std::endl;
}
