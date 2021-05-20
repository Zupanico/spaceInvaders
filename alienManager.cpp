#include "alienManager.h"

// Initialization du vector contenant les objet aliens;
void alienManager::initializeGrille()
{
	IntRect rectImg(0, 0, 32, 32);
	int espace = 10;
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 11; j++) {

			float posX = j * 32 + (espace * j) + 32 * 4;
			float posY = i * 32 + (espace * i * 3) + 32;

			if (i == 0) {
				_invader.emplace_back(alien(posX, posY, 32, 32, rectImg, "ressources/Squid1.bmp", true));	
			}
			if (i == 1 || i == 2) {
				_invader.emplace_back(alien(posX, posY, 32, 32, rectImg, "ressources/Skull1.bmp", true));
			}
			if (i == 3 || i == 4) {
				_invader.emplace_back(alien(posX, posY, 32, 32, rectImg, "ressources/Alien1.bmp", true));
			}
		}
	}
}

//	Les aliens bougent a droite;
void alienManager::moveRight()
{
	for (int i = 0; i < _invader.size(); i++) {
		_invader[i].move(_invader[i].getPosition().x + 10, _invader[i].getPosition().y);
	}
}

//	Les aliens bougent a down;
void alienManager::moveDown()
{
	for (int i = 0; i < _invader.size(); i++) {
		_invader[i].move(_invader[i].getPosition().x, _invader[i].getPosition().y + 10);
	}
}

//	Les aliens bougent a gauce;
void alienManager::moveLeft()
{
	for (int i = 0; i < _invader.size(); i++) {
		_invader[i].move(_invader[i].getPosition().x - 10, _invader[i].getPosition().y);
	}
}

//	Dessine les aliens si il sont vivant;
void alienManager::draw(RenderWindow& window)
{
	for (int i = 0; i < _invader.size(); i++) {
		if (_invader[i].isAlive()) {

			_invader[i].print(window);
		}
	}
}
