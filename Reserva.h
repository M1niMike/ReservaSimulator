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

    bool hasAnimal();


    //Set
    void setLinhas(int newLinhas);
    void setColunas(int newColunas);

    //Animal
    void criaAnimal(const string& tipo,const int& x, const int& y);
    void criaAnimalRandom(const string& tipo);
    int getNumberOfAnimals() const;
    string getTipoAnimal(string tipo) const;
    string obtemAnimal() const;

    Animais getAnimal(int linha, int coluna);
    Alimentos getAlimento(int linha, int coluna);

    //Alimento
    void criaAlimento(const string& tipo, const int& x, const int& y);
    void criaAlimentoRandom(const string& tipo);
    int getNumberOfFood() const;
    string getTipoAlimento(string tipo) const;
    string obtemAlimento() const;



private:
    int linhas;
    int colunas;
    vector<Animais*> animais;
    vector<Alimentos*> alimentos;
};

#endif //POO_TP_22_23_RESERVA_H
