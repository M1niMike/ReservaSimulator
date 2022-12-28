//
// Created by mikae on 28/12/2022.
//

#ifndef RESERVA_H_COELHO_H
#define RESERVA_H_COELHO_H

#include "..\Animais.h"

class Animais;

class Coelho : public Animais{
public:
    Coelho(string tipo, int x, int y) : Animais("c", 20, 0, 0, false, 1) {}
};


#endif //RESERVA_H_COELHO_H
