//
// Created by mikae on 07/11/2022.
//

#include "Reserva.h"
#include "util.h"

Reserva::Reserva(int nl, int nc): linhas(nl), colunas(nc) {}

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
void Reserva::criaAnimal(const string &tipo, int saude, int vida, int peso, const int& x, const int& y) {
    if (tipo != "C" && tipo != "O" && tipo != "L" && tipo != "G" && tipo != "M") {
        cout << "\nPor favor insira um animal valido!" << endl;
    }else{
        if (tipo == "C") {
            animais.push_back(new Animais(tipo, saude, vida, peso, x,y));
            animais[animais.size()-1]->setId(totalCoisas++);
        } else if (tipo == "O") {
            animais.push_back(new Animais(tipo,  saude, vida, peso, x, y));
            animais[animais.size()-1]->setId(totalCoisas++);
        } else if (tipo == "L") {
            animais.push_back(new Animais(tipo,  saude, vida, peso,  x, y));
            animais[animais.size()-1]->setId(totalCoisas++);
        } else if (tipo == "G") {
            animais.push_back(new Animais(tipo, saude, vida, peso, x, y));
            animais[animais.size()-1]->setId(totalCoisas++);
        } else if (tipo == "M") {
            animais.push_back(new Animais(tipo , saude, vida, peso, x, y));
            animais[animais.size()-1]->setId(totalCoisas++);
        }
    }
}
void Reserva::criaAnimalRandom(const string &tipo, int saude, int vida, int peso) {
    int lRandom = rand() % linhas + 1;
    int cRandom = rand() % colunas + 1;
    if (tipo != "C" && tipo != "O" && tipo != "L" && tipo != "G" && tipo != "M") {
        cout << "\nPor favor insira um animal valido!" << endl;
    } else {
        if (tipo == "C") {
            animais.push_back(new Animais(tipo, saude, vida, peso, lRandom , cRandom));
            alimentos[alimentos.size()-1]->setId(totalCoisas++);
            cout << "[" << tipo << "]" << " Criado em: " << lRandom << "x" << cRandom << endl;
        } else if (tipo == "O") {
            animais.push_back(new Animais(tipo, saude, vida, peso, lRandom , cRandom));
            alimentos[alimentos.size()-1]->setId(totalCoisas++);
            cout << "[" << tipo << "]" << " Criado em: " << lRandom << "x" << cRandom << endl;
        } else if (tipo == "L") {
            animais.push_back(new Animais(tipo, saude, vida, peso, lRandom , cRandom));
            alimentos[alimentos.size()-1]->setId(totalCoisas++);
            cout << "[" << tipo << "]" << " Criado em: " << lRandom << "x" << cRandom << endl;
        } else if (tipo == "G") {
            animais.push_back(new Animais(tipo, saude, vida, peso, lRandom , cRandom));
            alimentos[alimentos.size()-1]->setId(totalCoisas++);
            cout << "[" << tipo << "]" << " Criado em: " << lRandom << "x" << cRandom << endl;
        } else if (tipo == "M") {
            animais.push_back(new Animais(tipo, saude, vida, peso, lRandom , cRandom));
            alimentos[alimentos.size()-1]->setId(totalCoisas++);
            cout << "[" << tipo << "]" << " Criado em: " << lRandom << "x" << cRandom << endl;
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
        if (tipo == "R") {                    //tipo va vn tx cheiro id x y
            alimentos.push_back(new Alimentos(tipo, 20, 3, 0, "erva e verdura", x, y));
            alimentos[alimentos.size()-1]->setId(totalCoisas++);
        } else if (tipo == "T") {
            alimentos.push_back(new Alimentos(tipo, 30, 9999, 4, "verdura", x, y));
            alimentos[alimentos.size()-1]->setId(totalCoisas++);
        } else if (tipo == "P") {
            alimentos.push_back(new Alimentos(tipo, 9999, 4, 1, "carne", x, y));
            alimentos[alimentos.size()-1]->setId(totalCoisas++);
        } else if (tipo == "B") {
            alimentos.push_back(new Alimentos(tipo, 30, 10, 2, "carne e ketchup", x, y));
            alimentos[alimentos.size()-1]->setId(totalCoisas++);
        } else if (tipo == "Z") {
            alimentos.push_back(new Alimentos(tipo, 20, 2, 1, "fruta", x, y));
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
            alimentos.push_back(new Alimentos(tipo, 20, 3, 0, "erva e verdura", lRandom , cRandom));
            alimentos[alimentos.size()-1]->setId(totalCoisas++);
            cout << "[" << tipo << "]" << " Criado em: " << lRandom << "x" << cRandom << endl;
        } else if (tipo == "T") {
            alimentos.push_back(new Alimentos(tipo, 30, 9999, 4, "verdura", lRandom , cRandom));
            alimentos[alimentos.size()-1]->setId(totalCoisas++);
            cout << "[" << tipo << "]" << " Criado em: " << lRandom << "x" << cRandom << endl;
        } else if (tipo == "P") {
            alimentos.push_back(new Alimentos(tipo, 9999, 4, 1, "carne", lRandom , cRandom));
            alimentos[alimentos.size()-1]->setId(totalCoisas++);
            cout << "[" << tipo << "]" << " Criado em: " << lRandom << "x" << cRandom << endl;
        } else if (tipo == "B") {
            alimentos.push_back(new Alimentos(tipo, 30, 10, 2, "carne e ketchup", lRandom , cRandom));
            alimentos[alimentos.size()-1]->setId(totalCoisas++);
            cout << "[" << tipo << "]" << " Criado em: " << lRandom << "x" << cRandom << endl;
        } else if (tipo == "Z") {
            alimentos.push_back(new Alimentos(tipo, 20, 2, 1, "fruta", lRandom , cRandom));
            alimentos[alimentos.size()-1]->setId(totalCoisas++);
            cout << "[" << tipo << "]" << " Criado em: " << lRandom << "x" << cRandom << endl;
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

