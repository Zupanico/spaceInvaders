#pragma once
#include<SFML/Graphics.hpp>
#include<cassert>
using namespace sf; 

class alien {

	private:

		RectangleShape _alien;
		Texture _texture;
		IntRect _rectImg;

		bool _alive;

	public:

		//CONSTRUCTEUR
		void initialize(float x, float y, int w, int h, IntRect rectImg, const char* nomSprite, bool alive);		// initialisation de l'alien, position, grosseur, quel info img, int i envoie dans un case switch pour aller chercher le sprite, le booléen si l'alien est vivant;

		//GETTEUR
		RectangleShape getRectangleShape()const;	// retourne _alien
		Vector2f getPosition()const;				//	Retourne la position de l'alien
		IntRect getRectImg()const;					//	Retourne les coordonées de l'image
		Texture getTexture()const;					//	Retourne la texture de l'image (case switch pour incrémenter dans le vecteur et bientot pour faire l'animation;
		bool isAlive()const;						//	Retourne si l'alien est vivant

		//SETTEUR
		void setRectangleShape(float x, float y, int w, int h);		//	Setteur de la position et grossseur de l'alien
		void setPosition(float x, float y);							//	Setteur de la position
		void setRectImg(IntRect rectImg);							//	Setteur des coordonnées de l'image
		void setTexture(const char* nomSprite);						//	Setteur de la texture avec switch case;
		void setAlive(bool alive);									//	Setteur pour mettre vivant ou non (true false) avec la collision bientot;


		// MÉTHODE
		void move(float posX, float posY);
		void print(RenderWindow& window);							//	Dessine l'alien;

};
