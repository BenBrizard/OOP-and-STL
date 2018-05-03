/********************************************
* Titre: Travail pratique #5 - GestionnaireGenerique.h
* Date: 9 mars 2018
* Auteur: Benoit Brizard
*******************************************/

#pragma once
#include <iterator>
#include "Foncteur.h"
using namespace std;

template<typename T, typename C, typename A, typename S>
class GestionnaireGenerique
{
public:

	void ajouter(T* t) {
		A pred(conteneur_);
		conteneur_ = pred(t);
	}
	void supprimer(T* t) {
		S pred(conteneur_);
		pred(t);
	}
	C& obtenirConteneur() {
		//méthode non-constante car on renvoie une reference à l'attribut
		return conteneur_;
	}
	template<typename Predicate>
	void pourChaqueElement(Predicate p)
	{
		C::iterator debut = conteneur_.begin();
		C::iterator fin = conteneur_.end();
		for_each(debut, fin, p);

	}
	
protected:

	C conteneur_;
};
