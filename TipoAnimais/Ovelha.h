//
// Created by mikae on 05/01/2023.
//

#ifndef RESERVA_H_OVELHA_H
#define RESERVA_H_OVELHA_H

#include "../Animais.h"

class Ovelha : public Animais{
public:
    Ovelha(const string& tipo, int SOvelha, int VOvelha, int fome, int peso, int x, int y) : Animais(tipo, SOvelha, VOvelha, fome, peso, x, y) {}

    string getTipoAnimal() const override{ return "O"; }
    void fazMovimentacaoComAnimalFoge(int x, int y) override;
    void fazMovimentacaoSemAnimal_I_F(int inicio, int fim) override;
    void fazMovimentacaoSemAnimal_P(int posicao) override;
    void fazMovimentacaoComAnimalCaca(int x, int y, int distancia) override {}
    void fazDarVolta(int x, int y, int linhas, int colunas) override;
    void fazMovimentacaoComer(int x, int y, int valorNutri, int valorToxico) override;


};


#endif //RESERVA_H_OVELHA_H
