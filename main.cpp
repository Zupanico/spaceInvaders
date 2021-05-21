/***************************
 *  Auteurs :   Nicolas Garant, Frédérick Perrazelli-Delorme,
 *              Olivier Leclerc-Saint-Amant, Jean-Nyckolas Roy
 *  Fichier :   main.cpp
 *  Date :      13/05/2021
 *  But :       Jeu de Space Invaders en C++ avec la librairie SFML
 *              Contrôllez un vaisseau qui va de gauche à droite
 *              et tirez sur les aliens qui descendent lentement
 *              en tirant des lasers pour vous enlever des vies.
 *              Vous pouvez vous cacher derrière les murs qui se
 *              dégradent à mesure que vous et les aliens tirent
 *              dessus. Si vous êtes touchés, vous perdez une vie
 *              Au bout de 3 vies perdues, c'est Game Over et
 *              vous avez de le choix de recommencer ou non.
 ***************************/
#include <SFML/Audio.hpp>
#include "game.h"

int main() {
    game mainGame;
    mainGame.play();

    return 0;
}