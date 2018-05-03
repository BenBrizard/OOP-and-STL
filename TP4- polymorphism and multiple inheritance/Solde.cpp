/********************************************
* Titre: Travail pratique #4 - Solde..cpp
* Date: 3 mars 2017
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