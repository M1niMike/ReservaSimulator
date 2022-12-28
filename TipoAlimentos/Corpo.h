//
// Created by mikae on 28/12/2022.
//

#ifndef RESERVA_H_CORPO_H
#define RESERVA_H_CORPO_H

#include "..\Alimentos.h"

class Alimentos;

class Corpo : public Alimentos{
public:
    Corpo(string tipo, int x, int y) : Alimentos("p", 9999, 4, 1, "carne", 1, 5) {}
};

#endif //RESERVA_H_CORPO_H
