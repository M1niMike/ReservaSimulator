//
// Created by mikae on 05/01/2023.
//

#ifndef RESERVA_H_LOBO_H
#define RESERVA_H_LOBO_H

#include "../Animais.h"

class Lobo : public Animais{
public:
    Lobo(const string& tipo, int SLobo, int VLobo, int fome, int peso, int x, int y) : Animais(tipo, SLobo, VLobo, fome, peso, x, y) {}

    string getTipoAnimal() const override{ return "L"; }

    void fazInteracao(Reserva r) override;
};

#endif //RESERVA_H_LOBO_H
