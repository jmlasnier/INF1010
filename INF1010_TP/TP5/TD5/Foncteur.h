/********************************************
* Titre: Travail pratique #5 - Foncteur.h
* Date: 1er avril 2018
* Auteur: Jean-Michel Lasnier
*******************************************/

#pragma once
#include <map>
#include <algorithm>
#include <set>
#include "Usager.h"
#include "Produit.h"

// TODO : Créer le FoncteurEgal
template <typename T>
class FoncteurEgal
{
public:
	FoncteurEgal(T* t):
		t_(t){}
	//*********************************TO*REVIEW********************************
	bool operator()(T* paire)
	{
		return t_ == paire;
	}
	bool operator()(pair<int, T*> paire) 
	{ 
		return t_ == paire.second;
	}	
	//*********************************TO*REVIEW********************************
private:
	T* t_;
};

// TODO : Créer le FoncteurGenerateurId
class FoncteurGenerateurId
{
public:
	FoncteurGenerateurId(): 
		id_{0}{}

	unsigned int operator()() 
	{
		return id_++;
	}
private:
	unsigned int id_;
};


// TODO : Créer le FoncteurDiminuerPourcent
class FoncteurDiminuerPourcent
{
public:
	FoncteurDiminuerPourcent(int pourcentage) : 
		pourcentage_(pourcentage){}
	//Calule le nouveau prix du Produit de la pair passé en paramètre et le modifie
	void operator()(pair<int, Produit*> paire) //seul retour qui fonctionne est void.... is it right?
	{
		double reduction = (100 - pourcentage_)/100.0;
		paire.second->modifierPrix(paire.second->obtenirPrix()*reduction);
	}
private:
	int pourcentage_;
};


// TODO : Créer le FoncteurIntervalle
class FoncteurIntervalle
{
public:
	FoncteurIntervalle(double borneInf, double borneSup) :
		borneInf_(borneInf),
		borneSup_(borneSup){}
	//Retourne vrai si le prix du Produit est compris entre les bornes
	bool operator() (pair<int, Produit*> paire) 
	{
		double prixPaire = paire.second->obtenirPrix();
		return (prixPaire > borneInf_ && prixPaire < borneSup_);
	}
private:
	double borneInf_;
	double borneSup_;
};


// TODO : Créer le Foncteur AjouterProduit
class AjouterProduit
{
public:
	AjouterProduit(multimap<int, Produit*>& multi) : 
		multimap_(multi){}

	multimap<int, Produit*>& operator()(Produit* prod)
	{
		multimap_.insert(pair<int, Produit*>(prod->obtenirReference(), prod));
		return multimap_;
	}
private:
	multimap<int, Produit*> &multimap_;
};

// TODO : Créer le Foncteur SupprimerProduit
class SupprimerProduit 
{
public:
	SupprimerProduit(multimap<int,Produit*>& m):
		multimap_(m){}

	multimap<int, Produit*>& operator()(Produit* prod) 
	{
		//Trouver le produit dans le multimap
		auto end = multimap_.end();
		auto prodTrouve = find_if(multimap_.begin(), end, FoncteurEgal<Produit>(prod));
		//Supprimer le produit s'il a été trouvé
		if (prodTrouve != end)
		{
			multimap_.erase(prodTrouve);
		}
		return multimap_;
	}
private:
	multimap<int, Produit*> &multimap_;
};


//TODO : Créer le Foncteur AjouterUsager
class AjouterUsager
{
public:
	AjouterUsager(set<Usager*>& set) :
		set_(set){}

	set<Usager*>& operator() (Usager* usager)
	{
		set_.insert(usager);
		return set_;
	}
private:
set<Usager*> &set_;

};

class SupprimerUsager
{
public:
	SupprimerUsager(set<Usager*>& set):
		set_(set){}

	set<Usager*>& operator()(Usager* usager)
	{
		//Trouver l'usager dans le set
		auto end = set_.end();
		auto usagerTouve = find_if(set_.begin(), end, FoncteurEgal<Usager>(usager));
		//Supprimer l'usager s'il a été trouvé
		if (usagerTouve != end)
		{
			set_.erase(usagerTouve);
		}
		return set_;
	}
private:
	set<Usager*> &set_;
};