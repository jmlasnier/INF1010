/********************************************
* Titre: Travail pratique #3 - Client.h
* Date:
* Auteur:
*******************************************/

#include "Usager.h"
using namespace std;

// Constructeur par param�tre et par d�faut de la classe Usager
Usager::Usager(const string&  nom, const string& prenom, int identifiant, const string& codePostal):
	nom_{ nom },
	prenom_{ prenom },
	identifiant_{ identifiant },
	codePostal_{ codePostal }	
{
}

// M�thodes d'acc�s
string Usager::obtenirNom() const
{
	return nom_;
}


string Usager::obtenirPrenom() const
{
	return prenom_;
}


int Usager::obtenirIdentifiant() const
{
	return identifiant_;
}


string Usager::obtenirCodePostal() const
{
	return codePostal_;
}

// M�thodes de modification
void  Usager::modifierNom(const string& nom)
{
	nom_ = nom;
}

void Usager::modifierPrenom(const string& prenom)
{
	prenom_ = prenom;
}

void Usager::modifierIdentifiant(int identifiant)
{
	identifiant_ = identifiant;
}

void Usager::modifierCodePostal(const string& codePostal)
{
	codePostal_ = codePostal;
}

//Surcharge de l'op�rateur =
Usager &Usager::operator=(const Usager & usager)
{
	if (this != &usager) {
		nom_ = usager.nom_;
		prenom_ = usager.prenom_;
		identifiant_ = usager.identifiant_;
		codePostal_ = usager.codePostal_;		
	}
	return *this;
}

//Surcharge de l'op�rateur == lorsqu'un identifiant de type int est � la droite de l'op�rateur
bool Usager::operator==(int identifiant) const {
	return identifiant_ == identifiant;
};

//Surcharge de l'op�rateur == lorsqu'un objet de la classe Usager est � la droite de l'op�rateur
bool Usager::operator == (const Usager & usager)
{
	return  *this == usager.obtenirIdentifiant();
}

//Surcharge de l'op�rateur globale == de type friend
bool operator==(int indentifiant, const Usager& usager) {
	return usager == indentifiant;
}

//Surcharge de l'op�rateur <<
ostream & operator<<(ostream & os, const Usager & usager)
{
	os << " Usager: \t ";
	os << "nom: " << usager.obtenirNom() << endl
	   << "\t prenom: " << usager.obtenirPrenom() << endl
	   << "\t codePostal: " << usager.obtenirCodePostal() << endl;
	return os;
}

