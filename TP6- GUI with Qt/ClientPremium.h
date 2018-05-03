/********************************************
* Titre: Travail pratique #6 - ClientPremium.h
* Date: 10 avril 2018
* Auteur: Benoit Brizard
*******************************************/
#ifndef CLIENT_PREMIUM_H
#define CLIENT_PREMIUM_H

#include <string>
#include "Client.h"

using namespace std;

class ClientPremium : public Client
{
  public:
    ClientPremium(unsigned int joursRestants = 0);
    ClientPremium(const string &nom, const string &prenom, int identifiant, const string &codePostal, unsigned int joursRestants);

    unsigned int obtenirJoursRestants() const;
    void modifierJoursRestants(unsigned int joursRestants);

  private:
    unsigned int joursRestants_; // avant la fin de l'abonnement
};

#endif
