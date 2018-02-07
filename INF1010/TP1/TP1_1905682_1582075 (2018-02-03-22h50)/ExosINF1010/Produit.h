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
	// Constructeurs par defaut et par parametres			//On utilise pas de constructeur par défaut. On utilise un constructeur
	//Produit();											//par paramètre où les attributs sont initialisés en même temps. 
	Produit(string nom, int reference, double prix);		

	// Methodes d'acces
	string obtenirNom() const;
	int obtenirReference() const;
	double obtenirPrix() const;

	// Methodes de modification
	void modifierNom(string nom);
	void modifierReference(int reference);
	void modifierPrix(double prix);
   
    // autres methodes
    void afficher();
   
private:

	// attributs prives
	string nom_;
	int reference_;
	double prix_;
};

#endif