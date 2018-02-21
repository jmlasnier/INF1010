/********************************************
* Titre: Travail pratique #2 - Client.cpp
* Date: 25 janvier 2018
* Auteur: Mohammed Esseddik BENYAHIA & Timothée CHAUVIN
*******************************************/

#include "Client.h"

Client::Client(const string&  nom, const string& prenom, int identifiant, const string& codePostal, long date) :
	nom_{ nom },
	prenom_{ prenom },
	identifiant_{ identifiant },
	codePostal_{ codePostal },
	dateNaissance_{ date },
	monPanier_{ nullptr }
{
}

Client::~Client()
{
	if (monPanier_ != nullptr)
		delete monPanier_;
}


//Constructeur par copie
Client::Client(const Client& copie) : nom_(copie.nom_), prenom_(copie.prenom_), identifiant_(copie.identifiant_),
codePostal_(copie.codePostal_), dateNaissance_(copie.dateNaissance_), monPanier_(nullptr)
{
	if (copie.obtenirPanier() != nullptr)
	{
		monPanier_ = new Panier();
		for (int i = 0; i < copie.obtenirPanier()->obtenirNombreContenu(); i++)
		{
			monPanier_->ajouter(copie.obtenirPanier()->obtenirContenuPanier()[i]);
		}
	}
	
}

// Methodes d'acces
string Client::obtenirNom() const
{
	return nom_;
}

string Client::obtenirPrenom() const
{
	return prenom_;
}

int Client::obtenirIdentifiant() const
{
	return identifiant_;
}

string Client::obtenirCodePostal() const
{
	return codePostal_;
}

long Client::obtenirDateNaissance() const
{
	return dateNaissance_;
}

Panier * Client::obtenirPanier() const
{
	return monPanier_;
}

// Methodes de modification
void  Client::modifierNom(const string& nom)
{
	nom_ = nom;
}

void Client::modifierPrenom(const string& prenom)
{
	prenom_ = prenom;
}

void Client::modifierIdentifiant(int identifiant)
{
	identifiant_ = identifiant;
}

void Client::modifierCodePostal(const string& codePostal)
{
	codePostal_ = codePostal;
}

void Client::modifierDateNaissance(long date)
{
	dateNaissance_ = date;
}

// Autres méthodes
void Client::acheter(Produit * prod)
{
	if (monPanier_ == nullptr)
		monPanier_ = new Panier();
	monPanier_->ajouter(prod);
}

void Client::livrerPanier()
{
	monPanier_->livrer();
	delete monPanier_;
	monPanier_ = nullptr;
}

ostream& operator<<(ostream& os, const Client& client)
{
	if (nullptr != client.monPanier_)
	{
		return os  << *client.obtenirPanier();
	}
	return os << "Le panier est vide!" << endl;
}

//Surcharge de l'opérateur=				//Pour faire une deep copie du client passé en parametre
Client& Client::operator=(const Client& client)
{
	nom_ = client.nom_;
	prenom_ = client.prenom_;
	identifiant_ = client.identifiant_;
	codePostal_ = client.codePostal_;
	dateNaissance_ = client.dateNaissance_;
	monPanier_ = new Panier();
	for (int i = 0; i < client.obtenirPanier()->obtenirContenuPanier().size() ; i++)
	{
		monPanier_->ajouter(client.obtenirPanier()->obtenirContenuPanier()[i]);
	}

	return *this;
}

//surcharge de l'opérateur == (client == identifiant)	//Vérifie si le client correspond à l'identifiant l'identifiant est entré à droite de l'opérateur
bool Client::operator==(const int identifiant)
{
	return (identifiant_ == identifiant);
}

//surcharge de l'opérateur == (identifiant == client)	//Vérifie si le client correspond à l'identifiant quand le client est entré à droite de l'opérateur
bool operator==(int identifiant, const Client& client)
{
	return (identifiant == client.obtenirIdentifiant());
}
