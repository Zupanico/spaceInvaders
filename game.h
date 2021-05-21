/***************************
 *  Auteur :    Jean-Nyckolas Roy
 *  Fichier :   laser.cpp
 *  Date :      13/05/2021
 *  But :		Classe game qui s'occupe des fonctionnalitées du jeu
 ***************************/
#include <vector>
#include "laser.h"
#include "alien.h"
#include "vaisseau.h"
#include "mur.h"
#pragma once

using namespace std;

class game {
private:
    vaisseau _player;			//Vaisseau
    alien _aliens[5][11];		//Aliens
    mur _murs[4];				//Murs
    vector<laser> laserPlayer;	//Laser du joueur
    vector<laser> laserAlien;	//Laser des aliens

    int _dirAlien;				//Direction alien
    int _dirPlayer;				//Direction joueur
    int _score;					//Score
    int _lives;					//Vies
public:
    game();						//Constructeur par défaut

    int play();					//Méthode de jeu
    void initialize();			//Initialise la game
    void shoot(int posX, int posY);	//Tire les pew pews
    void alienShoot();				//Tire les pew pews aliens

    void alienMove();			//Aliens qui bougent
    void laserMove();			//Joueur qui bouge

    void collisionMur();		//Collisions avec le mur
    bool collisionPlayer();		//Collisions avec le player
    void collisionAlien();

    void laserDraw(RenderWindow& window);
    void mursDraw(RenderWindow& window);
    void alienDraw(RenderWindow& window);

    void gameOver(RenderWindow& window);

    void setText(Text& text, const char* message, Font& font, const char* police,
                 int posX, int posY, int taille, const Color& color, int style);
};