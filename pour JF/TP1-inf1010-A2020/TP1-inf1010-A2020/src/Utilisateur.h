/// Classe qui represente un Utilisateur.
/// \author Simon Gauvin
/// \date 14 septembre 2020

#ifndef UTILISATEUR_H
#define UTILISATEUR_H

#include <ostream>
#include <string>
#include "GestionnaireJeux.h"
#include "Jeu.h"

class Utilisateur
{
public:
    Utilisateur(const std::string& nom, unsigned int age, unsigned int fonds);

    void afficher(std::ostream& stream) const;

    bool acheterJeu(const Jeu* jeu);
    void ajouterFonds(unsigned int fonds);

    std::size_t getNbJeux() const;
    const std::string& getNom() const;
    unsigned int getAge() const;
    unsigned int getFonds() const;

private:
    const Jeu* librairieJeux_[GestionnaireJeux::nbJeuxMax];
    std::size_t nbJeux_;

    std::string nom_;
    unsigned int age_;
    unsigned int fonds_;
};

#endif // UTILISATEUR_H