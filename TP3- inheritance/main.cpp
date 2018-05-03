/**************************************************
* Titre: Travail pratique #3 - main.cpp
* Date: 16 février 2018
* Auteur: Benoit Brizard et Laurence Rousseau
**************************************************/

#include "Fournisseur.h"
#include "ProduitOrdinaire.h"
#include "ProduitAuxEncheres.h"
#include "Client.h"
#include <string>
#include <iostream>
#include <fstream>
#include <time.h> 
using namespace std;

const int  NB_PRODUCTS = 15;

/**

*Répondez aux questions ici :
*
* 1/
* Les mots clé pour savoir si il est logique d'utiliser l'héritage est la relation "est un". Par exemple ici,
* ProduitAuxEncheres "est un" produit, de même que ProduitOrdinaire "est un" produit. Ce n'est pas la même chose que
* l'agrégation ou la composition, où l'on utilise plutôt "utilise un", "a un" ou "est fait d'un". C'est logique de faire dériver
* ces classes de produit, car on veut avoir les mêmes attributs et les mêmes méthodes de base qu'un produit. On va cependant
* utiliser les méthodes de base d'une manière un peu différente, spécifique à la classe dérivée.
*
* 2/
* 2.1 
* Dans Panier, on veut pouvoir afficher les produits qui s'y trouvent, peu importe le type de produit (différente classe).
* Cela veut dire qu'en affichant un panier, le compilateur ne sait pas d'avance quelle surcharge de l'opérateur <<
* devra  être utilisée pour afficher les différents produits. De plus, pusique les opérateurs de flux sont des méthodes 
* globales (non membres d'une classe en particulier), cela veut dire qu'on ne peut pas les appeler explicitement selon 
* l'implémentation qu'on veut. Par exemple, si on veut afficher un ProduitAuxEncheres, on ne peut pas faire
* cout.ProduitAuxEncheres::operator<<(produit_aux_encheres), car la fonction n'est pas membre. On pourrait penser de définir
* l'opérateur << comme virtuel, ce qui nous éviterait l'ambiguité de la surcharge de <<. Cependant, encore une fois, la fonction
* est globale, on ne peut pas la définir comme étant virtuelle. Vraiment, le seul moyen d'indiquer 
* au compilateur quelle surcharge de l'opérateur on veut utiliser, c'est de fournir les types conséquents en paramètres. 
* Si on veut afficher un ProduitAuxEncheres, on doit fournir un ProduitAuxEncheres en paramètre à <<. C'est pourquoi on 
* fait un static_cast : on dit au compilateur de considérer qu'un certain élément est d'un certain type (certaine classe),
* ce qui nous permet d'utiliser l'implémentation de la surcharge qu'on veut. static_cast nous permet d'éviter les ambiguités
* relatives à la surcharge des opérateurs.

* 2.2
* Il faut savoir que contenuPanier_ est déclaré comme un vecteur de Produit*. Cela veut dire que si on utilise << sur un de
* ses éléments, le compilateur prendra ces pointeurs pour des Produit et la surcharge prenant en paramètre des produit sera
* utilisée : on ne va pas afficher les infos spécifiques aux ProduitAuxEncheres ou aux ProduitOrdinaire. 
**/

int main()
{
	cout << "________________________________________________" << endl;
	cout << "CREATION DE CLIENTS ET TESTS DES METHODES" << endl << endl;
	// Creez un objet de classe client à l'aide du constructeur
	Client martine("Bellaiche", "Martine", 1111, "H2T3A6", 199004);

	// creez un objet de la classe client à l'aide du constructeur de copie
	// et modifier sonm identifiant
	Client maCopie(martine);
	
	// vérifier si les copies sont identiques;
	
	//Devrait afficher clients identiques
	if (maCopie == martine)
		cout << "clients identiques" << endl;
	else
		cout << "non Identiques " << endl;

	maCopie.modifierIdentifiant(777);
	//Devrait afficher clients non identiques
	if (maCopie == martine)
		cout << "clients identiques" << endl;
	else
		cout << "non Identiques " << endl;

	cout << "________________________________________________" << endl;
	cout << "TEST DE L'OPERATEUR = DE CLIENT" << endl << endl;
	
	Client unAutreClient("Client", "autre", 2222, "h3T3A7", 20180212);
	unAutreClient = maCopie;
	cout << unAutreClient;

	//Devrait afficher clients identiques
	if (maCopie == unAutreClient)
		cout << "clients identiques" << endl;
	else
		cout << "non Identiques " << endl;

	
	cout << "________________________________________________" << endl;
	cout << "CREATION DE FOURNISSEURS" << endl << endl;
	// Creez un fournisseur
	Fournisseur poly = Fournisseur("Ecole", "Polytechnique", 123456789, "H3T 1J4");
	Fournisseur ets = Fournisseur("Ecole", "ETS", 21, "X4S 9W3");
	// afficher le fournisseur
	cout << "________________________________________________" << endl;
	cout << "AFFICHAGE DES FOURNISSEURS" << endl << endl;
	cout << poly<< endl;
	cout << ets << endl;
	cout << "________________________________________________" << endl;
	cout << "TESTS DES METHODES" << endl << endl;
	ets = poly;
	cout << ets << endl;
	//Devrait afficher true
	cout << "Est-ce que l'ETS a comme ID 123456789 ? " << boolalpha << (123456789 == ets) << endl;
	ets.modifierNom("Concordia");
	ets.modifierIdentifiant(21);
	//Devrait afficher false
	cout << "Est-ce que l'ETS et Polytechnique sont la meme universite ? " << boolalpha << (ets == poly) << endl;

	cout << "________________________________________________" << endl;
	cout << "CREATION DE PRODUITS" << endl << endl;
	ProduitOrdinaire* produits[NB_PRODUCTS];
	double echantillonPrix[NB_PRODUCTS] =
	{ 12.56, 50.0, 34.0, 56.0, 77.0, 91.0, 21.0, 34.0, 88.0, 65.0, 42.0, 72.0, 82.0, 53.0, 68.0 };
	for (int i = 0; i < NB_PRODUCTS; i++)
		produits[i] = new ProduitOrdinaire(poly, "p" + to_string(i), i, echantillonPrix[i], TypeProduitOrdinaire, true);
	
		
	// Creez un produit aux encheres
	ProduitAuxEncheres* prodAuxEncheres = new ProduitAuxEncheres(poly, "pAuxEncheres", 20,
		100, TypeProduitAuxEncheres);
	

	cout << "________________________________________________" << endl;
	cout << "MARTINE FAIT DES EMPLETTES" << endl << endl;
	//On s'assure de générer des nombres aléatoires différents pour la note du client lors de son achat à chaque compilation
	srand(time(0));
	// Le client achete les 7 premiers porduits
	for (int i = 0; i < 7; i++)
		martine.acheter(produits[i]);


	//afficher Panier du client
	cout << martine;
	
	// afficher le fournisseur
	cout << poly;
	cout << "________________________________________________" << endl;
	cout << "MARTINE MISE 500$ AUX ENCHERES !!" << endl << endl;
	// Client mise sur le produit aux encheres 
	martine.miserProduit(prodAuxEncheres, 500);
	// afficher le produit aux enchères
	cout << *prodAuxEncheres << endl;
	cout <<"Montant du panier si Martine gagne l'enchere: "<< martine.obtenirPanier()->calculerTotalApayer()<<endl;

	cout << "________________________________________________" << endl;
	cout << "LA COPIE DE MARTINE MISE ENCORE PLUS !" << endl << endl;
	// Ma copie mise aussi  sur le produit  aux enchères
	maCopie.miserProduit(prodAuxEncheres, 555);
	// afficher le produit aux enchères
	cout << *prodAuxEncheres << endl;
	cout << "Montant du panier de Martine suite a la mise de sa copie: " << martine.obtenirPanier()->calculerTotalApayer() << endl;
	// Afficher Panier du client
	cout << martine << endl;
	// trouver le produit le plus cher du panier
	cout << " Produit le plus cher " << *martine.obtenirPanier()->trouverProduitPlusCher();
	

	// livrer le panier du client martine
	martine.livrerPanier();
	// Afficher lefournisseur
	cout << poly << endl;
		
	// Nettoyer la memoire 
	for (int i = 0; i < NB_PRODUCTS; i++) {
		delete produits[i];
	}
	delete prodAuxEncheres;
	
	return 0;
}
