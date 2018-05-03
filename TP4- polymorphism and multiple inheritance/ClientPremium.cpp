/********************************************
* Titre: Travail pratique #4 - ClientPremium.cpp
* Date: 3 mars 2017
* Auteur: Benoit Brizard
*******************************************/
#include "ClientPremium.h"
#include <iostream>

ClientPremium::ClientPremium(unsigned int joursRestants)
    : Client(),
      joursRestants_(joursRestants)
{
}

ClientPremium::ClientPremium(const string &nom, const string &prenom, int identifiant,
                             const string &codePostal, unsigned int codeClient,
                             unsigned int joursRestants)
    : Client(nom, prenom, identifiant, codePostal, codeClient),
      joursRestants_(joursRestants)
{
}

unsigned int ClientPremium::obtenirJoursRestants() const
{
    return joursRestants_;
}

double ClientPremium::obtenirTotalAPayer() const
{
	double total = 0;
	for (unsigned int i = 0; i < panier_.size(); i++)
	{
		if (panier_[i]->obtenirPrix() - 5 > 0)
		{
			total += panier_[i]->obtenirPrix() - 5;
		}
	}
	return total;
}

void ClientPremium::afficherProfil() const
{
	Client::afficherProfil();
	cout << "\t\t" << "jours restants:  " << joursRestants_ << endl;

}

void ClientPremium::modifierJoursRestants(unsigned int joursRestants)
{
    joursRestants_ = joursRestants;
}
