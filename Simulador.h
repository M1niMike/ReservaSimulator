//
// Created by mikae on 07/11/2022.
//

#ifndef POO_TP_22_23_SIMULADOR_H
#define POO_TP_22_23_SIMULADOR_H
#include "util.h"
#include "Reserva.h"

class Simulador{
public:
    Simulador(Reserva *aux);
    const Reserva& getReserva() const {return *r;}
    int leFicheiro();
private:
    Reserva *r;
    static int instantes;
};

#endif //POO_TP_22_23_SIMULADOR_H
