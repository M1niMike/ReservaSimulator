//
// Created by mikae on 05/01/2023.
//

#include "Lobo.h"
#include "../Reserva.h"

void Lobo::fazInteracao(Reserva r) {

}

void Lobo::fazMovimentacaoSAR() { //SAR = Sem Animal Redondeza
    setX(getX() + 1);
    setY(getY() + 1);
}

void Lobo::fazMovimentacaoCAR() { //CAR = Com Animal Redondeza
    //Fazer Logica
}
