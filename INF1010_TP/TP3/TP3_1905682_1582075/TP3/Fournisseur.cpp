/********************************************
* Titre: Travail pratique #3 - Fournisseur.cpp
* Date: 
* Auteur:
*******************************************/
#include "Fournisseur.h"

//Constructeur par param�tres et par d�faut de la classe Fournisseur
Fournisseur::Fournisseur(const string&  nom, const string& prenom, int identifiant, const string& codePostal) :
	Usager(nom, prenom, identifiant, codePostal)
{
	for (int i = 0; i < NIVEAUX_SATISFACTION; i++)
	{
		satisfaction_.niveaux_[i] = 0;
	}
}

//M�thode d'acc�s
vector<Produit*> Fournisseur::obtenirCatalogue() const
{
	return contenuCatalogue_;
}


Satisfaction Fournisseur::obtenirSatisfaction() const
{
	return satisfaction_;
}

//M�thode de modification
void Fournisseur::modifierSatisfaction(Satisfaction satisfaction)
{
	satisfaction_ = satisfaction;
}

//Incr�mente de 1 dans le tableau niveau au niveau d'appr�ciation donn� en param�tre
void Fournisseur::noter(int appreciation)
{
	satisfaction_.niveaux_[appreciation]++;
}

//Ajoute un produit au catalogue du Fournisseur
void Fournisseur::ajouterProduit(Produit* produit)
{
	contenuCatalogue_.push_back(produit);
}

//Enleve le produit au catalogue du Fournisseur
void Fournisseur::enleverProduit(Produit* produit)
{
	if (contenuCatalogue_.size() > 0)
	{
		for (size_t i = 0; i < contenuCatalogue_.size(); i++)
		{
			if (*contenuCatalogue_[i] == *produit)
				contenuCatalogue_[i] = contenuCatalogue_.back();
		}
		contenuCatalogue_.pop_back();
	}
	
}


//Surcharge de l'operateur =
Fournisseur& Fournisseur::operator=(const Fournisseur& fournisseur)
{
	if (this != &fournisseur)			//S'assurer de ne pas l'affecter � lui-m�me
	{
		static_cast<Usager>(*this) = static_cast<Usager>(fournisseur);
		satisfaction_ = fournisseur.satisfaction_;
		contenuCatalogue_ = fournisseur.contenuCatalogue_;
	}
	return *this;
}

//Surcharge de l'op�rateur <<
ostream& operator<<(ostream & os, Fournisseur& fournisseur)
{
	os << "Fournisseur: " << static_cast<Usager>(fournisseur)
		<< "\t notes: " << endl;		//Fait planter le programme

	for (int i = 0; i < NIVEAUX_SATISFACTION; i++)
	{
		os << "\t " << i << ": "
			<< fournisseur.obtenirSatisfaction().niveaux_[i] << endl;
	}
	return os;
}

