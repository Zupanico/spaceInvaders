/***************************
 *  Auteur :    Jean-Nyckolas Roy
 *  Fichier :   laser.cpp
 *  Date :      13/05/2021
 *  But :		Manager de toute les fonctionnalité du jeu
 ***************************/
#include <SFML/Graphics.hpp>
#include <time.h>
#include <Windows.h>
#include "game.h"
#define WIDTH 800
#define HEIGHT 600

using namespace sf;

game::game()
{
    _dirAlien = 0;
    _dirPlayer = 0;
    _score = 0;
    _lives = 0;
}

int game::play()
{
    srand(time(NULL));

    int laserCooldown = 0;
    int alienMovingCooldown = 0;
    int alienLaserCooldown = 0;

    bool endGame;

    Font font;			//Police d'écriture pour le jeu
    Text score;			//Texte pour le score
    Text scoreNum;
    Text lives;			//Texte pour les vies
    Text livesNum;
    Text intro;			//Texte pour l'intro

    Clock clock;	//Compteur permettant de contrôler la vitesse du jeu
    Time time;

    RenderWindow window(VideoMode(WIDTH, HEIGHT), "SpaceInvaders");	//Fenêtre principale
    window.setFramerateLimit(60);

    Event event;	//Variable servant à vérifier les évènements tels qu'une touche du clavier appuyée ou relâchée

    RectangleShape fondEcran;	//Rectangle servant de fond d'écran
    RectangleShape ecranDebut;	//Image de début du jeu

    Texture textureDebut;		//Image du début

    while (true) {
        //Fond d'écran
        fondEcran.setSize(Vector2f(WIDTH, HEIGHT));
        fondEcran.setFillColor(Color::Black);


        //Textures et affichage de l'écran de début
        ecranDebut.setPosition(Vector2f(240, 0));
        ecranDebut.setSize(Vector2f(320,224));
        if (!textureDebut.loadFromFile("ressources/start.bmp"))
        {
            return 1;
        }
        ecranDebut.setTexture(&textureDebut);

        setText(score, "SCORE", font, "ressources/SuperLegendBoy.ttf",	//Initiallise le texte pour le score
                10, 10, 24, Color::White, Text::Bold);
        setText(lives, "LIVES", font, "ressources/SuperLegendBoy.ttf",	//Initiallise le texte pour les vies
                WIDTH - 200, 10, 24, Color::White, Text::Bold);
        setText(intro, "Appuyez une touche pour commencer", font, "ressources/SuperLegendBoy.ttf",	//Initialisationion du texte de collision avec
                15, HEIGHT / 2, 24, Color::Green, Text::Bold);

        endGame = false;

        initialize();

        //Affichage intro
        window.draw(fondEcran);
        window.draw(ecranDebut);
        window.draw(intro);

        window.display();

        window.waitEvent(event);
        //Boucle de jeu principale
        while (window.isOpen()) {
            while (window.pollEvent(event)) {
                if (event.type == Event::Closed)	//On ferme la fenêtre si le X est cliqué
                    window.close();
                else if (event.type == Event::KeyPressed) {
                    switch (event.key.code) {
                        case Keyboard::Escape:	//Dans le cas ou la touche Esc est pressée, on ferme la fenêtre
                            window.close();
                            break;
                        case Keyboard::Right:	//Dans le cas ou la touche Right est pressée, la direction change vers la droite
                            _dirPlayer = 2;
                            break;
                        case Keyboard::Left:	//Dans le cas ou la touche Left est pressée, la direction change vers la gauche
                            _dirPlayer = 4;
                            break;
                        case Keyboard::Space:
                            if (laserCooldown == 0) {
                                shoot(_player.getPosition().x + 21, _player.getPosition().y);
                                laserCooldown = 7;
                            }
                            break;
                    }
                }
                else if (event.type == Event::KeyReleased) {
                    switch (event.key.code) {
                        case Keyboard::Right:	//Dans le cas ou la touche Right est pressée, la direction change vers la droite
                            _dirPlayer = 0;
                            break;
                        case Keyboard::Left:	//Dans le cas ou la touche Left est pressée, la direction change vers la gauche
                            _dirPlayer = 0;
                            break;
                    }
                }
            }

            time = clock.getElapsedTime(); //Prends le temps de l’horloge
            if (time.asMilliseconds() >= 80.0f) { //à chaque seconde
                setText(livesNum, to_string(_lives).c_str(), font, "ressources/SuperLegendBoy.ttf",	//Initialisationion du texte de collision avec
                        WIDTH - 32, 10, 24, Color::White, Text::Bold);
                setText(scoreNum, to_string(_score).c_str(), font, "ressources/SuperLegendBoy.ttf",	//Initialisationion du texte de collision avec
                        10, 45, 24, Color::White, Text::Bold);

                _player.move(_dirPlayer);

                if (_player.getPosition().x > WIDTH - 42)
                    _player.move(4);
                else if (_player.getPosition().x < 0)
                    _player.move(2);

                laserMove();
                collisionMur();
                collisionAlien();

                if (collisionPlayer()) {
                    gameOver(window);
                    endGame = true;
                    break;
                }

                //Affichages dse aliens, murs, lasers, vies, score, vaisseau, etc
                window.clear();	//Efface le contenu de la fenêtre
                window.draw(fondEcran);	//Draw le fond d'écran sur la fenêtre
                mursDraw(window);
                laserDraw(window);
                window.draw(score);
                window.draw(scoreNum);
                window.draw(lives);
                window.draw(livesNum);
                alienDraw(window);
                _player.print(window);
                window.display();	//Actualise l'affichage de la fenêtre
                clock.restart(); //remet l’horloge à 0

                //Cooldown de laser pour pas qui tire tout le temps
                if (laserCooldown != 0) {
                    laserCooldown--;
                }

                if (alienMovingCooldown != 0) {
                    alienMovingCooldown--;
                }
                    //Cooldown de mouvement des aliens
                else {
                    alienMovingCooldown = 4;
                    alienMove();
                }

                if (alienLaserCooldown != 0) {
                    alienLaserCooldown--;
                }
                    //Cooldown d'aliens pour pas qui tirent tout le temps
                else {
                    alienLaserCooldown = 7;
                    alienShoot();
                }
            }
        }
    }
}

//Initialise la game
void game::initialize()
{
    IntRect rectSprite(0, 0, 30, 20);
    IntRect rectPlayer(0, 0, 30, 10);
    IntRect rectAlien(0, 0, 32, 32);

    _score = 0;
    _lives = 3;
    _dirPlayer = 0;
    _dirAlien = 2;

    _player.initialize(WIDTH / 2, HEIGHT - 50, 42, 14, rectPlayer, "ressources/player.bmp");

    //Murs
    for (int i = 0; i < 4; i++) {
        _murs[i].init((WIDTH / 4) * i + 60, 440, 100, 80, IntRect(0, 0, 100, 80), 0);
    }

    //Aliens
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 11; j++) {
            if (i == 0) {
                _aliens[i][j].initialize(10 + 45 * j, 100 + 32 * i, 32, 32, rectAlien, 2, true);
            }
            else if (i == 1 || i == 2) {
                _aliens[i][j].initialize(10 + 45 * j, 100 + 32 * i, 32, 32, rectAlien, 1, true);
            }
            else {
                _aliens[i][j].initialize(10 + 45 * j, 100 + 32 * i, 32, 32, rectAlien, 0, true);
            }
        }
    }
}

//Tire les lasers vaisseau
void game::shoot(int posX, int posY)
{
    laserPlayer.push_back(laser(posX, posY, 3, 10, true, Color::Green));
}

//Tire les lasers aliens
void game::alienShoot()
{
    int random = rand() % 11;
    int posX = 0;
    int posY = 0;
    bool shoot = false;

    //Shoot aléatoirement
    while (shoot == false) {
        for (int i = 4; i >= 0; i--) {
            if (_aliens[i][random].isAlive()) {
                shoot = true;
                posY = _aliens[i][random].getPosition().y + 32;
                posX = _aliens[i][random].getPosition().x + 16;
                break;
            }
        }
    }

    laserAlien.push_back(laser(posX, posY, 3, 10, true, Color::Red));
}

//Aliens qui bougent de gauche à droite puis descendent
void game::alienMove()
{
    if (_dirAlien == 2 && _aliens[0][10].getPosition().x > WIDTH - 47) {
        _dirAlien = 32;
    }
    else if (_dirAlien == 4 && _aliens[0][0].getPosition().x < 15) {
        _dirAlien = 34;
    }

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 11; j++) {
            if (_dirAlien == 2)
                _aliens[i][j].move(15, 0);
            else if (_dirAlien == 4)
                _aliens[i][j].move(-15, 0);
            else if (_dirAlien == 32 || _dirAlien == 34)
                _aliens[i][j].move(0, 15);

            _aliens[i][j].changeSprite();
        }
    }

    if (_dirAlien == 32) {
        _dirAlien = 4;
    }
    else if (_dirAlien == 34) {
        _dirAlien = 2;
    }
}

//Laser qui change de coordonnée y pour être tiré.
void game::laserMove()
{
    for (int i = 0; i < laserPlayer.size(); i++) {
        laserPlayer[i].moveUp(15);
        if (laserPlayer[i].getY() < 0) {
            laserPlayer.erase(laserPlayer.begin() + i);
            i--;
        }
    }

    for (int i = 0; i < laserAlien.size(); i++) {
        laserAlien[i].moveDown(15);
    }
}

//Collisions avec le mur pour pas que ça passe au travers
void game::collisionMur()
{
    for (int i = 0; i < laserPlayer.size(); i++) {
        for (int j = 0; j < 4; j++) {
            if (laserPlayer[i].getX() > _murs[j].getX() && laserPlayer[i].getX() < _murs[j].getX() + 100 && _murs[j].getVies() > 0) {
                if (laserPlayer[i].getY() > _murs[j].getY() && laserPlayer[i].getY() < _murs[j].getY() + 80) {
                    laserPlayer.erase(laserPlayer.begin() + i);
                    i--;
                    break;
                }
            }
        }
    }

    for (int i = 0; i < laserAlien.size(); i++) {
        for (int j = 0; j < 4; j++) {
            if (laserAlien[i].getX() > _murs[j].getX() && laserAlien[i].getX() < _murs[j].getX() + 100 && _murs[j].getVies() > 0) {
                if (laserAlien[i].getY() > _murs[j].getY() && laserAlien[i].getY() < _murs[j].getY() + 80) {
                    laserAlien.erase(laserAlien.begin() + i);
                    i--;
                    _murs[j].hit();
                    break;
                }
            }
        }
    }
}

//Collisions du joueur avec le laser des aliens
bool game::collisionPlayer()
{
    for (int i = 0; i < laserAlien.size(); i++) {
        if (laserAlien[i].getX() > _player.getPosition().x && laserAlien[i].getX() < _player.getPosition().x + 42) {
            if (laserAlien[i].getY() > _player.getPosition().y && laserAlien[i].getY() < _player.getPosition().y + 16) {
                laserAlien.erase(laserAlien.begin() + i);
                i--;
                _lives--;
                break;
            }
        }
    }

    if (_lives == 0) {
        return true;
    }

    return false;
}

//Collision du laser du joueur avec les aliens
void game::collisionAlien()
{
    bool sendhelp = false;

    for (int i = 0; i < laserPlayer.size(); i++) {
        for (int j = 0; j < 5; j++) {
            for (int k = 0; k < 11; k++) {
                if (laserPlayer[i].getX() > _aliens[j][k].getPosition().x && laserPlayer[i].getX() < _aliens[j][k].getPosition().x + 32 && _aliens[j][k].isAlive()) {
                    if (laserPlayer[i].getY() > _aliens[j][k].getPosition().y && laserPlayer[i].getY() < _aliens[j][k].getPosition().y + 32) {
                        laserPlayer.erase(laserPlayer.begin() + i);
                        i--;
                        _aliens[j][k].hit();
                        sendhelp = true;
                        break;
                    }
                }
            }
            if (sendhelp == true)
                break;
        }
    }
}

//Imprime les lasers
void game::laserDraw(RenderWindow& window)
{
    for (int i = 0; i < laserPlayer.size(); i++) {
        laserPlayer[i].print(window);
    }

    for (int i = 0; i < laserAlien.size(); i++) {
        laserAlien[i].print(window);
    }
}

//Imprime les murs
void game::mursDraw(RenderWindow& window)
{
    for (int i = 0; i < 4; i++) {
        _murs[i].print(window);
    }
}

//Imprime les aliens
void game::alienDraw(RenderWindow& window)
{
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 11; j++) {
            _aliens[i][j].print(window);
        }
    }
}

//Écran de game over
void game::gameOver(RenderWindow& window)
{
    Texture textureGameOver;
    textureGameOver.loadFromFile("ressources/gameover1.bmp");
    RectangleShape screen;
    screen.setSize(Vector2f(WIDTH, HEIGHT));
    screen.setTexture(&textureGameOver);
    window.draw(screen);
    window.display();
    Sleep(3000);
}

//Set le texte
void game::setText(Text& text, const char* message, Font& font, const char* police,
                   int posX, int posY, int taille, const Color& color, int style) {
    font.loadFromFile(police);

    text.setFont(font); //Set la police à utiliser (elle doit avoir été loadée)
    text.setString(message); //Set le texte à afficher
    text.setCharacterSize(taille); //Set la taille (en pixels)
    text.setFillColor(color); //Set la couleur du texte
    text.setStyle(style); //Set le style du texte
    text.setPosition(posX, posY);
}
