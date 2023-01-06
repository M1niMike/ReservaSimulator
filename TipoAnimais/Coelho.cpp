//
// Created by mikae on 05/01/2023.
//

#include "Coelho.h"
#include "../Reserva.h"

void Coelho::fazInteracao(Reserva r) {
    //r->
}

void Coelho::fazMovimentacaoSAR(int inicio, int fim) { //SAR = Sem Animal Redondeza
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

    /*setX(getX() + rand() % fim + inicio); // rand() % 2 + 1 -- 1 e 2
    setY(getY() + rand() % fim + inicio);*/
}

void Coelho::fazMovimentacaoCAR() { // se ele vir alguma coisa nas redondezas, ele foge
    setX(getX() - 1);
    setY(getY() - 1);
}

//void Coelho::fazMovimentacaoCAlimentoR() {}
