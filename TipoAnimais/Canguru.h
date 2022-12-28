//
// Created by mikae on 28/12/2022.
//

#ifndef RESERVA_H_CANGURU_H
#define RESERVA_H_CANGURU_H

#include "..\Animais.h"

class Animais;

class Canguru : public Animais{
public:
    Canguru(string tipo, int x, int y) : Animais("g", 20, 10, 70, false, 1) {}
};


#endif //RESERVA_H_CANGURU_H
