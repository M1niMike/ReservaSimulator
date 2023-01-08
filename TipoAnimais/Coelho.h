//
// Created by mikae on 05/01/2023.
//

#ifndef RESERVA_H_COELHO_H
#define RESERVA_H_COELHO_H

#include "../Animais.h"

class Coelho : public Animais{
public:
    Coelho(const string& tipo, int SCoelho, int VCoelho, int fome, int peso, int x, int y ,int idPai) : Animais(tipo, SCoelho, VCoelho, fome, peso, x, y, 0)
    {}

    string getTipoAnimal() const override{ return "C"; }
    void fazMovimentacaoSemAnimal_I_F(int inicio, int fim) override;
    void fazMovimentacaoSemAnimal_P(int posicao) override;
    void fazMovimentacaoComAnimalFoge(int x, int y) override;
    void fazDarVolta(int x, int y, int linhas, int colunas) override;
    void fazMovimentacaoComer(int x, int y, int valorNutri, int valorToxico) override;
    void fazMovimentacaoComAnimalCaca(int x, int y, int distancia) override {}
    void fazMovimentacaoAtePai(int x, int y, int inicio, int fim, int distancia) override {}

};


#endif //RESERVA_H_COELHO_H
