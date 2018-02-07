/********************************************
* Titre: Travail pratique #1 -Rayon.h
* Date: 20 janvier 2018
* Auteur: 
*******************************************/

#ifndef RAYON_H
#define RAYON_H

#include <string>
#include "Produit.h"
using namespace std;

class Rayon
{
public:
	// Constructeurs par defaut et par paraametres
    Rayon();
	Rayon(string cat);
   
	// Methodes d'acces
	string obtenirCategorie();
	Produit ** obtenirTousProduits();
    int obtenirCapaciteProduits();
    int obtenirNombreProduits();
	

	// Methodes de modification
	void modifierCategorie(string cat);
    
    // autres methodes
    void ajouterProduit (Produit * produit);
    void afficher();
	

private:

	// Attributs prives
	string categorie_ = "inconnu"; //pour merge les constructeurs, on peut mettre categorie_="inconnu"
    Produit ** tousProduits_=nullptr;
	int capaciteProduits_ = 0;
	int nombreProduits_ = 0;

};

#endif
