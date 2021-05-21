/***************************
 *  Auteur :    Nicolas Garant
 *  Fichier :   mur.cpp
 *  Date :      13/05/2021
 *  But :
 ***************************/
#include "mur.h"

//Constructeur vide
mur::mur()
{
    setRectangleShape(0, 0, 0, 0);
    _nbVies = 0;
}

//Construteur par défaut
mur::mur(int posX, int posY, int _w, int _h, IntRect rectSprinte, int texture)
{
    setRectangleShape(posX, posY, _w, _h);
    _rectSprite = rectSprinte;
    setIntRect(rectSprinte);
    setTexture(texture);
    _nbVies = 12;
}

//Initialise le mur
void mur::init(int posX, int posY, int _w, int _h, IntRect rectSprinte, int texture) {
    setRectangleShape(posX, posY, _w, _h);
    _rectSprite = rectSprinte;
    setIntRect(rectSprinte);
    setTexture(texture);
    _nbVies = 12;
}

//Getteur de Rectangle
RectangleShape mur::getRectangleShape() const {
    return _posMur;
}

//Getteur de position
Vector2f mur::getPosition() const {
    return _posMur.getPosition();
}

//Getteur de X
int mur::getX()
{
    return _posMur.getPosition().x;
}

//Getteur de Y
int mur::getY()
{
    return _posMur.getPosition().y;
}

//Getteur de Vies
int mur::getVies()
{
    return _nbVies;
}

//Si mur frappé, perd de la vie
void mur::hit()
{
    if (_nbVies > 0) {
        _nbVies--;
        setTexture(12 - _nbVies);
    }
}

//Getteur IntRect
IntRect mur::getIntRect() const {
    return _rectSprite;
}

//Getteur de texture
Texture mur::getTexture() const {
    return _textureMur;
}

//Setteur de rectangleShape
void mur::setRectangleShape(int posX, int posY, int _w, int _h) {
    _posMur.setSize(Vector2f(_w, _h));
    _posMur.setPosition(posX, posY);
}

//Setteur de position
void mur::setPosition(int posX, int posY) {
    _posMur.setPosition(posX, posY);
}

//Setteur de IntRect
void mur::setIntRect(IntRect intRect) {
    _posMur.setTextureRect(intRect);
}

//Setteur de texture
void mur::setTexture(int texture) {
    _textureMur.loadFromFile(textMurs[texture]);
    _posMur.setTexture(&_textureMur);//Applique la texture à position
    setIntRect(_rectSprite);
}

//Affichage du mur
void mur::print(RenderWindow& window) const {
    window.draw(_posMur);
}