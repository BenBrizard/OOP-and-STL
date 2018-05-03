/********************************************
* Titre: Travail pratique #5 - GestionnaireUsagers.cpp
* Date: 9 mars 2018
* Auteur: Ryan Hardie
*******************************************/

#include "GestionnaireUsagers.h"

void GestionnaireUsagers::afficherProfils() const
{
	cout << "PROFILS" << endl;
	set<Usager*>::const_iterator it = conteneur_.begin();
	for(it;it !=  conteneur_.end();it++)
	{
		(*it)->afficher();
	}
}
double GestionnaireUsagers::obtenirChiffreAffaires() const
{
	set<Usager*>::const_iterator it = conteneur_.begin();
	double total = 0;
	for (it; it != conteneur_.end(); it++)
	{
		total += (*it)->obtenirTotalAPayer();
	}
	return total;
}
void GestionnaireUsagers::ajouterUsager(Usager *usager)
{
	// Puisque le conteneur est un set, jamais on ne retrouvera plus d'une fois le même usager
	ajouter(usager);
}
void GestionnaireUsagers::reinitialiser()
{
	set<Usager*>::iterator it = conteneur_.begin();
	set<Usager*>::iterator fin = conteneur_.end();
	for_each(it, fin, [](Usager* usager) {usager->reinitialiser(); });

}
void GestionnaireUsagers::encherir(Client* client, ProduitAuxEncheres *produit, double montant) const
{
	if (montant > produit->obtenirPrix())
	{
		produit->mettreAJourEnchere(client, montant);
	}
}