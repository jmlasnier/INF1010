/********************************************
* Titre: Travail pratique #2 - Panier.cpp
* Date: 25 janvier 2018
* Auteur: Mohammed Esseddik BENYAHIA & Timothée CHAUVIN
*******************************************/

#include "Panier.h"

Panier::Panier() :	totalAPayer_{ 0 }
{
}

Panier::~Panier()
{
}

// methodes d'accès
vector <Produit *>  Panier::obtenirContenuPanier()const
{
	return contenuPanier_;
}

int Panier::obtenirNombreContenu() const
{
	return contenuPanier_.size();
}


double Panier::obtenirTotalApayer() const
{
	return totalAPayer_;
}

void Panier::modifierTotalAPayer(double totalAPayer)
{
	totalAPayer_ = totalAPayer;
}

// méthodes de modification

// autres méthodes
void Panier::ajouter(Produit* prod)		//Implementation modifié pour les vector. Sert simplement à ajouter un produit(passé en parametre)
{										//dans le panier du client et le prix total du panier est ensuite ajusté.
	contenuPanier_.push_back(prod);
	totalAPayer_ += prod->obtenirPrix();
}

void Panier::livrer()					//Vide le panier du client
{
	contenuPanier_.clear();
	totalAPayer_ = 0;
}

//Méthode trouverProduitPlusCher() qui retourne le produit le plus cher présent dans le panier
Produit * Panier::trouverProduitPlusCher()
{
	Produit* prod = nullptr;
	int nbProd = obtenirNombreContenu();

	if (nbProd != 0)
	{
		prod = contenuPanier_[0];
		for (int i = 1; i < nbProd; i++)
		{
			if (*contenuPanier_[i] > *prod)
				prod = contenuPanier_[i];
		}
	}
	return prod;
}
	// TODO: Implementez la methode
	//Surcharge de l'opérateur <<
	
ostream& operator<<(ostream& os, Panier& panier)		//Surchrage de << pour afficher les produits dans le panier
{														// ainsi que le prix total du panier du client
	for (int i = 0; i < panier.obtenirNombreContenu(); i++)
	{
		os << *panier.obtenirContenuPanier()[i];
	}
	os << "Total a payer: " <<panier.obtenirTotalApayer() << "$" << endl;
	
	return os;
}