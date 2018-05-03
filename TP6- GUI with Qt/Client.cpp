/********************************************
* Titre: Travail pratique #6 - Client.cpp
* Date: 10 avril 2018
* Auteur: Benoit Brizard
*******************************************/
#include "Client.h"
#include <iostream>

Client::Client()
    : Usager(), codeClient_(0)
{
}

Client::Client(const string &nom, const string &prenom, int identifiant,
               const string &codePostal)
    : Usager(nom, prenom, identifiant, codePostal), codeClient_(0)
{
}

unsigned int Client::obtenirCodeClient() const
{
    return codeClient_;
}
void Client::modifierCodeClient(unsigned int codeClient)
{
    codeClient_=codeClient;
}
