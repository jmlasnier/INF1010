#include "Equipe.h"
#include <fstream>
#include <iostream>
#include <stdlib.h>

// Constructeurs
Equipe::Equipe (string nomEquipe, string nomPays) 
{
	// Equipe information
	this->teamName = nomEquipe;
	this->teamPays = nomPays;
}

// Setters
void Equipe::setTeamName(string name)
{
	teamName = name;
}

void Equipe::setTeamPays(string pays)
{
	teamPays = pays;
}

// Getters
string Equipe::getTeamName()
{
	return teamName;
}
string Equipe::getTeamPays()
{
	return teamPays;
}


// Afficher l'�quipe
void Equipe::afficher()
{
	std::cout << "Nom equipe : " << this->teamName << std::endl;
	std::cout << "Pays equipe: " << this->teamPays << std::endl;
}
