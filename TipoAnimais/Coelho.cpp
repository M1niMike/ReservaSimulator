//
// Created by mikae on 05/01/2023.
//

#include "Coelho.h"

void Coelho::fazMovimentacaoSemAnimal_I_F(int inicio, int fim) { //SAR = Sem Animal Redondeza
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

void Coelho::fazMovimentacaoSemAnimal_P(int posicao) {
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

void Coelho::fazMovimentacaoComAnimal() { // se ele vir alguma coisa nas redondezas, ele foge
    setX(getX() - 1);
    setY(getY() - 1);

}

void Coelho::fazDarVolta(int x, int y, int linhas, int colunas)
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

void Coelho::fazMovimentacaoComer(int x, int y, int valorNutri, int valorToxico)
{
    int distX = x - getX();
    int distY = y - getY();


    if(distX > 0){ // Se a distância for maior que zero, move o animal para a direita (ou para cima, no caso do eixo y)
        setX(getX() + 1);
    }else if(distX < 0){ // Se a distância for menor que zero, move o animal para a esquerda (ou para baixo)
        setX(getX() - 1);
    }

    // Repete o processo para o y
    if(distY > 0){
        setY(getY() + 1);
    }
    else if(distX > 0){
        setX(getX() + 1);
    }

    if(getX() == x && getY() == y){ // se as coordenadas do animal forem iguais a do alimento, ele come
        // Altera os status do animal
        setSaude(getSaude() + valorNutri);
        setSaude(getSaude() - valorToxico);
        //fome fica a 0, pois comeu

        setFome(0); // se estiver vivo ele come
    }
}

