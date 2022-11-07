//
// Created by mikae on 07/11/2022.
//

#ifndef POO_TP_22_23_TIPOANIMAIS_H
#define POO_TP_22_23_TIPOANIMAIS_H

#include "util.h"

class TipoAnimais{
    string tipo;

public:
    string getTipoAnimal () const {return tipo;}
    TipoAnimais(string t) : tipo(t){};

};

class Coelho : public TipoAnimais{};

class Ovelha : public TipoAnimais{};

class Lobo : public TipoAnimais{};

class Canguro : public TipoAnimais{};

class AnimalMisterioso : public TipoAnimais{};


#endif //POO_TP_22_23_TIPOANIMAIS_H
