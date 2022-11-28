//
// Created by mikae on 07/11/2022.
//

#include "Animais.h"
#include "util.h"

Animais::Animais(const string& t, int SAnimal = 0, int VAnimal = 0, int peso = 0, int x = 0, int y = 0) : tipo(t), x(x), y(y), SAnimal(SAnimal), VAnimal(VAnimal), peso(peso){
}

//Gets
string Animais::getTipoAnimal() const {
    return tipo;
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

//Printa
string Animais::PrintaAnimal() const{
    ostringstream oss;

    oss << "\nID: " << id;
    oss << "\nTipo de animal: " << tipo;
    oss << "\nSaude: " << SAnimal;
    oss << "\nVida: " << VAnimal;
    oss << "\nPeso: " << peso << endl;

    return oss.str();
}
