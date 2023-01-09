//
// Created by mikae on 08/01/2023.
//

#include "Historico.h"

Historico::Historico() : tam(0){
    alimentos = new Alimentos();
}

void Historico::adiciona(string nomeAlimento, int VNutri, int VToxic)
{
    Alimentos *aux;

    for (int i = 0; i < tam; i++){
        aux[i] = alimentos[i];
    }

    alimentos = aux;

    //<>
}