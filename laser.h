/***************************
 *  Auteur :    Nicolas Garant
 *  Fichier :   laser.h
 *  Date :      13/05/2021
 *  But :       Classe laser qui peut partir soit du personnage ou de l'alien
 ***************************/
#include <SFML/Graphics.hpp>


using namespace sf;

class laser {
private:
    RectangleShape _posLaser;       //Rectangle du laser
    bool _isActive;                 //Regarde si le laser est activé
    bool _enemy;                    //Laser enemi
public:
    laser(int posX, int posY, int _w, int _h, bool isActive, Color color);  //Constructeur par défaut
    void init(int posX, int posY, int _w, int _h, bool isActive);           //initialisateur

    RectangleShape getRectangleShape() const;       //Getteur de RectangleShape

    Vector2f getPosition() const;   //Getteur de position
    int getX();                     //Getteur de X
    int getY();                     //Getteur de Y

    void setRectangleShape(int posX, int posY, int _w, int _h); //Setteur de rectangleshape

    void setPosition(int posX, int posY);                       //Setteur de position

    void move(bool shoot, int posX, int posY);                  //Bouge sur l'axe des Y
    void moveUp(int step);                                      //Bouge vers le haut
    void moveDown(int step);                                    //Bouge vers le bas

    void print(RenderWindow& window) const;                     //Imprime l'écran
};