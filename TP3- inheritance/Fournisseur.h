/********************************************
* Titre: Travail pratique #3 - Fournisseur.h
* Date: 13 février 2017
* Auteur: Benoit Brizard et Laurence Rousseau
*******************************************/

#ifndef FOURNISSEUR_H
#define FOURNISSEUR_H
const int NIVEAUX_SATISFACTION = 5;
struct Satisfaction {
	int niveaux_[NIVEAUX_SATISFACTION];
};

#include <string>
#include <vector>
#include "Usager.h"
#include "Produit.h"

using namespace std;
class Produit;
class Fournisseur : public Usager
{
public:
	Fournisseur(const string&  nom="", const string& prenom="", int identifiant=0, const string& codePostal=0);
	~Fournisseur();
	const vector<Produit*> & obtenirCatalogue() const;
	const Satisfaction& obtenirSatisfaction() const;
	
	void modifierSatisfaction(const Satisfaction& satisfaction);	
	void noter(int appreciation);

	void ajouterProduit(Produit* produit);
	void enleverProduit(Produit* produit);	
	Fournisseur& operator=(const Fournisseur& fournisseur);

	friend ostream& operator<<(ostream & os, Fournisseur& fournisseur);

private:
	Satisfaction satisfaction_;
	vector<Produit*> contenuCatalogue_;	
};

#endif