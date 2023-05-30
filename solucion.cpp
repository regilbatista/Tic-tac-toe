#include "constantes.h"
#include "solucion.h"
#include "logica.h"

#include <iostream>
using namespace std;


int GetEstado()
{
    char** tab = GetTablero();
    char player = '_';

    // Validación horizontal
    for (int i = 0; i < 3; i++) {
        if (tab[i][0] != '_' && tab[i][0] == tab[i][1] && tab[i][1] == tab[i][2]) {
            player = tab[i][0];
            break;
        }
    }

    // Validación vertical
    if (player == '_') {
        for (int i = 0; i < 3; i++) {
            if (tab[0][i] != '_' && tab[0][i] == tab[1][i] && tab[1][i] == tab[2][i]) {
                player = tab[0][i];
                break;
            }
        }
    }

    // Validación diagonal de izquierda a derecha
    if (player == '_' && tab[0][0] != '_' && tab[0][0] == tab[1][1] && tab[1][1] == tab[2][2]) {
        player = tab[0][0];
    }

    // Validación diagonal de derecha a izquierda
    if (player == '_' && tab[0][2] != '_' && tab[0][2] == tab[1][1] && tab[1][1] == tab[2][0]) {
        player = tab[0][2];
    }

    if (player == 'X') {
        return GANO_X;
    } else if (player == 'O') {
        return GANO_O;
    } else {
        // Verificar si todas las casillas están llenas (empate)
        bool todasLlenas = true;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (tab[i][j] == '_') {
                    todasLlenas = false;
                    break;
                }
            }
            if (!todasLlenas) {
                break;
            }
        }

        if (todasLlenas) {
            return EMPATE;
        } else {
            return JUEGO_EN_CURSO;
        }
    }
}