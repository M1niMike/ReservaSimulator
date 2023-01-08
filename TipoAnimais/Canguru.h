//
// Created by mikae on 05/01/2023.
//

#ifndef RESERVA_H_CANGURU_H
#define RESERVA_H_CANGURU_H

#include "../Animais.h"

class Canguru : public Animais{
public:
    Canguru(const string& tipo, int SCanguru, int VCanguru, int fome, int peso, int x, int y) : Animais(tipo, SCanguru, VCanguru, fome, peso, x, y) {}

    string getTipoAnimal() const override{ return "G"; }
    void fazMovimentacaoComAnimal() override;
    void fazMovimentacaoSemAnimal_I_F(int inicio, int fim) override;
    void fazMovimentacaoSemAnimal_P(int posicao) override;
    void fazDarVolta(int x, int y, int linhas, int colunas) override;
    void fazMovimentacaoComer(int x, int y, int valorNutri, int valorToxico) override {}
};



#endif //RESERVA_H_CANGURU_H
