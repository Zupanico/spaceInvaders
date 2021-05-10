#include <SFML/Graphics.hpp>
#include "laser.h"
#include "bonhomme.h"

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
    int dir;

    player.init(400, 300, 32, 32, IntRect(0, 0, 32, 32), "ressources/charsets.bmp");

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
                }
            }
        }
        time = clock.getElapsedTime(); //Prends le temps de l’horloge
        if (time.asMilliseconds() >= 100.0f) { //à chaque seconde

            player.move(dir);

            window.clear();
            window.draw(fondEcran);

            ifCollision(player);

            player.print(window);
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