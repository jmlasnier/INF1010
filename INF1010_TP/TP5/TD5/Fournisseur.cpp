#include "Fournisseur.h"
#include "GestionnaireProduits.h"
#include <iostream>

Fournisseur::Fournisseur()
    : Usager()
{
	catalogue_ = new GestionnaireProduits();
}

Fournisseur::Fournisseur(const string &nom, const string &prenom, int reference,
                         const string &codePostal)
    : Usager(nom, prenom, reference, codePostal)
{
	// TODO : À modifier
	catalogue_ = new GestionnaireProduits();
}

Fournisseur::~Fournisseur()
{
	delete catalogue_;
}
GestionnaireProduits* Fournisseur::obtenirCatalogue() const
{
	// TODO : À modifier
    return catalogue_;
}

void Fournisseur::afficherCatalogue() const
{
	// TODO : À modifier
    cout << "CATALOGUE (de " << obtenirNom() << ")"
    //     << "\n";
    //for (unsigned int i = 0; i < catalogue_.size(); i++)
    //    catalogue_[i]->afficher();
     << endl;
}

void Fournisseur::afficher() const
{
	// TODO : À modifier
    Usager::afficher();
   // cout << "\t\tcatalogue:\t" << catalogue_.size() << " elements" << endl;
}

void Fournisseur::reinitialiser()
{
	//// TODO : À modifier
	catalogue_->reinitialiserFournisseur();
 //   for (unsigned int i = 0; i < catalogue_.size(); i++)
 //       catalogue_[i]->modifierFournisseur(nullptr);
 //catalogue_.clear();
}

void Fournisseur::ajouterProduit(Produit *produit)
{
	// TODO : À modifier//DONE
	if (produit->obtenirFournisseur() != this)
	{
		produit->obtenirFournisseur()->enleverProduit(produit);

	}
	catalogue_->ajouter(produit);
}

void Fournisseur::enleverProduit(Produit *produit)
{
	// TODO : À modifier//DONE
    catalogue_->supprimer(produit);
	produit->modifierFournisseur(nullptr);
}

Produit* Fournisseur::trouverProduitPlusCher() const
{
	Produit* pointeur = new Produit;
	return pointeur;
}
void Fournisseur::DiminuerPrix(int pourcent) const
{

}