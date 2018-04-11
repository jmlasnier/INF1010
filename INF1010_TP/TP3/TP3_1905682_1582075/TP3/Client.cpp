/********************************************
* Titre: Travail pratique #3 - Client.cpp
* Date: 
* Auteur: 
*******************************************/

#include "Client.h"
#include "Fournisseur.h"


//Constructeur par paramètre et par défaut de la classe Client
Client::Client(const string&  nom, const string& prenom, int identifiant, const string& codePostal, long date):
	Usager(nom, prenom, identifiant, codePostal),
	dateNaissance_{date},
	monPanier_{nullptr}
{	}

//Destructeur de la classe Client
Client::~Client()
{
	if (monPanier_ != nullptr)
		delete monPanier_;
}

//Constructeur par copie de Client
Client::Client(const Client & client) :
	Usager(client.obtenirNom(), client.obtenirPrenom(), client.obtenirIdentifiant(), client.obtenirCodePostal()),	
	dateNaissance_{ client.dateNaissance_ }
{
	if (client.monPanier_ == nullptr)
		monPanier_ = nullptr;
	else {
		monPanier_ = new Panier(client.obtenirIdentifiant());
		for (int i = 0; i < client.monPanier_->obtenirNombreContenu(); i++) {
			monPanier_->ajouter(client.monPanier_->obtenirContenuPanier()[i]);
		}
		int idClient = this->obtenirIdentifiant();
		monPanier_->modifierTotalAPayer(client.monPanier_->obtenirTotalApayer());
	}
}


// Methodes d'acces
long Client::obtenirDateNaissance() const
{
	return dateNaissance_;
}

Panier * Client::obtenirPanier() const
{
	return monPanier_;
}


// Methodes de modification
void Client::modifierDateNaissance(long date)
{
	dateNaissance_ = date;
}

// Autres méthodes

//Permet au client d'acheter un produit et de l'ajouter à son panier. De plus, une note est donné au hasard au fournisseur
void Client::acheter(ProduitOrdinaire * prod)
{
	if (monPanier_ == nullptr)
		monPanier_ = new Panier(this->obtenirIdentifiant());
	monPanier_->ajouter(prod);
	// obtenir une note aléatoire
	int note = rand() % BORNE_SUPERIEURE_RAND;
	// faire la mise à jour de la satisfaction au fournisseur
	prod->obtenirFournisseur().noter(note);
}

//Permet de livrer le panier et donc de vider le panier. Désaloue la mémoire du pointeur monPanier_ pour éviter les fuites
void Client::livrerPanier()
{
	monPanier_->livrer();
	delete monPanier_;
	monPanier_ = nullptr;
}

//Permet au client de miser sur un produit. Si sa mise est plus élevée que celle précédente, 
//le prix du produit augmente et est identifié au client en question
void Client::miserProduit(ProduitAuxEncheres* produitAuxEncheres, double montantMise)
{
	if (nullptr == monPanier_)
		monPanier_ = new Panier(obtenirIdentifiant());
	if (montantMise >= produitAuxEncheres->obtenirPrix())
	{
		produitAuxEncheres->modifierPrix(montantMise);
		produitAuxEncheres->modifierIdentifiantClient(this->obtenirIdentifiant());
	}
	
}

//Surcharge de l'opérateur =
Client & Client::operator=(const Client & client)
{
	if (this != &client) {
		this->modifierNom(client.obtenirNom());
		this->modifierPrenom(client.obtenirPrenom());
		this->modifierIdentifiant(client.obtenirIdentifiant());
		this->modifierCodePostal(client.obtenirCodePostal());
		dateNaissance_ = client.obtenirDateNaissance();
		if (client.monPanier_ != nullptr) {
			delete monPanier_;
			monPanier_ = new Panier(obtenirIdentifiant());
			for (int i = 0; i < client.monPanier_->obtenirNombreContenu(); i++) {
				monPanier_->ajouter(client.monPanier_->obtenirContenuPanier()[i]);
			}
		}
		else
			monPanier_ = nullptr;
	}
	return *this;
}

//Surcharge de l'opérateur <<
ostream & operator<<(ostream & os, const Client & client)
{
	os << "Client: " << static_cast<Usager>(client);
		

	if (nullptr != client.obtenirPanier())
	{
		os << "Le panier de " << client.obtenirPrenom() << ":" << endl
			<< *client.obtenirPanier() << endl;
	}
	else
	{
		os << "Le panier est vide!" << endl;
	}
	return os;
}
