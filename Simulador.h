//
// Created by mikae on 07/11/2022.
//

#ifndef POO_TP_22_23_SIMULADOR_H
#define POO_TP_22_23_SIMULADOR_H
#include "util.h"
#include "Reserva.h"

class Simulador{
    Reserva *r;

public:
    Simulador(Reserva *aux);

    Reserva* getReserva() const {return r;}
};

#endif //POO_TP_22_23_SIMULADOR_H
