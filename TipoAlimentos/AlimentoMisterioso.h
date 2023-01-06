//
// Created by mikae on 06/01/2023.
//

#ifndef RESERVA_H_ALIMENTOMISTERIOSO_H
#define RESERVA_H_ALIMENTOMISTERIOSO_H

#include "../Alimentos.h"

class AlimentoMisterioso : public Alimentos{
public:
    AlimentoMisterioso(const string& tipo, const string& c, int VAlimentoM, int Vn, int tx, int x, int y) : Alimentos(tipo, c, VAlimentoM, Vn, tx,  x, y) {}

    string getTipoAlimento() const override{ return "a"; }



};

#endif //RESERVA_H_ALIMENTOMISTERIOSO_H
