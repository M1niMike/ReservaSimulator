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
    int getIdPai() const;

    bool isDead();

    //Sets
    void setSaude(int novaSaude) { SAnimal = novaSaude;}
    void setPeso(int newPeso) {peso = newPeso;}
    void setVida(int newVida) { VAnimal = newVida;}
    void setId(int newId) {id = newId;}
    void setFome(int newFome) {fome = newFome;}
    void setX(int newX){x = newX;}
    void setY(int newY){y = newY;}
    void setIdPai(int newIdPai){idPai = newIdPai;}

    //prints
    string PrintaAnimal() const;

    virtual void fazMovimentacaoSemAnimal_I_F(int inicio, int fim) = 0;
    virtual void fazMovimentacaoSemAnimal_P(int posicao) = 0;
    virtual void fazMovimentacaoComAnimalFoge(int x, int y) = 0;
    virtual void fazMovimentacaoComAnimalCaca(int x, int y, int distancia) = 0;
    virtual void fazMovimentacaoComer(int x, int y, int valorNutri, int valorToxico) = 0;
    virtual void fazMovimentacaoAtePai(int x, int y,int inicio, int fim, int distancia) = 0;
    virtual void fazDarVolta(int x, int y, int linhas, int colunas) = 0;
    virtual string getTipoAnimal () const = 0;

    Animais(const string &t, int SAnimal, int VAnimal, int fome, int peso, int x, int y, int idPai);

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
    int idPai;

};


#endif //POO_TP_22_23_ANIMAIS_H
