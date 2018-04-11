#include "Client.h"
#include "ProduitAuxEncheres.h"
#include "GestionnaireProduits.h"
#include "Foncteur.h"
#include <iostream>
#include <algorithm>

Client::Client(unsigned int codeClient)
    : Usager(),
      codeClient_(codeClient),
	panier_(new GestionnaireProduits())
{
	// TODO : � modifier//DONE
}

Client::Client(const string &nom, const string &prenom, int identifiant,
               const string &codePostal, unsigned int codeClient)
    : Usager(nom, prenom, identifiant, codePostal),
      codeClient_(codeClient),
	panier_(new GestionnaireProduits())
{
	// TODO : � modifier//DONE
}

Client::~Client()
{
	delete panier_;
}

unsigned int Client::obtenirCodeClient() const
{
    return codeClient_;
}

GestionnaireProduits* Client::obtenirPanier() const
{
	// TODO : � modifier //DONE
    return panier_;
}

double Client::obtenirTotalAPayer() const
{
	// TODO : � modifier
    //double montant = panier_->
	double montant = 0;
    //for (unsigned int i = 0; i < panier_.size(); i++)
    //    montant += panier_[i]->obtenirPrix();
    return montant;
}

void Client::afficherPanier() const
{
	// TODO : � modifier
    cout << "PANIER (de " << obtenirNom() << ")"
         << "\n";
    //for (unsigned int i = 0; i < panier_.size(); i++)
    //    panier_[i]->afficher();
    cout << endl;
}

void Client::afficher() const
{
	// TODO : � modifier
    Usager::afficher();
    //cout << "\t\tcode client:\t" << codeClient_ << endl  << "\t\tpanier:\t\t" << panier_.size() << " elements" << endl;
}

void Client::modifierCodeClient(unsigned int codeClient)
{
    codeClient_ = codeClient_;
}

void Client::enleverProduit(Produit *produit)
{
	panier_->supprimer(produit);
	// TODO : � modifier
    //for (unsigned int i = 0; i < panier_.size(); i++)
    //{
    //    if (panier_[i] == produit)
    //    {
    //        panier_[i] = panier_[panier_.size() - 1];
    //        panier_.pop_back();
    //        return;
    //    }
    //}
}

void Client::ajouterProduit(Produit *produit)
{
	 //TODO : � modifier
	panier_->ajouter(produit);
  //  for (unsigned int i = 0; i < panier_.size(); i++)
  //      if (panier_[i] == produit)
  //          return;
  //  panier_.push_back(produit);
	
}

void Client::reinitialiser()
{
	// TODO : � modifier

	panier_->reinitialiserClient();
    //for (unsigned int i = 0; i < panier_.size(); i++)
    //{
    //    ProduitAuxEncheres *produit = dynamic_cast<ProduitAuxEncheres *>(panier_[i]);
    //    if (produit) {
    //        produit->modifierEncherisseur(nullptr);
    //        produit->modifierPrix(produit->obtenirPrixInitial());
    //    }
    //}
    //panier_.clear();
}

Produit* Client::trouverProduitPlusCher() const
{
	Produit* ptr = new Produit();
	return ptr;
}