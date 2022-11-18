//
// Created by mikae on 07/11/2022.
//

#ifndef POO_TP_22_23_ALIMENTOS_H
#define POO_TP_22_23_ALIMENTOS_H

#include "util.h"

class Alimentos{
public:
    char getTipoAlimento() const {return tipo;}
    Alimentos(const char& t) : tipo(t){};
private:
    char tipo;
};

class Relva : public Alimentos{
public:
    Relva(char t,int VRelva, int valorNutricao, int toxicidade, string cheiro) : Alimentos('r'), VRelva(20), valorNutricao(3), toxicidade(0), cheiro("erva e verdura") {};
private:
    int VRelva;
    int valorNutricao;
    int toxicidade;
    string cheiro;
};

class Cenoura : public Alimentos{
public:
    Cenoura(char t,int VCenoura, int valorNutricao, int toxicidade, string cheiro) : Alimentos('t'), VCenoura(9999), valorNutricao(4), toxicidade(1), cheiro("verdura") {};
private:
    int VCenoura;
    int valorNutricao;
    int toxicidade;
    string cheiro;
};

class Corpo : public Alimentos{
public:
    Corpo(char t,int VCorpo, int valorNutricao, int toxicidade, string cheiro) : Alimentos('p'), VCorpo(9999), valorNutricao(4), toxicidade(1), cheiro("carne") {};
private:
    int VCorpo;
    int valorNutricao;
    int toxicidade;
    string cheiro;
};

class Bife : public Alimentos{
public:
    Bife(char t,int VBife, int valorNutricao, int toxicidade, string cheiro) : Alimentos('b'), VBife(30), valorNutricao(10), toxicidade(2), cheiro("carne e ketchup") {};
private:
    int VBife;
    int valorNutricao;
    int toxicidade;
    string cheiro;
};

class AlimentoMisterio : public Alimentos{
public:
    AlimentoMisterio(char t,int VBanana, int valorNutricao, int toxicidade, string cheiro) : Alimentos('g'), VBanan(20), valorNutricao(2), toxicidade(1), cheiro("fruta") {};
private:
    int VBanan;
    int valorNutricao;
    int toxicidade;
    string cheiro;
};


#endif //POO_TP_22_23_ALIMENTOS_H
