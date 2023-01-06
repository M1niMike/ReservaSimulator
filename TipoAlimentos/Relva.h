//
// Created by mikae on 06/01/2023.
//

#ifndef RESERVA_H_RELVA_H
#define RESERVA_H_RELVA_H

#include "../Alimentos.h"

class Relva : public Alimentos{
public:
    Relva(const string& tipo, const string& c, int VRelva, int Vn, int tx,  int x, int y) : Alimentos(tipo, c, VRelva, Vn, tx,  x, y) {}

    string getTipoAlimento() const override{ return "r"; }

};

#endif //RESERVA_H_RELVA_H
