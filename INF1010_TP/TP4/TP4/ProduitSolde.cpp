#include "ProduitSolde.h"

ProduitSolde::ProduitSolde(int pourcentageRabais)
    : Produit(),
      Solde(pourcentageRabais)
{
}

ProduitSolde::ProduitSolde(Fournisseur *fournisseur, const string &nom,
                           int reference, double prix, int pourcentageRabais)
    : Produit(fournisseur, nom, reference, prix),
      Solde(pourcentageRabais)
{
}

double ProduitSolde::obtenirPrix() const
{
    // TODO		// problemes eventuelles entre int et double???
	return (prix_ * pourcentageRabais_)/100;
	
}

void ProduitSolde::afficher() const
{
    // TODO
	cout << "\t" << obtenirNom() << endl
		<< "\t \t reference: \t" << obtenirReference() << endl
		<< "\t \t prix: \t" << obtenirPrix() << endl
		<< "\t \t rabais: \t" << obtenirPourcentageRabais() << "%" << endl;
}
