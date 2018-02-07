#include "Rayon.h"

//Constructeur par param�tres avec liste d'initialisation**********************************************************
Rayon::Rayon(string cat = "inconnu"):categorie_(cat), tousProduits_(nullptr), capaciteProduits_(0), nombreProduits_(0)
{
}

//Destructeur
Rayon::~Rayon()
{
	//delete[] tousProduits_;		//Servait � d�salouer les pointeurs mais mon ordi plantait lorsque je d�commentais cette 
}									//ligne pour une raison que j'ignore. M�me sitation avec les destructeurs dans Panier.cpp et Client.cpp


//M�thodes d'acc�s aux attributs***********************************************************************************
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


//M�thode de modification******************************************************************************************
void Rayon::modifierCategorie(string cat)
{
	categorie_ = cat;
}


// autres methodes************************************************************************************************
void Rayon::ajouterProduit(Produit* produit)		
{
	if (nullptr == tousProduits_)			//Cr�� un tableau initial avec une capacit� de 5 si le tableau est null
	{
		tousProduits_ = new Produit*[5];
		for (int i = 0; i < 5; i++)
		{
			tousProduits_[i] = nullptr;
			capaciteProduits_++;
		}
	}
	else if (capaciteProduits_ == nombreProduits_)			//Si le tableau est plein, on ajoute 5 espaces � la capacit� du tableau
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
	tousProduits_[nombreProduits_++] = produit;			//Cette partie rajoute le produit voulu au panier en plus d'incr�menter l'attribut nombreProduits_ du m�me coup
}

void Rayon::afficher()									//Affichage du rayon et appelle la fonction pour afficher les produits
{
	cout << "*******************************************************" << endl;
	cout << "|Categorie: " << categorie_ << endl; //Deux endl de suite pour un affichage plus espac� et facile � lire
	//Boucle pour afficher les produits
	for (int i = 0; i < nombreProduits_; i++)
	{
		tousProduits_[i]->afficher();
	}
	
	cout << "|capaciteProduits: " << capaciteProduits_ << endl;
	cout << "|nombreProduits: " << nombreProduits_ << endl;
	cout << "*******************************************************" << endl;
}