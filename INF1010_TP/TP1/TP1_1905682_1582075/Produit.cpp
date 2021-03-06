#include "Produit.h"

//Constructeur par parametres avec liste d'initialisation********************************************
Produit::Produit(string nom="outil", int reference=0, double prix=0.0):nom_(nom),
	reference_(reference), prix_(prix)
{
}


//M�thodes d'acc�s aux atttributs********************************************************************
string Produit::obtenirNom() const
{
	return nom_;
}

int Produit::obtenirReference() const
{
	return reference_;
}

double Produit::obtenirPrix() const
{
	return prix_;
}


//M�thodes de modification***************************************************************************
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

//autres m�thodes************************************************************************************
void Produit::afficher()			//Sert simplement � afficher les attibuts d'un objet Produit
{
	cout << "|--------------" << endl;
	cout << "|Nom: " << nom_ << endl;
	cout << "|Reference: " << reference_ << endl;
	cout << "|Prix: " << prix_ << endl;
	cout << "|--------------" << endl;
}
