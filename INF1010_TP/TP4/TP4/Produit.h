#ifndef PRODUIT_H
#define PRODUIT_H

#include <string>

using namespace std;

class Fournisseur;

class Produit
{	
  public:
    Produit(Fournisseur *fournisseur = nullptr, const string &nom = "outil",
            int reference = 0, double prix = 0.0);
	
	virtual void afficher() const;
	virtual double obtenirPrix() const;
	virtual void reinitialiser();

    string obtenirNom() const;
    int obtenirReference() const;
    Fournisseur *obtenirFournisseur() const;
    
    void modifierNom(const string &nom);
    void modifierReference(int reference);
    void modifierPrix(double prix);
    void modifierFournisseur(Fournisseur *fournisseur);

  private:
    Fournisseur *fournisseur_;
    string nom_;
    int reference_;

  protected:
    double prix_;
};

#endif
