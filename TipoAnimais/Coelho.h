//
// Created by mikae on 05/01/2023.
//

#ifndef RESERVA_H_COELHO_H
#define RESERVA_H_COELHO_H

#include "../Animais.h"

class Coelho : public Animais{
public:
    Coelho(const string& tipo, int SCoelho, int VCoelho, int fome, int peso, int x, int y) : Animais(tipo, SCoelho, VCoelho, fome, peso, x, y) {}

    string getTipoAnimal() const override{ return "C"; }
    void fazMovimentacaoSemAnimal_I_F(int inicio, int fim) override;
    void fazMovimentacaoSemAnimal_P(int posicao) override;
    void fazMovimentacaoComAnimal() override;
    void fazDarVolta(int x, int y, int linhas, int colunas) override;
    void fazMovimentacaoComer(int x, int y, int valorNutri, int valorToxico) override;

};


#endif //RESERVA_H_COELHO_H
