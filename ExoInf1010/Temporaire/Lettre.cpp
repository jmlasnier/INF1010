/****************************************************************************
 * Fichier: Lettre.cpp
 * Auteur: William Bussiere
 * Date: 24 mai 2011
 * Description: Implementation de la classe Lettre
 ****************************************************************************/

#include "Lettre.h"

Lettre::Lettre(string destinateur, string destinataire)
	: destinateur_(destinateur), destinataire_(destinataire)
{
}

string Lettre::getDestinateur()
{
	return destinateur_;
}

string Lettre::getDestinataire()
{
	return destinataire_;
}

ostream& operator<< ( ostream& out, Lettre lettre )
{
	out << "De : " << lettre.getDestinateur() << "   A : " << lettre.getDestinataire();

	return out;
}