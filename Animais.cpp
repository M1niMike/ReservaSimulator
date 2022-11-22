//
// Created by mikae on 07/11/2022.
//

#include "Animais.h"
#include "util.h"

int Animais::ID = 1;

Animais::Animais(const string& t, int Sa = 0, int p = 0, int Va = 0, bool isDead = false, int id = 1) : tipo(t), sAnimal(Sa), peso(p), vAnimal(Va), isDead(isDead), id(ID++){

}

string Animais::getTipoAnimal() const {
    ostringstream oss;

    oss << tipo << endl;

    return oss.str();
}

int Animais::getSaude() {
    return sAnimal;
}

int Animais::getPeso() {
    return peso;
}

int Animais::getvAnimal() {
    return vAnimal;
}

//int Animais::getX() const {
//    return cordX;
//}
//
//int Animais::getY() const {
//    return cordY;
//}
