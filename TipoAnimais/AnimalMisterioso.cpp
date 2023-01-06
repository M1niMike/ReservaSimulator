//
// Created by mikae on 05/01/2023.
//

#include "AnimalMisterioso.h"
#include "../Reserva.h"

void AnimalMisterioso::fazInteracao(Reserva r) {

}
//Fazer Logica do AnimalMisterioso
void AnimalMisterioso::fazMovimentacaoSAR() { //SAR = Sem Animal Redondeza
    setX(getX() + 1);
    setY(getY() + 1);
}

void AnimalMisterioso::fazMovimentacaoCAR() { //CAR = Com Animal Redondeza
    //Fazer Logica
}
