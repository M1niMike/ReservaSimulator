//
// Created by mikae on 05/01/2023.
//

#include "AnimalMisterioso.h"


//Fazer Logica do AnimalMisterioso
void AnimalMisterioso::fazMovimentacaoSemAnimal_I_F(int inicio, int fim) { //SAR = Sem Animal Redondeza
    setX(getX() + rand() % fim + inicio);
    setY(getY() + rand() % fim + inicio);
}

void AnimalMisterioso::fazMovimentacaoComAnimal() { //CAR = Com Animal Redondeza
    //Fazer Logica
}

void AnimalMisterioso::fazDarVolta(int x, int y, int linhas, int colunas)
{
    if (x < 1) {
        setX(linhas - 1);
    }
    if (x >= linhas) {

        setX(0);
    }
    if (y < 1) {

        setY(colunas - 1);
    }
    if (y >= colunas) {

        setY(0);
    }
}

void AnimalMisterioso::fazMovimentacaoComer(int x, int y, int valorNutri, int valorToxico)
{
    int distX = x - getX();
    int distY = y - getY();


    if(distX > 0){ // Se a distância for maior que zero, move o animal para a direita (ou para cima, no caso do eixo y)
        setX(getX() + 1);
    }else if(distX < 0){ // Se a distância for menor que zero, move o animal para a esquerda (ou para baixo)
        setX(getX() - 1);
    }

    // Repete o processo para o y
    if(distY > 0){
        setY(getY() + 1);
    }
    else if(distX > 0){
        setX(getX() + 1);
    }

    if(getX() == x && getY() == y){ // se as coordenadas do animal forem iguais a do alimento, ele come
        // Altera os status do animal
        setSaude(getSaude() + valorNutri);
        setSaude(getSaude() - valorToxico);
        //fome fica a 0, pois comeu

        setFome(0); // se estiver vivo ele come
    }
}