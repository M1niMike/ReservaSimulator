//
// Created by mikae on 28/12/2022.
//

#ifndef RESERVA_H_BIFE_H
#define RESERVA_H_BIFE_H

#include "..\Alimentos.h"

class Alimentos;

class Bife : public Alimentos{
public:
    Bife(string tipo, int x, int y) : Alimentos("b", 30, 10, 2, "carne e ketchup", 1, 2) {}
};



#endif //RESERVA_H_BIFE_H
