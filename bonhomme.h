/***************************
 *  Auteur :    Nicolas Garant
 *  Fichier :   bonhomme.h
 *  Date :      13/05/2021
 *  But :
 ***************************/

#include <SFML/Graphics.hpp>

using namespace sf; //en mettant ce namespace, ça évite des sf::

class bonhomme {
protected:
    RectangleShape _posBonhomme;
    Texture _textureBonhomme;
    IntRect _rectSprite;
public:
    void init(int posX, int posY, int _w, int _h,
              IntRect rectSprinte, const char *nomSprite);

    RectangleShape getRectangleShape() const;

    Vector2f getPosition() const;

    IntRect getIntRect() const;

    Texture getTexture() const;

    void setRectangleShape(int posX, int posY, int _w, int _h);

    void setPosition(int posX, int posY);

    void setIntRect(IntRect intRect);

    void setTexture(const char *nomSprite);

    void move(int dir);

    void print(RenderWindow &window) const;
};