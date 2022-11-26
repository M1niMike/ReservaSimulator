//
// Created by mikae on 07/11/2022.
//

#include "Animais.h"
#include "util.h"

/*Animais::Animais(int id, const string& t, int Sa = 0, int p = 0, int Va = 0, bool isDead = false, int x = 0, int y = 0) : id(id), tipo(t), SAnimal(Sa), peso(p), VAnimal(Va), isDead(isDead), x(x), y(y){


}*/

Animais::Animais(int id, const string& t, int x, int y) : id(id), tipo(t), x(x), y(y){
    VAnimal = 30;
    SAnimal = 20;
    peso = 10;
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
    return SAnimal;
}

int Animais::getPeso() const{
    return peso;
}

int Animais::getvAnimal() const{
    return VAnimal;
}

int Animais::getX() const {
    return x;
}

int Animais::getY() const {
    return y;
}
