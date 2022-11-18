//
// Created by mikae on 07/11/2022.
//

#ifndef POO_TP_22_23_INTERFACE_H
#define POO_TP_22_23_INTERFACE_H

#include "util.h"
#include "Reserva.h"

class Simulador{

public:
    static void runInterface();
    static void menuSimulador();
    static string leFicheiroComandos(string fileName);
    static int leFicheiroValores(string fileName);
    void validaComandos(string cmd);
    vector<string> splitString(string cmd) const;
    void printaReserva(Reserva r);


private:
    Reserva *r;

};

#endif //POO_TP_22_23_INTERFACE_H
