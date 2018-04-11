/****************************************************************************
 * Fichier: Main.cpp
 * Auteur: William Bussiere
 * Date: 24 mai 2011
 * Description: Utilisation de la classe generique Casiers (matrice generique)
 ****************************************************************************/

#include "Casiers.h"
#include "Lettre.h"

#include <iostream>
using namespace std;


int main (void)
{
	// Boite a surprise!
	Casiers<int, 3, 3> boiteASurprises;

	boiteASurprises.ajouterItem(5,	0, 0);
	boiteASurprises.ajouterItem(24,	0, 0);
	boiteASurprises.ajouterItem(8,	2, 0);
	boiteASurprises.ajouterItem(69,	1, 1);

	boiteASurprises.afficherContenuCase(0, 0);
	cout << endl;



	// Boite aux lettres
	Casiers<Lettre, 2, 2> boiteAuxLettres;

	boiteAuxLettres.ajouterItem( Lettre("Jean-Remi",	"Barthelemie")	, 0, 0 );
	boiteAuxLettres.ajouterItem( Lettre("Christophe",	"Barthelemie")	, 0, 0 );
	boiteAuxLettres.ajouterItem( Lettre("Raymond",		"Suze")			, 0, 0 );
	boiteAuxLettres.ajouterItem( Lettre("Steph",		"Jules")		, 1, 0 );
	boiteAuxLettres.ajouterItem( Lettre("Jeremy",		"Jules")		, 1, 0 );


	boiteAuxLettres.afficherContenuCase(2, 1); // Ce qui est en dehors des limites de la boite aux lettres
	cout << endl;
	boiteAuxLettres.afficherContenuCase(0, 0);
	cout << endl;

	return 0;
}