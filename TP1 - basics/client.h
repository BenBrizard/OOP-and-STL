
//  client.h
//  Created by Martine Bellaiche on 18-01-22.
//  Copyright © 2018 Martine Bellaiche. All rights reserved.
//

#ifndef CLIENT_H
#define CLIENT_H
#define CAPACITE_CLIENT 4
#include <string>
#include "panier.h"
#include <iostream>
using namespace std;
class Client
{
public:
	//Constructeur par paramètres
    Client (const string&  nom,  const string& prenom, int identifiant, const string& codePostal, long date);
	~Client();

    // methodes d'acces    
    string obtenirNom() const;
    string obtenirPrenom() const;
    int obtenirIdentifiant() const;
    string obtenirCodePostal() const;
    long obtenirDateNaissance() const;
 

    // methodes de modification
    void modifierNom(const string& nom) ;
    void modifierPrenom(const string& prenom) ;
    void modifierIdentifiant(int identifiant) ;
    void modifierCodePostal(const string& codePostal);
    void modifierDateNaissance(long date);
	
    
    // autres méthodes
    void acheter (Produit * produit);
    void afficherPanier() const;
    void livrerPanier();
    
    
private:
    
    string nom_;
    string prenom_;
    int identifiant_;
    string codePostal_;
    long dateNaissance_;
    Panier *  monPanier_;
};
#endif /* client_h */
