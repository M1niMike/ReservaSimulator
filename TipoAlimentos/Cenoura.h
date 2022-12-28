//
// Created by mikae on 28/12/2022.
//

#ifndef RESERVA_H_CENOURA_H
#define RESERVA_H_CENOURA_H

#include "..\Alimentos.h"

class Alimentos;

class Cenoura : public Alimentos{
public:
    Cenoura(string tipo, int x, int y) : Alimentos("t", 9999, 4, 1, "verdura", 1, 4) {}
};


#endif //RESERVA_H_CENOURA_H
