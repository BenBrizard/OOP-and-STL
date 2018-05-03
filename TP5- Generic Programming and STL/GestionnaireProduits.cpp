/********************************************
* Titre: Travail pratique #5 - GestionnaireProduits.cpp
* Date: 9 mars 2018
* Auteur: Ryan Hardie
*******************************************/

#include "GestionnaireProduits.h"
#include "ProduitAuxEncheres.h"
#include <functional>



void GestionnaireProduits::reinitialiserClient()
{
	multimap<int, Produit*>::iterator it = conteneur_.begin();
	multimap<int, Produit*>::iterator fin = conteneur_.end();

	while (it != fin)
	{
		if (ProduitAuxEncheres * ptr = dynamic_cast<ProduitAuxEncheres *>(it->second))
		{
			//On vérifie que le produit qu'on supprime est un produit aux enchères. Si oui, on met à jour les infos
			ptr->modifierEncherisseur(nullptr);
			ptr->modifierPrix(ptr->obtenirPrixInitial());
		}
		it++;
	}

	conteneur_.clear();
}
void GestionnaireProduits::reinitialiserFournisseur()
{
	pourChaqueElement([](const pair<int, Produit*>& p) {p.second->modifierFournisseur(nullptr); });
	conteneur_.clear();

}
void GestionnaireProduits::afficher() const
{
	multimap<int, Produit*>::const_iterator it = conteneur_.begin();
	multimap<int, Produit*>::const_iterator fin = conteneur_.end();
	for (it; it != fin; it++)
	{
		it->second->afficher();
		cout << "\t\texemplaires : \t" << conteneur_.count(it->first) << endl;
	}
	

}
double GestionnaireProduits::obtenirTotalAPayer() const
{
	multimap<int, Produit*>::const_iterator it = conteneur_.begin();
	multimap<int, Produit*>::const_iterator fin = conteneur_.end();
	double total = 0;
	for (conteneur_.begin(); it != fin; it++)
	{
		total += it->second->obtenirPrix();
	}
	return total;
}
double GestionnaireProduits::obtenirTotalApayerPremium() const
{
	multimap<int, Produit*>::const_iterator it = conteneur_.begin();
	multimap<int, Produit*>::const_iterator fin = conteneur_.end();
	double total = 0;
	for (it;  it != fin; it++)
	{
		if (it->second->obtenirPrix() - 5 > 0)
		{
			total += it->second->obtenirPrix() - 5;
		}
	}
	return total;

}
Produit* GestionnaireProduits::trouverProduitPlusCher() const
{
	multimap<int, Produit*>::const_iterator it;
	multimap<int, Produit*>::const_iterator debut = conteneur_.begin();
	multimap<int, Produit*>::const_iterator fin = conteneur_.end();
	it = max_element(debut, fin, [](const pair<int, Produit*>& gauche, const pair<int, Produit*>& droite)
	{ return gauche.second->obtenirPrix() < droite.second->obtenirPrix(); });
	if (it != fin)
		return (it->second);
	else
		return nullptr;
}
vector<pair<int, Produit*>> GestionnaireProduits::obtenirProduitsEntre(double inf, double sup) const
{
		multimap<int, Produit*>::const_iterator debut = conteneur_.begin();
		multimap<int, Produit*>::const_iterator fin = conteneur_.end();
		vector<pair<int, Produit*>> entre;
		copy_if(debut,fin, back_inserter(entre), FoncteurIntervalle(inf,sup));
		return entre;
}
Produit* GestionnaireProduits::obtenirProduitSuivant(Produit* produit) const
{
	if (produit != nullptr)
	{
		multimap<int, Produit*>::const_iterator debut = conteneur_.begin();
		multimap<int, Produit*>::const_iterator it = find_if(debut, conteneur_.end(), bind(greater<pair<int, Produit*>>(), std::placeholders::_1,
			make_pair(produit->obtenirReference(), produit)));
		if (it != conteneur_.end())
			return it->second;
		
	}
	else
		return nullptr;
}