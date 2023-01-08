//
// Created by mikae on 05/01/2023.
//

#ifndef RESERVA_H_LOBO_H
#define RESERVA_H_LOBO_H

#include "../Animais.h"

class Lobo : public Animais{
public:
    Lobo(const string& tipo, int SLobo, int VLobo, int fome, int peso, int x, int y, int idPai) : Animais(tipo, SLobo, VLobo, fome, peso, x, y, 0)
    {}

    string getTipoAnimal() const override{ return "L"; }
    void fazMovimentacaoComAnimalFoge(int x, int y) override {};
    void fazMovimentacaoSemAnimal_P(int posicao) override;
    void fazMovimentacaoSemAnimal_I_F(int inicio, int fim) override {}
    void fazMovimentacaoComAnimalCaca(int x, int y, int distancia) override;
    void fazDarVolta(int x, int y, int linhas, int colunas) override;
    void fazMovimentacaoComer(int x, int y, int valorNutri, int valorToxico) override;
    void fazMovimentacaoAtePai(int x, int y, int inicio, int fim, int distancia) override {}

};

#endif //RESERVA_H_LOBO_H
