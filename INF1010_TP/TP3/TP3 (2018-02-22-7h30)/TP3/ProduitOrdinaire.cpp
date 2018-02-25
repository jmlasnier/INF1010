/********************************************
* Titre: Travail pratique #3 - ProduitOrdinaire.h
* Date: 
* Auteur:
*******************************************/


#include <string>
#include <iostream>
#include "ProduitOrdinaire.h"
#include "Fournisseur.h"
using namespace std;

ProduitOrdinaire::ProduitOrdinaire(Fournisseur& fournisseur,const string& nom, int reference, double prix, TypeProduit type, bool estTaxable) :
	Produit(fournisseur, nom, reference, prix, type),
	estTaxable_{ estTaxable }
{																					//le constructeur de ProduitOrdinaire hérité de Produit
}

//Méthode d'acces pour l'attribut estTaxable_ de la classe fille
bool ProduitOrdinaire::obtenirEstTaxable() const
{
	return estTaxable_;
}

//Méthode de modification pour l'attribut estTaxable_ de la classe fille
void ProduitOrdinaire::modifierEstTaxable(bool estTaxable)
{
	estTaxable_ = estTaxable;
}

//Surcharge de l'opérateur << qui affiche le ProduitOrdinaire
ostream & operator<<(ostream& os, const ProduitOrdinaire& produit)			
{
	os << "ProduitOrdinaire: "
		<< static_cast <Produit> (produit)
		<< "\t \t estTaxable: " << boolalpha << produit.obtenirEstTaxable() << endl;
	return os;
}

//Surcharge de l'opérateur>> qui prend un ProduitOrdinaire
istream & operator>>(istream & is, ProduitOrdinaire& produit)
{
	Produit produitUpcast = static_cast<Produit>(produit);
	return is >> produitUpcast >> produit.estTaxable_;
}

