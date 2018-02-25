/********************************************
* Titre: Travail pratique #3 - ProduitAuxEncheres.cpp
* Date: 
* Auteur:
*******************************************/

#include "ProduitAuxEncheres.h"


//Constructeur par param�tre et par d�faut
ProduitAuxEncheres::ProduitAuxEncheres(Fournisseur& fournisseur, const string& nom, int reference, double prix, TypeProduit type, double prixBase, int identifiant):
	Produit(fournisseur, nom, reference, prix, type),
	prixBase_{ prixBase },
	identifiantClient_{ identifiant }
{}

//M�thode d'acces pour l'attribut identifiantClient_ de la classe fille
int ProduitAuxEncheres::obtenirIdentifiantClient() const
{
	return identifiantClient_;
}
//M�thode d'acces pour l'attribut prixBase_ de la classe fille
double ProduitAuxEncheres::obtenirPrixBase() const
{
	return prixBase_;
}

//M�thode de modification pour l'attribut identifiantClient_ de la classe fille
void ProduitAuxEncheres::modifierIdentifiantClient(int identifiantClient)
{
	identifiantClient_ = identifiantClient;
}

//M�thode de modification pour l'attribut prixBase_ de la classe fille
void ProduitAuxEncheres::modifierPrixBase(double prixBase)
{
	prixBase_ = prixBase;
}


istream& operator>>(istream& is, ProduitAuxEncheres& produit)
{
	return is >> static_cast<Produit>(produit) >> produit.identifiantClient_ >> produit.prixBase_;
}

ostream& operator<<(ostream& os, const ProduitAuxEncheres& produit)
{
	return os << static_cast<Produit>(produit) << endl
				<< "identifiantClient: " << produit.obtenirIdentifiantClient()
				<< "prixBase: " << produit.obtenirPrixBase << endl;
}