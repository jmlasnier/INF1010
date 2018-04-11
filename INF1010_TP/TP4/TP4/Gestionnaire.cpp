#include "Gestionnaire.h"

vector<Usager *> Gestionnaire::obtenirUsagers() const
{
    return usagers_;
}

void Gestionnaire::afficherLesProfils() const
{
	//TODO
	cout << "PROFILS" << endl;
	for (unsigned int i = 0; i < usagers_.size(); i++)
	{
		usagers_[i]->afficherProfil();
	}
}

double Gestionnaire::obtenirChiffreAffaires() const
{
	double totalAPayer = 0.0;
	for (unsigned int i = 0; i < usagers_.size(); i++)
	{
		totalAPayer += usagers_[i]->obtenirTotalAPayer();
	}
	return totalAPayer;
}

void Gestionnaire::ajouterUsager(Usager *usager)
{
	// TODO
	bool figureDeja = false;
		for (unsigned int i = 0; i < usagers_.size(); i++)
		{
			if ( usagers_[i] == usager)
				figureDeja = true;
		}
	if (figureDeja==false)
		usagers_.push_back(usager);
}

void Gestionnaire::reinitialiser()
{
    // TODO
	for (unsigned int i = 0; i < usagers_.size(); i++)
	{
		usagers_[i]->reinitialiser();
	}
}

void Gestionnaire::encherir(Client *client, ProduitAuxEncheres *produit, double montant) const
{
    // TODO
	if (montant >= produit->obtenirPrix())
	{
		produit->mettreAJourEnchere(client, montant);
	}
}
