/********************************************
* Titre: Travail pratique #6 - Fournisseur.cpp
* Date: 10 avril 2018
* Auteur: Benoit Brizard
*******************************************/
#include "Fournisseur.h"
#include <iostream>

Fournisseur::Fournisseur()
    : Usager()
{
}

Fournisseur::Fournisseur(const string &nom, const string &prenom, int identifiant,
                         const string &codePostal)
    : Usager(nom, prenom, identifiant, codePostal)
{
}
