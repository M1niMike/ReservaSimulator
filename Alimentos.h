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
    vector<string> getCheiro() const;
    int getX() const;
    int getY() const;
    int getId() const;

    //sets
    void setId(int newId) { id = newId; }
    void setValimento(int newValimento) { VAlimento = newValimento; }
    void setValorNutri(int newValorNutri) { valorNutri = newValorNutri; }
    void setToxicidade(int newToxicidade) { toxicidade = newToxicidade; }
    void setCheiro(string newCheiro) { cheiro.push_back(newCheiro); }

    //prints
    string PrintaAlimento() const;

    Alimentos(const string& t, int Va, int Vn, int tx, int x, int y);

    Alimentos();

    virtual ~Alimentos() = default;

private:
    string tipo;
    int VAlimento;
    int valorNutri;
    int toxicidade;
    vector<string> cheiro;
    int id;
    int cordX, cordY;
};




#endif //POO_TP_22_23_ALIMENTOS_H
