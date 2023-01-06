//
// Created by mikae on 05/01/2023.
//

#include "Ovelha.h"
#include "../Reserva.h"

void Ovelha::fazInteracao(Reserva r) {

}


void Ovelha::fazMovimentacaoSAR(int inicio, int fim) { //SAR = Sem Animal Redondeza

    setX(getX() + rand() % fim + inicio);
    setY(getY() + rand() % fim + inicio);
}

void Ovelha::fazMovimentacaoCAR() {  //CAR = Com Animal Redondeza

}

