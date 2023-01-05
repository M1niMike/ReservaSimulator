//
// Created by mikae on 07/11/2022.
//

#include "Reserva.h"
#include "util.h"

#include "TipoAnimais/Coelho.h"
#include "TipoAnimais/Ovelha.h"
#include "TipoAnimais/Lobo.h"
#include "TipoAnimais/Canguru.h"
#include "TipoAnimais/AnimalMisterioso.h"


Reserva::Reserva(int numInstantes, int nl, int nc): linhas(nl), colunas(nc), numInstantes(numInstantes), /*APAGAR*/ debug(15, 15, 50, 15){}

//Funcs Auxiliares
int Reserva::getTotalCoisas(){
    return totalCoisas++;
}
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

int Reserva::getInstantes() const {
    return numInstantes;
}

/*ANIMAL*/
void Reserva::criaAnimal(const string &tipo, int saude, int vida, const int& x, const int& y) {
    if (tipo != "C" && tipo != "O" && tipo != "L" && tipo != "G" && tipo != "M") {
        cout << "\nPor favor insira um animal valido!" << endl;
    }else{
        if (tipo == "C") {
            animais.push_back(new Coelho("Coelho", saude, vida, 0, rand() % 4 + 1, x,y));
            animais[animais.size()-1]->setId(totalCoisas++);
        } else if (tipo == "O") {
            animais.push_back(new Ovelha("Ovelha",  saude, vida, 0, rand() % 8 + 4, x, y));
            animais[animais.size()-1]->setId(totalCoisas++);
        } else if (tipo == "L") {
            animais.push_back(new Lobo("Lobo",  saude, vida, 0, 15, x, y));
            animais[animais.size()-1]->setId(totalCoisas++);
        } else if (tipo == "G") {
            animais.push_back(new Canguru("Canguru", saude, vida, 0, 10, x, y));
            animais[animais.size()-1]->setId(totalCoisas++);
        } else if (tipo == "M") {
            animais.push_back(new AnimalMisterioso("Macaco (AM)" , saude, vida, 0, rand() % 10 + 2, x, y));
            animais[animais.size()-1]->setId(totalCoisas++);
        }
    }
}
void Reserva::criaAnimalRandom(const string &tipo, int saude, int vida) {
    int lRandom = rand() % linhas + 1;
    int cRandom = rand() % colunas + 1;
    if (tipo != "C" && tipo != "O" && tipo != "L" && tipo != "G" && tipo != "M") {
        cout << "\nPor favor insira um animal valido!" << endl;
    } else {
        if (tipo == "C") {
            animais.push_back(new Coelho("Coelho", saude, vida, 0, rand() % 4 + 1, lRandom , cRandom));
            alimentos[alimentos.size()-1]->setId(totalCoisas++);
        } else if (tipo == "O") {
            animais.push_back(new Ovelha("Ovelha", saude, vida, 0, rand() % 8 + 4, lRandom , cRandom));
            alimentos[alimentos.size()-1]->setId(totalCoisas++);
        } else if (tipo == "L") {
            animais.push_back(new Lobo("Lobo", saude, vida, 0, 15, lRandom , cRandom));
            alimentos[alimentos.size()-1]->setId(totalCoisas++);
        } else if (tipo == "G") {
            animais.push_back(new Canguru("Canguru", saude, vida, 0, 10, lRandom , cRandom));
            alimentos[alimentos.size()-1]->setId(totalCoisas++);
        } else if (tipo == "M") {
            animais.push_back(new AnimalMisterioso("Macaco (AM)", saude, vida, 0, rand() % 10 + 2, lRandom , cRandom));
            alimentos[alimentos.size()-1]->setId(totalCoisas++);
        }
    }
}
vector<Animais*> Reserva::getVecAnimal() const {
    return animais;
}
int Reserva::getNumberOfAnimals() const {
    return animais.size();
}

//string Reserva::getInfoAnimalId(int id) const {
//
//    ostringstream oss;
//    for(int i = 0; i < animais.size(); i++){
//
//        oss << animais[i]->getId();
//    }
//
//    return oss.str();
//}

/*ALIMENTO*/
void Reserva::criaAlimento(const string &tipo, const int& x, const int& y) {
    if (tipo != "R" && tipo != "T" && tipo != "P" && tipo != "B" && tipo != "Z") {
        cout << "\nPor favor insira um alimento valido!" << endl;
    } else {
        if (tipo == "R") {
            alimentos.push_back(new Relva("Relva", "erva e verdura", 20, 3, 0,  x, y));
            alimentos[alimentos.size()-1]->setId(totalCoisas++);
        } else if (tipo == "T") {
            alimentos.push_back(new Cenoura("Cenoura", "verdura", 9999, 4, 0,  x, y));
            alimentos[alimentos.size()-1]->setId(totalCoisas++);
        } else if (tipo == "B") {
            alimentos.push_back(new Bife("Bife", "carne e ketchup", 30, 10, 2,  x, y));
            alimentos[alimentos.size()-1]->setId(totalCoisas++);
        } else if (tipo == "P") {
            alimentos.push_back(new Corpo("Corpo", "carne", 9999, 4, 0, x, y));
            alimentos[alimentos.size()-1]->setId(totalCoisas++);
        } else if (tipo == "A") {
            alimentos.push_back(new AlimentoMisterioso("Banana (ALM)", "fruta", 15, 5, 0, x, y));
            alimentos[alimentos.size()-1]->setId(totalCoisas++);
        }
    }

}
void Reserva::criaAlimentoRandom(const string &tipo) {
    int lRandom = rand() % linhas + 1;
    int cRandom = rand() % colunas + 1;
    if (tipo != "R" && tipo != "T" && tipo != "P" && tipo != "B" && tipo != "Z") {
        cout << "\nPor favor insira um alimento valido!" << endl;
    } else {
        if (tipo == "R") {                    //tipo va vn tx cheiro id x y
            alimentos.push_back(new Relva("Relva", "erva e verdura", 20, 3, 0,  lRandom , cRandom));
            alimentos[alimentos.size()-1]->setId(totalCoisas++);

        } else if (tipo == "T") {
            alimentos.push_back(new Cenoura("Cenoura", "verdura", 9999, 4, 0, lRandom , cRandom));
            alimentos[alimentos.size()-1]->setId(totalCoisas++);

        } else if (tipo == "P") {
            alimentos.push_back(new Corpo("Corpo", "carne", 9999, 4, 0, lRandom , cRandom));
            alimentos[alimentos.size()-1]->setId(totalCoisas++);

        } else if (tipo == "B") {
            alimentos.push_back(new Bife("Bife", "carne e ketchup", 30, 10, 2, lRandom , cRandom));
            alimentos[alimentos.size()-1]->setId(totalCoisas++);

        } else if (tipo == "Z") {
            alimentos.push_back(new AlimentoMisterioso("Banana (ALM)", "fruta", 15, 5, 0, lRandom , cRandom));
            alimentos[alimentos.size()-1]->setId(totalCoisas++);

        }
    }
}

void Reserva::removeAnimalbyId(const int& id){
    auto it = animais.begin();

    while(it != animais.end()){
        if((*it)->getId() == id){
            delete *it;
            it = animais.erase(it);
        }else{
            it++;
        }
    }
}

void Reserva::removeAnimalbyCoord(const int& x, const int& y) {
    auto it = animais.begin();

    while(it != animais.end()){
        if((*it)->getX() == x && (*it)->getY() == y){
            delete *it;
            it = animais.erase(it);
        }else{
            it++;
        }
    }
}

void Reserva::removeAlimentobyCoord(const int& x, const int& y) {
    auto it = alimentos.begin();

    while(it != alimentos.end()){
        if((*it)->getX() == x && (*it)->getY() == y){
            delete *it;
            it = alimentos.erase(it);
        }else{
            it++;
        }
    }
}

void Reserva::removeAlimentobyId(const int& id) {
    auto it = alimentos.begin();

    while(it != alimentos.end()){
        if((*it)->getId() == id){
            delete *it;
            it = alimentos.erase(it);
        }else{
            it++;
        }
    }
}

void Reserva::feedAnimalById(const int &id, const int &valorNutritivo, const int &toxicidade) {

    for(auto it = animais.begin(); it != animais.end(); it++){
        if((*it)->getId() == id){
            int total = (*it)->getSaude() + valorNutritivo - toxicidade;
            (*it)->setSaude(total);
        }
    }
}


void Reserva::feedAnimalbyCoord(const int &x, const int &y, const int &valorNutritivo, const int &toxicidade) {

    for(auto it = animais.begin(); it != animais.end(); it++){
        if((*it)->getX() == x && (*it)->getY() == y){
            int total = (*it)->getSaude() + valorNutritivo - toxicidade;
            (*it)->setSaude(total);
        }
    }
}


int Reserva::getNumberOfFood() const {
    return alimentos.size();
}
vector<Alimentos*> Reserva::getVecAlimento() const {
    return alimentos;
}


bool Reserva::hasAlimento(int x, int y) {
    for(int i =0; i < alimentos.size(); i++){
        if(alimentos[i]->getX() == x && alimentos[i]->getY() == y){
            return true;
        }
    }
    return false;
}




/*PEGAR NISSO DEPOIS*/


//void Reserva::interacaoAnimal() {
////    for(auto animal:animais){
////        animalfazInteracao(this)
////    }
//
//    for(int i = 0; i < animais.size(); i++){
//        animais[i]->fazInteracao(*this);
//    }
//}




//bool Reserva::verificaAnimalRedondeza(const int &x, const int &y, const int &valorRedondeza) {
//
////    animais[i]->getX() < x+valorRedondeza - # Coordenada abaixo da coordenada atual
////    animais[i]->getX() > x-valorRedondeza - # Coordenada acima da coordenada atual
////    animais[i]->getY() < y+valorRedondeza - # Coordenada à direita da coordenada atual
////    animais[i]->getY() > y-valorRedondeza - # Coordenada à esquerda da coordenada atual
//
//    for(int i = 0; i < animais.size(); i++){
//        if(animais[i]->getX() < x+valorRedondeza && animais[i]->getX() > x-valorRedondeza && animais[i]->getY() < y+valorRedondeza && animais[i]->getY() > y-valorRedondeza){
//            if(animais[i].)
//        }
//    }
//}
