//
// Created by mikae on 07/11/2022.
//

#include "Alimentos.h"
#include "util.h"



Alimentos::Alimentos(const string& t, const string& c, int Va = 0, int Vn = 0, int tx = 0, int x = 0, int y = 0) :tipo(t), VAlimento(Va), valorNutri(Vn), toxicidade(tx), cheiro(c), cordX(x), cordY(y), podeSerComido(0){
}

//Gets
int Alimentos::getValimento() const{
    return VAlimento;
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
int Alimentos::getId() const {
    return id;
}

//Prints
string Alimentos::PrintaAlimento() const{
    ostringstream oss;

    oss << "\nID: " << id << " | " << "Tipo do alimento: " << tipo << " | " << "Tempo de validade: " << VAlimento << "\n" << "Valor Nutritivo: " << valorNutri << " | " << "Toxidade: " << toxicidade << " | " << "Cheiro: " << cheiro << "\n";

    return oss.str();
}
