//
// Created by mikae on 05/01/2023.
//

#include "Coelho.h"
#include "../Reserva.h"

void Coelho::fazInteracao(Reserva r) {
    //r->
}

void Coelho::fazMovimentacaoSAR() { //SAR = Sem Animal Redondeza
    setX(getX() + rand() % 2 + 1);
    setY(getY() + rand() % 2 + 1);
}

void Coelho::fazMovimentacaoCAR() { //CAR = Com Animal Redondeza
    //Fazer Logica
}
