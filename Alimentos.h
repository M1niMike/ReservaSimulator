//
// Created by mikae on 07/11/2022.
//

#ifndef POO_TP_22_23_ALIMENTOS_H
#define POO_TP_22_23_ALIMENTOS_H

#include "util.h"

class Alimentos{
public:
    //gets
    char getTipoAlimento() const;
    int getValimento();
    int getValorNutri();
    int getToxicidade();
    string getCheiro();
    int getX() const;
    int getY() const;

    Alimentos(const char& t, int Va, int Vn, int tx, string c, int x, int y);
private:
    char tipo;
    int vAlimento;
    int valorNutri;
    int toxicidade;
    string cheiro;
    int cordX, cordY;
};

//class Relva : public Alimentos{
//public:
//    Relva(char t,int VRelva, int valorNutricao, int toxicidade, string cheiro) : Alimentos('r'), VRelva(20), valorNutricao(3), toxicidade(0), cheiro("erva e verdura") {};
//private:
//    int VRelva;
//    int valorNutricao;
//    int toxicidade;
//    string cheiro;
//};

class Relva : public Alimentos{
public:
    Relva(char tipo) : Alimentos('r', 20, 3, 0, "erva e verdura", 0 , 0) {}
};

//class Cenoura : public Alimentos{
//public:
//    Cenoura(char t,int VCenoura, int valorNutricao, int toxicidade, string cheiro) : Alimentos('t'), VCenoura(9999), valorNutricao(4), toxicidade(1), cheiro("verdura") {};
//private:
//    int VCenoura;
//    int valorNutricao;
//    int toxicidade;
//    string cheiro;
//};

class Cenoura : public Alimentos{
public:
    Cenoura(char tipo) : Alimentos('t', 9999, 4, 1, "verdura", 0 , 1) {}
};

//class Corpo : public Alimentos{
//public:
//    Corpo(char t,int VCorpo, int valorNutricao, int toxicidade, string cheiro) : Alimentos('p'), VCorpo(9999), valorNutricao(4), toxicidade(1), cheiro("carne") {};
//private:
//    int VCorpo;
//    int valorNutricao;
//    int toxicidade;
//    string cheiro;
//};

class Corpo : public Alimentos{
public:
    Corpo(char tipo) : Alimentos('p', 9999, 4, 1, "carne", 0 , 2) {}
};


//class Bife : public Alimentos{
//public:
//    Bife(char t,int VBife, int valorNutricao, int toxicidade, string cheiro) : Alimentos('b'), VBife(30), valorNutricao(10), toxicidade(2), cheiro("carne e ketchup") {};
//private:
//    int VBife;
//    int valorNutricao;
//    int toxicidade;
//    string cheiro;
//};

class Bife : public Alimentos{
public:
    Bife(char tipo) : Alimentos('b', 30, 10, 2, "carne e ketchup", 0 , 3) {}
};


//class AlimentoMisterio : public Alimentos{
//public:
//    AlimentoMisterio(char t,int VBanana, int valorNutricao, int toxicidade, string cheiro) : Alimentos('g'), VBanan(20), valorNutricao(2), toxicidade(1), cheiro("fruta") {};
//private:
//    int VBanan;
//    int valorNutricao;
//    int toxicidade;
//    string cheiro;
//};

class AlimentoMisterio : public Alimentos{
public:
    AlimentoMisterio(char tipo) : Alimentos('g', 20, 2, 1, "fruta", 0 , 4) {}
};


#endif //POO_TP_22_23_ALIMENTOS_H
