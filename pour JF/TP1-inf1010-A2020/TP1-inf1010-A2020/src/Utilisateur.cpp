// *************************************************************
//  IMPLEMANTATION FILE (Utilisateur.cpp)
//  Ce fichier implémente les fonctions membres du fichier Utilisateur qui lui contient les prototypes dans la définition de la classe 
//  \author Jérémie Kerouac (1897211), Jean-François Martin (1901024)
//  \date 15 septembre 2020
// *************************************************************
#include "Jeu.h"
#include "GestionnaireJeux.h"
#include "Utilisateur.h"

// Constructeur par paramètres 
Utilisateur::Utilisateur(const std::string& nom, unsigned int age, unsigned int fonds) : nom_(nom), age_(age), fonds_(fonds), nbJeux_(0), librairieJeux_{ nullptr }
{
    
}

/// Affiche l'utilisateur
/// \param stream   Le stream dans lequel afficher l'utilisateur.
void Utilisateur::afficher(std::ostream& stream) const
{
    stream << nom_ << " (" << age_ << " ans). Fonds: " << fonds_ << "$. ";
    stream << "Jeux: [";
    for (std::size_t i = 0; i < nbJeux_; i++)
    {
        stream << librairieJeux_[i]-> getNom();
        if (i != nbJeux_ -1)
        {
            stream << ',';
        }
    }
    stream << ']';
}


// Fonction qui prend en entrée un pointeur à un objet de type Jeu et l'ajoute dans la librairieJeux_ de l'utilisateur
bool Utilisateur::acheterJeu(const Jeu* jeu)
{
    // Les conditions à respecter (consignes du tp). Si une des conditions n'est pas respectée, alors on donne false
    //On peut utiliser ceci, qui prend explicitement l'attribut privé, mais on peut utiliser la fonction membre getNbJeux()
    //if (nbJeux_ == GestionnaireJeux::nbJeuxMax || jeu == (nullptr)|| fonds_ < jeu->getPrix())


    if (getNbJeux() == GestionnaireJeux::nbJeuxMax || jeu == (nullptr) || fonds_ < jeu->getPrix()) 
    {
        return false;
    }
    
    // Enlève le montant associé au jeu de l'utilisateur
    // Ou (*jeu).getprix()
    fonds_ -= jeu->getPrix();
    
    
    // On ajoute le jeu à la position nbJeux_, car ils sont indexés de 0 à 7. Donc nbJeux_ est la position i+1, où i est le dernier jeu dans la librairie.
    // Aussi, on vérifie que i < nbJeux_, car à la position i=7 nous sommes au 8e jeux et c'est le maximum. 
    //librairieJeux_[nbJeux_]=jeu. Ici, on prend une boucle for pour s'assurer de ne pas écrire par-dessus un jeu déjà dans la bibliothèque de l'utilisateur

    for (std::size_t i = 0; i < nbJeux_ ; i++)
    {
        if (librairieJeux_[i] == nullptr)
        {
            librairieJeux_[i] = jeu;
            nbJeux_++;
        }
    }
   
    return true;

}

// Fonction void, car elle ne retourne rien. On ajoute avec += les fonds à l'attribut fonds_

void Utilisateur::ajouterFonds(unsigned int fonds)
{
    fonds_ += fonds; 
}

// Fonction qui retourne le nombre de jeux de l'utilisateur
std::size_t Utilisateur::getNbJeux() const
{
    return nbJeux_;


}

// Fonction qui retourne le nom de l'utilisateur, constante puisque c'est un getter qui ne change pas la valeur de l'attribut

const std::string& Utilisateur::getNom() const
{
    return nom_;
}

// Fonction qui retourne l'âge de l'utilisateur, constante puisque c'est un getter qui ne change pas la valeur de l'attribut
unsigned int Utilisateur::getAge() const
{
    return age_;
}
// Fonction qui retourne les fonds de l'utilisateur, constante puisque c'est un getter qui ne change pas la valeur de l'attribut

unsigned int Utilisateur::getFonds() const

{
    return fonds_;
}