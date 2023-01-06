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

    void fazInteracao(Reserva r) override;

    void fazMovimentacaoCAR() override;

    void fazMovimentacaoSAR(int inicio, int fim) override;

    Animais* duplica() const override {return new Canguru(*this);}
};



#endif //RESERVA_H_CANGURU_H
