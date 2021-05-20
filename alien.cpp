#include "alien.h"

//	Constructeur sans paramètre
alien::alien()
{
	setRectangleShape(0, 0, 32, 32);
	setAlive(true);
}

//	Constructeur avec paramètre
alien::alien(float x, float y, int w, int h, IntRect rectImg,int i, bool alive)
{
	setRectangleShape(x, y, w, h);
	setType(i);
	setRectImg(rectImg);
	setAlive(alive);
}

// Initialize l'alien
void alien::initialize(float x, float y, int w, int h, IntRect rectImg, const char* nomSprite, bool alive)
{
	setRectangleShape(x, y, w, h);
	setTexture(nomSprite);
	setRectImg(rectImg);
	setAlive(alive);
}

// Retourne les valeurs de l'alien
RectangleShape alien::getRectangleShape() const
{
	return _alien;
}

// Retourne la position de l'alien
Vector2f alien::getPosition()const
{
	return _alien.getPosition();
}

int alien::getType() const
{
	return _type;
}

//	Retourne les coordonnées de l'image
IntRect alien::getRectImg() const
{
	return _rectImg;
}

// Retourne la texture;
Texture alien::getTexture() const
{
	return _texture;
}

// Retourne si l'alien est vivant;
bool alien::isAlive()const
{
	return _alive;
}

// Setteur de la position et grosseur de l'alien;
void alien::setRectangleShape(float x, float y, int w, int h)
{
	_alien.setPosition(x, y);
	_alien.setSize(Vector2f(w, h));
}

void alien::setType(int i)
{
	_type = i;
}

//	Setteur de la position
void alien::setPosition(float x, float y)
{
	_alien.setPosition(x, y);
}

//	Setteur des coordonnées image;
void alien::setRectImg(IntRect rectImg)
{
	_alien.setTextureRect(rectImg);
}

// Switch case pour faire animation et initialization de l'alien;
void alien::setTexture(const char* nomSprite)
{
	_texture.loadFromFile(nomSprite);
	_alien.setTexture(&_texture);
}

// Setteur de true false selon si l'alien est vivant;
void alien::setAlive(bool alive)
{
	_alive = alive;
}

void alien::move(float posX, float posY)
{
	_alien.setPosition(posX, posY);
}

// Draw de l'alien;
void alien::print(RenderWindow& window)
{
	window.draw(_alien);
}

