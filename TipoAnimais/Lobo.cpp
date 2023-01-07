//
// Created by mikae on 05/01/2023.
//

#include "Lobo.h"
#include "../Reserva.h"

void Lobo::fazInteracao(Reserva r) {

}

void Lobo::fazMovimentacaoSemAnimal_P(int posicao) { //SAR = Sem Animal Redondeza
    for (int i = 0; i < posicao; i++){

        int vezes = rand() % 8 + 1;

        if (vezes == 1){ // mexe para cima
            setX(getX()-1);
        }
        else if (vezes == 2){ //mexe a direita
            setY(getY()+1);
        }
        else if (vezes == 3){ // mexe para baixo
            setX(getX()+1);
        }
        else if (vezes == 4){ // mexe para trás (esquerda)
            setY(getY()-1);
        }
        else if(vezes == 5){ // mexe para a diagonal esquerda cima
            setX(getX()-1);
            setY(getY()-1);
        }
        else if(vezes == 6){ // mexe para a diagonal direita cima
            setX(getX()+1);
            setY(getY()-1);
        }
        else if(vezes == 7){ // mexe para a diagonal direita baixo
            setX(getX()+1);
            setY(getY()+1);
        }
        else if(vezes == 8){ // mexe para a diagonal esquerda baixo
            setX(getX()-1);
            setY(getY()+1);
        }
    }
}

void Lobo::fazMovimentacaoComAnimal() { //CAR = Com Animal Redondeza
    //Fazer Logica
}
