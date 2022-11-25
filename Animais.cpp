//
// Created by mikae on 07/11/2022.
//

#include "Animais.h"
#include "util.h"

Animais::Animais(int id, const string& t, int Sa = 0, int p = 0, int Va = 0, bool isDead = false, int x = 0, int y = 0) : id(id),tipo(t), sAnimal(Sa), peso(p), vAnimal(Va), isDead(isDead), cordX(x), cordY(y){
}

string Animais::getTipoAnimal() const {
    ostringstream oss;

    oss << tipo;

    return oss.str();
}

int Animais::getId() const {
    return id;
}

int Animais::getSaude() const{
    return sAnimal;
}

int Animais::getPeso() const{
    return peso;
}

int Animais::getvAnimal() const{
    return vAnimal;
}



int Animais::getX() const {
    return cordX;
}

int Animais::getY() const {
    return cordY;
}
