//
// Created by mikae on 07/11/2022.
//

#include "Animais.h"
#include "util.h"

Animais::Animais(int id, const string& t, int SAnimal = 0, int VAnimal = 0, int peso = 0, int x = 0, int y = 0) : id(id), tipo(t), x(x), y(y), SAnimal(SAnimal), VAnimal(VAnimal), peso(peso){
}

/*Animais::Animais(int id, const string& t, int x, int y, int SAnimal = 0, int VAnimal = 0, int peso = 0) : id(id), tipo(t), x(x), y(y){

}*/

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
