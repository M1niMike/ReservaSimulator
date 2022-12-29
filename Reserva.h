//
// Created by mikae on 07/11/2022.
//

#ifndef POO_TP_22_23_RESERVA_H
#define POO_TP_22_23_RESERVA_H

#include "util.h"
#include "Animais.h"
#include "Alimentos.h"
#include <vector>

class Reserva {
public:
    Reserva(int nl = 0, int nc = 0);

    ~Reserva()
    {
        for (auto it = animais.begin(); it != animais.end(); it++)
        {
            delete (*it);
        }
        cout << "\nAdeus...Animais...\n";

        for (auto it = alimentos.begin(); it != alimentos.end(); it++)
        {
            delete (*it);
        }
        cout << "\nAdeus...alimentos...\n" << endl;
    };

    //Get
    int getLinhas() const;
    int getColunas() const;
    bool verificaLinhasColunas(const int &x, const int &y);

    //Set
    void setLinhas(int newLinhas);
    void setColunas(int newColunas);

    //Animal
    vector<Animais *> getVecAnimal() const;
    void criaAnimal(const string &tipo, int saude, int vida, int peso, const int &x, const int &y);
    void criaAnimalRandom(const string &tipo, int saude, int vida, int peso);
    int getNumberOfAnimals() const;
    void removeAnimalbyId(const int &id);
    void removeAnimalbyCoord(const int &x, const int &y);

    string getInfoAnimalId(int id) const;

    //Alimento
    vector<Alimentos *> getVecAlimento() const;
    void criaAlimento(const string &tipo, const int &x, const int &y);
    void criaAlimentoRandom(const string &tipo);
    int getNumberOfFood() const;
    int getTotalCoisas();
    string getInfoAlimentoId(int id) const;
    bool hasAlimento(int x, int y);
    void removeAlimentobyId(const int &id);
    void removeAlimentobyCoord(const int &x, const int &y);

private:
    int linhas;
    int colunas;
    vector<Animais *> animais;
    vector<Alimentos *> alimentos;
    int totalCoisas = 1;
    Window textInterface;
    //static int ID;
};

#endif //POO_TP_22_23_RESERVA_H