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


//ANIMAL
//int Reserva::getNumberOfAnimals() const {
//    //TODO
//}

string Reserva::obtemAnimal() const{
    ostringstream oss;

    for (auto it = animais.begin(); it != animais.end(); it++){
        oss << "\nAnimal: " << (*it)->getId();
        oss << "\nTipo de animal: " << (*it)->getTipoAnimal();
        oss << "\nVida: " << (*it)->getSaude();
        oss << "\nPeso: " << (*it)->getPeso() << endl;
//        << "\nVida: " << (*it)->getSaude()
//        <<"\nPeso: " << (*it)->getPeso() << endl;
    }

    return oss.str();
}

//bool Reserva::hasAnimal(){
//
//}

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
        }
    }
}

void Reserva::criaAnimalRandom(const string& tipo) {
    if (tipo != "c" && tipo != "o" && tipo != "l" && tipo != "g" && tipo != "m"){
        cout << "\nPor favor insira um animal valido!" << endl;
    } else{
        if(tipo == "c"){
            animais.push_back(new Coelho(tipo, rand() % linhas * colunas, rand() % linhas * colunas));
        }
        else if (tipo == "o"){
            animais.push_back(new Ovelha(tipo, rand() % linhas * colunas, rand() % linhas * colunas));
        }
        else if (tipo == "l"){
            animais.push_back(new Lobo(tipo, rand() % linhas * colunas, rand() % linhas * colunas));
        }
        else if (tipo == "g"){
            animais.push_back(new Canguru(tipo, rand() % linhas * colunas, rand() % linhas * colunas));
        }
        else if (tipo == "m"){
            animais.push_back(new AnimalMisterioso(tipo, rand() % linhas * colunas, rand() % linhas * colunas));
        }
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

int Reserva::getNumberOfAnimals() const {
    return animais.size();
}

string Reserva::getTipoAnimal(string tipo) const{
    ostringstream oss;

    for (auto it = animais.begin(); it != animais.end(); it++){
        if(tipo == (*it)->getTipoAnimal()){
            oss << (*it)->getTipoAnimal();
        }else{
            oss << "animal desconhecido";
        }

    }

    return oss.str();
}


//ALIMENTO
void Reserva::criaAlimento(const string &tipo, const int &x, const int &y) {

    if (tipo != "r" && tipo != "t" && tipo != "p" && tipo != "b" && tipo != "g"){
        cout << "\nPor favor insira um alimento valido!" << endl;
    } else {
        if (x < 0 || x > getLinhas() * getColunas() || y < 0 || y > getLinhas() * getColunas())
            cout << "\nPor favor insira um numero valido de colunas/linhas!" << endl;

        else{
            if(tipo == "r"){
                alimentos.push_back(new Relva(tipo, x, y));
            }
            else if (tipo == "t"){
                alimentos.push_back(new Cenoura(tipo, x, y));
            }
            else if (tipo == "p"){
                alimentos.push_back(new Corpo(tipo, x, y));
            }
            else if (tipo == "b"){
                alimentos.push_back(new Bife(tipo, x, y));
            }
            else if (tipo == "g"){
                alimentos.push_back(new AlimentoMisterio(tipo, x, y));
            }
        }
    }

}

string Reserva::obtemAlimento() const{
    ostringstream oss;

    for (auto it = alimentos.begin(); it != alimentos.end(); it++){
        oss << "\nAlimento: " << (*it)->getId();
        oss << "\nTipo de alimento: " << (*it)->getTipoAlimento();
        oss << "\nVida: " << (*it)->getValimento();
        oss << "\nValor Nutricional: " << (*it)->getValorNutri();
        oss << "\nToxicidade: " << (*it)->getToxicidade();
        oss << "\nCheiro: " << (*it)->getCheiro() << endl;
//        << "\nVida: " << (*it)->getSaude()
//        <<"\nPeso: " << (*it)->getPeso() << endl;
    }

    return oss.str();
}

int Reserva::getNumberOfFood() const {
    return alimentos.size();
}

void Reserva::criaAlimentoRandom(const string &tipo) {
    if (tipo != "r" && tipo != "t" && tipo != "p" && tipo != "b" && tipo != "g"){
        cout << "\nPor favor insira um alimento valido!" << endl;
    } else {
            if(tipo == "r"){
                alimentos.push_back(new Relva(tipo, rand() % linhas * colunas, rand() % linhas * colunas));
            }
            else if (tipo == "t"){
                alimentos.push_back(new Cenoura(tipo, rand() % linhas * colunas, rand() % linhas * colunas));
            }
            else if (tipo == "p"){
                alimentos.push_back(new Corpo(tipo, rand() % linhas * colunas, rand() % linhas * colunas));
            }
            else if (tipo == "b"){
                alimentos.push_back(new Bife(tipo, rand() % linhas * colunas, rand() % linhas * colunas));
            }
            else if (tipo == "g"){
                alimentos.push_back(new AlimentoMisterio(tipo, rand() % linhas * colunas, rand() % linhas * colunas));
            }
        }
}









