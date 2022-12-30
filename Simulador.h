//
// Created by mikae on 07/11/2022.
//

#ifndef POO_TP_22_23_INTERFACE_H
#define POO_TP_22_23_INTERFACE_H

#include "util.h"
#include "Reserva.h"

class Reserva;

class Simulador {
public:
    //funcs Auxiliares
    void runInterface();
    void menuSimulador();
    bool leFicheiro(string fileName);
    void validaComandos(string cmd);
    vector<string> splitString(const string &cmd) const;
    void buildReserva();
    void buildArea(int x, int y);
    void getInfoAnimal(int x, int y);
    void getInfoAlimento(int x, int y);
    bool verificaCoord(const int &linha, const int &coluna);
    string maiscula(string palavra);
    int constantesReader(string aux);
    bool leFicheiroConstantes(string fileName);


    //Comandos
    void cmdCriaAnimal(vector<string> comando);
    void cmdCriaAnimalRandom(vector<string> comando);
    void cmdCriaAlimento(vector<string> comando);
    void cmdCriaAlimentoRandom(vector<string> comando);
    void cmdExit();
    void cmdAnim();
    void cmdSee(vector<string> comando);
    void cmdInfo(vector<string> comando);
    void cmdLoad(vector<string> comando);
    void cmdKillAnimalId(vector<string> comando);
    void cmdKillAnimalCoord(vector<string> comando);
    void cmdNoFoodId(vector<string> comando);
    void cmdNoFoodCoord(vector<string> comando);
    void cmdEmpty(vector<string> comando);
    void cmdRestore(vector<string> comando);
    void cmdStore(vector<string> comando);

    Reserva *getReserva() const
    {
        return r;
    };

    Simulador(Reserva *r, Terminal &t);

    /*~Simulador()
    {
        delete r;
    }*/

private:
    Reserva *r;
    map<string, int> mapaConstantes;
    map<string, Reserva*> mapaSave;
    Terminal &t;
    Window cmdW;
    Window textInterface;
    Window reservaPrinter;
};

#endif //POO_TP_22_23_INTERFACE_H