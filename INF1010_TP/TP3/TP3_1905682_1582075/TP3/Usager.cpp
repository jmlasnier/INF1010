/********************************************
* Titre: Travail pratique #3 - Client.h
* Date:
* Auteur:
*******************************************/

#include "Usager.h"
using namespace std;

// Constructeur par paramètre et par défaut de la classe Usager
Usager::Usager(const string&  nom, const string& prenom, int identifiant, const string& codePostal):
	nom_{ nom },
	prenom_{ prenom },
	identifiant_{ identifiant },
	codePostal_{ codePostal }	
{
}

// Méthodes d'accès
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

// Méthodes de modification
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

//Surcharge de l'opérateur =
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

//Surcharge de l'opérateur == lorsqu'un identifiant de type int est à la droite de l'opérateur
bool Usager::operator==(int identifiant) const {
	return identifiant_ == identifiant;
};

//Surcharge de l'opérateur == lorsqu'un objet de la classe Usager est à la droite de l'opérateur
bool Usager::operator == (const Usager & usager)
{
	return  *this == usager.obtenirIdentifiant();
}

//Surcharge de l'opérateur globale == de type friend
bool operator==(int indentifiant, const Usager& usager) {
	return usager == indentifiant;
}

//Surcharge de l'opérateur <<
ostream & operator<<(ostream & os, const Usager & usager)
{
	os << " Usager: \t ";
	os << "nom: " << usager.obtenirNom() << endl
	   << "\t prenom: " << usager.obtenirPrenom() << endl
	   << "\t codePostal: " << usager.obtenirCodePostal() << endl;
	return os;
}

