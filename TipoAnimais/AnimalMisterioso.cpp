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
