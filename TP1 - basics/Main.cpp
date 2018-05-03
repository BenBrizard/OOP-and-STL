/**************************************************
* Titre: Travail pratique #1 - Main.cpp
* Date: 20 janvier 2018
* Auteur: Benoit Brizard et Laurence Rousseau
**************************************************/


#include "Produit.h"
#include "Rayon.h"
#include "client.h"
#include "panier.h"
using namespace std;

int main()
{
	cout << "________________________________________________" << endl;
	cout << "CREATION DES PRODUITS" << endl << endl;

	//1-  Creez 15 objets de classe produit
	Produit toaster("Grille-pain", 4540, 30.99);
	Produit frigo("Refrigerateur", 5504, 1299.99);
	Produit couteau("Couteau", 7812, 7.99);
	Produit sel("Saliere", 4458, 14.67);
	Produit mixer("Malaxeur", 1225, 237.98);
	Produit planche("Planche a decouper", 1278, 15.49);
	Produit bike("Bicyclette", 3340, 300.99);
	Produit flute("Flute", 1832, 12.65);
	Produit micro("Micro", 2559, 45.12);
	Produit iphone("IPhone", 6666, 730.99);
	Produit parachute("Parachute", 4169, 350.62);
	Produit gourde("Gourde", 1111, 20.00);
	Produit chandail("Chandail", 4639, 15.99);
	Produit shoes("Souliers", 1234, 73.99);
	Produit cadre("Cadre", 4687, 22.56);


	/*******************************************************************/
	/*                       DEBUT DES TESTS                           */
	/*******************************************************************/
	//2-  Modifiez le nom, la référence, le prix de  troisieme objet Produit créé
    //   afficher les attributs de cet objet Produit

	
	cout << "________________________________________________" << endl;
	cout << "AFFICHAGE D'UN PRODUIT" << endl << endl;
	couteau.modifierNom("Ouvre-boite");
	couteau.modifierPrix(35.00);
	couteau.modifierReference(7878);
	couteau.afficher();


	//3-  Creez un objet de classe rayon à l'aide du constructeur par défaut
	cout << "________________________________________________" << endl;
	cout << "CREATION ET MODIFICATION D'UN RAYON" << endl << endl;
	Rayon rayon;
		   
	//4-  Modifiez la catégorie  du rayon
	rayon.modifierCategorie("Cuisine");
   
    // 5- Ajouter 6 produits de  voret chaoix dans le rayon créé
	cout << "________________________________________________" << endl;
	cout << "AJOUT DE PRODUITS AU RAYON" << endl << endl;
	rayon.ajouterProduit(&toaster);
	rayon.ajouterProduit(&frigo);
	rayon.ajouterProduit(&planche);
	rayon.ajouterProduit(&mixer);
	rayon.ajouterProduit(&couteau);
	rayon.ajouterProduit(&sel);
    // 6- afficher le contenu du rayon
	rayon.afficher();
	
  
	//7-  Creez un objet de classe client à l'aide du constructeur
	cout << "________________________________________________" << endl;
	cout << "CREATION  ET AFFICHAGE D'UN CLIENT" << endl << endl;
	Client bob("L'Eponge","Bob", 1849948, "H3S1S3", 199010);
	//8-  afficher l'etat des attributs du client
	cout << "Le client se nomme " << bob.obtenirPrenom() << " " << bob.obtenirNom() << ". Son identifiant est " << bob.obtenirIdentifiant() <<"."<< endl;
	cout << "Son code postal est " << bob.obtenirCodePostal() << " et sa date de naissance est (AAAA/MM/) : " << bob.obtenirDateNaissance() << "." << endl;
	//9-   Le client achete 9 produits
	cout << "________________________________________________" << endl;
	cout << "LE CLIENT EFFECTUE DES ACHATS" << endl << endl;
	bob.acheter(&toaster);
	bob.acheter(&bike);
	bob.acheter(&parachute);
	bob.acheter(&couteau);
	bob.acheter(&frigo);
	bob.acheter(&sel);
	bob.acheter(&gourde);
	bob.acheter(&chandail);
	bob.acheter(&shoes);


	//10- Afficher le contenu du panier du client
	bob.afficherPanier();

     //11- livrer le panier du client
	cout << "________________________________________________" << endl;
	cout << "LE CLIENT LIVRE SON PANIER" << endl << endl;
	bob.livrerPanier();
		
    
	//12- afficher le contenu du panier du client
	bob.afficherPanier();
	//13-  terminer le programme correctement

	/*******************************************************************/
	/*         LIBERATION DES RESSOURCES ALLOUEES                      */
	/*******************************************************************/

	//Les éléments alloués dynamiquement sont libérées dans les destructeurs appropriés
	//Les produits, le rayon et le client vont être détruit automatiquement à la fin du programme, car ils ne sont pas alloués dynamiquement.
	

	return 0;

}
