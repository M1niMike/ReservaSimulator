//
// Created by mikae on 07/11/2022.
//

#ifndef POO_TP_22_23_ANIMAIS_H
#define POO_TP_22_23_ANIMAIS_H

#include "util.h"

class Animais{
public:
    //gets
    string getTipoAnimal () const;
    int getSaude() const;
    int getPeso () const;
    int getvAnimal() const;
    int getId() const {return id;}

    int getX() const;
    int getY() const;

    Animais(const string& t, int Sa, int p, int Va, bool isDead, int id, int x, int y );
private:
    string tipo;
    int sAnimal;
    int peso;
    int vAnimal; // tempo de vida
    bool isDead;
    static int ID;
    int id;
    int cordX, cordY;
};

/*
class Coelho : public Animais{
public:
    Coelho(string tipo, int x, int y) : Animais("c", 20, 0, 0, false, 1) {}
};



class Ovelha : public Animais{
public:
    Ovelha(string tipo, int x, int y) : Animais("o", 30, 0, 0, false, 1) {}
};



class Lobo : public Animais{
public:
    Lobo(string tipo, int x, int y) : Animais("l", 25, 15, 0, false, 1) {}
};



class Canguru : public Animais{
public:
    Canguru(string tipo, int x, int y) : Animais("g", 20, 10, 70, false, 1) {}
};


class AnimalMisterioso : public Animais{
public:
    AnimalMisterioso(string tipo, int x, int y) : Animais("m", 0, 0, 0, false, 1) {}
};*/

#endif //POO_TP_22_23_ANIMAIS_H
