/**************************************************
* Titre: Travail pratique #2 - Main.cpp
* Date: 25 janvier 2018
* Auteur: Benoit Brizard et Laurence Rousseau
**************************************************/

#include "Produit.h"
#include "Rayon.h"
#include "client.h"
#include "panier.h"
#include <string>
#include <iostream>

using namespace std;

#define NB_PRODUCTS 15

/**
*Répondez aux questions ici :
1. Quelle est l’utilité de l’opérateur = et du constructeur par copie? 

	L'opérateur = sert à modifier les attributs d'un objet pour les attributs d'un autre objet déjà créé. Cela peut
	servir à écraser les caractéristiques d'un objet pour les remplacer à celles d'un autre.

	Le constructeur par copie, c'est vraiment un constructeur. Il sert à créer un objet en initialisant tous ses attributs
	avec les attributs d'un objet déjà créé. C'est utile lorsqu'on veut créer un objet identique à un autre.
	Par exemple, si on veut modifier un objet mais garder une copie intacte, le constructeur par copie est 
	tout désigné. C'est surtout utile si on veut créer un objet avec les attributs d'un autre.

2. Dans quel cas est-il absolument nécessaire de les implémenter?

	On veut implémenter le constructeur par copie lorsqu'on veut éviter le "shallow copy" d'un pointeur par
	le constructeur par copie de défaut. En effet, on peut préférer copier l'objet qui est pointé plutôt que
	d'avoir 2 pointeurs pointant au même endroit (peut entraîner des erreurs, car si un des objets est détruit,
	le pointeur peut être "deleted" et l'autre objet verra son pointeur pointer vers une adresse invalide).

	C'est exactement le même principe pour l'opérateur =. Cet opérateur ne fait qu'attribuer les attributs d'un objet
	à un autre. Ainsi, 2 objets peuvent avoir un pointeur pointant au même endroit. Il faut implémenter la surcharge
	de l'opérateur = si on veut éviter cette situation.

3. Qu’est-ce qui différencie l’opérateur = du constructeur par copie?

	L'opérateur = affecte les caractéristiques d'un objet existant à un autre objet existant. Il faut donc que les deux 
	objets soient déjà créés pour parler d'affectation. 

	Le constructeur par copie lui crée un objet avec les mêmes attributs qu'un objet déjà existant. On crée
	donc un nouvel objet avec le constructeur par copie.

**/

int main()
{
	Produit* unProduit = new Produit();

	// Faire saisir à l'utilisateur les attributs du produit unProduit selon le format de la capture d'écran de l'énoncé
	cin >> *unProduit;
	
	// Afficher le Produit unProduit
	cout << "Le produit saisi est " << *unProduit << endl;

	// Creation de 15 produits
	
	Produit * produits[NB_PRODUCTS];
	double echantillonPrix[NB_PRODUCTS] = { 12.56, 50.0, 34.0, 56.0, 77.0, 91.0, 21.0, 34.0, 88.0, 65.0, 42.0, 72.0, 82.0, 53.0, 68.0 };

	for (int i = 0; i < NB_PRODUCTS; i++)
		produits[i] = new Produit("p" + to_string(i), i, echantillonPrix[i]);

	// Modification du nom, de la référence, du prix du troisieme produit créé
	produits[2]->modifierNom("p20");
	produits[2]->modifierPrix(100);
	produits[2]->modifierReference(31);

	cout << "Le produit p20 est moins cher que le produit p1 ? ";
	// Comparer le prix du produit p20 et p1 à l'aide de la surcharge d'un operateur
	cout << boolalpha << (*produits[2] < *produits[1]) << endl<< endl;

		
	// Cration d'un rayon sport
	Rayon sport;

	// Modification la catégorie  du rayon
	sport.modifierCategorie("sport");

	// Ajoutez les 10 premiers produits de dans le rayon créé
	for (int i = 0; i < 10; i++)
		sport += produits[i];

	// Ajoutez encore une fois le produit p0 dans le rayon sport
	sport += produits[0];
	

	// Affichez le contenu du rayon
	cout << sport;

	// Affichez le nombre de doublons du premier produit dans le rayon sport
	cout << "Nombre de doublons du produit p0 : " << sport.compterDoublons(*produits[0]) << endl<< endl;

	// Creation d'un client
	Client martine("Bellaiche", "Martine", 1111, "H2T3A6", 199004);

	// Martine achète les 5 derniers porduits
	for (int i = NB_PRODUCTS -1; i > 9; i--)
		martine.acheter(produits[i]);

	// Copie du client martine dans un autre client puis changment de son nom, prenom et identifiant pour "Paul Martin 689"
	Client paul = Client(martine);
	paul.modifierNom("Martin");
	paul.modifierPrenom("Paul");
	paul.modifierIdentifiant(689);

	cout << "Test identifiant paul: " << boolalpha << (689 == paul) << endl << endl;

	// Paul achete le produit p0
	paul.acheter(produits[0]);

	// Livrez le panier de Paul
	paul.livrerPanier();

	// Affichez le panier de Paul et de Martine
	cout << paul << endl << endl;
	cout << martine << endl << endl;

	// Afichez le produit le plus cher du panier de martine
	cout << "Le produit le plus cher que Martine ait achete est :" << endl;
	cout << *martine.obtenirPanier()->trouverProduitPlusCher() << endl;

	// Terminer le programme correctement
	
	for (int i = 0; i < NB_PRODUCTS; i++)
		delete produits[i];
	delete unProduit;

	return 0;

}
