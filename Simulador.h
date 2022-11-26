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
    bool leFicheiroComandos(Reserva &res,string fileName);
    void validaComandos(Reserva &res, string cmd);
    vector<string> splitString(const string& cmd) const;
    void buildReserva();
    void buildArea(Reserva &res, int x, int y);
    void getInfoAnimal(int x, int y);
    void getInfoAlimento(int x, int y);
    bool verificaCoord(Reserva &r, const int& linha, const int& coluna);

    //Comandos
    void cmdCriaAnimal(Reserva &res, vector<string> comando);
    void cmdCriaAnimalRandom(Reserva &res, vector<string> comando);
    void cmdCriaAlimento(Reserva &res, vector<string> comando);
    void cmdCriaAlimentoRandom(Reserva &res, vector<string> comando);
    void cmdExit();
    void cmdAnim();
    void cmdSee(Reserva &res, vector<string> comando);
    string maiscula(string palavra);
    void cmdLoad(Reserva &res, vector<string> comando);


    Reserva* getReserva() const {
        return r;
    };

    Simulador(Reserva *r);

    ~Simulador(){
        cout << "\nAdeus...Reserva...\n";
        delete r;
    }

private:
    Reserva *r;

};

#endif //POO_TP_22_23_INTERFACE_H