/// Fonction main qui test le programme
/// \author Simon Gauvin
/// \date 14 septembre 2020

#include <iostream>
#include <tuple>
#include <vector>
//#include "DebogageMemoire.h"
#include "GestionnaireUtilisateurs.h"
#include "Jeu.h"
#include "Utilisateur.h"

// TODO: activer tous les tests en remplacant false par true.
#define ACTIVER_TESTS_CLASSE_JEU true
#define ACTIVER_TESTS_CLASSE_GESTIONNAIREJEUX true
#define ACTIVER_TESTS_CLASSE_UTILISATEUR true
#define ACTIVER_TESTS_CLASSE_GESTIONNAIREUTILISATEURS false

int main()
{
    std::vector<bool> testsReussis;
    std::vector<double> ponderations;

#if ACTIVER_TESTS_CLASSE_JEU == true
    {
        Jeu jeu("nom test", 123);

        // Test du constructeur et des fonctions
        testsReussis.push_back(jeu.getNom() == "nom test" && jeu.getPrix() == 123);
        ponderations.push_back(1.0);
    }
#else
    testsReussis.push_back(false);
    ponderations.push_back(0.0);
    std::cout << "Les tests pour la classe Jeu ne sont pas actives.\n";
#endif

#if ACTIVER_TESTS_CLASSE_GESTIONNAIREJEUX == true
    {
        GestionnaireJeux gestionnaireJeux;

        // Test du constructeur par défaut et de la fonction getNbJeux
        testsReussis.push_back(gestionnaireJeux.getNbJeux() == 0); // 0.5
        ponderations.push_back(0.5);

        // Test d'ajout d'un jeu
        gestionnaireJeux.ajouterJeu(Jeu("blablou1", 45));
        testsReussis.push_back(gestionnaireJeux.getNbJeux() == 1);
        ponderations.push_back(0.5);

        // Test sur le nombre de jeux maximum
        gestionnaireJeux.ajouterJeu(Jeu("blablou2", 43));
        gestionnaireJeux.ajouterJeu(Jeu("blablou3", 45));
        gestionnaireJeux.ajouterJeu(Jeu("blablou4", 45));
        gestionnaireJeux.ajouterJeu(Jeu("blablou5", 45));
        gestionnaireJeux.ajouterJeu(Jeu("blablou6", 45));
        gestionnaireJeux.ajouterJeu(Jeu("blablou7", 45));
        gestionnaireJeux.ajouterJeu(Jeu("blablou8", 45));
        std::size_t nbJeuxAvant = gestionnaireJeux.getNbJeux();
        gestionnaireJeux.ajouterJeu(Jeu("blablou9", 45));
        testsReussis.push_back(gestionnaireJeux.getNbJeux() == GestionnaireJeux::nbJeuxMax &&
                                        nbJeuxAvant == GestionnaireJeux::nbJeuxMax);
        ponderations.push_back(0.5);

        // Test sur la recherche des jeux
        const Jeu* jeuExistant = gestionnaireJeux.chercherJeu("blablou2");
        const Jeu* jeuNonExistant = gestionnaireJeux.chercherJeu("blablou14");

        const bool jeuExistantTrouve = jeuExistant != nullptr &&
                                       jeuExistant->getNom() == "blablou2" &&
                                       jeuExistant->getPrix() == 43;
        testsReussis.push_back(jeuExistantTrouve && jeuNonExistant == nullptr);
        ponderations.push_back(0.5);

        // Test sur la lecture du fichier des jeux
        gestionnaireJeux.chargerDepuisFichier("Text.txt");
        gestionnaireJeux.afficher(std::cout);

        const Jeu* ksp = gestionnaireJeux.chercherJeu("Kerbal Space Program");
        const Jeu* fortnite = gestionnaireJeux.chercherJeu("Fortnite");
        const Jeu* gta = gestionnaireJeux.chercherJeu("GTA5");
        const Jeu* fallGuys = gestionnaireJeux.chercherJeu("Fall Guys");

        const bool testLectureFichier =
            ksp != nullptr && ksp->getPrix() == 1200 && fortnite != nullptr &&
            fortnite->getPrix() == 0 && gta != nullptr && gta->getPrix() == 4000 &&
            fallGuys != nullptr && fallGuys->getPrix() == 2200 && gestionnaireJeux.getNbJeux() == 4;

        testsReussis.push_back(testLectureFichier);
        ponderations.push_back(1.0);
    }
#else
    testsReussis.push_back(false);
    ponderations.push_back(0.0);
    testsReussis.push_back(false);
    ponderations.push_back(0.0);
    testsReussis.push_back(false);
    ponderations.push_back(0.0);
    testsReussis.push_back(false);
    ponderations.push_back(0.0);
    testsReussis.push_back(false);
    ponderations.push_back(0.0);
    std::cout << "Les tests pour la classe GestionnaireJeux ne sont pas actives.\n";
#endif

#if ACTIVER_TESTS_CLASSE_UTILISATEUR == true
    {
        // Test pour le constructeur
        Utilisateur utilisateur1("Francis Le Clown", 22, 1200);
        testsReussis.push_back(utilisateur1.getNom() == "Francis Le Clown" && utilisateur1.getAge() == 22 && utilisateur1.getFonds() == 1200);
        ponderations.push_back(0.5);
        
        // Test pour la fonction d'ajout d'un jeu.

        Jeu jeu1("Far Cry 4", 3000); 
        
        // Ne devrait pas ajouter le jeu puisque l'utilisateur n'a pas les fonds requis.
        utilisateur1.acheterJeu(&jeu1);
        std::size_t nombreJeuxApresAchatSansLesFonds = utilisateur1.getNbJeux();

        // Ne devrait pas ajouter de jeu puisqu'il est un pointeur nul.
        utilisateur1.acheterJeu(nullptr);
        std::size_t nombreJeuxApresAjoutPointeurNul = utilisateur1.getNbJeux();

        // Devrait fonctionner;
        utilisateur1.ajouterFonds(3000 - 1200);
        utilisateur1.acheterJeu(&jeu1);
        std::size_t nombreJeuxApresAchatReussi = utilisateur1.getNbJeux();

        // Devrait seulement autoriser le nombre de jeux maximum.
        Jeu jeuGratuit = Jeu("blip", 0);
        for (std::size_t i = 0; i < 43; i++)
        {
            utilisateur1.acheterJeu(&jeuGratuit);
        }

        testsReussis.push_back(nombreJeuxApresAchatSansLesFonds == 0 && nombreJeuxApresAjoutPointeurNul == 0 && nombreJeuxApresAchatReussi == 1 && utilisateur1.getNbJeux() == GestionnaireJeux::nbJeuxMax && utilisateur1.getFonds() == 0);
        ponderations.push_back(0.5);
    }
#else
    testsReussis.push_back(false);
    ponderations.push_back(0.0);
    testsReussis.push_back(false);
    ponderations.push_back(0.0);
    std::cout << "Les tests pour la classe Utilisateur ne sont pas actives.\n";
#endif

#if ACTIVER_TESTS_CLASSE_GESTIONNAIREUTILISATEURS == true
    {
        GestionnaireUtilisateurs gestionnaireUtilisateurs;
        // Test sur l'ajout des utilisateurs
        gestionnaireUtilisateurs.ajouterUtilisateur(new Utilisateur("Francis Le Clown", 22, 2000));
        gestionnaireUtilisateurs.ajouterUtilisateur(new Utilisateur("Jean La Giraffe", 23, 3000));
        gestionnaireUtilisateurs.ajouterUtilisateur(new Utilisateur("Paul La Banane", 24, 4000));
        gestionnaireUtilisateurs.ajouterUtilisateur(new Utilisateur("Guy Le Melon", 25, 5000));

        testsReussis.push_back(gestionnaireUtilisateurs.getNbUtilisateurs() == 4);
        ponderations.push_back(1.0);

        // Test sur la recherche des utilisateurs
        Utilisateur* paul = gestionnaireUtilisateurs.chercherUtilisateur("Paul La Banane");
        testsReussis.push_back(paul != nullptr && paul->getFonds() == 4000 && paul->getAge() == 24);
        ponderations.push_back(0.5);

        // Test sur la supression des utilisateurs
        gestionnaireUtilisateurs.retirerUtilisateur("Francis Le Clown");
        testsReussis.push_back(gestionnaireUtilisateurs.getNbUtilisateurs() == 3 && gestionnaireUtilisateurs.chercherUtilisateur("Francis Le Clown") == nullptr);
        ponderations.push_back(0.5);

        // Affichage des utilisateurs
        if (paul != nullptr)
        {
            Jeu jeuRandom("Jeu Random", 0);
            paul->acheterJeu(&jeuRandom);
        }

        gestionnaireUtilisateurs.afficher(std::cout);
    }
#else
    testsReussis.push_back(false);
    ponderations.push_back(0.0);
    testsReussis.push_back(false);
    ponderations.push_back(0.0);
    testsReussis.push_back(false);
    ponderations.push_back(0.0);
    std::cout << "Les tests pour la classe GestionnaireUtilisateurs ne sont pas actives.\n";
#endif

    std::cout << '\n';
    double totalPonderation = 0.0;
    double totalPoints = 0.0;
    for (std::size_t i = 0; i < ponderations.size() && i < testsReussis.size(); i++)
    {
        totalPonderation += ponderations[i];
        double points = testsReussis[i] ? ponderations[i] : 0;
        totalPoints += points;
        if (ponderations[i] != 0.0)
        {
            std::cout << "Test #" << i + 1 << " : " << points << "/" << ponderations[i] << '\n';
        }
        else
        {
            std::cout << "Test #" << i + 1 << " n'est pas active. Veuillez l'activer pour avoir vos points.\n";
        }
    }

    std::cout << "Total pour les tests: " << totalPoints << '/' << totalPonderation << '\n';
}
