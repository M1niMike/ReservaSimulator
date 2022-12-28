//
// Created by mikae on 28/12/2022.
//

#ifndef RESERVA_H_RELVA_H
#define RESERVA_H_RELVA_H

#include "..\Alimentos.h"

class Alimentos;

class Relva : public Alimentos{
public:
    Relva(string tipo, int x, int y) : Alimentos("r", 20, 3, 0, "erva e verdura", 1, 6) {}
};



#endif //RESERVA_H_RELVA_H
