// TODO: inclure l'en-tete de la declaration de la classe
#include <limits>
#include <ostream>
#include <string>
#include "Utilisateur.h"
#include "GestionnaireUtilisateurs.h"


namespace
{
    constexpr std::size_t capaciteInitialeUtilisateurs = 2;
    constexpr int utilisateurNonExistant = -1;
} // namespace

// TODO: Constructeur de la classe.

// TODO: Destructeur de la classe GestionnaireUtilisateurs.

// TODO: void GestionnaireUtilisateurs::ajouterUtilisateur(Utilisateur* utilisateur)

// TODO: Utilisateur* GestionnaireUtilisateurs::chercherUtilisateur(const std::string& nomUtilisateur)

// TODO: void GestionnaireUtilisateurs::retirerUtilisateur(const std::string& nomUtilisateur)

/// Affiche les utilisateurs
/// \param stream   Le stream dans lequel afficher
void GestionnaireUtilisateurs::afficher(std::ostream& stream)
{
    for (std::size_t i = 0; i < nbUtilisateurs_; i++)
    {
        utilisateurs_[i]->afficher(stream);
        stream << '\n';
    }
}


// TODO: getNbUtilisateurs()

// TODO: trouverIndexUtilisateur(const std::string& nomUtilisateur)

/// Augmente la capacité de la liste des utilisateurs.
void GestionnaireUtilisateurs::augmenterCapaciteUtilisateurs()
{
    // Multiplicateur de la taille de la liste lorsqu'elle devient pleine.
    static constexpr unsigned int augmentationCapaciteJeux = 2;

    // TODO
}
