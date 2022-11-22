//
// Created by mikae on 07/11/2022.
//

#include "Reserva.h"
#include "util.h"

Reserva::Reserva(int nl, int nc): linhas(nl), colunas(nc) {}

int Reserva::getLinhas() const {
    return linhas;
}

int Reserva::getColunas() const {
    return colunas;
}

void Reserva::setLinhas(int newLinhas){
    linhas = newLinhas;
}

void Reserva::setColunas(int newColunas) {
    colunas = newColunas;
}

//int Reserva::getNumberOfAnimals() const {
//    //TODO
//}

string Reserva::obtemReserva() const{
    ostringstream oss;

    for (auto it = animais.begin(); it != animais.end(); it++){
        oss << "\nAnimal: " << (*it)->getId();
        oss << "\nTipo de animal: " << (*it)->getTipoAnimal()
        << "\nVida: " << (*it)->getSaude()
        <<"\nPeso: " << (*it)->getPeso() << endl;
    }

    return oss.str();
}

void Reserva::criaAnimal(const string &tipo, const int& x, const int& y) {
    if (tipo != "c" && tipo != "o" && tipo != "l" && tipo != "g" && tipo != "m"){
        cout << "\nPor favor insira um animal valido!" << endl;
    } else {
        if (x < 0 || x > getLinhas() * getColunas() || y < 0 || y > getLinhas() * getColunas())
            cout << "\nPor favor insira um numero valido de colunas/linhas!" << endl;

        else{
                if(tipo == "c"){
                    animais.push_back(new Coelho(tipo, x, y));
                }
                else if (tipo == "o"){
                    animais.push_back(new Ovelha(tipo, x, y));
                }
                else if (tipo == "l"){
                    animais.push_back(new Lobo(tipo, x, y));
                }
                else if (tipo == "g"){
                    animais.push_back(new Canguru(tipo, x, y));
                }
                else if (tipo == "m"){
                    animais.push_back(new AnimalMisterioso(tipo, x, y));
                }
                cont++;
        }
    }
}

void Reserva::criaAnimalRandom(const string& tipo) {
    if (tipo != "c" || tipo != "o" || tipo != "l" || tipo != "g" || tipo != "m"){
        cout << "\nPor favor insira um animal valido!" << endl;
    }
}

Animais Reserva::getAnimal(int linha, int coluna) {


    for(int i = 0; i < linha; i++){
        for(int j = 0; i < coluna; i++){
            return animais[i][j];
        }
    }
    return animais[0][0];
}








