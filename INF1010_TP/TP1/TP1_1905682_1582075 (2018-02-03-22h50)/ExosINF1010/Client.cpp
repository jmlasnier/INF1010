#include "client.h"

//Construsteur par paramètres*****************************************************************
Client::Client(string  nom, string prenom, int identifiant, string codePostal, long date):nom_(nom),prenom_(prenom), 
	identifiant_(identifiant), codePostal_(codePostal), dateNaissance_(date), monPanier_(nullptr)
{
}

Client::~Client()
{
	//delete monPanier_;		Probleme de compilation quand non-commenté comme avec les autres destructeurs
}

//Méthodes d'accès aux attributs**************************************************************
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

//Méthodes de modification**************************************************************************
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


//autres méthodes**********************************************************************************
void Client::acheter(Produit* prod)
{
	if (nullptr == monPanier_)
	{
		monPanier_ = new Panier(4);
	}
	monPanier_->ajouter(prod);
	
}

void Client::afficherPanier() const
{
	if (monPanier_ != nullptr)
	{
		monPanier_->afficher();
	}
	else
	{
		cout << "Le panier est vide" << endl;
	}
}

void Client::livrerPanier()
{
	monPanier_->livrer();
	delete monPanier_;
	monPanier_ = nullptr;
}	

void Client::afficherInfoClient() const				//Méthode ajouté qui permet d'afficher les info du client sans son panier
{
	cout << "*******************************************************" << endl;
	cout << "|nom: " << nom_ << endl;
	cout << "|prenom: " << prenom_ << endl;
	cout << "|identifiant: " << identifiant_ << endl;
	cout << "|code postal: " << codePostal_ << endl;
	cout << "|date de naissance: " << dateNaissance_ << endl << endl;
	cout << "*******************************************************" << endl;
}

