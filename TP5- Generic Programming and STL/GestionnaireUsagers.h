/********************************************
* Titre: Travail pratique #5 - GestionnaireUsagers.h
* Date: 9 mars 2018
* Auteur: Benoit Brizard
*******************************************/

#pragma once
#include "ProduitAuxEncheres.h"
#include <iterator>
#include "GestionnaireGenerique.h"
#include <utility>
#include "Foncteur.h"


using namespace std;

class Usager;
class Client;

class GestionnaireUsagers : public GestionnaireGenerique<Usager, set<Usager*>, AjouterUsager, SupprimerUsager>
{
public:

	void afficherProfils() const;
	double obtenirChiffreAffaires() const;
	void ajouterUsager(Usager *usager);
	void reinitialiser();
	void encherir(Client* client, ProduitAuxEncheres *produit, double montant) const;

};




