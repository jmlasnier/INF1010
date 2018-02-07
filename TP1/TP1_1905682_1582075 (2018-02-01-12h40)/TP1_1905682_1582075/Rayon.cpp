#include "Rayon.h"

//Constructeur par défaut*********************************************
/*Rayon::Rayon()
{
	categorie_ = "inconnu";
	tousProduits_ = nullptr;
	capaciteProduits_ = 0;
	nombreProduits_ = 0;
}
*///PU BESOIN A CAUSE DU MERGE DES CONSTRUCTEURS

//Constructeur par paramètres AVEC LISTE D'INITIALISATION!*****************************************
Rayon::Rayon(string cat = "inconnu"):categorie_(cat), tousProduits_(nullptr), capaciteProduits_(0), nombreProduits_(0)
{
}

//Méthodes d'accès aux attributs***************************************
string Rayon::obtenirCategorie() const
{
	return categorie_;
}

Produit ** Rayon::obtenirTousProduits() const
{
	return tousProduits_;
}

int Rayon::obtenirCapaciteProduits() const
{
	return capaciteProduits_;
}

int Rayon::obtenirNombreProduits() const
{
	return nombreProduits_;
}


//Méthode de modification**********************************************
void Rayon::modifierCategorie(string cat)
{
	categorie_ = cat;
}


// autres methodes******************************************************
void Rayon::ajouterProduit(Produit* produit)		//REVIEW!! :O
{
	if (tousProduits_ == nullptr)
	{
		tousProduits_ = new Produit*[5];
		for (int i = 0; i < 5; i++)
		{
			tousProduits_[i] = nullptr;
			capaciteProduits_++;
		}
	}
	else if (capaciteProduits_ == nombreProduits_)
	{
		capaciteProduits_ += 5;
		Produit** nouvTousProduits;
		nouvTousProduits = new Produit*[capaciteProduits_]; //nouveau tableau avec capacite+5

		for (int i = 0; i < nombreProduits_; i++)
		{
			nouvTousProduits[i] = tousProduits_[i];
			tousProduits_[i] = nullptr;
		}
		for (int i = nombreProduits_; i < capaciteProduits_ ; i++)
		{
			nouvTousProduits[i] = nullptr;
		}
		delete[] tousProduits_;
		tousProduits_ = nouvTousProduits;
		nouvTousProduits = nullptr;
	}
	tousProduits_[nombreProduits_++] = produit;
}

void Rayon::afficher()
{
	cout << "Categorie: " << categorie_ << endl;
	//Boucle pour afficher les produits
	for (int i = 0; i < nombreProduits_; i++)
	{
		tousProduits_[i]->afficher();
	}
	
	cout << "capaciteProduits: " << capaciteProduits_ << endl;
	cout << "nombreProduits: " << nombreProduits_ << endl;
}