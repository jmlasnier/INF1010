/********************************************
* Titre: Travail pratique #3 - Panier.cpp
* Date: 
* Auteur: 
*******************************************/

#include "Panier.h"
using namespace std;

Panier::Panier(int idClient):
	idClient_(idClient), totalAPayer_{0}
{	 
}


Panier::~Panier()
{
	contenuPanier_.clear();
}

// methodes d'accès
vector<Produit*>  Panier::obtenirContenuPanier()const
{
	return contenuPanier_;
}

int Panier::obtenirNombreContenu() const
{
	return (int)contenuPanier_.size();
}


int Panier::obtenirIdClient() const {
	return idClient_;
}

double Panier::obtenirTotalApayer() const {
	return totalAPayer_;
}

/*static_cast<ProduitAuxEncheres*>(contenuPanier_[i])*/
double Panier::calculerTotalApayer() //const enlevé
{
	for (int i = 0; i < obtenirNombreContenu(); i++)
	{
		if (contenuPanier_[i]->retournerType() == 1)
		{
			ProduitAuxEncheres * prodAuxEncheres = static_cast<ProduitAuxEncheres*> (contenuPanier_[i]);
			if (idClient_ == prodAuxEncheres->obtenirIdentifiantClient())
				totalAPayer_ = contenuPanier_[i]->obtenirPrix();
		}
	}
	return totalAPayer_;
}



void Panier::modifierTotalAPayer(double totalAPayer)
{
	totalAPayer_ = totalAPayer;
}


void Panier::modifierIdClient(int idClient) {
	idClient_ = idClient;
}




void Panier::ajouter(Produit * prod)
{
	if (prod->retournerType() == 0)
	{
		totalAPayer_ += (prod->obtenirPrix()*TAUX_TAXE);
	}
	contenuPanier_.push_back(prod);
	totalAPayer_ += prod->obtenirPrix();
}

void Panier::livrer()
{
	totalAPayer_ = 0;
	contenuPanier_.clear();
}

Produit* Panier::trouverProduitPlusCher()
{
	if (contenuPanier_.empty())
		return nullptr;

	Produit* prodPlusChere = contenuPanier_[0];
	for (unsigned int i = 1; i < contenuPanier_.size(); i++)
		if (*contenuPanier_[i] > *prodPlusChere)
			prodPlusChere = contenuPanier_[i];

	return prodPlusChere;
}

ostream & operator<<(ostream & os,  const Panier & panier)
{

	for (int i = 0; i < panier.obtenirNombreContenu(); i++)
	{
		if (panier.obtenirContenuPanier()[i]->retournerType() == 0)
		{
			os << *(static_cast<ProduitOrdinaire*>(panier.obtenirContenuPanier()[i])) << endl;
		}
		else
			os << *(static_cast<ProduitAuxEncheres*>(panier.obtenirContenuPanier()[i])) << endl;
	}


	os << "---->totalAPayer_: " << panier.obtenirTotalApayer() << endl;

	return os;
}
