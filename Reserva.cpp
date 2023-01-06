//
// Created by mikae on 07/11/2022.
//

#include "Reserva.h"
#include "util.h"

/*ANIMAIS*/

#include "TipoAnimais/Coelho.h"
#include "TipoAnimais/Ovelha.h"
#include "TipoAnimais/Lobo.h"
#include "TipoAnimais/Canguru.h"
#include "TipoAnimais/AnimalMisterioso.h"

/*ALIMENTOS*/

#include "TipoAlimentos/Relva.h"
#include "TipoAlimentos/Cenoura.h"
#include "TipoAlimentos/Corpo.h"
#include "TipoAlimentos/Bife.h"
#include "TipoAlimentos/AlimentoMisterioso.h"


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
            animais.push_back(new Coelho("Coelho", saude, vida, 0,  rand() % 4 + 1, x,y));
            animais[animais.size()-1]->setId(totalCoisas++);
        } else if (tipo == "O") {
            animais.push_back(new Ovelha("Ovelha",  saude, vida, 0, rand() % 5 + 4, x, y));
            animais[animais.size()-1]->setId(totalCoisas++);
        } else if (tipo == "L") {
            animais.push_back(new Lobo("Lobo",  saude, vida, 0, 15, x, y));
            animais[animais.size()-1]->setId(totalCoisas++);
        } else if (tipo == "G") {
            animais.push_back(new Canguru("Canguru", saude, vida, 0, 10, x, y));
            animais[animais.size()-1]->setId(totalCoisas++);
        } else if (tipo == "M") {
            animais.push_back(new AnimalMisterioso("Macaco (AM)" , saude, vida, 0, rand() % 9 + 2, x, y));
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
            animais.push_back(new Ovelha("Ovelha", saude, vida, 0, rand() % 5 + 4, lRandom , cRandom)); //rand() % 5 + 4; numero entre 4 e 8 --
            alimentos[alimentos.size()-1]->setId(totalCoisas++);
        } else if (tipo == "L") {
            animais.push_back(new Lobo("Lobo", saude, vida, 0, 15, lRandom , cRandom));
            alimentos[alimentos.size()-1]->setId(totalCoisas++);
        } else if (tipo == "G") {
            animais.push_back(new Canguru("Canguru", saude, vida, 0, 10, lRandom , cRandom));
            alimentos[alimentos.size()-1]->setId(totalCoisas++);
        } else if (tipo == "M") {
            animais.push_back(new AnimalMisterioso("Macaco (AM)", saude, vida, 0, rand() % 9 + 2, lRandom , cRandom));
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
    if (tipo != "R" && tipo != "T" && tipo != "B" && tipo != "Z") {
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
        }else if (tipo == "A") {
            alimentos.push_back(new AlimentoMisterioso("Banana (ALM)", "fruta", 15, 5, 0, x, y));
            alimentos[alimentos.size()-1]->setId(totalCoisas++);
        }
    }

}
void Reserva::criaAlimentoRandom(const string &tipo) {
    int lRandom = rand() % linhas + 1;
    int cRandom = rand() % colunas + 1;
    if (tipo != "R" && tipo != "T" && tipo != "B" && tipo != "Z") {
        cout << "\nPor favor insira um alimento valido!" << endl;
    } else {
        if (tipo == "R") {                    //tipo va vn tx cheiro id x y
            alimentos.push_back(new Relva("Relva", "erva e verdura", 20, 3, 0,  lRandom , cRandom));
            alimentos[alimentos.size()-1]->setId(totalCoisas++);

        } else if (tipo == "T") {
            alimentos.push_back(new Cenoura("Cenoura", "verdura", 9999, 4, 0, lRandom , cRandom));
            alimentos[alimentos.size()-1]->setId(totalCoisas++);

        }else if (tipo == "B") {
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


void Reserva::interacaoAnimal() {
    bool animalRedondeza = false;
    bool pesoPerigoso = false;
    int engravida = 0;

    for(int i = 0; i < animais.size(); i++){

        if(animais[i]->getTipoAnimal() == "C"){ // ANIMAL C COELHO

            animais[i]->setVida(animais[i]->getvAnimal()-1); //A cada instante diminui um do vAnimal
            animais[i]->setFome(animais[i]->getFome()+1);// A cada instante aumenta a fome do animal

            if(animais[i]->getvAnimal() != 0){ //Se a vida for diferente de 0, ele faz toda a logica do animal

                if (animais[i]->getvAnimal() == animais[i]->getvAnimal() - 8){
                    engravida = rand() % 1 + 2;
                    if(engravida == 1){ //engravidou com sucesso
                       animais.push_back(animais[i]->duplica());
                       animais[animais.size()-1]->setId(totalCoisas++);
                    }

                } // passaram 8 instantes

                animalRedondeza = verificaAnimalRedondeza(animais[i]->getId(), animais[i]->getX(), animais[i]->getY(), 4); // Return true - se tiver | Return false - se não tiver
                pesoPerigoso = checkPeso(animais[i]->getId(), animais[i]->getX(), animais[i]->getY(), 4, 10); // Return true - se tiver algum peso perigoso | Return false - se não tiver nenhum

                if(animalRedondeza && pesoPerigoso){  ; // Return true para ambos - faz Movimentação com animal na redondeza

                    debug << "Tem animal na redondeza C\n";

                    if(animais[i]->getFome() >= 10){ // se a fome for maior ou igual a 10, ele faz a logica do if

                        animais[i]->setSaude(animais[i]->getSaude()-1);


                    }else if(animais[i]->getFome() >= 20){ // se a fome for maior ou igual a 20, ele faz a logica do else if

                        animais[i]->setSaude(animais[i]->getSaude()-2);

                    }
                    animais[i]->fazMovimentacaoCAR(); //se move na direcao oposta

                }else{  // Return false - faz Movimentação sem animal na redondeza

                    debug << "Nao tem animal na redondeza C\n";

                    if(animais[i]->getFome() >= 10){ // se a fome for maior ou igual a 10, ele faz a logica do if

                        animais[i]->setSaude(animais[i]->getSaude()-1);

                        animais[i]->fazMovimentacaoSAR(1,3);

                    }else if(animais[i]->getFome() >= 20){ // se a fome for maior ou igual a 20, ele faz a logica do else if

                        animais[i]->setSaude(animais[i]->getSaude()-2);

                        animais[i]->fazMovimentacaoSAR(1,4);

                    }else{ // se a fome for menor que 10, ele faz a logica do else

                        animais[i]->fazMovimentacaoSAR(1,2);
                    }
                }
            }else{ // se vAnimal for = 0, ele morre e é eliminado do vetor

                removeAnimalbyId(animais[i]->getId());
            }


        }else if(animais[i]->getTipoAnimal() == "O"){

            animalRedondeza = verificaAnimalRedondeza(animais[i]->getId(), animais[i]->getX(), animais[i]->getY(), 3);

            if(animalRedondeza){   // Return true - faz Movimentação com animal na redondeza

                debug << "Tem animal na redondeza O\n";

            }else{  // Return false - faz Movimentação sem animal na redondeza

                debug << "Nao tem animal na redondeza O\n";
                animais[i]->fazMovimentacaoSAR(1,1);
            }

        }else if(animais[i]->getTipoAnimal() == "L"){

            animalRedondeza = verificaAnimalRedondeza(animais[i]->getId(), animais[i]->getX(), animais[i]->getY(), 5);

            if(animalRedondeza){  ; // Return true - faz Movimentação com animal na redondeza

                debug << "Tem animal na redondeza L\n";

            }else{  // Return false - faz Movimentação sem animal na redondeza

                debug << "Nao tem animal na redondeza L\n";
                animais[i]->fazMovimentacaoSAR(1,1);
            }

        }else if(animais[i]->getTipoAnimal() == "G"){

            animalRedondeza = verificaAnimalRedondeza(animais[i]->getId(), animais[i]->getX(), animais[i]->getY(), 7);

            if(animalRedondeza){  ; // Return true - faz Movimentação com animal na redondeza

                debug << "Tem animal na redondeza G\n";

            }else{  // Return false - faz Movimentação sem animal na redondeza

                debug << "Nao tem animal na redondeza G\n";
                animais[i]->fazMovimentacaoSAR(1,1); // random entre e 1 2
            }

        }else if(animais[i]->getTipoAnimal() == "M"){

            animalRedondeza = verificaAnimalRedondeza(animais[i]->getId(), animais[i]->getX(), animais[i]->getY(), 9);

            if(animalRedondeza){  ; // Return true - faz Movimentação com animal na redondeza

                debug << "Tem animal na redondeza M\n";

            }else{  // Return false - faz Movimentação sem animal na redondeza

                debug << "Nao tem animal na redondeza M\n";
                animais[i]->fazMovimentacaoSAR(2,7);
            }
        }
    }
    debug.clear();
}

bool Reserva::checkPeso(const int &id, const int &x, const int &y, const int &valorRedondeza, const int &peso) {
    for (auto &animal : animais) {

        // Verifica se o animal atual é o mesmo que o animal de referência

        if (animal->getId() == id) {
            continue; // Pula o animal atual e continua iterando pelos demais
        }

        // Verifica se o animal atual está nas redondezas do animal referência

        if (animal->getX() < x + valorRedondeza && animal->getX() > x - valorRedondeza && animal->getY() < y + valorRedondeza && animal->getY() > y - valorRedondeza) {
            if(animal->getPeso() >= peso){
                return true; // Encontrou um animal com peso perigoso nas redondezas
            }
        }
    }
    return false; // Não encontrou nenhum animal com peso perigoso nas redondezas
}

bool Reserva::verificaAnimalRedondeza(const int &id, const int &x, const int &y, const int &valorRedondeza) {
    for (auto &animal : animais) {

        // Verifica se o animal atual é o mesmo que o animal de referência

        if (animal->getId() == id) {
            continue; // Pula o animal atual e continua iterando pelos demais
        }

        // Verifica se o animal atual está nas redondezas do animal referência

        if (animal->getX() < x + valorRedondeza && animal->getX() > x - valorRedondeza && animal->getY() < y + valorRedondeza && animal->getY() > y - valorRedondeza) {
            return true; // Encontrou um animal nas redondezas
        }
    }
    return false; // Não encontrou nenhum animal nas redondezas
}

void Reserva::interacaoAlimento() {

    int vNutriInicial;

    for(int i = 0; i < alimentos.size(); i++ ){ //Percorre os alimentos da reserva

        if(alimentos[i]->getTipoAlimento() == "r"){// Verifica se o tipo é r

            alimentos[i]->setValimento(alimentos[i]->getValimento() - 1 ); // a cada instante diminui um do vAlimento

            if(alimentos[i]->getValimento() != 0){// se o alimento ainda tiver vAlimento, faz a logica


            }else{ // caso o vAlimento for 0, ele remove o alimento do vetor

                removeAlimentobyId(alimentos[i]->getId());
            }

        }else if(alimentos[i]->getTipoAlimento() == "t"){ // Verifica se o tipo é t

            if(alimentos[i]->getValimento() != 0){

                if (numInstantes % 10 == 0 && alimentos[i]->getToxicidade() < 3) {// a cada 10 instantes, aumenta um valor de toxicidade até dar stack em 3

                    alimentos[i]->setToxicidade(alimentos[i]->getToxicidade()+1);
                }

            }

        }else if(alimentos[i]->getTipoAlimento() == "p"){ // Verifica se o tipo é p

                vNutriInicial = alimentos[i]->getValorNutri(); // salva o valorNutri para usar como o valorInicial


                alimentos[i]->setValorNutri(alimentos[i]->getValorNutri() - 1); // diminui o valor nutritivo em 1 unidade a cada instante
                alimentos[i]->setToxicidade(alimentos[i]->getToxicidade() + 1); // aumenta o valor de toxicidade em 1 unidade em cada instante

                if (numInstantes > 2 * vNutriInicial) { // se passaram tantos instantes como duas vezes o valor nutritivo inicial

                    alimentos[i]->setToxicidade(alimentos[i]->getToxicidade() - 1); // para de aumentar o valor de toxicidade
                }

        }else if(alimentos[i]->getTipoAlimento() == "b"){ // Verifica se o tipo é b

            alimentos[i]->setValimento(alimentos[i]->getValimento() - 1); // diminui um do vAlimento a cada instante

            if(alimentos[i]->getValorNutri() > 0){ // diminui o valor nutri a cada instante até chegar a zero

                alimentos[i]->setValorNutri(alimentos[i]->getValorNutri() - 1);
            }

            if(alimentos[i]->getValimento() == 0){ //se o vAlimento for zero, ele remove o alimento do vetor/reserva

                removeAlimentobyId(alimentos[i]->getId());
            }


        }else if(alimentos[i]->getTipoAlimento() == "a"){ // Verifica se o tipo é a


        }
        debug.clear();
    }
}

void Reserva::incrementaInstante() {

    numInstantes++;
    interacaoAlimento();
    interacaoAnimal();

}

void Reserva::incrementaInstante(int valor) {
    for(int i = 0; i < valor; i++){
        numInstantes++;
        interacaoAlimento();
        interacaoAnimal();
    }
}

void Reserva::sleepChrono(int valorTempo) {
    this_thread::sleep_for(chrono::seconds (valorTempo));
}

void Reserva::incrementaInstante(int valor, int tempo) {
    for(int i = 0; i < valor; i++){
        numInstantes++;
        interacaoAlimento();
        interacaoAnimal();
        sleepChrono(tempo);
    }
}





