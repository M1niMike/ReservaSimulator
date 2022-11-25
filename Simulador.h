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
    string leFicheiroComandos(Reserva &res,string fileName);
    void validaComandos(Reserva &res, string cmd);
    vector<string> splitString(const string& cmd) const;
    void buildReserva();
    void buildArea(int x, int y);
    void getInfoAnimal(int x, int y);
    void getInfoAlimento(int x, int y);

    //Comandos
    void cmdCriaAnimal(Reserva &res, vector<string> comando);
    void cmdCriaAnimalRandom(Reserva &res, vector<string> comando);
    void cmdCriaAlimento(Reserva &res, vector<string> comando);
    void cmdCriaAlimentoRandom(Reserva &res, vector<string> comando);
    void cmdExit();
    void cmdAnim();
    void cmdInfo(Reserva &res, vector<string> comando);
    string maiscula(string palavra);
    //void cmdInfo();
    /*void cmdLoad(vector<string> comando); need fix*/

    Reserva* getReserva() const {
        return r;
    };

    Simulador(Reserva *r);

private:
    Reserva *r;

};

#endif //POO_TP_22_23_INTERFACE_H
