#pragma once
#ifndef Equipe_H
#define Equipe_H

#include <string>

using namespace std;


class Equipe 
{
public:
	// Constructeurs
	Equipe () {}
	Equipe(string nomEquipe, string nomPays);

	// Setters
	void setTeamName(string);
	void setTeamPays(string);

	// Getters
	string getTeamName();
	string getTeamPays();


	// Afficher l'équipe
	void afficher();
private:
	string teamName;
	string teamPays;
};

#endif