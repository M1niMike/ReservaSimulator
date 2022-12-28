//
// Created by mikae on 07/11/2022.
//

#ifndef POO_TP_22_23_ANIMAIS_H
#define POO_TP_22_23_ANIMAIS_H

#include "util.h"

class Animais{
public:
    //gets
    string getTipoAnimal () const;
    int getSaude() const;
    int getPeso () const;
    int getvAnimal() const;
    int getX() const;
    int getY() const;
    int getId() const;

    //Sets
    void setSaude(int novaSaude) { SAnimal = novaSaude;}
    void setPeso(int newPeso) {peso = newPeso;}
    void setVida(int newVida) { VAnimal = newVida;}
    void setId(int newId) {id = newId;}

    //prints
    string PrintaAnimal() const;


    Animais(const string& t, int SAnimal, int VAnimal, int peso, int x, int y);
    //Animais(int id, const string& t, int SAnimal, int VAnimal, int peso, int x, int y);

private:
    string tipo;
    int SAnimal;
    int peso;
    int VAnimal; // tempo de vida
    bool isDead;
    int x, y;
    int id;

};

#endif //POO_TP_22_23_ANIMAIS_H
