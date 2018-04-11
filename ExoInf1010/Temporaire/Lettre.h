/****************************************************************************
 * Fichier: Lettre.h
 * Auteur: William Bussiere
 * Date: 24 mai 2011
 * Description: Definition de la classe Lettre
 ****************************************************************************/

#ifndef _LETTRE_H_
#define _LETTRE_H_

#include <iostream>
#include <string>
using namespace std;


class Lettre
{
public :
	Lettre(string destinateur, string destinataire);

	string getDestinateur();
	string getDestinataire();

private :
	string destinateur_;
	string destinataire_;

};


// On doit indiquer au compilateur qu'il existe une surcharge de l'operateur << 
// pour l'objet Lettre (pour les fonctions generiques).
ostream& operator<< ( ostream& out, Lettre lettre );

#endif