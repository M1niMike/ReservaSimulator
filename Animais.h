//
// Created by mikae on 07/11/2022.
//

#ifndef POO_TP_22_23_ANIMAIS_H
#define POO_TP_22_23_ANIMAIS_H

#include "util.h"

class Animais{
    char tipo;
public:
    char getTipoAnimal () const {return tipo;}
    Animais(const char& t) : tipo(t){};
};

class Coelho : public Animais{
public:
    Coelho(char t,int SCoelho, int peso, int VCoelho, bool isDead) : Animais('C'), SCoelho(20), peso((rand() % 4) + 1), VCoelho(0), isDead(false) {};
private:
    int SCoelho;
    int peso;
    int VCoelho;
    bool isDead;
};

class Ovelha : public Animais{
public:
    Ovelha(char t, int SOvelha, int peso, int VOvelha, bool isDead) : Animais('O'), SOvelha(30), peso((rand() % 8) + 4), isDead(false) {};
private:
    int SOvelha;
    int peso;
    int VOvelha;
    bool isDead;
};

class Lobo : public Animais{
public:
    Lobo(char t, int SLobo, int peso, int VLobo, bool isDead) : Animais('L'), SLobo(25), peso(15), isDead(false){};
private:
    int SLobo;
    int peso;
    int VLobo;
    bool isDead;
};

class Canguru : public Animais{
public:
    Canguru(char t, int SCanguru, int peso, int VCanguru, bool isDead) : Animais('C'), SCanguru(20), peso(10), VCanguru(70), isDead(false){};
private:
    const int SCanguru;
    int peso;
    int VCanguru;
    bool isDead;
};

class AnimalMisterioso : public Animais{
public:
    AnimalMisterioso(char t, int SAnimalMisterio, int peso, int VAnimalMisterio, bool isDead) : Animais('M'), SAnimalMisterio(12 /*depois ver a saude*/), peso(10), VAnimalMisterio(25), isDead(false) {};

private:
    int SAnimalMisterio;
    int peso;
    int VAnimalMisterio;
    bool isDead;
};

#endif //POO_TP_22_23_ANIMAIS_H
