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

    void fazInteracao(Reserva r) override;

    void fazMovimentacaoSAR(int inicio, int fim) override;

    void fazMovimentacaoCAR() override;

    Animais* duplica() const override {return new Coelho(*this);}
};


#endif //RESERVA_H_COELHO_H
