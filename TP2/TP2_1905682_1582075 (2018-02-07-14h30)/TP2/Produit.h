/********************************************
* Titre: Travail pratique #2 - Produit.h
* Date: 25 janvier 2018
* Auteur: Mohammed Esseddik BENYAHIA & Timoth�e CHAUVIN
*******************************************/

#pragma once

#include <string>
#include <iostream>

using namespace std;

class Produit
{

public:
	Produit(const string& nom = "outil", int reference = 0, double prix = 0.0);

	string obtenirNom() const;
	int obtenirReference() const;
	double obtenirPrix() const;

	void modifierNom(const string& nom);
	void modifierReference(int reference);
	void modifierPrix(double prix);

	// TODO: Ajouter la surcharge de l'op�rateur >
	bool operator>(Produit const &produitCompare);
	bool estPlusGrandQue(Produit const& b) const;

	// TODO: Ajouter la surcharge de l'op�rateur <
	bool operator<(Produit const &produitCompare);
	bool estPlusPetitQue(Produit const& b) const;

	// TODO: Ajouter la surcharge de l'operateur ==
	bool operator==(Produit const& produitCompare);
	bool estEgal(Produit const& produitCompare);

	// TODO: Ajouter la surcharge de l'opérateur >>
	friend istream& operator>>(istream& i, const Produit& unProduit);

	
	
	// TODO: Cette methode doit �tre remplac�e par la surcharge de l'op�rateur <<
	friend ostream& operator<<(ostream& o, const Produit& unProduit);

	void afficher() const;
   
private:
	string nom_;
	int reference_;
    double prix_;
};
