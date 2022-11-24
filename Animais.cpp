//
// Created by mikae on 07/11/2022.
//

#include "Animais.h"
#include "util.h"

int Animais::ID = 1;

Animais::Animais(const string& t, int Sa = 0, int p = 0, int Va = 0, bool isDead = false, int id = 1, int x = 0, int y = 0) : tipo(t), sAnimal(Sa), peso(p), vAnimal(Va), isDead(isDead), id(ID++), cordX(x), cordY(y){

}

string Animais::getTipoAnimal() const {
    ostringstream oss;

    oss << tipo;

    return oss.str();
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



//int Animais::getX() const {
//    return cordX;
//}
//
//int Animais::getY() const {
//    return cordY;
//}
