


// *************************************************************
//  IMPLEMANTATION FILE (GestionnaireJeux.cpp)
//  Ce fichier implémente les fonctions membres du fichier GestionnaireJeux qui lui contient les prototypes dans la définition de la classe 
//  \author Jérémie Kerouac (1897211), Jean-François Martin (1901024)
//  \date 15 septembre 2020
// *************************************************************



#include "GestionnaireJeux.h"

#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>

// Constructeur par défaut de la classe GestionnaireJeux

GestionnaireJeux::GestionnaireJeux() : nbJeux_(0)
{
}


// Fonction qui ajoute un jeu si le nombre de jeux dans le tableau de jeux n'a pas déjà atteint sa capacité maximale (nbJeuxMax)

bool GestionnaireJeux::ajouterJeu(const Jeu& jeu)
{
    if (nbJeux_ == nbJeuxMax)
    {
    return false;
    }

    jeux_[nbJeux_] = jeu; // ajoute le jeu à la position nbJeux_, car on incrémente de 0 à n en c++. Donc la position i+1 est la position nbJeux_
    nbJeux_++; // On ajoute un au nombre de jeux
    
    
    return true;

}


//  Fonction qui retrouve le jeu dans le tableau d'objets de jeux. Il retourne un pointeur (adresse) pour le jeu en question, associé à l'indice i.
// On fait une boucle de 0 à 7, car on a seulement 8 jeux maximum. Donc, i < nbJeux_ donnera de 0 à 7 éléments (8 jeux).

const Jeu* GestionnaireJeux::chercherJeu(const std::string& nomJeu) const

{
    
    for (std::size_t i=0; i < nbJeux_; i++)
    {
        //Jeu* ptr = nullptr;
        if (jeux_[i].getNom()==nomJeu)
        {
            return &jeux_[i];
             
        }
    }
    return nullptr; // Si on ne trouve pas le jeu, on retourne le pointeur nul
}

// On charge le fichier en mode lecture avec ifstream. On prend ensuite ligne par ligne, à l'aide d'un objet string initialisé préalablement.

bool GestionnaireJeux::chargerDepuisFichier(const std::string& nomFichier)
{
                std::ifstream fichierJeu(nomFichier);
        


                if (fichierJeu) // vérification si le fichier a été ouvert
                {
                nbJeux_ = 0; // déclaration nbJeux_ = 0 puisque le fichier a été ouvert
                std::string ligne; // on définit un string pour prendre la lecture de chaque ligne du fichier .txt
    

                            while (std::getline(fichierJeu, ligne))
                            {
                                lireLigneJeu(ligne);

                            }
                 std::cout << "Le fichier a été ouvert" << std::endl;
                 return true;
                }

    
   


std::cout << "Le fichier n'a pas été ouvert" << std::endl;
return false;
}




/// Affiche la liste des jeux.
/// \param stream   Le stream dans lequel afficher les jeux.
void GestionnaireJeux::afficher(std::ostream& stream) const
{
    for (std::size_t i = 0; i < nbJeux_; i++)
    {
        jeux_[i].afficher(stream);
        stream << '\n';
    }
}

// Fonction qui donne le nombre de jeux de l'utilisateur

std::size_t GestionnaireJeux::getNbJeux() const
{
    return nbJeux_;  //retour la valeur voulue

}


// On lit chaque ligne comportant un quoted string et un insigned int. Ensuite, on créer un nouveau Jeu avec le nom et le prix extraits. On ajoute ensuite le jeu dans le tableau de jeux.
// \param ligne    La ligne qui comporte les différentes informations du jeu.
// \return         Un bool qui représente si la ligne a été lue correctement.
bool GestionnaireJeux::lireLigneJeu(const std::string& ligne)
{
            std::istringstream stream(ligne);
            std::string nomJeu;
            unsigned int prixJeu;

            if (stream >> std::quoted(nomJeu) && stream >> prixJeu)
            {

                Jeu nouveauJeu(nomJeu, prixJeu);

                    
                    //On fait ceci jeux_[nbJeux_] = nouveauJeu avec la fonction ajouterJeu.Comme nous sommes déjà dans GestionnaireJeux, nous utilisons directement la fonction.
                    //Ceci if (jeux_[nbJeux_ - 1].getNom() != "Inconnu"...On met nbJeux_ - 1, ca on incrémente à partir de 0 en C++) est fait automatiquement avec la fonction ajouterJeu,
                    //si la lecture a fonctionnée, alors le le nom du nouvel objet jeu ne sera pas inconnu et ajouterJeu retournera true.

                if (ajouterJeu(nouveauJeu))            
                {
                    return true;
                }
               
                
            }
            return false;
}
