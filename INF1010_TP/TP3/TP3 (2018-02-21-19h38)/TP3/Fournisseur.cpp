/********************************************
* Titre: Travail pratique #3 - Fournisseur.cpp
* Date: 
* Auteur:
*******************************************/
#include "Fournisseur.h"

Fournisseur::Fournisseur(const string&  nom, const string& prenom, int identifiant, const string& codePostal, Satisfaction satisfaction) :
	Usager(nom, prenom, identifiant, codePostal),
	satisfaction_{satisfaction}
{
	for (int i = 0; i < NIVEAUX_SATISFACTION; i++)
	{
		satisfaction.niveaux_[i] = 0;
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

//Incr�mente de 1 dans le tableau niveau au niveau donn� par appr�ciation
// Le -1 dans le tableau sert � incr�menter la bonne position du tableau
// ex: ( niveau1 sera � la position niveau_[0]
void Fournisseur::noter(int appreciation)
{
	satisfaction_.niveaux_[appreciation-1]++;
}

void Fournisseur::ajouterProduit(Produit* produit)
{
	contenuCatalogue_.push_back(produit);
}

void Fournisseur::enleverProduit(Produit* produit)
{
	for (int i = 0; i < contenuCatalogue_.size(); i++)	//Copie du dernier �l�ment � la position
	{													//de l'�l�ment retir�
		if (contenuCatalogue_[i] = produit)
			contenuCatalogue_[i] = contenuCatalogue_.back();
	}
	contenuCatalogue_.pop_back();						//retirer le dernier �l�ment
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


ostream& operator<<(ostream & os, Fournisseur& fournisseur)
{
	os << static_cast<Usager>(fournisseur);
		for (int i = 0; i < NIVEAUX_SATISFACTION; i++)
		{
			os << fournisseur.obtenirSatisfaction().niveaux_[i] << endl;
		}
		
	/*for (int i = 0; i < fournisseur.obtenirCatalogue().size() ; i++)
		{
		os << *fournisseur.obtenirCatalogue()[i] << endl;
		}*/
}

