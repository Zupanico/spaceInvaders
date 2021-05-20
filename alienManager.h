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
	
	void moveRight();
	void moveDown();
	void moveLeft();
	void movementComplet(RenderWindow& window);

	void draw(RenderWindow& window);

};