/***************************
 *  Auteur :    Nicolas Garant
 *  Fichier :   laser.h
 *  Date :      13/05/2021
 *  But :       Classe laser qui peut partir soit du personnage ou de l'alien
 ***************************/
#include <SFML/Graphics.hpp>


using namespace sf;

class laser {
private:
    RectangleShape _posLaser;

public:
    void init(int posX, int posY, int _w, int _h);

    RectangleShape getRectangleShape() const;

    Vector2f getPosition() const;

    void setRectangleShape(int posX, int posY, int _w, int _h);

    void setPosition(int posX, int posY);

    void move(int shoot);

    void print(RenderWindow &window) const;
};


