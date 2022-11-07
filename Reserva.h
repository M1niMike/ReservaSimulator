//
// Created by mikae on 07/11/2022.
//

#ifndef POO_TP_22_23_RESERVA_H
#define POO_TP_22_23_RESERVA_H

#include "util.h"

class Reserva{
    int Linhas;
    int Colunas;

public:
    Reserva(int nl=0, int nc=0);

    int getLinhas() const {return Linhas;}
    int getColunas() const {return Colunas;}
};

#endif //POO_TP_22_23_RESERVA_H
