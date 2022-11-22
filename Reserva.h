//
// Created by mikae on 07/11/2022.
//

#ifndef POO_TP_22_23_RESERVA_H
#define POO_TP_22_23_RESERVA_H

#include "util.h"
#include "Animais.h"
#include "Alimentos.h"
#include <vector>
class Reserva{
public:
    Reserva(int nl=0, int nc=0);

    //Get
    int getLinhas() const;
    int getColunas() const;

    //Set
    void setLinhas(int newLinhas);
    void setColunas(int newColunas);

    Animais getAnimal(int linha, int coluna);
    Alimentos getAlimento(int linha, int coluna);

    string obtemReserva() const;

    void criaAnimal(const string& tipo,const int& x, const int& y);
    void criaAnimalRandom(const string& tipo);

    int getNumberOfAnimals() const;

private:
    int linhas;
    int colunas;
    int cont = 0;
    vector<Animais*> animais;
};

#endif //POO_TP_22_23_RESERVA_H
