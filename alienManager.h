#pragma once
#include"alien.h"
#include<vector>

using namespace std;

class alienManager {

private:

	vector <alien> _invader;

public:

	// CONSTRUCTEUR
	void initializeGrille();
	
	// Méthode
	void spritePlus();
	void spriteLess();
	void moveRight();
	void moveDown();
	void moveLeft();
	void draw(RenderWindow& window);

};
