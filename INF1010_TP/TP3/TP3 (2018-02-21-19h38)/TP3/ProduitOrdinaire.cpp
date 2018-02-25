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
	os << static_cast <Produit> (produit) << endl
		<< "estTaxable: " << produit.obtenirEstTaxable() << endl;
}

//Surcharge de l'opérateur>> qui prend un ProduitOrdinaire
istream & operator>>(istream & is, ProduitOrdinaire& produit)
{
	return is >> static_cast<Produit>(produit) >> produit.estTaxable_;
}

