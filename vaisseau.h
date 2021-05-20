/***************************
 *  Auteur :    Olivier Leclerc St-Amand
 *  Fichier :   vaisseau.h
 *  Date :      13/05/2021
 *  But :
 ***************************/
#pragma once

#include <SFML/Graphics.hpp>
#include "bonhomme.h"
#include "vaisseau.h"
#include "mur.h"
#include "laser.h"

using namespace sf;

class vaisseau : public bonhomme {

private:

    RectangleShape _vaisseau;
    Texture _textureVaisseau;
    IntRect _rectSprite;


public:

    //CONSTRUCTEUR
    vaisseau();    //	Constructeur sans paramètres;
    vaisseau(float x, float y, int w, int h, IntRect rectImg, const char *nomSprite); //	Constructeur avec paramètres;


    void initialize(float x, float y, int w, int h, IntRect rectImg,
                    const char *nomSprite);        // initialisation de l'alien, position, grosseur, quel info img, int i envoie dans un case switch pour aller chercher le sprite, le booléen si l'alien est vivant;

    //GETTEUR
    RectangleShape getRectangleShape() const;    // retourne _vaisseau
    Vector2f getPosition() const;                //	Retourne la position du vaisseau
    IntRect getIntRect() const;                    //	Retourne les coordonées de l'image
    Texture
    getTexture() const;                    //	Retourne la texture de l'image (case switch pour incrémenter dans le vecteur et bientot pour faire l'animation;


    //SETTEUR
    void setRectangleShape(float x, float y, int w, int h);        //	Setteur de la position et grossseur de l'alien
    void setPosition(float x, float y);                            //	Setteur de la position
    void setIntRect(IntRect rectImg);                            //	Setteur des coordonnées de l'image
    void setTexture(const char *nomSprite);                        //	Setteur de la texture avec switch case;



    // MÉTHODE
    void move(int dir);

    void print(RenderWindow &window);                            //	Dessine l'alien;

};



