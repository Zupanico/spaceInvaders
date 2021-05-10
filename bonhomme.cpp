//
// Created by nicol on 30/avr./2021.

#include "bonhomme.h"

void bonhomme::init(int posX, int posY, int _w, int _h, IntRect rectSprinte, const char *nomSprite) {

    //Bonhomme
    setRectangleShape(posX, posY, _w, _h);
    _rectSprite = rectSprinte;
    setIntRect(rectSprinte);
    setTexture(nomSprite);
}

RectangleShape bonhomme::getRectangleShape() const {
    return _posBonhomme;
}

Vector2f bonhomme::getPosition() const {
    return _posBonhomme.getPosition();
}

IntRect bonhomme::getIntRect() const {
    return _rectSprite;
}

Texture bonhomme::getTexture() const {
    return _textureBonhomme;
}

void bonhomme::setRectangleShape(int posX, int posY, int _w, int _h) {
    _posBonhomme.setSize(Vector2f(_w, _h));
    _posBonhomme.setPosition(posX, posY);
}

void bonhomme::setPosition(int posX, int posY) {
    _posBonhomme.setPosition(posX, posY);
}

void bonhomme::setIntRect(IntRect intRect) {
    _posBonhomme.setTextureRect(intRect);
}

void bonhomme::setTexture(const char *nomSprite) {
    _textureBonhomme.loadFromFile(nomSprite);
    _posBonhomme.setTexture(&_textureBonhomme);//Applique la texture à position
    setIntRect(_rectSprite);
}

void bonhomme::move(int dir) {

    switch (dir) {

        case 1:
            _posBonhomme.move(Vector2f(0, -10));
            _rectSprite.top = 96; //choisi la bonne ligne selon la direction
//code pour déplacer le carré bleu vers le haut de 10 pixels
//utiliser la méthode move qui est tout désignée pour ça
            break;
        case 2:
            _posBonhomme.move(Vector2f(10, 0));
            _rectSprite.top = 64; //choisi la bonne ligne selon la direction
//code pour déplacer le carré bleu vers la droite de 10 pixels
            break;
        case 3:
            _posBonhomme.move(Vector2f(0, 10));
            _rectSprite.top = 0; //choisi la bonne ligne selon la direction
//code pour déplacer le carré bleu vers le bas de 10 pixels
            break;
        case 4:
            _posBonhomme.move(Vector2f(-10, 0));
            _rectSprite.top = 32; //choisi la bonne ligne selon la direction
//code pour déplacer le carré vers la gauche de 10 pixels
            break;
    }
    _rectSprite.left += 32; //change l’image horizontalement
    if (_rectSprite.left >= 96) //Après 3, on revient à la première à 0
        _rectSprite.left = 0;
    _posBonhomme.setTextureRect(_rectSprite);
}

void bonhomme::print(RenderWindow &window) const {
    window.draw(_posBonhomme);
}


