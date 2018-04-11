/****************************************************************************
 * Fichier: Casiers.h
 * Auteur: William Bussiere
 * Date: 24 mai 2011
 * Description: Definition et Implementation de la classe generique Casiers
 ****************************************************************************/

#ifndef _CASIERS_H_
#define _CASIERS_H_

#include <vector>
#include <iostream>
using namespace std;


template < typename T, unsigned int N, unsigned int M >
class Casiers
{
public :
	Casiers();

	void ajouterItem(const T &item, unsigned int ligne, unsigned int colonne);
	void afficherContenuCase(unsigned int ligne, unsigned int colonne) const;

private :
	vector<T> cases_[N][M];
};

/****************************************************************************
 * Fonction:	Casiers<T,N,M>::Casiers
 * Description: Constructeur par defaut (unique constructeur)
 * Paramètres:	aucun
 * Retour:		aucun
 ****************************************************************************/
template < typename T, unsigned int N, unsigned int M >
Casiers<T,N,M>::Casiers()
{
}


/****************************************************************************
 * Fonction:	Casiers<T,N,M>::ajouterItem
 * Description: Ajoute un item dans le vecteur d'une case
 * Paramètres:	- (T) item : item a ajouter (IN)
 *				- (unsigned int) ligne : la position en ligne de la case
 *				- (unsigned int) colonne : la position en colonne de la case
 * Retour:		aucun
 ****************************************************************************/
template < typename T, unsigned int N, unsigned int M >
void Casiers<T,N,M>::ajouterItem(const T &item, unsigned int ligne, unsigned int colonne)
{
	if(ligne < N && colonne < M)
		cases_[ligne][colonne].push_back( item );

	else
		cout << "Case inexistante" << endl;
}


/****************************************************************************
 * Fonction:	Casiers<T,N,M>::afficherContenuCase
 * Description: Affiche les elements du vecteur d'une case
 * Paramètres:	- (unsigned int) ligne : la position en ligne de la case
 *				- (unsigned int) colonne : la position en colonne de la case
 * Retour:		aucun
 ****************************************************************************/
template < typename T, unsigned int N, unsigned int M >
void Casiers<T,N,M>::afficherContenuCase(unsigned int ligne, unsigned int colonne) const
{
	if(ligne < N && colonne < M)
	{
		cout << "Contenu de la case : " << endl;

		for(unsigned int i=0; i < cases_[ligne][colonne].size(); i++)
			cout << cases_[ligne][colonne][i] << endl;
	}

	else
		cout << "Case inexistante" << endl;
}

#endif