//
// Created by mikae on 05/01/2023.
//

#include "Coelho.h"
#include "../Reserva.h"

void Coelho::fazInteracao(Reserva r) {
    //r->
}

void Coelho::fazMovimentacaoSAR(int inicio, int fim) { //SAR = Sem Animal Redondeza
    setX(getX() + rand() % fim + inicio); // rand() % 2 + 1 -- 1 e 2
    setY(getY() + rand() % fim + inicio);
}

void Coelho::fazMovimentacaoCAR() { // se ele vir alguma coisa nas redondezas, ele foge
    setX(getX() - 1);
    setY(getY() - 1);
}

//void Coelho::fazMovimentacaoCAlimentoR() {}
