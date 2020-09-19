/// Classe de la gestion des jeux.
/// \author Simon Gauvin
/// \date 14 septembre 2020

#ifndef GESTIONNAIREJEUX_H
#define GESTIONNAIREJEUX_H

#include <ostream>
#include <string>
#include "Jeu.h"

class GestionnaireJeux
{
public:
    GestionnaireJeux();

    bool ajouterJeu(const Jeu& jeu);
    const Jeu* chercherJeu(const std::string& nomJeu) const;
    bool chargerDepuisFichier(const std::string& nomFichier);
    void afficher(std::ostream& stream) const;

    std::size_t getNbJeux() const;

    static constexpr std::size_t nbJeuxMax = 8;

private:
    bool lireLigneJeu(const std::string& ligne);

    Jeu jeux_[nbJeuxMax];
    std::size_t nbJeux_;
};

#endif // GESTIONNAIREJEUX_H
