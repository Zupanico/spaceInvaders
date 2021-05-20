/***************************
 *  Auteur :    Olivier leclerc St-Amand
 *  Fichier :   vaisseau.cpp
 *  Date :      13/05/2021
 *  But :
 ***************************/
#include "vaisseau.h"

 //	Constructeur sans paramètre
vaisseau::vaisseau()
{
	setRectangleShape(0, 0, 32, 32);
}

//	Constructeur avec paramètre
vaisseau::vaisseau(float x, float y, int w, int h, IntRect rectImg, const char* nomSprite)
{
	setRectangleShape(x, y, w, h);
	setTexture(nomSprite);
	setIntRect(rectImg);
}

// Initialize le vaisseau
void vaisseau::initialize(float x, float y, int w, int h, IntRect rectImg, const char* nomSprite)
{
	setRectangleShape(x, y, w, h);
	setTexture(nomSprite);
	setIntRect(rectImg);
}

// Retourne les valeurs du vaisseau
RectangleShape vaisseau::getRectangleShape() const
{
	return _vaisseau;
}

// Retourne la position du vaisseau
Vector2f vaisseau::getPosition()const
{
	return _vaisseau.getPosition();
}

//	Retourne les coordonnées de l'image
IntRect vaisseau::getIntRect() const
{
	return _rectSprite;
}

// Retourne la texture;
Texture vaisseau::getTexture() const
{
	return _textureVaisseau;
}


// Setteur de la position et grosseur du vaisseau;
void vaisseau::setRectangleShape(float x, float y, int w, int h)
{
	_vaisseau.setPosition(x, y);
	_vaisseau.setSize(Vector2f(w, h));
}

//	Setteur de la position
void vaisseau::setPosition(float x, float y)
{
	_vaisseau.setPosition(x, y);
}

//	Setteur des coordonnées image;
void vaisseau::setIntRect(IntRect rectImg)
{
	_vaisseau.setTextureRect(rectImg);
}

// Switch case pour faire animation et initialization du vaisseau;
void vaisseau::setTexture(const char* nomSprite)
{
	_textureVaisseau.loadFromFile(nomSprite);
	_vaisseau.setTexture(&_textureVaisseau);
    setIntRect(_rectSprite);
}


void vaisseau::move(int dir)
{
    switch (dir) {

    case 4:
		_vaisseau.move(Vector2f(-10, 0));
		break;
    case 2:
        _vaisseau.move(Vector2f(10, 0));
        break; 
    }
    _rectSprite.left += 32; //change l’image horizontalement
    if (_rectSprite.left >= 96) //Après 3, on revient à la première à 0
        _rectSprite.left = 0;
    _vaisseau.setTextureRect(_rectSprite);
}

// Draw de l'alien;
void vaisseau::print(RenderWindow& window)
{
	window.draw(_vaisseau);
}

