/********************************************
* Titre: Travail pratique #1 - Produit.h
* Date: 20 janvier 2018
* Auteur: Mohammed Esseddik BENYAHIA
*******************************************/

#ifndef PRODUIT_H
#define PRODUIT_H

#include <string>
#include <iostream>
using namespace std;

class Produit
{
public:
	// Constructeurs par defaut et par parametres
	Produit();
	Produit(string nom, int reference, double prix);

	// Methodes d'acces
	string obtenirNom();
	int obtenirReference();
	double obtenirPrix();

	// Methodes de modification
	void modifierNom(string nom);
	void modifierReference(int reference);
	void modifierPrix(double prix);
   
    // autres methodes
    void afficher();
   
private:

	// attributs prives
	nom_ = "outil";
	reference_ = 0;
	prix_ = 0.0;
};

#endif
