//
// Created by mikae on 07/11/2022.
//

#include "Reserva.h"
#include "util.h"

Reserva::Reserva(int nl, int nc): linhas(nl), colunas(nc){}

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

/*ANIMAL*/
void Reserva::criaAnimal(const string &tipo, int saude, int vida, const int& x, const int& y) {
    if (tipo != "C" && tipo != "O" && tipo != "L" && tipo != "G" && tipo != "M") {
        cout << "\nPor favor insira um animal valido!" << endl;
    }else{
        if (tipo == "C") {
            animais.push_back(new Coelho("Coelho", saude, vida, rand() % 4 + 1, x,y));
            animais[animais.size()-1]->setId(totalCoisas++);
        } else if (tipo == "O") {
            animais.push_back(new Ovelha("Ovelha",  saude, vida, rand() % 8 + 4, x, y));
            animais[animais.size()-1]->setId(totalCoisas++);
        } else if (tipo == "L") {
            animais.push_back(new Lobo("Lobo",  saude, vida, 15, x, y));
            animais[animais.size()-1]->setId(totalCoisas++);
        } else if (tipo == "G") {
            animais.push_back(new Canguru("Canguru", saude, vida, 10, x, y));
            animais[animais.size()-1]->setId(totalCoisas++);
        } else if (tipo == "M") {
            animais.push_back(new AnimalMisterioso("Macaco (AM)" , saude, vida, rand() % 10 + 2, x, y));
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
            animais.push_back(new Coelho("Coelho", saude, vida, rand() % 4 + 1, lRandom , cRandom));
            alimentos[alimentos.size()-1]->setId(totalCoisas++);
        } else if (tipo == "O") {
            animais.push_back(new Ovelha("Ovelha", saude, vida, rand() % 8 + 4, lRandom , cRandom));
            alimentos[alimentos.size()-1]->setId(totalCoisas++);
        } else if (tipo == "L") {
            animais.push_back(new Lobo("Lobo", saude, vida, 15, lRandom , cRandom));
            alimentos[alimentos.size()-1]->setId(totalCoisas++);
        } else if (tipo == "G") {
            animais.push_back(new Canguru("Canguru", saude, vida, 10, lRandom , cRandom));
            alimentos[alimentos.size()-1]->setId(totalCoisas++);
        } else if (tipo == "M") {
            animais.push_back(new AnimalMisterioso("Macaco (AM)", saude, vida, rand() % 10 + 2, lRandom , cRandom));
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
    for (int i = 0; i < animais.size(); i++){
        if (animais[i]->getId() == id){
            animais.erase(animais.begin()+i);
        }
    }
}

void Reserva::removeAnimalbyCoord(const int& x, const int& y) {
    for (int i = 0; i < animais.size(); i++){
        if(animais[i]->getX() == x && animais[i]->getY() == y) {
            animais.erase(animais.begin() + i);
        }
    }
}

void Reserva::removeAlimentobyCoord(const int& x, const int& y) {
    for (int i = 0; i < alimentos.size(); i++){
        if(alimentos[i]->getX() == x && alimentos[i]->getY() == y){
            alimentos.erase(alimentos.begin()+i);
        }
    }
}

void Reserva::removeAlimentobyId(const int& id) {
    for (int i = 0; i < alimentos.size(); i++){
        if(alimentos[i]->getId() == id){
            alimentos.erase(alimentos.begin()+i);
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

//string Reserva::getInfoAlimentoId(int id) const {
//    ostringstream oss;
//    for(int i = 0; i < alimentos.size(); i++){
//
//        oss << alimentos[i]->getId();
//    }
//
//    return oss.str();
//}

