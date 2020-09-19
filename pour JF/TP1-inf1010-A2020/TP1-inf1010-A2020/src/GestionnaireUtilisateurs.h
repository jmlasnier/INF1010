/// Classe qui gere les utilisateurs.
/// \author Simon Gauvin
/// \date 14 septembre 2020

#ifndef GESTIONNAIREUTILISATEURS_H
#define GESTIONNAIREUTILISATEURS_H

#include <ostream>
#include <string>
#include "Utilisateur.h"
#include "Jeu.h"

class GestionnaireUtilisateurs
{
public:
    GestionnaireUtilisateurs();
    ~GestionnaireUtilisateurs();

    void ajouterUtilisateur(Utilisateur* utilisateur);
    Utilisateur* chercherUtilisateur(const std::string& nomUtilisateur);
    void retirerUtilisateur(const std::string& nomUtilisateur);

    void afficher(std::ostream& stream);

    std::size_t getNbUtilisateurs() const;

private:
    int trouverIndexUtilisateur(const std::string& nomUtilisateur) const;
    void augmenterCapaciteUtilisateurs();

    Utilisateur** utilisateurs_;
    std::size_t nbUtilisateurs_;
    std::size_t capaciteUtilisateurs_;
};

#endif // GESTIONNAIREUTILISATEURS_H