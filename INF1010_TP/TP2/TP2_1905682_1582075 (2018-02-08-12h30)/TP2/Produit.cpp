/********************************************
* Titre: Travail pratique #2 - Produit.cpp
* Date: 25 janvier 2018
* Auteur: Mohammed Esseddik BENYAHIA & Timothee CHAUVIN
*******************************************/

#include "Produit.h"

Produit::Produit(const string& nom, int reference, double prix) :
	nom_{ nom },
	reference_{ reference },
	prix_{ prix }
{ }

// Methodes d'acces
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


// Methodes de modification
void Produit::modifierNom(const string& nom)
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

/*void Produit::afficher() const
{
	cout << "nom : " << nom_ 
			  << "\t ref : " << reference_ 
			  << "\t prix : " << prix_;
}*/

//Surcharge de l'opérateur >
bool Produit::operator>(Produit const &produitCompare)
{
	return (prix_ > produitCompare.prix_);
}

//Surcharge de l'opérateur <
bool Produit::operator<(Produit const &produitCompare)
{
	return (prix_ < produitCompare.prix_);
}

//Surcharge de l'opérateur ==
bool Produit::operator==(Produit const &produitCompare)
{
	return(nom_ == produitCompare.nom_ && reference_ == produitCompare.reference_ &&
		prix_ == produitCompare.reference_);
}

//surcharge de l'opérateur >>

istream & operator >> (istream & is, Produit & produit)
{
	return is >> produit.nom_ >> produit.reference_ >> produit.prix_;
}

//Surcharge de l'opérateur <<
ostream& operator<<(ostream& os, Produit& produit)
{
	return os << produit.obtenirNom() << "/" << produit.obtenirReference() << "/" << produit.obtenirPrix() << endl;
}