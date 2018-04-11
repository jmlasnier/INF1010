/********************************************
* Titre: Travail pratique #5 - GestionnaireProduits.cpp
* Date: 9 mars 2018
* Auteur: Ryan Hardie
*******************************************/

#include "GestionnaireProduits.h"
#include <algorithm>
#include <numeric>

void GestionnaireProduits::reinitialiserClient()
{

	conteneur_.clear();
}

void GestionnaireProduits::reinitialiserFournisseur()
{
	auto end = conteneur_.end();
	for (auto it = conteneur_.begin(); it != end; it++)
	{
		(*it).second->reinitialiser();
	}
	//Pas certain si meme chose que reinitialiserClient... mais ferait du sens
	conteneur_.clear();
}

void GestionnaireProduits::afficher()
{
	//TODO
}

double GestionnaireProduits::obtenirTotalAPayer()
{
	double total = 0.0;
	//multimap<int, Produit*>::iterator itr = conteneur_.begin();
	//for (itr; itr != conteneur_.end(); itr++)
	//{
	//	total += itr->second->obtenirPrix();
	//	}
	return total;
}

double GestionnaireProduits::obtenirTotalAPayerPremium()
{
	double total = 0.0;
	//multimap<int, Produit*>::iterator itr = conteneur_.begin();
	//for (itr; itr != conteneur_.end(); itr++)
	//{
	//	if (itr->second->obtenirPrix() >= 5)
	//	{
	//		total += itr->second->obtenirPrix() - 5;
	//	}
	//}
	return total;
}

Produit* GestionnaireProduits::trouverProduitPlusCher()
{
	Produit* prod = new Produit();
	return prod;
}

vector < pair<int, Produit*>> GestionnaireProduits::obtenirProduitsEntre(double borneInf, double borneSup)
{
	vector < pair<int, Produit*>> vec;
	return vec;
}
Produit* GestionnaireProduits::obtenirProduitSuivant(Produit* unProd)
{

	Produit* prod = new Produit();
	return prod;
}