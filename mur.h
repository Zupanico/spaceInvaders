/***************************
 *  Auteur :    Nicolas Garant
 *  Fichier :   mur.h
 *  Date :      13/05/2021
 *  But :
 ***************************/
#include <SFML/Graphics.hpp>

using namespace sf;

class mur {
private:
    RectangleShape _posMur;     //Rectangle du mur
    Texture _textureMur;        //Texture du mur
    IntRect _rectSprite;        //Sprite
    int _nbVies;
    const char* textMurs[13] = { "ressources/mur0.bmp", "ressources/mur1.bmp", "ressources/mur2.bmp",
                                 "ressources/mur3.bmp", "ressources/mur4.bmp", "ressources/mur5.bmp",
                                 "ressources/mur6.bmp", "ressources/mur7.bmp", "ressources/mur8.bmp",
                                 "ressources/mur9.bmp", "ressources/mur10.bmp", "ressources/mur11.bmp", "ressources/mur12.bmp" };
    //    {"ressources/mur0.bmp", "ressources/mur1.bmp", "ressources/mur2.bmp",
    //     "ressources/mur3.bmp", "ressources/mur4.bmp", "ressources/mur5.bmp",
    //     "ressources/mur6.bmp", "ressources/mur7.bmp", "ressources/mur8.bmp",
    //     "ressources/mur9.bmp", "ressources/mur10.bmp", "ressources/mur11.bmp"};
public:
    //Constructeurs
    mur();
    mur(int posX, int posY, int _w, int _h, IntRect rectSprinte, int texture);
    void init(int posX, int posY, int _w, int _h, IntRect rectSprinte, int texture); //Initialisateur

    RectangleShape getRectangleShape() const;       //Getteur de rectangleshape

    Vector2f getPosition() const;                   //Getteur de position
    int getX();                                     //Getteur de X
    int getY();                                     //Getteur de Y
    int getVies();                                  //Getteur de Vies

    void hit();                                     //Lorsque les murs sont frappés ont prends cette méthode

    IntRect getIntRect() const;                     //Getteur de Sprite

    Texture getTexture() const;                     //Getteur de Texture

    void setRectangleShape(int posX, int posY, int _w, int _h); //Setteur de RectangleShape

    void setPosition(int posX, int posY);           //Setteur de postition

    void setIntRect(IntRect intRect);               //Setteur de Sprite

    void setTexture(int texture);                   //Setteur de texture

    void print(RenderWindow& window) const;         //Imprime à l'écran
};
