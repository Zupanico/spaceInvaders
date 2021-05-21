/***************************
 *  Auteur :    Nicolas Garant
 *  Fichier :   laser.cpp
 *  Date :      13/05/2021
 *  But :
 ***************************/
#include "laser.h"
//Constructeur par défaut
laser::laser(int posX, int posY, int _w, int _h, bool isActive, Color color)
{
    setPosition(posX, posY);
    _posLaser.setSize(Vector2f(_w, _h));
    _isActive = isActive;
    _posLaser.setFillColor(color);
}

//Initialise
void laser::init(int posX, int posY, int _w, int _h, bool isActive) {
    setRectangleShape(posX, posY, _w, _h);
}


//Getteur RectangleShape
RectangleShape laser::getRectangleShape() const {
    return _posLaser;
}

//Getteur Position
Vector2f laser::getPosition() const {
    return _posLaser.getPosition();
}

//Getteur X
int laser::getX()
{
    return _posLaser.getPosition().x;
}

//Getteur Y
int laser::getY()
{
    return _posLaser.getPosition().y;
}

//Setteur rectangle
void laser::setRectangleShape(int posX, int posY, int _w, int _h) {
    _posLaser.setFillColor(Color::Transparent);
    _posLaser.setSize(Vector2f(_w, _h));
    _posLaser.setPosition(posX, posY);

}

//Setteur Position
void laser::setPosition(int posX, int posY) {
    _posLaser.setPosition(posX, posY);
}

//Move de laser
void laser::move(bool shoot, int posX, int posY) {
    if (shoot) {
        _posLaser.setPosition(posX, posY);
        _posLaser.setFillColor(Color::Green);
    }
}

//Move mais en haut
void laser::moveUp(int step)
{
    setPosition(_posLaser.getPosition().x, _posLaser.getPosition().y - step);
}

//Move mais en bas
void laser::moveDown(int step)
{
    setPosition(_posLaser.getPosition().x, _posLaser.getPosition().y + step);

}

//Affichage
void laser::print(RenderWindow& window) const {
    if (_isActive)      //Si le Laser est activé il sera imprimé
        window.draw(_posLaser);
}