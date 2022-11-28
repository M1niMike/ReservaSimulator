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


/*
class Relva : public Alimentos{
public:
    Relva(string tipo, int x, int y) : Alimentos("r", 20, 3, 0, "erva e verdura", 1) {}
};

class Cenoura : public Alimentos{
public:
    Cenoura(string tipo, int x, int y) : Alimentos("t", 9999, 4, 1, "verdura", 1) {}
};


class Corpo : public Alimentos{
public:
    Corpo(string tipo, int x, int y) : Alimentos("p", 9999, 4, 1, "carne", 1) {}
};

class Bife : public Alimentos{
public:
    Bife(string tipo, int x, int y) : Alimentos("b", 30, 10, 2, "carne e ketchup", 1) {}
};

class AlimentoMisterio : public Alimentos{
public:
    AlimentoMisterio(string tipo, int x, int y) : Alimentos("g", 20, 2, 1, "fruta", 1) {}
};*/


#endif //POO_TP_22_23_ALIMENTOS_H
