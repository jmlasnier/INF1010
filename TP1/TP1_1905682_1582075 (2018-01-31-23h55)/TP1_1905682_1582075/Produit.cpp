#include "Produit.h"

//Constructeur par d�faut
/*Produit::Produit()		///Pu besoin a cause du "merge" des constructeurs
{
	nom_ = "outil";
	reference_ = 0;
	prix_ = 0.0;
}
*/
//Constructeur par parametres AVEC LISTE D'INITIALISATION***************************************************
Produit::Produit(string nom, int reference, double prix):nom_(nom),
	reference_(reference), prix_(prix)
{
}


//M�thodes d'acc�s aux atttributs***********************************************
string Produit::obtenirNom()
{
	return nom_;
}

int Produit::obtenirReference()
{
	return reference_;
}

double Produit::obtenirPrix()
{
	return prix_;
}


//M�thodes de modification******************************************************
void Produit::modifierNom(string nom)
{
	nom_ = nom;
}

void Produit::modifierReference(int reference)
{
	reference_ = reference;
}

void Produit::modifierPrix(double prix)
{
	prix_ = prix;
}

//autres m�thodes**************************************************************
void Produit::afficher()
{
	cout << "Nom: " << nom_ << endl;
	cout << "Reference: " << reference_ << endl;
	cout << "Prix: " << prix_ << endl;
}
