/***************************
 *  Auteur :    Nicolas Garant
 *  Fichier :   mur.cpp
 *  Date :      13/05/2021
 *  But :
 ***************************/
#include "mur.h"

void mur::init(int posX, int posY, int _w, int _h, IntRect rectSprinte, const char *nomSprite) {
    setRectangleShape(posX, posY, _w, _h);
    _rectSprite = rectSprinte;
    setIntRect(rectSprinte);
    setTexture(nomSprite);
    _nbVies = 0;
}

RectangleShape mur::getRectangleShape() const {
    return _posMur;
}

Vector2f mur::getPosition() const {
    return _posMur.getPosition();
}

IntRect mur::getIntRect() const {
    return _rectSprite;
}

Texture mur::getTexture() const {
    return _textureMur;
}

void mur::setRectangleShape(int posX, int posY, int _w, int _h) {
    _posMur.setSize(Vector2f(_w, _h));
    _posMur.setPosition(posX, posY);
}

void mur::setPosition(int posX, int posY) {
    _posMur.setPosition(posX, posY);
}

void mur::setIntRect(IntRect intRect) {
    _posMur.setTextureRect(intRect);
}

void mur::setTexture(const char *nomSprite) {
    _textureMur.loadFromFile(nomSprite);
    _posMur.setTexture(&_textureMur);//Applique la texture à position
    setIntRect(_rectSprite);
}

void mur::print(RenderWindow &window) const {
    window.draw(_posMur);
}

