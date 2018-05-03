/********************************************
* Titre: Travail pratique #1 -Rayon.h
* Date: 20 janvier 2018
* Auteur: Benoit Brizard et Laurence Rousseau
*******************************************/

#ifndef RAYON_H
#define RAYON_H
#define CAPACITE_RAYON 5

#include <string>
#include "Produit.h"
using namespace std;

class Rayon
{
public:
	// Constructeurs par defaut et par paraametres
  //  Rayon();
	Rayon(const string& categorie="inconnu");
	~Rayon();
   
	// Methodes d'acces
	string obtenirCategorie() const;
	Produit ** obtenirTousProduits() const;
    int obtenirCapaciteProduits() const;
    int obtenirNombreProduits() const;
	

	// Methodes de modification
	void modifierCategorie(const string& categorie);
    
    // autres methodes
    void ajouterProduit (Produit * produit);
    void afficher() const;
	

private:

	// Attributs prives
	string categorie_;
    Produit ** tousProduits_;
    int capaciteProduits_;
	int nombreProduits_;

};

#endif
