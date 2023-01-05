//
// Created by mikae on 05/01/2023.
//

#ifndef RESERVA_H_ANIMALMISTERIOSO_H
#define RESERVA_H_ANIMALMISTERIOSO_H

#include "../Animais.h"

class AnimalMisterioso : public Animais{
public:
    AnimalMisterioso(const string&  tipo, int SAnimalM, int VAnimalM, int fome, int peso, int x, int y) : Animais(tipo, SAnimalM, VAnimalM, fome, peso, x, y) {}

    string getTipoAnimal() const override{ return "M"; }

    void fazInteracao(Reserva r) override;

};


#endif //RESERVA_H_ANIMALMISTERIOSO_H
