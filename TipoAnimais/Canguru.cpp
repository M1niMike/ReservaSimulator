//
// Created by mikae on 05/01/2023.
//

#include "Canguru.h"


void Canguru::fazMovimentacaoSemAnimal_I_F(int inicio, int fim) { //SAR = Sem Animal Redondeza
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

void Canguru::fazMovimentacaoSemAnimal_P(int posicao) {
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

void Canguru::fazMovimentacaoComAnimalFoge(int x, int y) { // Com Aninal Redondeza
    if (x < getX()) { // Verifica se a coordenada x do objeto atual é menor que a coordenada x do objeto de destino
        if (y < getY()) {
            setX(getX() + 1); // Move o objeto atual diagonalmente em direção ao objeto de destino incrementando tanto x quanto y
            setY(getY() + 1);
        } else if (y == getY()) {
            setX(getX() + 1); // Move o objeto atual horizontalmente em direção ao objeto de destino incrementando x
        } else if (y > getY()) {
            setX(getX() + 1); // Move o objeto atual diagonalmente em direção ao objeto de destino incrementando x e decrementando y
            setY(getY() - 1);
        }
    } else if (x == getX()) {// Verifica se as coordenadas x são iguais
        if (y < getY()) {
            setY(getY() + 1);// Move o objeto atual verticalmente em direção ao objeto de destino incrementando y
        } else if (y > getY()) {
            setY(getY() - 1); // Move o objeto atual verticalmente em direção ao objeto de destino decrementando y
        }
    } else if (x > getX()) { // Verifica se a coordenada x do objeto atual é maior que a coordenada x do objeto de destino
        if (y < getY()) {
            setX(getX() - 1); // Move o objeto atual diagonalmente em direção ao objeto de destino decrementando x e incrementando y
            setY(getY() + 1);
        } else if (y == getY()) {
            setX(getX() - 1);  // Move o objeto atual horizontalmente em direção ao objeto de destino decrementando x
        } else if (y > getY()) {
            setX(getX() - 1); // Move o objeto atual diagonalmente em direção ao objeto de destino decrementando x e decrementando y
            setY(getY() - 1);
        }
    }

}

void Canguru::fazDarVolta(int x, int y, int linhas, int colunas)
{
    if (x < 1) {
        setX(linhas - 1);
    }
    if (x >= linhas) {

        setX(0);
    }
    if (y < 1) {

        setY(colunas - 1);
    }
    if (y >= colunas) {

        setY(0);
    }
}
