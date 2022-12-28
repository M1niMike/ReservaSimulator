//
// Created by mikae on 28/12/2022.
//

#ifndef RESERVA_H_LOBO_H
#define RESERVA_H_LOBO_H

#include "..\Animais.h"

class Animais;

class Lobo : public Animais{
public:
    Lobo(string tipo, int x, int y) : Animais("l", 25, 15, 0, false, 1) {}
};


#endif //RESERVA_H_LOBO_H
