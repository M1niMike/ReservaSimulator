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
    bool leFicheiro(string fileName);
    void validaComandos(string cmd);
    vector<string> splitString(const string& cmd) const;
    void buildReserva();
    void buildArea(int x, int y);
    void getInfoAnimal(int x, int y);
    void getInfoAlimento(int x, int y);
    bool verificaCoord(const int& linha, const int& coluna);

    void constantesReaderAndChanger(string fileName);

    //Comandos
    void cmdCriaAnimal(vector<string> comando);
    void cmdCriaAnimalRandom(vector<string> comando);
    void cmdCriaAlimento(vector<string> comando);
    void cmdCriaAlimentoRandom(vector<string> comando);
    void cmdExit();
    void cmdAnim();
    void cmdSee(vector<string> comando);
    string maiscula(string palavra);
    void cmdLoad(vector<string> comando);


    Reserva* getReserva() const {
        return r;
    };

    Simulador(Reserva *r);

    ~Simulador(){
        delete r;
    }

private:
    Reserva *r;

};

#endif //POO_TP_22_23_INTERFACE_H