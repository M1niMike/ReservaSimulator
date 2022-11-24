//
// Created by mikae on 07/11/2022.
//

#include "Alimentos.h"
#include "util.h"

int Alimentos::ID = 1;

Alimentos::Alimentos(const string& t, int Va = 0, int Vn = 0, int tx = 0, string c = "", int id = 1, int x = 0, int y = 0) : tipo(t), vAlimento(Va), valorNutri(Vn), toxicidade(tx), cheiro(c), id(ID++), cordX(x), cordY(y) {}


int Alimentos::getValimento() const{
    return vAlimento;
}

int Alimentos::getValorNutri() const{
    return valorNutri;
}

int Alimentos::getToxicidade() const {
    return toxicidade;
}

string Alimentos::getTipoAlimento() const {
    ostringstream oss;

    oss << tipo;

    return oss.str();
}


string Alimentos::getCheiro() const{
    ostringstream oss;

    oss << "(" << cheiro << ")" << endl;

    return oss.str();
}

int Alimentos::getX() const {
    return cordX;
}

int Alimentos::getY() const {
    return cordY;
}
