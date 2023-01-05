//
// Created by mikae on 07/11/2022.
//

#ifndef POO_TP_22_23_ALIMENTOS_H
#define POO_TP_22_23_ALIMENTOS_H

#include "util.h"

class Reserva; // Forma de inibir o include recursivo, falando para o compilador que tal classe vai ser implementada em outro lugar

class Alimentos{
public:
    //gets
    virtual string getTipoAlimento() const;
    int getValimento() const;
    int getValorNutri() const;
    int getToxicidade() const;
    string getCheiro() const;
    int getX() const;
    int getY() const;
    int getId() const;
    bool canBeEaten(){
        return podeSerComido = 1;
    }

    //sets
    void setId(int newId) {id = newId;}

    //prints
    string PrintaAlimento() const;

    Alimentos(const string& t, const string& c, int Va, int Vn, int tx, int x, int y);

    virtual ~Alimentos() = default;

private:
    string tipo;
    int VAlimento;
    int valorNutri;
    int toxicidade;
    string cheiro;
    int id;
    int cordX, cordY;
    int podeSerComido;
};


class Relva : public Alimentos{
public:
    Relva(const string& tipo, const string& c, int VRelva, int Vn, int tx,  int x, int y) : Alimentos(tipo, c, VRelva, Vn, tx,  x, y) {}

    string getTipoAlimento() const override{
        return "r";
    }

};

class Cenoura : public Alimentos{
public:
    Cenoura(const string& tipo, const string& c, int VCenoura, int Vn, int tx, int x, int y) : Alimentos(tipo, c, VCenoura, Vn, tx,  x, y) {}

    string getTipoAlimento() const override {
        return "t";
    }


};



class Corpo : public Alimentos{
public:
    Corpo(const string& tipo, const string& c, int VCorpo, int Vn, int tx, int x, int y) : Alimentos(tipo, c, VCorpo, Vn, tx,  x, y) {}

    string getTipoAlimento() const override{
        return "p";
    }


};

class Bife : public Alimentos{
public:
    Bife(const string& tipo, const string& c, int VBife, int Vn, int tx, int x, int y) : Alimentos(tipo, c, VBife, Vn, tx,  x, y) {}

    string getTipoAlimento() const override{
        return "b";
    }


};




class AlimentoMisterioso : public Alimentos{
public:
    AlimentoMisterioso(const string& tipo, const string& c, int VAlimentoM, int Vn, int tx, int x, int y) : Alimentos(tipo, c, VAlimentoM, Vn, tx,  x, y) {}

    string getTipoAlimento() const override{
        return "a";
    }



};



#endif //POO_TP_22_23_ALIMENTOS_H
