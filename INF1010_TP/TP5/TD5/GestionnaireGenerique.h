/********************************************
* Titre: Travail pratique #5 - GestionnaireUsagers.cpp
* Date: 2 avril 2018
* Auteur: Jean-Michel Lasnier
*******************************************/
#ifndef GESTIONNAIRE_GENERIQUE_H
#define GESTIONNAIRE_GENERIQUE_H
#pragma once

using namespace std;
// TODO : Cr�er la classe GestionnaireGenerique
// TODO : M�thodes :

template<typename T, typename C, typename A, typename S>
class GestionnaireGenerique
{
public:
	//????????????Faire un constructeur????????????????? non

	C obtenirConteneur() const
	{
		return conteneur_;
	}

	void ajouter(T* ptr)
	{
		A a(conteneur_);
		a(ptr);
	}
	void supprimer(T* ptr)
	{
		S s(conteneur_);
		s(ptr);
	}

	//Pas certain si typename est plac� � la bonne place
	template <typename Predicate >
	void pourChaqueElement(Predicate foncteur)
	{
		for_each(conteneur_.begin(), conteneur_.end(), foncteur);
	}

protected:
	C conteneur_;

};

//Sera � l'ext�rieur de la classe pour le moment... well see after

#endif