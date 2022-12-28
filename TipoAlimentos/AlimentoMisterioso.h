//
// Created by mikae on 28/12/2022.
//

#ifndef RESERVA_H_ALIMENTOMISTERIOSO_H
#define RESERVA_H_ALIMENTOMISTERIOSO_H

#include "..\Alimentos.h"

class Alimentos;

class AlimentoMisterioso : public Alimentos{
public:
    AlimentoMisterioso(int id, string tipo, int x, int y) : Alimentos("g", 20, 2, 1, "fruta", 1, 3) {}
//    Alimentos(const string& t, int Va, int Vn, int tx, string c, int x, int y);
};



#endif //RESERVA_H_ALIMENTOMISTERIOSO_H
