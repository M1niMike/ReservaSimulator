//
// Created by mikae on 05/01/2023.
//

#include "Ovelha.h"
#include "../Reserva.h"

void Ovelha::fazInteracao(Reserva r) {

}


void Ovelha::fazMovimentacaoSAR() { //SAR = Sem Animal Redondeza

    setX(getX() + 1);
    setY(getY() + 1);

}

void Ovelha::fazMovimentacaoCAR() {  //CAR = Com Animal Redondeza

}

