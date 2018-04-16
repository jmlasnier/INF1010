#ifndef Joueur_H
#define Joueur_H

#include "Equipe.h"
#include <string>

using namespace std;
        
// Cette classe represente un Joueur
class Joueur {
public:
    // Constructeurs
    Joueur () {}
    Joueur(string, string, int, string, string);
	~Joueur();
    // Setters
    void setNom(string);
    void setPrenom(string);
    void setAge(int);
    
    // Getters
    string getNom();
    string getPrenom();
    int getAge();
    string getNomEquipe();
    string getPaysEquipe();
   
    // Associer une equipe � un joueur 
    void associerEquipe(string, string);
    // Enregistrer le Joueur
    void saveJoueur(string);
    // Afficher le Joueur
    void afficher();
    // Chercher un Joueur dans une base de donnees par titre
    Joueur* trouverJoueur(string, string,string);
    //Pour enlever le code duplique de trouverJoueur
    string recherche (string line, int& i);

private:
    // Informations sur le joueur
    string nom;
    string prenom;
    int age;
    // Informations sur l'�quipe
    //D�plac� dans 
	//string teamName;
    //string teamPays;
	Equipe* equipe;
};

#endif 
