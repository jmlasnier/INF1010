/********************************************
* Titre: Travail pratique #3 - ProduitAuxEncheres.cpp
* Date: 
* Auteur:
*******************************************/

#include "ProduitAuxEncheres.h"


//Constructeur par paramètre et par défaut
ProduitAuxEncheres::ProduitAuxEncheres(Fournisseur& fournisseur, const string& nom, int reference, double prix, TypeProduit type, double prixBase, int identifiant):
	Produit(fournisseur, nom, reference, prix, type),
	prixBase_{ prixBase },
	identifiantClient_{ identifiant }
{
	prixBase_ = obtenirPrix();
}

//Méthode d'acces pour l'attribut identifiantClient_ de la classe fille
int ProduitAuxEncheres::obtenirIdentifiantClient() const
{
	return identifiantClient_;
}
//Méthode d'acces pour l'attribut prixBase_ de la classe fille
double ProduitAuxEncheres::obtenirPrixBase() const
{
	return prixBase_;
}

//Méthode de modification pour l'attribut identifiantClient_ de la classe fille
void ProduitAuxEncheres::modifierIdentifiantClient(int identifiantClient)
{
	identifiantClient_ = identifiantClient;
}

//Méthode de modification pour l'attribut prixBase_ de la classe fille
void ProduitAuxEncheres::modifierPrixBase(double prixBase)
{
	prixBase_ = prixBase;
}


istream& operator>>(istream& is, ProduitAuxEncheres& produit)
{
	Produit produitUpcast = static_cast<Produit>(produit);

	/*return is >> static_cast<Produit>(produit) >> produit.identifiantClient_ >> produit.prixBase_;*/
	return is >> produitUpcast >> produit.identifiantClient_ >> produit.prixBase_;
}

ostream& operator<<(ostream& os, const ProduitAuxEncheres& produit)
{
	os << "ProduitAuxEncheres: "
		<< static_cast<Produit>(produit)
		<< "\t \t prixBase: " << produit.obtenirPrixBase() << endl
		<< "\t \t identifiantClient: " << produit.obtenirIdentifiantClient() << endl;
	
	return os;
}