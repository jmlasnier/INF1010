#ifndef CLIENT_H
#define CLIENT_H

#include <string>
#include <vector>
#include "Usager.h"
#include "Produit.h"

using namespace std;

class Client : public Usager
{
  public:
    Client(unsigned int codeClient = 0);
    Client(const string &nom, const string &prenom, int identifiant, const string &codePostal, unsigned int codeClient = 0);

	virtual void afficherProfil() const;
	virtual double obtenirTotalAPayer() const;
	virtual void enleverProduit(Produit *produit);
	virtual void ajouterProduit(Produit *produit);
	virtual void reinitialiser();

	void afficherPanier() const;

    unsigned int obtenirCodeClient() const;
    vector<Produit *> obtenirPanier() const;
    	
	void modifierCodeClient(unsigned int codeClient);
  
  protected:
    vector<Produit *> panier_;

  private:
    unsigned int codeClient_;
};

#endif
