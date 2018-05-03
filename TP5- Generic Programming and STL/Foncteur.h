/********************************************
* Titre: Travail pratique #5 - Foncteur.h
* Date: 9 mars 2018
* Auteur: Benoit Brizard et Laurence Rousseau
*******************************************/

#pragma once
#include <utility>
#include <map>
#include <algorithm> 
#include <set>
#include "Usager.h"
#include "Produit.h"
using namespace std;



template<typename T>
class FoncteurEgal {
public:

	FoncteurEgal(T* t) :t_(t) {}

	bool operator()(const pair<int, T*>& p) const;

private:
	
	T* t_;		

};

class FoncteurGenerateurId {
public:
	FoncteurGenerateurId() :id_(0) {};
	int operator()() {
		return id_++;
	}
private:
	int id_;
};

class FoncteurDiminuerPourcent {
public:
	FoncteurDiminuerPourcent(int pourcent) :pourcentage_(pourcent){};
	void operator()(const pair<int, Produit*>& p) {
		p.second->modifierPrix( ((double)(100 - pourcentage_)/100)* p.second->Produit::obtenirPrix());
	}
private:
	int pourcentage_;
};

class FoncteurIntervalle {
public:
	FoncteurIntervalle(double inf, double sup) :borneInf_(inf), borneSup_(sup){};
	bool operator()(const pair<int, Produit*>& p) const {

		return (p.second->obtenirPrix() > borneInf_ && p.second->obtenirPrix() < borneSup_);
	}
private:
	double borneInf_;
	double borneSup_;
};


class AjouterProduit {
public:
	AjouterProduit(multimap<int, Produit*>& ref) : multimap_(ref) {};
	multimap<int, Produit*>& operator()(Produit *prod) {

		multimap_.insert(make_pair(prod->obtenirReference(), prod));
		return multimap_;

	}
private:

	multimap<int, Produit*>& multimap_;
	
};

class SupprimerProduit {
public:
	SupprimerProduit(multimap<int, Produit*>& ref) : multimap_(ref) {};
	multimap<int, Produit*>& operator()(Produit *prod) 
	{
	    multimap<int, Produit*>::iterator it= find_if(multimap_.begin(), multimap_.end(), FoncteurEgal<Produit>(prod));
		if (it->second == prod)
		{	
			multimap_.erase(it);
		}
		return multimap_;
	}
private:

	multimap<int, Produit*>& multimap_;

};


class AjouterUsager {
public:
	AjouterUsager(set<Usager*>& set) : set_(set) {};
	set<Usager*>& operator()(Usager * usager)
	{
		set_.insert(usager);
		return set_;
	}
private:
	set<Usager*>& set_;
};


class SupprimerUsager {
public:
	SupprimerUsager(set<Usager*>& set) : set_(set) {};
	set<Usager*>& operator()(Usager * usager)
	{
		usager->reinitialiser();
		set_.erase(usager);
		return set_;
	}
private:
	set<Usager*>& set_;
};


template<typename T>
bool FoncteurEgal<T>::operator()(const pair<int, T*>& p) const
{
	return(p.second == t_);
}