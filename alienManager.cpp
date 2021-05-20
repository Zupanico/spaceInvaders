#include "alienManager.h"

void alienManager::initializeGrille()
{
	alien invader;
	IntRect rectImg(0, 0, 32, 32);
	int espace = 10;
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 11; j++) {

			float posX = j * 32 + (espace * j) + 32 * 4;
			float posY = i * 32 + (espace * i * 3) + 32;

			if (i == 0) {
				invader.initialize(posX, posY, 32, 32, rectImg,"ressources/Squid1.bmp", true);
			}
			if (i == 1 || i == 2) {
				invader.initialize(posX, posY, 32, 32, rectImg,"ressources/Skull1.bmp", true);
			}
			if (i == 3 || i == 4) {
				invader.initialize(posX, posY, 32, 32, rectImg,"ressources/Alien1.bmp", true);
			}
			_invader.push_back(invader);
		}
	}
}

void alienManager::moveRight()
{
	for (int i = 0; i < _invader.size(); i++) {
		_invader[i].move(_invader[i].getPosition().x + 10, _invader[i].getPosition().y);
	}
}

void alienManager::moveDown()
{
	for (int i = 0; i < _invader.size(); i++) {
		_invader[i].move(_invader[i].getPosition().x, _invader[i].getPosition().y + 10);
	}
}

void alienManager::moveLeft()
{
	for (int i = 0; i < _invader.size(); i++) {
		_invader[i].move(_invader[i].getPosition().x - 10, _invader[i].getPosition().y);
	}
}

void alienManager::movementComplet(RenderWindow& window)
{	
	moveRight();
	moveDown();
	moveLeft();
}


void alienManager::draw(RenderWindow& window)
{
	for (int i = 0; i < _invader.size(); i++) {
		if (_invader[i].isAlive()) {

			_invader[i].print(window);
		}
	}
}
