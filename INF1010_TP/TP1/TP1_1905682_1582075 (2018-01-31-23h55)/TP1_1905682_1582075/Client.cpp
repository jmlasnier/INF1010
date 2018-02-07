#include "client.h"

//Construsteur par paramètres
Client::Client(string  nom, string prenom, int identifiant, string codePostal, long date):nom_(nom),prenom_(prenom), 
	identifiant_(identifiant), codePostal_(codePostal), dateNaissance_(date)
{
}

//Méthodes d'accès aux attributs
string Client::obtenirNom()
{
	return nom_;
}

string Client::obtenirPrenom()
{
	return prenom_;
}

int Client::obtenirIdentifiant()
{
	return identifiant_;
}

string Client::obtenirCodePostal()
{
	return codePostal_;
}

long Client::obtenirDateNaissance()
{
	return dateNaissance_;
}

//Méthodes de modification
void Client::modifierNom(string nom)
{
	nom_ = nom;
}

void Client::modifierPrenom(string prenom)
{
	prenom_ = prenom;
}
void Client::modifierIdentifiant(int identifiant)
{
	identifiant_ = identifiant;
}

void Client::modifierCodePostal(string codePostal)
{
	codePostal_ = codePostal;
}

void Client::modifierDateNaissance(long date)
{
	dateNaissance_ = date;
}


//autres méthodes
void Client::acheter(Produit* prod)
{
	if (monPanier_ = nullptr)
	{
		Panier monNouveauPanier=Panier(4);
		monNouveauPanier.ajouter(prod);
	}
	monPanier_->ajouter(prod);
}

void Client::afficherPanier()
{
	if (monPanier_ != nullptr)
	{
		afficherPanier();
	}
	else
	{
		cout << "Le panier est vide" << endl;
	}
}

void Client::livrerPanier()
{
	monPanier_->~Panier();
}			//Destructeurs de panier ont été créé! Les enlever si non utilisé!!

