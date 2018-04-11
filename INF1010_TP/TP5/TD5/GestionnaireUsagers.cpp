/********************************************
* Titre: Travail pratique #5 - GestionnaireUsagers.cpp
* Date: 2 avril 2018
* Auteur: Jean-Michel Lasnier
*******************************************/

#include "GestionnaireUsagers.h"

GestionnaireUsagers::GestionnaireUsagers(){}

double GestionnaireUsagers::obtenirChiffreAffaires() const
{
	return 0;
}

void GestionnaireUsagers::encherir(Client *client, ProduitAuxEncheres *prod, double montant) const
{
	if (montant > prod->obtenirPrix())
	{
		if (prod->obtenirEncherisseur() != nullptr)
		{
			prod->obtenirEncherisseur()->enleverProduit(prod);
		}
		prod->mettreAJourEnchere(client, montant);
	}
}
void GestionnaireUsagers::reinitialiser()
{

	set<Usager*>::iterator end = conteneur_.end();
	for (set<Usager*>::iterator it = conteneur_.begin(); it != end; it++)
	{
		(*it)->reinitialiser();
	}
	

	/*for (auto& usager : conteneur_)//JeffreyStyle
	{
		usager->reinitialiser();
	}*/
}
void GestionnaireUsagers::afficherProfils() const
{

}