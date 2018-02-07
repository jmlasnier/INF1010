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

void Produit::afficher() const
{
	cout << "nom : " << nom_ 
			  << "\t ref : " << reference_ 
			  << "\t prix : " << prix_;
}

//Surcharge de l'opérateur >
bool Produit::estPlusGrandQue(Produit const& produitCompare) const
{
	if (prix_ > produitCompare.prix_)
	{
		return true;
	}
	else
		return false;
}
bool Produit::operator>(Produit const &produitCompare)
{
	return estPlusGrandQue(produitCompare);
}

//Surcharge de l'opérateur <

bool Produit::estPlusPetitQue(Produit const& produitCompare) const
{
	if (prix_ < produitCompare.prix_)
	{
		return true;
	}
	else
		return false;
}
bool Produit::operator<(Produit const &produitCompare)
{
	return estPlusPetitQue(produitCompare);
}

//Surcharge de l'opérateur ==
bool Produit::estEgal(Produit const &produitCompare)
{
	return(nom_ == produitCompare.nom_ && reference_ == produitCompare.reference_ &&
		prix_ == produitCompare.reference_);
}
bool Produit::operator==(Produit const &produitCompare)
{
	return estEgal(produitCompare);
}

//surcharge de l'opérateur >>
istream& operator>>(istream i, const Produit& unProduit)
{
	//à vérifier!!
	return i >> unProduit.modifierNom >> unProduit.obtenirReference >> unProduit.obtenirPrix;
}


//Surcharge de l'opérateur <<
ostream& operator<<(ostream& o, const Produit& unProduit)
{
	return o << unProduit.nom_ << "/" << unProduit.reference_ << "/" << unProduit.prix_;
}