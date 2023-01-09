//
// Created by mikae on 08/01/2023.
//

#ifndef _HISTORICO_H_
#define _HISTORICO_H_
#include "Alimentos.h"
#include "Animais.h"


class Historico {
 public:
    Historico();
    void adiciona(string nomeAlimento, int VNutri, int VToxic);
    void apaga();
 private:

  Alimentos *alimentos;
  int tam;
};


#endif //_HISTORICO_H_
