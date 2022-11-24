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

    int leFicheiroValores(string fileName);
    string leFicheiroComandos(Reserva &r,string fileName);
    void validaComandos(Reserva &r, string cmd);
    vector<string> splitString(const string& cmd) const;
    void buildReserva();

    //Comandos
    void cmdCriaAnimal(Reserva &r, vector<string> comando);
    void cmdCriaAnimalRandom(vector<string> comando);
    void cmdCriaAlimento(vector<string> comando);
    void cmdCriaAlimentoRandom(vector<string> comando);
    void cmdExit();
    void cmdAnim();
    /*void cmdLoad(vector<string> comando); need fix*/

    Reserva* getReserva() const {
        return r;
    };

    Simulador(Reserva *r);

private:
    Reserva *r;

};

#endif //POO_TP_22_23_INTERFACE_H
