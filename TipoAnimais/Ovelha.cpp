//
// Created by mikae on 05/01/2023.
//

#include "Ovelha.h"
#include "../Reserva.h"

void Ovelha::fazInteracao(Reserva r) {

}


void Ovelha::fazMovimentacaoSemAnimal_I_F(int inicio, int fim) { //SAR = Sem Animal Redondeza

    for (int i = 0; i < rand() % fim + inicio; i++){

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

void Ovelha::fazMovimentacaoSemAnimal_P(int posicao) {
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

void Ovelha::fazMovimentacaoComAnimal() {  //CAR = Com Animal Redondeza

}

