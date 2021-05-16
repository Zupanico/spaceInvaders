/***************************
 *  Auteur :    Nicolas Garant
 *  Fichier :   laser.cpp
 *  Date :      13/05/2021
 *  But :
 ***************************/
#include "laser.h"

void laser::init(int posX, int posY, int _w, int _h) {
    setRectangleShape(posX, posY, _w, _h);
}

RectangleShape laser::getRectangleShape() const {
    return _posLaser;
}

Vector2f laser::getPosition() const {
    return _posLaser.getPosition();
}

void laser::setRectangleShape(int posX, int posY, int _w, int _h) {
    _posLaser.setFillColor(Color::Green);
    _posLaser.setSize(Vector2f(_w, _h));
    _posLaser.setPosition(posX, posY);

}

void laser::setPosition(int posX, int posY) {
    _posLaser.setPosition(posX, posY);
}

void laser::move(int shoot) {
    if (shoot == 1) {
        _posLaser.move(Vector2f(0, -10));
    }
}

void laser::print(RenderWindow &window) const {
    window.draw(_posLaser);
}


