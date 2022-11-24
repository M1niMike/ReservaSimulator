//
// Created by mikae on 07/11/2022.
//

#ifndef POO_TP_22_23_INTERFACE_H
#define POO_TP_22_23_INTERFACE_H

#include "util.h"
#include "Reserva.h"

class Reserva;

class Simulador{
public:
    void runInterface();
    void menuSimulador();
    string leFicheiroComandos(string fileName);
    int leFicheiroValores(string fileName);
    void validaComandos(string cmd);
    vector<string> splitString(const string& cmd) const;
    void buildReserva(Reserva &r);
    void cmdCriaAnimal(vector<string> comando);

    Reserva* getReserva() const {
        return r;
    };

    Simulador(Reserva *r);

private:
    Reserva *r;

};

#endif //POO_TP_22_23_INTERFACE_H
