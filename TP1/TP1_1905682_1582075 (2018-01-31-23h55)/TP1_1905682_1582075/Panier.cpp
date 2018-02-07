#include "panier.h"

//Constructeur par paramètre********************************************
Panier::Panier(int capacite):capaciteContenu_(capacite)
{
}

//Destructeur Panier
Panier::~Panier()
{
}

//Méthodes d'accès des attributs***************************************
Produit ** Panier::obtenirContenuPanier()
{
	return contenuPanier_;
}

int Panier::obtenirNombreContenu()
{
	return nombreContenu_;
}

double Panier::obtenirTotalApayer()
{
	return totalAPayer_;
}

//autres méthodes*******************************************************

void Panier::ajouter(Produit* prod)
{
	if (nombreContenu_ == capaciteContenu_)				//Ce qui est contenu dans if sert à 
	{													//doubler la capacité du panier si
		capaciteContenu_ *= 2;							//celui-ci est plein
		Produit** nouvContenuPanier;
		nouvContenuPanier = new Produit*[capaciteContenu_];

		for (int i = 0; i < nombreContenu_; i++)
		{
			nouvContenuPanier[i]=contenuPanier_[i];
			contenuPanier_ = nullptr;
		}
		for (int i = nombreContenu_; i < capaciteContenu_; i++)
		{
			nouvContenuPanier[i] = nullptr;
		}
		delete[] contenuPanier_;
		contenuPanier_ = nouvContenuPanier;
		nouvContenuPanier = nullptr;
	}
	contenuPanier_[nombreContenu_++] = prod;			//ajoute le produit 

	totalAPayer_ += prod->obtenirPrix;					//Pour mettre à jour le prix total à payer
}

void Panier::livrer()
{
	for (int i = 0; i < nombreContenu_; i++)
	{
		contenuPanier_[i] = nullptr;
	}
	nombreContenu_ = 0;									//NEED REVIEW
	capaciteContenu_ = 0;
	totalAPayer_ = 0.0;

						//est-ce qu'on doit rappeler le constructeur par défaut?????
}

void Panier::afficher()
{
	for (int i = 0; i < nombreContenu_; i++)
	{
		contenuPanier_[i]->afficher();
	}
	cout << "nombreContenu_: " << nombreContenu_ << endl;
	cout << "capaciteContenu_: " << capaciteContenu_ << endl;
	cout << "totalAPayer_: " << totalAPayer_ << endl;
}






