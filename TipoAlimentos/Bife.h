//
// Created by mikae on 06/01/2023.
//

#ifndef RESERVA_H_BIFE_H
#define RESERVA_H_BIFE_H

#include "../Alimentos.h"


class Bife : public Alimentos{
public:
    Bife(const string& tipo, int VBife, int Vn, int tx, int x, int y) : Alimentos(tipo, VBife, Vn, tx,  x, y) {
        setCheiro("carne");
        setCheiro("ketchup");
    }

    string getTipoAlimento() const override{ return "b"; }

};



#endif //RESERVA_H_BIFE_H
