/********************************************
* Titre: Travail pratique #5 - GestionnaireUsagers.cpp
* Date: 2 avril 2018
* Auteur: Jean-Michel Lasnier
*******************************************/
#ifndef GESTIONNAIRE_USAGERS_H
#define GESTIONNAIRE_USAGERS_H
#pragma once
#include "GestionnaireGenerique.h"
#include "Usager.h"
#include "Client.h"
#include "Foncteur.h"
#include "ProduitAuxEncheres.h"
#include <set>
using namespace std;

// TODO : Créer la classe GestionnaireUsager
class GestionnaireUsagers : public GestionnaireGenerique<Usager, set<Usager*>, AjouterUsager, SupprimerUsager>
{
public:
	//Constructeur
	GestionnaireUsagers();
//Les méthodes retrouvées de la classe Gestionnaire sont :
// TODO : La classe ressemble beaucoup à la classe Gestionnaire
	double obtenirChiffreAffaires() const;
	void encherir(Client *client, ProduitAuxEncheres *prod, double montant) const;
	void reinitialiser();
	void afficherProfils() const;
private:
};

#endif
