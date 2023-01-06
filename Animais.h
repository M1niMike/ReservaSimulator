//
// Created by mikae on 07/11/2022.
//

#ifndef POO_TP_22_23_ANIMAIS_H
#define POO_TP_22_23_ANIMAIS_H

#include "util.h"


class Reserva; // Forma de inibir o include recursivo, falando para o compilador que tal classe vai ser implementada em outro lugar

class Animais{
public:
    //gets

    int getSaude() const;
    int getPeso () const;
    int getvAnimal() const;
    int getX() const;
    int getY() const;
    int getId() const;
    int getFome() const;

    bool isDead();

    //Sets
    void setSaude(int novaSaude) { SAnimal = novaSaude;}
    void setPeso(int newPeso) {peso = newPeso;}
    void setVida(int newVida) { VAnimal = newVida;}
    void setId(int newId) {id = newId;}
    void setFome(int newFome) {fome = newFome;}
    void setX(int newX){x = newX;}
    void setY(int newY){y = newY;}

    //prints
    string PrintaAnimal() const;


    bool alimentaAnimal(int valorNutritivo, int valorToxico);

    virtual void fazInteracao(Reserva r) = 0;
    virtual void fazMovimentacaoSAR(int inicio, int fim) = 0;
    virtual void fazMovimentacaoCAR() = 0;
    virtual string getTipoAnimal () const = 0;

    Animais(const string& t, int SAnimal, int VAnimal, int fome, int peso, int x, int y);

    virtual ~Animais() = default;

private:
    string tipo;
    int SAnimal;
    int peso;
    int VAnimal; // tempo de vida
    int estaMorto;
    // bool podeComer;
    int fome;
    int x, y;
    int id;

};


#endif //POO_TP_22_23_ANIMAIS_H
