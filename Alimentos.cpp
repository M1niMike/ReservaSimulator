//
// Created by mikae on 07/11/2022.
//

#include "Alimentos.h"
#include "util.h"

Alimentos::Alimentos(const char& t, int Va = 0, int Vn = 0, int tx = 0, string c = "", int x = 0, int y = 0) : tipo(t), vAlimento(Va), valorNutri(Vn), toxicidade(tx), cheiro(c), cordX(x), cordY(y) {}

char Alimentos::getTipoAlimento() const {
    return tipo;
}

int Alimentos::getValimento() {
    return vAlimento;
}

int Alimentos::getValorNutri() {
    return valorNutri;
}

int Alimentos::getToxicidade() {
    return toxicidade;
}

int Alimentos::getX() const {
    return cordX;
}

int Alimentos::getY() const {
    return cordY;
}

string Alimentos::getCheiro() {
    ostringstream oss;

    oss << "(" << cheiro << ")" << endl;

    return oss.str();
}
