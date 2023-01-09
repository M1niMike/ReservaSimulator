//
// Created by mikae on 06/01/2023.
//

#ifndef RESERVA_H_CORPO_H
#define RESERVA_H_CORPO_H


#include "../Alimentos.h"

class Corpo : public Alimentos{
public:
    Corpo(const string& tipo, int VCorpo, int Vn, int tx, int x, int y) : Alimentos(tipo, VCorpo, Vn, tx,  x, y) {
        setCheiro("carne");
    }

    string getTipoAlimento() const override{ return "p"; }


};

#endif //RESERVA_H_CORPO_H
