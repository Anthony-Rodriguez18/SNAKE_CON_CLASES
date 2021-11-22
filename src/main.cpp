/*Grupo: El profesor y las chicas super poderosas        CIENCIA DE LA COMPUTACIÓN I  CCOMP2-1
INTEGRANTES:
- Josue Carpio
- Ariana Leon
- Anthony Rodriguez */
#include "../include/basic.h"

int main()
{
    Game *const game = new Game(WIDTH, HEIGHT);
    game->init();

    delete game;

    return 0;
}