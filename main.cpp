#include "escultor.h"
#include <iostream>

using namespace std;

int main() {
    Sculptor puzzle(250,250,250);

    // Formação do cubo ------------------------------------------
    puzzle.setColor(0.2, 0.2, 0.2, 1);
    puzzle.putBox(1, 17, 1, 17, 1, 17);
    
    puzzle.setColor(0, 0, 0, 1);
    puzzle.putBox(6, 6, 1, 17, 1, 17);
    puzzle.putBox(12, 12, 1, 17, 1, 17);
    puzzle.putBox(1, 17, 6, 6, 1, 17);
    puzzle.putBox(1, 17, 12, 12, 1, 17);
    puzzle.putBox(1, 17, 1, 17, 6, 6);
    puzzle.putBox(1, 17, 1, 17, 12, 12);

    // Primeira dupla ............................................
    // Face vermelha ---------------------------------------------
    // Primeira linha
    puzzle.setColor(1, 0, 0, 1);
    puzzle.putBox(1, 1, 2, 4, 2, 4);
    puzzle.putBox(1, 1, 2, 4, 8, 10);
    puzzle.putBox(1, 1, 2, 4, 14, 16);
    // Segunda linha
    puzzle.putBox(1, 1, 8, 10, 2, 4);
    puzzle.putBox(1, 1, 8, 10, 8, 10);
    puzzle.putBox(1, 1, 8, 10, 14, 16);
    // Terceira linha
    puzzle.setColor(0, 1, 0, 1);
    puzzle.putBox(1, 1, 14, 16, 2, 4);
    puzzle.setColor(0, 0, 1, 1);
    puzzle.putBox(1, 1, 14, 16, 8, 10);
    puzzle.setColor(1, 1, 0, 1);
    puzzle.putBox(1, 1, 14, 16, 14, 16);

    // Face laranja ----------------------------------------------
    // Primeira linha
    puzzle.setColor(1, 0.5, 0, 1);
    puzzle.putBox(17, 17, 2, 4, 2, 4);
    puzzle.putBox(17, 17, 2, 4, 8, 10);
    puzzle.putBox(17, 17, 2, 4, 14, 16);
    // Segunda linha
    puzzle.putBox(17, 17, 8, 10, 2, 4);
    puzzle.putBox(17, 17, 8, 10, 8, 10);
    puzzle.putBox(17, 17, 8, 10, 14, 16);
    // Terceira linha
    puzzle.putBox(17, 17, 14, 16, 2, 4);
    puzzle.putBox(17, 17, 14, 16, 8, 10);
    puzzle.setColor(1, 0, 0, 1);
    puzzle.putBox(17, 17, 14, 16, 14, 16);

    // Segunda dupla..............................................
    // Face branca ----------------------------------------------
    // Primeira linha
    puzzle.setColor(1, 1, 1, 1);
    puzzle.putBox(2, 4, 1, 1, 2, 4);
    puzzle.putBox(2, 4, 1, 1, 8, 10);
    puzzle.putBox(2, 4, 1, 1, 14, 16);
    // Segunda linha
    puzzle.putBox(8, 10, 1, 1, 2, 4);
    puzzle.putBox(8, 10, 1, 1, 8, 10);
    puzzle.putBox(8, 10, 1, 1, 14, 16);
    // Terceira linha
    puzzle.putBox(14, 16, 1, 1, 2, 4);
    puzzle.putBox(14, 16, 1, 1, 8, 10);
    puzzle.putBox(14, 16, 1, 1, 14, 16);

    // Face amarela ----------------------------------------------
    // Primeira linha
    puzzle.setColor(1, 1, 0, 1);
    puzzle.putBox(2, 4, 17, 17, 2, 4);
    puzzle.putBox(2, 4, 17, 17, 8, 10);
    puzzle.setColor(0, 0, 1, 1);
    puzzle.putBox(2, 4, 17, 17, 14, 16);
    // Segunda linha
    puzzle.setColor(1, 1, 0, 1);
    puzzle.putBox(8, 10, 17, 17, 2, 4);
    puzzle.putBox(8, 10, 17, 17, 8, 10);
    puzzle.putBox(8, 10, 17, 17, 14, 16);
    // Terceira linha
    puzzle.setColor(0, 1, 0, 1);
    puzzle.putBox(14, 16, 17, 17, 2, 4);
    puzzle.setColor(1, 1, 0, 1);
    puzzle.putBox(14, 16, 17, 17, 8, 10);
    puzzle.putBox(14, 16, 17, 17, 14, 16);

    // Terceira dupla..............................................
    // Face azul ----------------------------------------------
    // Primeira linha
    puzzle.setColor(0, 0, 1, 1);
    puzzle.putBox(2, 4, 2, 4, 1, 1);
    puzzle.putBox(2, 4, 8, 10, 1, 1);
    puzzle.setColor(1, 0, 0, 1);
    puzzle.putBox(2, 4, 14, 16, 1, 1);
    // Segunda linha
    puzzle.setColor(0, 0, 1, 1);
    puzzle.putBox(8, 10, 2, 4, 1, 1);
    puzzle.putBox(8, 10, 8, 10, 1, 1);
    puzzle.setColor(1, 0, 0, 1);
    puzzle.putBox(8, 10, 14, 16, 1, 1);
    // Terceira linha
    puzzle.setColor(0, 0, 1, 1);
    puzzle.putBox(14, 16, 2, 4, 1, 1);
    puzzle.putBox(14, 16, 8, 10, 1, 1);
    puzzle.setColor(1, 1, 0, 1);
    puzzle.putBox(14, 16, 14, 16, 1, 1);

    // Face Verde ----------------------------------------------
    // Primeira linha
    puzzle.setColor(0, 1, 0, 1);
    puzzle.putBox(2, 4, 2, 4, 17, 17);
    puzzle.putBox(2, 4, 8, 10, 17, 17);
    puzzle.setColor(1, 0.5, 0, 1);
    puzzle.putBox(2, 4, 14, 16, 17, 17);
    // Segunda linha
    puzzle.setColor(0, 1, 0, 1);
    puzzle.putBox(8, 10, 2, 4, 17, 17);
    puzzle.putBox(8, 10, 8, 10, 17, 17);
    puzzle.putBox(8, 10, 14, 16, 17, 17);
    // Terceira linha
    puzzle.setColor(0, 1, 0, 1);
    puzzle.putBox(14, 16, 2, 4, 17, 17);
    puzzle.putBox(14, 16, 8, 10, 17, 17);
    puzzle.setColor(0, 0, 1, 1);
    puzzle.putBox(14, 16, 14, 16, 17, 17);

    puzzle.writeOFF((char*) "puzzle.off");

    return 0;
}