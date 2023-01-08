//
// Created by mikae on 05/01/2023.
//

#ifndef RESERVA_H_ANIMALMISTERIOSO_H
#define RESERVA_H_ANIMALMISTERIOSO_H

#include "../Animais.h"

class AnimalMisterioso : public Animais{
public:
    AnimalMisterioso(const string& tipo, int SAnimalM, int VAnimalM, int fome, int peso, int x, int y) : Animais(tipo, SAnimalM, VAnimalM, fome, peso, x, y) {}

    string getTipoAnimal() const override{ return "M"; }
    void fazMovimentacaoComAnimalFoge(int x, int y) override;
    void fazMovimentacaoSemAnimal_I_F(int inicio, int fim) override;
    void fazMovimentacaoSemAnimal_P(int posicao) override {}
    void fazDarVolta(int x, int y, int linhas, int colunas) override;
    void fazMovimentacaoComer(int x, int y, int valorNutri, int valorToxico) override;
    void fazMovimentacaoComAnimalCaca(int x, int y, int distancia) override {}

};


#endif //RESERVA_H_ANIMALMISTERIOSO_H
