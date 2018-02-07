/**************************************************
* Titre: Travail pratique #1 - Main.cpp
* Date: 20 janvier 2018
* Auteur: Mohammed Esseddik BENYAHIA
**************************************************/

#include "Produit.h"
#include "Rayon.h"
#include "client.h"
#include "panier.h"
#include <string>
#include <iostream>

using namespace std;

int main()
{
	//C'est à vous de voir si vous devez allouer dynamiquement ou non les élèments

	//1-  Creez 15 objets du classe produit
	Produit carotte = Produit("carotte", 1, 3.50);
	Produit brocoli = Produit("brocoli", 2, 3.25);
	Produit poivron = Produit("poivron", 3, 4.00);
	Produit fraise = Produit("fraise", 4, 6.50);
	Produit banane = Produit("banane", 5, 5.00);
	Produit poulet = Produit("poulet", 6, 12.75);
	Produit boeuf = Produit("boeuf", 7, 10.50);
	Produit crevette = Produit("crevette", 8, 13.75);
	Produit saumon = Produit("saumon", 9, 16.75);
	Produit truite = Produit("truite", 10, 10.75);
	Produit ailesDePoulet = Produit("ailesDePoulet", 11, 15.25);
	Produit chips = Produit("chips", 12, 2.50);
	Produit cocacola = Produit("cocacola", 13, 3.50);
	Produit vin = Produit("vin", 14, 22.00);
	Produit biere = Produit("biere", 15, 27.00);

	//2-  Modifiez le nom, la référence, le prix de  troisieme objet Produit créé
    //   afficher les attributs de cet objet Produit
	poivron.modifierNom("piment");
	poivron.modifierReference(16);
	poivron.modifierPrix(4.50);

	poivron.afficher()
	
	//3-  Creez un objet du classe rayon à l'aide du constructeur par défaut
   
	//4-  Modifiez la catégorie  du rayon
   
    // 5- Ajouter 6 produits de  voret chaoix dans le rayon créé
    

    // 6- afficher le contenu du rayon
   
  
	//7-  Creez un objet de classe client à l'aide du constructeur
   

	//8-  afficher l'etat des attributs du client
   

	//9-   Le client achete 9 produits
   

	//10- Afficher le contenu du panier du client

     //11- livrer le panier du client
   
    
	//12- afficher le contenu du panier du client
    
	//13-  terminer le programme correctement
    
    return 0;
}
