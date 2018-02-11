/********************************************
* Titre: Travail pratique #2 - Rayon.cpp
* Date: 25 janvier 2018
* Auteur: Timoth�e CHAUVIN
*******************************************/

#include "Rayon.h"

Rayon::Rayon(const string& cat) :
	categorie_{ cat }
{
}

Rayon::~Rayon()
{
}

// Methodes d'acces
string Rayon::obtenirCategorie() const
{
	return categorie_;
}

vector<Produit*> Rayon::obtenirTousProduits() const
{
	return tousProduits_;
}

int Rayon::obtenirCapaciteProduits() const
{
	return tousProduits_.capacity();
}

int Rayon::obtenirNombreProduits() const
{
	return tousProduits_.size();
}

// Methodes de modification
void Rayon::modifierCategorie(const string& cat)
{
	categorie_ = cat;
}

//ajouterProduit avec la surcharge d'operateur +=
 Rayon& Rayon::operator+=(Produit& produit)
{
	 tousProduits_.push_back(&produit);
	return *this;
}


//Methode de modification compterDoublons
int Rayon::compterDoublons(const Produit& produit)
{
	int doublons = 0;
	for (int i = 0; i < obtenirNombreProduits(); i++)
	{
		if (*tousProduits_[i] == produit)
			doublons++;
	}
	return doublons;
}


//Surcharge de l'operateur <<
ostream& operator<<(ostream& os, Rayon& rayon)
{
	os << rayon.obtenirCategorie() << endl;
	for (int i = 0; i < rayon.obtenirNombreProduits() ; i++)
		{
			 os << *rayon.obtenirTousProduits()[i] << endl;
		}
	return os;
}
