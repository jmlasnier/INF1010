/********************************************
* Titre: Travail pratique #5 - GestionnaireProduits.h
* Date: 2 avril 2018
* Auteur: Jean-Michel Lasnier
*******************************************/
#ifndef GESTIONNAIRE_PRODUITS_H
#define GESTIONNAIRE_PRODUITS_H
#pragma once
#include "GestionnaireGenerique.h"
#include "Foncteur.h"
#include "Produit.h"
#include <vector>
#include <map>
#include <algorithm>

using namespace std;


// TODO : Créer la classe GestionnaireProduits
class GestionnaireProduits : public GestionnaireGenerique<Produit, multimap<int, Produit*>, AjouterProduit, SupprimerProduit>
{
public:
 void reinitialiserClient();
 void reinitialiserFournisseur();
 void afficher();
 double obtenirTotalAPayer();
 double obtenirTotalAPayerPremium();
 Produit* trouverProduitPlusCher();
 vector<pair<int,Produit*>> obtenirProduitsEntre(double borneInf, double borneSup);
 Produit* obtenirProduitSuivant(Produit* unProd);

};


// TODO : Créer la classe GestionnaireProduits

// TODO : Méthodes :
/*
- reinitialiserClient();
- reinitialiserFournisseur();
- afficher();
- obtenirTotalAPayer();
- obtenirTotalApayerPremium();
- trouverProduitPlusCher();
- obtenirProduitsEntre();
- obtenirProduitSuivant();
*/

#endif