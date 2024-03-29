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
    pair<int, int> createFilho(int x, int y, int direcao, int distancia);
    pair<int, int> createCorpo(int x, int y, int direcao);
    pair<int, int> pegaCoordAl(int x, int y, int valorRedondeza, string comida);
    pair<int, int> pegaValoresAl(int x, int y, int valorRedondeza, string comida);
    pair<int, int> pegaCoordAni(int id, int x, int y, int valorRedondeza, int peso);
    pair<int, int> pegaCoordCaca(int id, int x, int y, int valorRedondeza);
    pair<int, int> pegaCoordPai(int id, int idPai, int x, int y, int valorRedondeza);
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
    Animais* verificaAnimalRedondeza(const int &id, const int &x, const int &y, const int &valorRedondeza);
    bool verificaSeEstaFora(int x, int y, int linhas, int colunas);
    bool checkComida(int x, int y, int valorRedondeza, string comida);
    bool verificaAnimalRedondezaAlemPai(int id, int idPai, int x, int y, int valorRedondeza);
    int pegaPesoAnimalCacado(int id, int x, int y, int valorRedondeza);
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



};

#endif //POO_TP_22_23_RESERVA_H