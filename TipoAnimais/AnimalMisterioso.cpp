//
// Created by mikae on 05/01/2023.
//

#include "AnimalMisterioso.h"
#include "../Reserva.h"

void AnimalMisterioso::fazInteracao(Reserva r) {

}
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