#include <iostream>
#include "Joueur.h"

using namespace std;

/*
 * fonction principale
 */
int main(int argc, char** argv) {
    
    Joueur* joueur = new Joueur(); // Création d'un joueur
    string DBFile = "DB.txt"; // Fichier qui contient une base des joueurs
    int choix=1; // Opération séléctionnée par l'utilisateur. Initialisée à 1 pour pouvoir entrer
				 // entrer dans la boucle une première fois. Sera redéfinie au début de la boucle de toute façon
   
	while (choix != 0)
	{
        // Afficher les opérations possibles
        std::cout << std::endl << "--------------------------------------" << std::endl;
        std::cout << "0 - Quitter le programme " << std::endl;
        std::cout << "1 - Créer un joueur " << std::endl;
        std::cout << "2 - Trouver un joueur " << std::endl;
        std::cout << "3 - Afficher un joueur " << std::endl;
        std::cout << "4 - Enregistrer le joueur " << std::endl;
        std::cout << "--------------------------------------" << std::endl;
        // Lire le choi d'utilisateur
        std::cin >> choix;
        switch (choix) 
		{
            case 1:
            {
                // Informations du nouvel joueur
                string nom;
                string prenom;
                int age;
                string nomEquipe;
                string paysEquipe;
                // Demander l'utilisateur de saisir les informatins du nouvel joueur
                std::cout << "Saisir le nom du joueur : " ;
                std::cin >> nom;
                std::cout << "Saisir le prenom du joueur : " ;
                std::cin >> prenom;
                std::cout << "Saisir l'age du joueur : " ;
                std::cin >> age;
                std::cout << "Saisir le nom de l'équipe : " ;
                std::cin >> nomEquipe;
                std::cout << "Saisir le pay de l'équipe : " ;
                std::cin >> paysEquipe;
                // Créer un nouveau joueur
                delete joueur;
                joueur = new Joueur (nom, prenom, age, nomEquipe, paysEquipe);       
                break;
            }
            case 2:
            {
                // Demander l'utilisateur de saisir le nom et le prenom  d'un joueur à chercher dans la base de données
                string nom,prenom;
				std::cout << "Saisir le nom du joueur : " ;
                std::cin >> nom;
                std::cout << "Saisir le prenom du joueur : " ;
                std::cin >> prenom;
				// Chercher l'joueur
                Joueur* tmp = joueur->trouverJoueur(DBFile, nom,prenom);
                if (tmp != NULL) {// Si l'joueur est trouvé
                    joueur = tmp;
		    std::cout << "Joueur trouvé !" << std::endl;	
                } else {
                    std::cout << "Aucun joueur n'est trouvé!" << std::endl;
                }
                break;
            }
            case 3:
            {
                // Afficher le joueur
                if (joueur != NULL) {
                    joueur->afficher();
                } else {
                    std::cout << "Aucun joueur n'est séléctionné" << std::endl;
                }
                break;
            }
            case 4:
            {
                // Enregistrer le joueur dans la base de données.
                if (joueur != NULL){ 
                    joueur->saveJoueur(DBFile);
                    std::cout << "Joueur enregistré !" << std::endl;
                }
            }
        }        
    }
	return 0;
}

