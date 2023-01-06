//
// Created by mikae on 05/01/2023.
//

#include "Canguru.h"
#include "../Reserva.h"

void Canguru::fazInteracao(Reserva r) {

}

void Canguru::fazMovimentacaoSAR() { //SAR = Sem Animal Redondeza
        setX(getX() + 1);
        setY(getY() + 1);
}

void Canguru::fazMovimentacaoCAR() { // Com Aninal Redondeza
    //Fazer Logica
}
