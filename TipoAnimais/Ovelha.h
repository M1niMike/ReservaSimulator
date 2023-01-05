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

    void fazInteracao(Reserva r) override;
};


#endif //RESERVA_H_OVELHA_H
