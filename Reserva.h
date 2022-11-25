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

    bool hasAnimal(int x, int y);

    //Set
    void setLinhas(int newLinhas);
    void setColunas(int newColunas);

    //Animal
    void criaAnimal(const string& tipo,const int& x, const int& y);
    void criaAnimalRandom(const string& tipo);
    int getNumberOfAnimals() const;
    string PrintaAnimal() const;

    vector<Animais*> getVecAnimal() const;
    vector<Alimentos*> getVecAlimento() const;

    //Alimento
    void criaAlimento(const string& tipo, const int& x, const int& y);
    void criaAlimentoRandom(const string& tipo);
    int getNumberOfFood() const;
    //string getTipoAlimento(string tipo) const;
    string PrintaAlimento() const;

    int getTotalCoisas();

//    string getAnimalIn(int x, int y){return animais[x][y].getTipoAnimal();}

private:
    int linhas;
    int colunas;
    vector<Animais*> animais;
    vector<Alimentos*> alimentos;
    int totalCoisas = 1;
};

#endif //POO_TP_22_23_RESERVA_H
