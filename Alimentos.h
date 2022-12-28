//
// Created by mikae on 07/11/2022.
//

#ifndef POO_TP_22_23_ALIMENTOS_H
#define POO_TP_22_23_ALIMENTOS_H

#include "util.h"


class Alimentos{
public:
    //gets
    string getTipoAlimento() const;
    int getValimento() const;
    int getValorNutri() const;
    int getToxicidade() const;
    string getCheiro() const;
    int getX() const;
    int getY() const;
    int getId() const;

    //sets
    void setId(int newId) {id = newId;}

    //prints
    string PrintaAlimento() const;

    Alimentos(const string& t, int Va, int Vn, int tx, string c, int x, int y);

private:
    string tipo;
    int VAlimento;
    int valorNutri;
    int toxicidade;
    string cheiro;
    int id;
    int cordX, cordY;
};


#endif //POO_TP_22_23_ALIMENTOS_H
