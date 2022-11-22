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
    int getSaude();
    int getPeso ();
    int getvAnimal();
    int getId(){return id;}

//    int getX() const;
//    int getY() const;

    Animais(const string& t, int Sa, int p, int Va, bool isDead, int id);
private:
    string tipo;
    int sAnimal;
    int peso;
    int vAnimal; // tempo de vida
    bool isDead;
    static int ID;
    int id;
    //int cordX, cordY;
};

//class Coelho : public Animais{
//public:
//    Coelho(char t,int SCoelho, int peso, int VCoelho, bool isDead) : Animais('C'), SCoelho(20), peso((rand() % 4) + 1), VCoelho(0), isDead(false) {};
//
//
//private:
//    int SCoelho;
//    int peso;
//    int VCoelho;
//    bool isDead;
//};


class Coelho : public Animais{
public:
    Coelho(string tipo, int x, int y) : Animais("c", 20, 0, 0, false, 1) {}
};


//class Ovelha : public Animais{
//public:
//    Ovelha(char t, int SOvelha, int peso, int VOvelha, bool isDead) : Animais('O'), SOvelha(30), peso((rand() % 8) + 4), isDead(false) {};
//private:
//    int SOvelha;
//    int peso;
//    int VOvelha;
//    bool isDead;
//};

class Ovelha : public Animais{
public:
    Ovelha(string tipo, int x, int y) : Animais("o", 30, 0, 0, false, 1) {}
};

//class Lobo : public Animais{
//public:
//    Lobo(char t, int SLobo, int peso, int VLobo, bool isDead) : Animais('L'), SLobo(25), peso(15), isDead(false){};
//private:
//    int SLobo;
//    int peso;
//    int VLobo;
//    bool isDead;
//};

class Lobo : public Animais{
public:
    Lobo(string tipo, int x, int y) : Animais("l", 25, 15, 0, false, 1) {}
};

//class Canguru : public Animais{
//public:
//    Canguru(char t, int SCanguru, int peso, int VCanguru, bool isDead) : Animais('C'), SCanguru(20), peso(10), VCanguru(70), isDead(false){};
//private:
//    const int SCanguru;
//    int peso;
//    int VCanguru;
//    bool isDead;
//};

class Canguru : public Animais{
public:
    Canguru(string tipo, int x, int y) : Animais("g", 20, 10, 70, false, 1) {}
};

//class AnimalMisterioso : public Animais{
//public:
//    AnimalMisterioso(char t, int SAnimalMisterio, int peso, int VAnimalMisterio, bool isDead) : Animais('M'), SAnimalMisterio(12 /*depois ver a saude*/), peso(10), VAnimalMisterio(25), isDead(false) {};
//
//private:
//    int SAnimalMisterio;
//    int peso;
//    int VAnimalMisterio;
//    bool isDead;
//};

class AnimalMisterioso : public Animais{
public:
    AnimalMisterioso(string tipo, int x, int y) : Animais("m", 0, 0, 0, false, 1) {}
};

#endif //POO_TP_22_23_ANIMAIS_H
