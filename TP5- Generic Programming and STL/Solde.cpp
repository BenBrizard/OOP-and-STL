/********************************************
* Titre: Travail pratique #5 - Solde.cpp
* Date: 9 mars 2018
* Auteur: Benoit Brizard
*******************************************/
#include "Solde.h"

Solde::Solde(int pourcentageRabais)
    : pourcentageRabais_(pourcentageRabais)
{
}

double Solde::obtenirPourcentageRabais() const
{
    return pourcentageRabais_;
}

void Solde::modifierPourcentageRabais(int pourcentageRabais)
{
    pourcentageRabais_ = pourcentageRabais;
}