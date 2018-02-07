
//  panier.cpp
//  Created by Martine Bellaiche on 18-01-22.
//  Copyright © 2018 Martine Bellaiche. All rights reserved.
//

#include <string>
#include "Produit.h"

#ifndef PANIER_H
#define PANIER_H
class Panier
{
public:
    Panier (int capacite);
	~Panier();

    // methodes d'accès
    Produit **  obtenirContenuPanier();
    int obtenirNombreContenu();
    double obtenirTotalApayer();
    
    // méthodes de modification
    
    // autres méthodes
    void ajouter ( Produit * prod);
    void livrer();
    void afficher();
private:
    
    Produit ** contenuPanier_ = nullptr;
    int  nombreContenu_ = 0;
	int capaciteContenu_ = 0;
	double totalAPayer_ = 0.0;
};

#endif

