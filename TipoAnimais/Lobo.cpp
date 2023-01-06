//
// Created by mikae on 05/01/2023.
//

#include "Lobo.h"
#include "../Reserva.h"

void Lobo::fazInteracao(Reserva r) {

}

void Lobo::fazMovimentacaoSAR(int inicio, int fim) { //SAR = Sem Animal Redondeza
    setX(getX() + rand() % fim + inicio);
    setY(getY() + rand() % fim + inicio);
}

void Lobo::fazMovimentacaoCAR() { //CAR = Com Animal Redondeza
    //Fazer Logica
}
