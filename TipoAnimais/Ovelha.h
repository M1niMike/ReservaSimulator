//
// Created by mikae on 28/12/2022.
//

#ifndef RESERVA_H_OVELHA_H
#define RESERVA_H_OVELHA_H

#include "..\Animais.h"

class Animais;

class Ovelha : public Animais{
public:
    Ovelha(string tipo, int x, int y) : Animais("o", 30, 0, 0, false, 1) {}
};


#endif //RESERVA_H_OVELHA_H
