#include "ProduitAuxEncheres.h"

ProduitAuxEncheres::ProduitAuxEncheres(double prix)
    : Produit(),
      prixInitial_(prix),
      encherisseur_(nullptr)
{
}

ProduitAuxEncheres::ProduitAuxEncheres(Fournisseur *fournisseur, const string &nom,
                                       int reference, double prix)
    : Produit(fournisseur, nom, reference, prix),
      prixInitial_(prix),
      encherisseur_(nullptr)
{
}

double ProduitAuxEncheres::obtenirPrixInitial() const
{
    return prixInitial_;
}

Client *ProduitAuxEncheres::obtenirEncherisseur() const
{
    return encherisseur_;
}

void ProduitAuxEncheres::afficher() const
{
    // TODO
	cout << "\t" << obtenirNom() << endl
		<< "\t \t reference: \t" << obtenirReference() << endl
		<< "\t \t prix: \t" << obtenirPrix() << endl
		<< "\t \t prix initial: \t" << obtenirPrixInitial() << endl
		<< "\t \t enrechisseur: \t" << obtenirEncherisseur() << endl;

}

void ProduitAuxEncheres::reinitialiser()
{
	encherisseur_ = nullptr;
	modifierPrix(prixInitial_);
}

void ProduitAuxEncheres::modifierPrixInitial(double prixInitial)
{
    prixInitial_ = prixInitial;
}

void ProduitAuxEncheres::mettreAJourEnchere(Client *encherisseur, double nouveauPrix)
{
    // TODO
	if (encherisseur_ != encherisseur)
	{
		prix_ = nouveauPrix;
		encherisseur->ajouterProduit(this);
		encherisseur_->enleverProduit(this);
		encherisseur_ = encherisseur;
	}
}
