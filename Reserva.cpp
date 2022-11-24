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
//    int quant = animais.size();
//
//    for(int i = 0; i < quant; i++){
//        find(animais.begin(), animais.end(),quant);
//    }
//
//    if(find(animais.begin(), animais.end(), quant)){
//        return true;
//    }
//
//    return false;
//}

//bool Jogo::temEdificio(int l, int c)
//{
//    if(i->getIlha()[l][c].verificaEdificio())
//        return true;
//    else
//        false;
//    return false;
//}


void Reserva::criaAnimal(const string &tipo, const int& x, const int& y) {
    if (tipo != "c" && tipo != "o" && tipo != "l" && tipo != "g" && tipo != "m") {
        cout << "\nPor favor insira um animal valido!" << endl;
    } else {
        if (tipo == "c") {
            animais.push_back(new Animais(1,tipo, 20, 0, 0, false, x, y));
        } else if (tipo == "o") {
            animais.push_back(new Animais(1,tipo, 30, 0, 0, false, x, y));
        } else if (tipo == "l") {
            animais.push_back(new Animais(1,tipo, 25, 15, 0, false, x, y));
        } else if (tipo == "g") {
            animais.push_back(new Animais(1,tipo, 20, 10, 70, false, x, y));
        } else if (tipo == "m") {
            animais.push_back(new Animais(1,tipo, 0, 0, 0, false, x, y));
        }
    }

}

void Reserva::criaAnimalRandom(const string &tipo) {
    if (tipo != "c" && tipo != "o" && tipo != "l" && tipo != "g" && tipo != "m") {
        cout << "\nPor favor insira um animal valido!" << endl;
    } else {
        if (tipo == "c") {
            animais.push_back(new Animais(1,tipo, 20, 0, 0, false, rand() % linhas * colunas, rand() % linhas * colunas));
        } else if (tipo == "o") {
            animais.push_back(new Animais(1,tipo, 30, 0, 0, false, rand() % linhas * colunas, rand() % linhas * colunas));
        } else if (tipo == "l") {
            animais.push_back(new Animais(1,tipo, 25, 15, 0, false, rand() % linhas * colunas, rand() % linhas * colunas));
        } else if (tipo == "g") {
            animais.push_back(new Animais(1,tipo, 20, 10, 70, false, rand() % linhas * colunas, rand() % linhas * colunas));
        } else if (tipo == "m") {
            animais.push_back(new Animais(1,tipo, 0, 0, 0, false, rand() % linhas * colunas, rand() % linhas * colunas));
        }
    }

}

string Reserva::PrintaAnimal() const{
    ostringstream oss;
    for (auto it = animais.begin(); it != animais.end(); it++){
        oss << "\nID: " << (*it)->getId() << endl;
        oss << "\nTipo de animal: " << (*it)->getTipoAnimal() << endl;
        oss << "\nVida: " << (*it)->getSaude() << endl;
    }

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
    if (tipo != "r" && tipo != "t" && tipo != "p" && tipo != "b" && tipo != "z") {
        cout << "\nPor favor insira um alimento valido!" << endl;
    } else {
        if (tipo == "r") {                    //tipo va vn tx cheiro id x y
            alimentos.push_back(new Alimentos(1,tipo, 20, 3, 0, "erva e verdura", x, y));

        } else if (tipo == "t") {
            alimentos.push_back(new Alimentos(1,tipo, 30, 9999, 4, "verdura", x, y));

        } else if (tipo == "p") {
            alimentos.push_back(new Alimentos(1,tipo, 9999, 4, 1, "carne", x, y));

        } else if (tipo == "b") {
            alimentos.push_back(new Alimentos(1,tipo, 30, 10, 2, "carne e ketchup", x, y));

        } else if (tipo == "g") {
            alimentos.push_back(new Alimentos(1,tipo, 20, 2, 1, "fruta", x, y));
        }
    }

}


void Reserva::criaAlimentoRandom(const string &tipo) {
    if (tipo != "r" && tipo != "t" && tipo != "p" && tipo != "b" && tipo != "z") {
        cout << "\nPor favor insira um alimento valido!" << endl;
    } else {
        if (tipo == "r") {                    //tipo va vn tx cheiro id x y
            alimentos.push_back(new Alimentos(1, tipo, 20, 3, 0,"erva e verdura", rand() % linhas * colunas, rand() % linhas * colunas));

        } else if (tipo == "t") {
            alimentos.push_back(new Alimentos(1,tipo, 30, 9999, 4, "verdura", rand() % linhas * colunas, rand() % linhas * colunas));

        } else if (tipo == "p") {
            alimentos.push_back(new Alimentos(1,tipo, 9999, 4, 1, "carne", rand() % linhas * colunas, rand() % linhas * colunas));

        } else if (tipo == "b") {
            alimentos.push_back(new Alimentos(1,tipo, 30, 10, 2, "carne e ketchup", rand() % linhas * colunas, rand() % linhas * colunas));

        } else if (tipo == "g") {
            alimentos.push_back(new Alimentos(1,tipo, 20, 2, 1, "fruta", rand() % linhas * colunas, rand() % linhas * colunas));
        }


    }
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


vector<Alimentos *> Reserva::getVecAlimento() const {
    return alimentos;
}










