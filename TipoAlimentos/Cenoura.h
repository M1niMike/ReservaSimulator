//
// Created by mikae on 06/01/2023.
//

#ifndef RESERVA_H_CENOURA_H
#define RESERVA_H_CENOURA_H

#include "../Alimentos.h"

class Cenoura : public Alimentos{
public:
    Cenoura(const string& tipo, int VCenoura, int Vn, int tx, int x, int y) : Alimentos(tipo, VCenoura, Vn, tx,  x, y) {
        setCheiro("verdura");
    }

    string getTipoAlimento() const override { return "t"; }


};


#endif //RESERVA_H_CENOURA_H
