/********************************************
* Titre: Travail pratique #4 - Client.h
* Date: 3 mars 2017
* Auteur: Benoit Brizard
*******************************************/

#ifndef CLIENT_H
#define CLIENT_H

#include <string>
#include <vector>
#include "Usager.h"
#include "Produit.h"
#include "ProduitAuxEncheres.h"
#include "ProduitSolde.h"

using namespace std;

class Client : public Usager
{
  public:
    Client(unsigned int codeClient = 0);
    Client(const string &nom, const string &prenom, int identifiant, const string &codePostal, unsigned int codeClient = 0);
	~Client();
    unsigned int obtenirCodeClient() const;
    vector<Produit *> obtenirPanier() const;
    virtual double obtenirTotalAPayer() const;
    void afficherPanier() const;
    virtual void afficherProfil() const;

    void modifierCodeClient(unsigned int codeClient);
	virtual void enleverProduit(Produit *produit);
	virtual void ajouterProduit(Produit *produit);
	virtual void reinitialiser();
  
  protected:
    vector<Produit *> panier_;

  private:
    unsigned int codeClient_;
};

#endif
