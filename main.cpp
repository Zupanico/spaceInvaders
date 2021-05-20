/***************************
 *  Auteurs :   Nicolas Garant, Frédérick Perrazelli-Delorme,
 *              Olivier ???, Jean-Nyckolas Roy
 *  Fichier :   main.cpp
 *  Date :      13/05/2021
 *  But :       Jeu de Space Invaders en C++ avec la librairie SFML
 *              Contrôllez un vaisseau qui va de gauche à droite
 *              et tirez sur les aliens qui descendent lentement
 *              en tirant des lasers pour vous enlever des vies.
 *              Vous pouvez vous cacher derrière les murs qui se
 *              dégradent à mesure que vous et les aliens tirent
 *              dessus. Si vous êtes touchés, vous perdez une vie
 *              Au bout de 3 vies perdues, c'est Game Over et
 *              vous avez de le choix de recommencer ou non.
 ***************************/
#include <SFML/Graphics.hpp>
#include "vaisseau.h"

using namespace sf;

//Protoypes

bool ifCollision(bonhomme &bob);

int main() {
    RenderWindow window(VideoMode(800, 600), "Space Invaders");
    Event event;
    //Variable de temps
    Clock clock;
    Time time;
    bonhomme player;
    RectangleShape fondEcran;
    laser pewpew;
    mur murs[4];

    int posX;
    int posY;
    int dir;
    bool shoot;

    for (int i = 0; i < 4; ++i) {
        murs[i].init((80 + i * (100 + 80)), 400, 100, 75, IntRect(0, 0, 100, 75), "ressources/mur0.bmp");
    }

    pewpew.init(400, 550, 4, 10, false);
    player.init(400, 550, 32, 32, IntRect(0, 0, 32, 32), "ressources/charsets.bmp");
    fondEcran.setSize(Vector2f(800, 600));
    fondEcran.setFillColor(Color::Black);

    while (window.isOpen()) {

        while (window.pollEvent(event)) {
            if (event.type == Event::Closed)
                window.close();
            else if (event.type == Event::KeyPressed) {
                switch (event.key.code) {
                    case Keyboard::Escape:
                        window.close();
                        break;
                    case Keyboard::Up:
                        dir = 1;
//code pour déplacer le carré bleu vers le haut de 10 pixels
//utiliser la méthode move qui est tout désignée pour ça
                        break;
                    case Keyboard::Right:
                        dir = 2;
//code pour déplacer le carré bleu vers la droite de 10 pixels
                        break;
                    case Keyboard::Down:
                        dir = 3;
//code pour déplacer le carré bleu vers le bas de 10 pixels
                        break;
                    case Keyboard::Left:
                        dir = 4;
//code pour déplacer le carré vers la gauche de 10 pixels
                        break;
                    case Keyboard::Space:
                        shoot = true;
                        posX = player.getPosition().x + 16;
                        posY = 550;
                        break;
                }
            }
        }
        time = clock.getElapsedTime(); //Prends le temps de l’horloge
        if (time.asMilliseconds() >= 75.0f) { //à chaque seconde

            player.move(dir);
            posY -= 15;
            pewpew.move(shoot, posX, posY);


            window.clear();
            window.draw(fondEcran);
            ifCollision(player);

            for (int i = 0; i < 4; ++i) {
                murs[i].print(window);
            }

            player.print(window);
            pewpew.print(window);

            window.display();
            clock.restart();
        }
    }
    return 0;
}

bool ifCollision(bonhomme &bob) {
    /**Collisions**/

    //Mur de droite
    if (bob.getPosition().x > 800 - 32) {
        bob.setPosition(800 - 32, bob.getPosition().y);

        return true;
    }
    //Mur de gauche
    if (bob.getPosition().x < 0) {
        bob.setPosition(0, bob.getPosition().y);

        return true;
    }
    //Mur du haut
    if (bob.getPosition().y < 0) {
        bob.setPosition(bob.getPosition().x, 0);

        return true;
    }
    //Mur du bas
    if (bob.getPosition().y > 600 - 32) {
        bob.setPosition(bob.getPosition().x, 600 - 32);

        return true;
    }
    return false;
}