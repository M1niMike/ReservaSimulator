//
// Created by mikae on 07/11/2022.
//

#include "Animais.h"
#include "util.h"
#include "Reserva.h"


Animais::Animais(const string& t, int SAnimal = 0, int VAnimal = 0, int fome = 0, int peso = 0, int x = 0, int y = 0) : tipo(t), x(x), y(y), SAnimal(SAnimal), VAnimal(VAnimal), fome(fome), peso(peso), estaMorto(0){
}


//Gets
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

int Animais::getFome() const {
    return fome;
}

bool Animais::isDead() {
    return estaMorto = 1;
}

//Printa
string Animais::PrintaAnimal() const{
    ostringstream oss;

    oss << "\nID: " << id << " | " << "Tipo de animal: " << tipo << " | " << "Saude: " << SAnimal << " | " << "Vida: " << VAnimal << " | " << "X: " << x << " | " << "Y: " << y <<"\n";

    return oss.str();
}




