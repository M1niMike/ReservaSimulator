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


/*ANIMAL*/

//bool Reserva::hasAnimal(int x, int y){
//
//    for(int i = 0; i < animais.size(); i++){
//        animais[i]->getX();
//        animais[i]->getY();
//    }
//
//    if(find(animais.begin(), animais.end(), quant)){
//        return true;
//    }
//
//    return false;
//}


void Reserva::criaAnimal(const string &tipo, int saude, int vida, int peso, const int& x, const int& y) {
    if (tipo != "C" && tipo != "O" && tipo != "L" && tipo != "G" && tipo != "M") {
        cout << "\nPor favor insira um animal valido!" << endl;
    }else{
        if (tipo == "C") {
            animais.push_back(new Animais(getTotalCoisas(), tipo, saude, vida, peso, x,y));
        } else if (tipo == "O") {
            animais.push_back(new Animais(getTotalCoisas(), tipo,  saude, vida, peso, x, y));
        } else if (tipo == "L") {
            animais.push_back(new Animais(getTotalCoisas(), tipo,  saude, vida, peso,  x, y));
        } else if (tipo == "G") {
            animais.push_back(new Animais(getTotalCoisas(), tipo, saude, vida, peso, x, y));
        } else if (tipo == "M") {
            animais.push_back(new Animais(getTotalCoisas(), tipo , saude, vida, peso, x, y));
        }
    }
}

void Reserva::criaAnimalRandom(const string &tipo, int saude, int vida, int peso) {
    if (tipo != "C" && tipo != "O" && tipo != "L" && tipo != "G" && tipo != "M") {
        cout << "\nPor favor insira um animal valido!" << endl;
    } else {
        if (tipo == "C") {
            animais.push_back(new Animais(getTotalCoisas(), tipo, saude, vida, peso, (rand() % linhas +1) , (rand() % colunas+1)));
        } else if (tipo == "O") {
            animais.push_back(new Animais(getTotalCoisas(),tipo, saude, vida, peso, (rand() % linhas+1), (rand() % colunas+1)));
        } else if (tipo == "L") {
            animais.push_back(new Animais(getTotalCoisas(),tipo, saude, vida, peso, (rand() % linhas+1), (rand() % colunas+1)));
        } else if (tipo == "G") {
            animais.push_back(new Animais(getTotalCoisas(),tipo, saude, vida, peso, (rand() % linhas+1), (rand() % colunas+1)));
        } else if (tipo == "M") {
            animais.push_back(new Animais(getTotalCoisas(),tipo, saude, vida, peso, (rand() % linhas+1), (rand() % colunas+1)));
        }
    }
}

string Reserva::PrintaAnimal() const{
    ostringstream oss;

    for (auto it = animais.begin(); it != animais.end(); it++){
        oss << "\nID: " << (*it)->getId() << endl;
        oss << "\nTipo de animal: " << (*it)->getTipoAnimal() << endl;
        oss << "\nSaude: " << (*it)->getSaude() << endl;
        oss << "\nVida: " << (*it)->getvAnimal() << endl;
        oss << "\nPeso: " << (*it)->getPeso() << endl;
    }

    //oss << "Existem " << animais.size() + alimentos.size() << " coisas na reserva neste momento.";

    return oss.str();
}

vector<Animais*> Reserva::getVecAnimal() const {
    return animais;
}

//Animais Reserva::getAnimal(int linha, int coluna) {
//
//
//    for(int i = 0; i < linha; i++){
//        for(int j = 0; i < coluna; i++){
//            return animais[i][j];
//        }
//    }
//    return animais[0][0];
//}

int Reserva::getNumberOfAnimals() const {
    return animais.size();
}
/*ALIMENTO*/


void Reserva::criaAlimento(const string &tipo, const int& x, const int& y) {
    if (tipo != "R" && tipo != "T" && tipo != "P" && tipo != "B" && tipo != "Z") {
        cout << "\nPor favor insira um alimento valido!" << endl;
    } else {
        if (tipo == "R") {                    //tipo va vn tx cheiro id x y
            alimentos.push_back(new Alimentos(getTotalCoisas(),tipo, 20, 3, 0, "erva e verdura", x, y));

        } else if (tipo == "T") {
            alimentos.push_back(new Alimentos(getTotalCoisas(),tipo, 30, 9999, 4, "verdura", x, y));

        } else if (tipo == "P") {
            alimentos.push_back(new Alimentos(getTotalCoisas(),tipo, 9999, 4, 1, "carne", x, y));

        } else if (tipo == "B") {
            alimentos.push_back(new Alimentos(getTotalCoisas(),tipo, 30, 10, 2, "carne e ketchup", x, y));

        } else if (tipo == "Z") {
            alimentos.push_back(new Alimentos(getTotalCoisas(),tipo, 20, 2, 1, "fruta", x, y));
        }
    }

}


void Reserva::criaAlimentoRandom(const string &tipo) {
    if (tipo != "R" && tipo != "T" && tipo != "P" && tipo != "B" && tipo != "Z") {
        cout << "\nPor favor insira um alimento valido!" << endl;
    } else {
        if (tipo == "R") {                    //tipo va vn tx cheiro id x y
            alimentos.push_back(new Alimentos(getTotalCoisas(), tipo, 20, 3, 0,"erva e verdura", (rand() % linhas +1) , (rand() % colunas+1)));
        } else if (tipo == "T") {
            alimentos.push_back(new Alimentos(getTotalCoisas(),tipo, 30, 9999, 4, "verdura", (rand() % linhas +1) , (rand() % colunas+1)));

        } else if (tipo == "P") {
            alimentos.push_back(new Alimentos(getTotalCoisas(),tipo, 9999, 4, 1, "carne", (rand() % linhas +1) , (rand() % colunas+1)));

        } else if (tipo == "B") {
            alimentos.push_back(new Alimentos(getTotalCoisas(),tipo, 30, 10, 2, "carne e ketchup", (rand() % linhas +1) , (rand() % colunas+1)));

        } else if (tipo == "Z") {
            alimentos.push_back(new Alimentos(getTotalCoisas(),tipo, 20, 2, 1, "fruta", (rand() % linhas +1) , (rand() % colunas+1)));
        }
    }
}

int Reserva::getTotalCoisas(){
    return totalCoisas++;
}

string Reserva::PrintaAlimento() const{
    ostringstream oss;
    for (auto it = alimentos.begin(); it != alimentos.end(); it++){
        oss << "\nID: " << (*it)->getId() << "Alimento: ";
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

vector<Alimentos*> Reserva::getVecAlimento() const {
    return alimentos;
}




