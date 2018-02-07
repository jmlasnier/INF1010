#include "Rayon.h"

//Constructeur par paramètres avec liste d'initialisation**********************************************************
Rayon::Rayon(string cat = "inconnu"):categorie_(cat), tousProduits_(nullptr), capaciteProduits_(0), nombreProduits_(0)
{
}

//Destructeur
Rayon::~Rayon()
{
	//delete[] tousProduits_;		//Servait à désalouer les pointeurs mais mon ordi plantait lorsque je décommentais cette 
}									//ligne pour une raison que j'ignore. Même sitation avec les destructeurs dans Panier.cpp et Client.cpp


//Méthodes d'accès aux attributs***********************************************************************************
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


//Méthode de modification******************************************************************************************
void Rayon::modifierCategorie(string cat)
{
	categorie_ = cat;
}


// autres methodes************************************************************************************************
void Rayon::ajouterProduit(Produit* produit)		
{
	if (nullptr == tousProduits_)			//Créé un tableau initial avec une capacité de 5 si le tableau est null
	{
		tousProduits_ = new Produit*[5];
		for (int i = 0; i < 5; i++)
		{
			tousProduits_[i] = nullptr;
			capaciteProduits_++;
		}
	}
	else if (capaciteProduits_ == nombreProduits_)			//Si le tableau est plein, on ajoute 5 espaces à la capacité du tableau
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
	tousProduits_[nombreProduits_++] = produit;			//Cette partie rajoute le produit voulu au panier en plus d'incrémenter l'attribut nombreProduits_ du même coup
}

void Rayon::afficher()									//Affichage du rayon et appelle la fonction pour afficher les produits
{
	cout << "*******************************************************" << endl;
	cout << "|Categorie: " << categorie_ << endl; //Deux endl de suite pour un affichage plus espacé et facile à lire
	//Boucle pour afficher les produits
	for (int i = 0; i < nombreProduits_; i++)
	{
		tousProduits_[i]->afficher();
	}
	
	cout << "|capaciteProduits: " << capaciteProduits_ << endl;
	cout << "|nombreProduits: " << nombreProduits_ << endl;
	cout << "*******************************************************" << endl;
}