/**************************************************
* Titre: Travail pratique #2 - Main.cpp
* Date: 25 janvier 2018
* Auteur: Mohammed Esseddik BENYAHIA & Timothée CHAUVIN
**************************************************/

#include "Produit.h"
#include "Rayon.h"
#include "Client.h"
#include "Panier.h"
#include <string>
#include <iostream>

using namespace std;

#define NB_PRODUCTS 15

/**
*Répondez aux questions ici :
* 1/L'opérateur = et le constructeur par copie vont créer une "deep copie" de l'objet, ce qui signifie qu'un nouvel objet identique à l'initial sera créer avec les mêmes méthodes et attributs.
	On appelle cela un "deep copie" car, de nouvelles copies des objets utilisés en attribut sont aussi dubliqués, ce qui signifie que chaque objet auront leurs propres attributs au lieu 
	de partager les mêmes, ce qui serait un "shalow copie"
* 2/ Il est absolument nécessaire de les implanter dans la situation où une agregation à lieu. Supposons qu'on a un objet voiture qui possede des objets roues en attributs, si on veut copier la voiture,
	on veut que cette nouvelle voiture ait ses propres roues et non les roues de la voiture d'origine.
* 3/ Le constructeur par copie va créer une copie de l'objet à partir de rien. En d'autres mots, il va construire un nouvelle objet avec les même méthodes et attributs que l'objet copié. Pour l'opérateur =,
	il va plutot prendre un objet existant et va écraser les anciennes méthodes et attributs par ceux qui lui seront passé par l'objet copié. De plus, dans la situation où l'objet à gauche de l'opérateur =
	n'existerait pas encore, le constructeur par copie serait automatiquement appelé.
**/

int main()
{
	Produit* unProduit = new Produit();
	// Faire saisir à l'utilisateur les attributs du produit unProduit selon le format de la capture d'écran de l'énoncé
	cout << "Saisissez les attributs pour un produit : ";
	cin >> *unProduit;
	
	// Afficher le Produit unProduit
	cout << endl << "Le produit saisie est nom: " << *unProduit << endl;

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
	if (produits[2] < produits[1])
		cout << "true" << endl << endl;
	else
		cout << "false" << endl<< endl;
		

	// Cration d'un rayon sport
	Rayon sport;

	// Modification la catégorie  du rayon
	sport.modifierCategorie("sport");

	// Ajoutez les 10 premiers produits de dans le rayon créé
	for (int i = 0; i < 9; i++)
	{
		sport += *produits[i];
	}
	
	// Ajoutez encore une fois le produit p0 dans le rayon sport
	sport += *produits[0];

	// Affichez le contenu du rayon
	cout << "Le rayon sport: " << endl;
	cout << sport;

	// Affichez le nombre de doublons du premier produit dans le rayon sport
	cout << "Nombre de doublons du produit p0: " << sport.compterDoublons(*produits[0]) << endl << endl;

	// Creation d'un client
	Client martine("Bellaiche", "Martine", 1111, "H2T3A6", 199004);

	// Martine achète les 5 derniers porduits
	for (int i = NB_PRODUCTS-5; i < NB_PRODUCTS; i++)
	{
		martine.acheter(produits[i]);
	}
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
	cout << "Panier de paul:" << paul << endl;
	cout << "Panier de Martine: " << endl << martine << endl;

	// Afichez le produit le plus cher du panier de martine
	cout << "Le produit le plus cher que Martine ait achete est: " << endl << *martine.obtenirPanier()->trouverProduitPlusCher() << endl;
	// Terminer le programme correctement
	for (int i = 0; i < NB_PRODUCTS; i++)
	{
		delete produits[i];
	}
}
