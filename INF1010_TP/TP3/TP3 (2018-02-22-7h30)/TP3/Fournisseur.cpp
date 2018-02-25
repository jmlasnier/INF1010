/********************************************
* Titre: Travail pratique #3 - Fournisseur.cpp
* Date: 
* Auteur:
*******************************************/
#include "Fournisseur.h"

Fournisseur::Fournisseur(const string&  nom, const string& prenom, int identifiant, const string& codePostal) :
	Usager(nom, prenom, identifiant, codePostal)
{
	for (int i = 0; i < NIVEAUX_SATISFACTION; i++)
	{
		satisfaction_.niveaux_[i] = 0;
	}
}

vector<Produit*> Fournisseur::obtenirCatalogue() const
{
	return contenuCatalogue_;
}

Satisfaction Fournisseur::obtenirSatisfaction() const
{
	return satisfaction_;
}

void Fournisseur::modifierSatisfaction(Satisfaction satisfaction)
{
	satisfaction_ = satisfaction;
}

//Incrémente de 1 dans le tableau niveau au niveau donné par appréciation
void Fournisseur::noter(int appreciation)
{
	satisfaction_.niveaux_[appreciation]++;
}

void Fournisseur::ajouterProduit(Produit* produit)
{
	contenuCatalogue_.push_back(produit);
}

void Fournisseur::enleverProduit(Produit* produit)
{
	if (contenuCatalogue_.size() > 0)
	{
		for (size_t i = 0; i < contenuCatalogue_.size(); i++)	//Copie du dernier élément à la position
		{													//de l'élément retiré
			if (*contenuCatalogue_[i] == *produit)
				contenuCatalogue_[i] = contenuCatalogue_.back();
		}
		contenuCatalogue_.pop_back();						//retire le dernier élément
	}
	
}


//Surcharge de l'operateur =
Fournisseur& Fournisseur::operator=(const Fournisseur& fournisseur)
{
	if (this != &fournisseur)			//S'assurer de ne pas l'affecter à lui-même
	{
		static_cast<Usager>(*this) = static_cast<Usager>(fournisseur);
		satisfaction_ = fournisseur.satisfaction_;
		contenuCatalogue_ = fournisseur.contenuCatalogue_;
	}
	return *this;
}


ostream& operator<<(ostream & os, Fournisseur& fournisseur)
{
	os << "Fournisseur: " << static_cast<Usager>(fournisseur)
		<< "\t notes: " << endl;		//Fait planter le programme

	for (int i = 0; i < NIVEAUX_SATISFACTION; i++)
		{
		os << "\t " << i << ": "
			<<fournisseur.obtenirSatisfaction().niveaux_[i] << endl;
		}
		return os;
	/*for (int i = 0; i < fournisseur.obtenirCatalogue().size() ; i++)
		{
		os << *fournisseur.obtenirCatalogue()[i] << endl;
		}*/
}

