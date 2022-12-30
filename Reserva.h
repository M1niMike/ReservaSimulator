//
// Created by mikae on 07/11/2022.
//

#ifndef POO_TP_22_23_RESERVA_H
#define POO_TP_22_23_RESERVA_H

#include "util.h"
#include "Animais.h"
#include "Alimentos.h"


class Reserva {
public:
    Reserva(int numInstantes = 1, int nl = 0, int nc = 0);

    ~Reserva()
    {
        for (auto it = animais.begin(); it != animais.end(); it++)
        {
            delete (*it);
        }

        for (auto it = alimentos.begin(); it != alimentos.end(); it++)
        {
            delete (*it);
        }
    }

    //Get
    int getLinhas() const;
    int getColunas() const;
    int getInstantes() const;
    bool verificaLinhasColunas(const int &x, const int &y);

    //Set
    void setLinhas(int newLinhas);
    void setColunas(int newColunas);

    void incrementaInstante(){numInstantes++;} //funçao para o comando n
    void incrementaInstante(int valor) {numInstantes += valor;}

    //Animal
    vector<Animais *> getVecAnimal() const;
    void criaAnimal(const string &tipo, int saude, int vida, const int &x, const int &y);
    void criaAnimalRandom(const string &tipo, int saude, int vida);
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
    //static int ID;
    int numInstantes;

    //map string, Reservas* se o nome(string) for igual ao nome da reserva entao carregaReserva(cominputdouser)
};

#endif //POO_TP_22_23_RESERVA_H