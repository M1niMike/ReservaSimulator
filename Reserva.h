//
// Created by mikae on 07/11/2022.
//

#ifndef POO_TP_22_23_RESERVA_H
#define POO_TP_22_23_RESERVA_H

#include "util.h"

class Reserva{
public:
    Reserva(int nl=0, int nc=0);

    //Get
    int getLinhas() const;
    int getColunas() const;

    //Set
    void setLinhas(int newLinhas);
    void setColunas(int newColunas);

private:
    int linhas;
    int colunas;
};

#endif //POO_TP_22_23_RESERVA_H
