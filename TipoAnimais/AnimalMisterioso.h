//
// Created by mikae on 28/12/2022.
//

#ifndef RESERVA_H_ANIMALMISTERIOSO_H
#define RESERVA_H_ANIMALMISTERIOSO_H

#include "..\Animais.h"

class Animais;

class AnimalMisterioso : public Animais{
public:
    AnimalMisterioso(string tipo, int x, int y) : Animais("m", 0, 0, 0, false, 1) {}
};

#endif //RESERVA_H_ANIMALMISTERIOSO_H
