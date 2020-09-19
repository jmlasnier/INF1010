// *************************************************************
//  IMPLEMANTATION FILE (Jeu.cpp)
//  Ce fichier implémente les fonctions membres du fichier Jeu qui lui contient les prototypes dans la définition de la classe 
//  \author Jérémie Kerouac (1897211), Jean-François Martin (1901024)
//  \date 15 septembre 2020
// *************************************************************


#include "Jeu.h"
#include <limits>

// Constructeur par défaut avec liste d'initialisation
Jeu::Jeu() : nom_("Inconnu"), prix_(std::numeric_limits<unsigned int>::max())
{
}


// Constructeur par paramètres avec liste d'initialisation
Jeu::Jeu(std::string nom, unsigned int prix) : nom_(nom), prix_(prix)
{
}

/// Affiche le jeu.
/// \param stream   Le stream dans lequel afficher le jeu.
void Jeu::afficher(std::ostream& stream) const
{
    stream << nom_ << ": " << prix_ / 100.0 << "$";
}

// Fonction getter (constante) qui retourne le nom du jeu

const std::string& Jeu::getNom() const
{
    return nom_;
}

// Fonction getter (constante) qui retourne le prix du jeu. 

unsigned int Jeu::getPrix() const
{
    return prix_;
}
