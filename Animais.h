//
// Created by mikae on 07/11/2022.
//

#ifndef POO_TP_22_23_ANIMAIS_H
#define POO_TP_22_23_ANIMAIS_H

#include "util.h"

class Animais{
public:
    //gets
    virtual string getTipoAnimal () const;
    int getSaude() const;
    int getPeso () const;
    int getvAnimal() const;
    int getX() const;
    int getY() const;
    int getId() const;
    bool isDead();

    //Sets
    void setSaude(int novaSaude) { SAnimal = novaSaude;}
    void setPeso(int newPeso) {peso = newPeso;}
    void setVida(int newVida) { VAnimal = newVida;}
    void setId(int newId) {id = newId;}

    //prints
    string PrintaAnimal() const;


    Animais(const string& t, int SAnimal, int VAnimal, int peso, int x, int y);

    virtual ~Animais() = default;


private:
    string tipo;
    int SAnimal;
    int peso;
    int VAnimal; // tempo de vida
    int estaMorto;
    bool podeComer;
    int x, y;
    int id;

};

class Coelho : public Animais{
public:
    Coelho(const string& tipo, int SCoelho, int VCoelho, int peso, int x, int y) : Animais(tipo, SCoelho, VCoelho, peso, x, y) {}

    string getTipoAnimal() const override{
        return "C";
    }
};

class Lobo : public Animais{
public:
    Lobo(const string& tipo, int SLobo, int VLobo, int peso, int x, int y) : Animais(tipo, SLobo, VLobo, peso, x, y) {}

    string getTipoAnimal() const override{
        return "L";
    }
};

class AnimalMisterioso : public Animais{
public:
    AnimalMisterioso(const string&  tipo, int SAnimalM, int VAnimalM, int peso, int x, int y) : Animais(tipo, SAnimalM, VAnimalM, peso, x, y) {}

    string getTipoAnimal() const override{
        return "M";
    }
};

class Ovelha : public Animais{
public:
    Ovelha(const string& tipo, int SOvelha, int VOvelha, int peso, int x, int y) : Animais(tipo, SOvelha, VOvelha, peso, x, y) {}

    string getTipoAnimal() const override{
        return "O";
    }
};



class Canguru : public Animais{
public:
    Canguru(const string& tipo, int SCanguru, int VCanguru, int peso, int x, int y) : Animais(tipo, SCanguru, VCanguru, peso, x, y) {}

    string getTipoAnimal() const override{
        return "G";
    }
};



#endif //POO_TP_22_23_ANIMAIS_H
