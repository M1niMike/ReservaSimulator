//
// Created by mikae on 05/01/2023.
//

#include "Canguru.h"
#include "../Reserva.h"

void Canguru::fazInteracao(Reserva r) {

}

void Canguru::fazMovimentacaoSAR(int inicio, int fim) { //SAR = Sem Animal Redondeza
        setX(getX() + rand() % fim + inicio);
        setY(getY() + rand() % fim + inicio);
}

void Canguru::fazMovimentacaoCAR() { // Com Aninal Redondeza
    //Fazer Logica
}
