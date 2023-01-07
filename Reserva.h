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

    int constantesReader(string aux);
    bool leFicheiroConstantes(string fileName);

    //Get
    int getLinhas() const;
    int getColunas() const;
    int getInstantes() const;
    bool verificaLinhasColunas(const int &x, const int &y);


    //Set
    void setLinhas(int newLinhas);
    void setColunas(int newColunas);

    void incrementaInstante();

    //Animal
    vector<Animais *> getVecAnimal() const;
    void criaAnimal(const string &tipo, const int &x, const int &y);
    void criaAnimalRandom(const string &tipo);
    int getNumberOfAnimals() const;
    void removeAnimalbyId(const int &id);
    void removeAnimalbyCoord(const int &x, const int &y);
    void feedAnimalbyCoord(const int &x, const int &y, const int &valorNutritivo, const int &toxicidade);
    void feedAnimalById(const int &id, const int &valorNutritivo, const int &toxicidade);
    void interacaoAnimal();
    bool checkPeso(const int &id, const int &x, const int &y, const int &valorRedondeza, const int& peso);
    bool verificaAnimalRedondeza(const int &id, const int &x, const int &y, const int &valorRedondeza);

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
    bool verificaAlimentoRedondeza(const int &id, const int &x, const int &y, const int &valorRedondeza);
    void interacaoAlimento();

private:
    int linhas;
    int colunas;
    vector<Animais *> animais;
    vector<Alimentos *> alimentos;
    map<string, int> mapaConstantes;
    int totalCoisas = 1;
    //static int ID;
    int numInstantes;


    Window debug; //APAGAR DEPOIS

    //map string, Reservas* se o nome(string) for igual ao nome da reserva entao carregaReserva(cominputdouser)
};

#endif //POO_TP_22_23_RESERVA_H