/***************************
 *  Auteur :    Nicolas Garant
 *  Fichier :   laser.cpp
 *  Date :      13/05/2021
 *  But :
 ***************************/
#include "laser.h"

void laser::init(int posX, int posY, int _w, int _h, bool isActive) {
    setRectangleShape(posX, posY, _w, _h);
}

RectangleShape laser::getRectangleShape() const {
    return _posLaser;
}

Vector2f laser::getPosition() const {
    return _posLaser.getPosition();
}

void laser::setRectangleShape(int posX, int posY, int _w, int _h) {
    _posLaser.setFillColor(Color::Transparent);
    _posLaser.setSize(Vector2f(_w, _h));
    _posLaser.setPosition(posX, posY);

}

void laser::setPosition(int posX, int posY) {
    _posLaser.setPosition(posX, posY);
}

void laser::move(bool shoot, int posX, int posY) {
    if (shoot) {
        _posLaser.setPosition(posX, posY);
        _posLaser.setFillColor(Color::Green);
    }
}

void laser::print(RenderWindow &window) const {
    if (_isActive)      //Si le Laser est activé il sera imprimé
        window.draw(_posLaser);
}


