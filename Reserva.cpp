//
// Created by mikae on 07/11/2022.
//

#include "Reserva.h"
#include "util.h"

/*ANIMAIS*/

#include "TipoAnimais/Coelho.h"
#include "TipoAnimais/Ovelha.h"
#include "TipoAnimais/Lobo.h"
#include "TipoAnimais/Canguru.h"
#include "TipoAnimais/AnimalMisterioso.h"

/*ALIMENTOS*/

#include "TipoAlimentos/Relva.h"
#include "TipoAlimentos/Cenoura.h"
#include "TipoAlimentos/Corpo.h"
#include "TipoAlimentos/Bife.h"
#include "TipoAlimentos/AlimentoMisterioso.h"

static int idDoPai = 0;


Reserva::Reserva(int numInstantes, int nl, int nc): linhas(nl), colunas(nc), numInstantes(numInstantes)
{

}

//Funcs Auxiliares
int Reserva::getTotalCoisas()
{
    return totalCoisas++;
}

int Reserva::getLinhas() const
{
    return linhas;
}

int Reserva::getColunas() const
{
    return colunas;
}

void Reserva::setLinhas(int newLinhas)
{
    linhas = newLinhas;
}

void Reserva::setColunas(int newColunas)
{
    colunas = newColunas;
}

int Reserva::getInstantes() const
{
    return numInstantes;
}


bool Reserva::leFicheiroConstantes(string fileName)
{
    string textoDoFich;

    ifstream file;

    int valor;

    string aux;

    file.open(fileName);

    if (!file) {
        return false;
    }

    while (getline(file, textoDoFich)) {
        istringstream iss(textoDoFich);
        if (!(iss >> aux >> valor)) {
            continue;
        }
        mapaConstantes[aux] = valor;
    }

    file.ignore('\n');

    return true;
}


int Reserva::constantesReader(string aux)
{
    for (auto it : mapaConstantes) {
        if (mapaConstantes.find(aux) != mapaConstantes.end()) {
            return mapaConstantes[aux];
        }
    }
    return -1;
}


/*ANIMAL*/
void Reserva::criaAnimal(const string &tipo, const int &x, const int &y)
{
    if (tipo != "C" && tipo != "O" && tipo != "L" && tipo != "G" && tipo != "M") {
        cout << "\nPor favor insira um animal valido!" << endl;
    } else {
        if (tipo == "C") {
            animais.push_back(new Coelho("C", constantesReader("SCoelho"), constantesReader("VCoelho"), 0, rand() % 4 + 1, x, y, idDoPai));
            animais[animais.size() - 1]->setId(totalCoisas++);
        } else if (tipo == "O") {
            animais.push_back(new Ovelha("O", constantesReader("SOvelha"), constantesReader("VOvelha"), 0, rand() % 5 + 4, x, y, idDoPai));
            animais[animais.size() - 1]->setId(totalCoisas++);
        } else if (tipo == "L") {
            animais.push_back(new Lobo("L", constantesReader("SLobo"), constantesReader("VLobo"), 0, 15, x, y, idDoPai));
            animais[animais.size() - 1]->setId(totalCoisas++);
        } else if (tipo == "G") {
            animais.push_back(new Canguru("C", constantesReader("SCanguru"), constantesReader("VCanguru"), 0, 10, x, y, idDoPai++));
            animais[animais.size() - 1]->setId(totalCoisas++);
        } else if (tipo == "M") {
            animais.push_back(new AnimalMisterioso("M", constantesReader("SAnimalM"), constantesReader("VAnimalM"), 0, rand() % 9 + 2, x, y, idDoPai));
            animais[animais.size() - 1]->setId(totalCoisas++);
        }
    }
}

void Reserva::criaAnimalRandom(const string &tipo)
{
    int lRandom = rand() % linhas + 1;
    int cRandom = rand() % colunas + 1;
    if (tipo != "C" && tipo != "O" && tipo != "L" && tipo != "G" && tipo != "M") {
        cout << "\nPor favor insira um animal valido!" << endl;
    } else {
        if (tipo == "C") {
            animais.push_back(new Coelho("C", constantesReader("SCoelho"), constantesReader("VCoelho"), 0, rand() % 4 + 1, lRandom, cRandom, idDoPai));
            animais[animais.size() - 1]->setId(totalCoisas++);
        } else if (tipo == "O") {
            animais.push_back(new Ovelha("O", constantesReader("SOvelha"), constantesReader("VOvelha"), 0, rand() % 5 + 4, lRandom, cRandom, idDoPai)); //rand() % 5 + 4; numero entre 4 e 8 --
            animais[animais.size() - 1]->setId(totalCoisas++);
        } else if (tipo == "L") {
            animais.push_back(new Lobo("L", constantesReader("SLobo"), constantesReader("VLobo"), 0, 15, lRandom, cRandom, idDoPai));
            animais[animais.size() - 1]->setId(totalCoisas++);
        } else if (tipo == "G") {
            animais.push_back(new Canguru("G", constantesReader("SCanguru"), constantesReader("VCanguru"), 0, 10, lRandom, cRandom, idDoPai++));
            animais[animais.size() - 1]->setId(totalCoisas++);
        } else if (tipo == "M") {
            animais.push_back(new AnimalMisterioso("M", constantesReader("SAnimalM"), constantesReader("VAnimalM"), 0, rand() % 9 + 2, lRandom, cRandom, idDoPai));
            animais[animais.size() - 1]->setId(totalCoisas++);
        }
    }
}

vector<Animais *> Reserva::getVecAnimal() const
{
    return animais;
}

int Reserva::getNumberOfAnimals() const
{
    return animais.size();
}

//string Reserva::getInfoAnimalId(int id) const {
//
//    ostringstream oss;
//    for(int i = 0; i < animais.size(); i++){
//
//        oss << animais[i]->getId();
//    }
//
//    return oss.str();
//}



/*ALIMENTO*/
void Reserva::criaAlimento(const string &tipo, const int &x, const int &y)
{
    if (tipo != "R" && tipo != "T" && tipo != "B" && tipo != "A") {
        cout << "\nPor favor insira um alimento valido!" << endl;
    } else {
        if (tipo == "R") {
            alimentos.push_back(new Relva("r", 20, 3, 0, x, y));
            alimentos[alimentos.size() - 1]->setId(totalCoisas++);
        } else if (tipo == "T") {
            alimentos.push_back(new Cenoura("t", 9999, 4, 0, x, y));
            alimentos[alimentos.size() - 1]->setId(totalCoisas++);
        } else if (tipo == "B") {
            alimentos.push_back(new Bife("b", 30, 10, 2, x, y));
            alimentos[alimentos.size() - 1]->setId(totalCoisas++);
        } else if (tipo == "A") {
            alimentos.push_back(new AlimentoMisterioso("a", 15, 5, 0, x, y));
            alimentos[alimentos.size() - 1]->setId(totalCoisas++);
        }
    }

}

void Reserva::criaAlimentoRandom(const string &tipo)
{
    int lRandom = rand() % linhas + 1;
    int cRandom = rand() % colunas + 1;
    if (tipo != "R" && tipo != "T" && tipo != "B" && tipo != "A") {
        cout << "\nPor favor insira um alimento valido!" << endl;
    } else {
        if (tipo == "R") {                    //tipo va vn tx cheiro id x y
            alimentos.push_back(new Relva("r", 20, 3, 0, lRandom, cRandom));
            alimentos[alimentos.size() - 1]->setId(totalCoisas++);

        } else if (tipo == "T") {
            alimentos.push_back(new Cenoura("t", 9999, 4, 0, lRandom, cRandom));
            alimentos[alimentos.size() - 1]->setId(totalCoisas++);

        } else if (tipo == "B") {
            alimentos.push_back(new Bife("b", 30, 10, 2, lRandom, cRandom));
            alimentos[alimentos.size() - 1]->setId(totalCoisas++);

        } else if (tipo == "Z") {
            alimentos.push_back(new AlimentoMisterioso("a", 15, 5, 0, lRandom, cRandom));
            alimentos[alimentos.size() - 1]->setId(totalCoisas++);

        }
    }
}

void Reserva::removeAnimalbyId(const int &id)
{
    auto it = animais.begin();

    while (it != animais.end()) {
        if ((*it)->getId() == id) {
            delete *it;
            it = animais.erase(it);
        } else {
            it++;
        }
    }
}

void Reserva::removeAnimalbyCoord(const int &x, const int &y)
{
    auto it = animais.begin();

    while (it != animais.end()) {
        if ((*it)->getX() == x && (*it)->getY() == y) {
            delete *it;
            it = animais.erase(it);
        } else {
            it++;
        }
    }
}

void Reserva::removeAlimentobyCoord(const int &x, const int &y)
{
    auto it = alimentos.begin();

    while (it != alimentos.end()) {
        if ((*it)->getX() == x && (*it)->getY() == y) {
            delete *it;
            it = alimentos.erase(it);
        } else {
            it++;
        }
    }
}

void Reserva::removeAlimentobyId(const int &id)
{
    auto it = alimentos.begin();

    while (it != alimentos.end()) {
        if ((*it)->getId() == id) {
            delete *it;
            it = alimentos.erase(it);
        } else {
            it++;
        }
    }
}

void Reserva::feedAnimalById(const int &id, const int &valorNutritivo, const int &toxicidade)
{

    for (auto it = animais.begin(); it != animais.end(); it++) {
        if ((*it)->getId() == id) {
            int total = (*it)->getSaude() + valorNutritivo - toxicidade;
            (*it)->setSaude(total);
        }
    }
}

void Reserva::feedAnimalbyCoord(const int &x, const int &y, const int &valorNutritivo, const int &toxicidade)
{

    for (auto it = animais.begin(); it != animais.end(); it++) {
        if ((*it)->getX() == x && (*it)->getY() == y) {
            int total = (*it)->getSaude() + valorNutritivo - toxicidade;
            (*it)->setSaude(total);
        }
    }
}

int Reserva::getNumberOfFood() const
{
    return alimentos.size();
}

vector<Alimentos *> Reserva::getVecAlimento() const
{
    return alimentos;
}


bool Reserva::hasAlimento(int x, int y)
{
    for (int i = 0; i < alimentos.size(); i++) {
        if (alimentos[i]->getX() == x && alimentos[i]->getY() == y) {
            return true;
        }
    }
    return false;
}


/*PEGAR NISSO DEPOIS*/


void Reserva::interacaoAnimal()
{
    bool pesoPerigoso = false;
    bool achouComida = false;
    int engravida = 0;

    Animais *an;
    //Alimentos *al;

    for (int i = 0; i < animais.size(); i++) {

       if (animais[i]->getTipoAnimal() == "C") { // ANIMAL C COELHO

            if (animais[i]->getvAnimal() != 0) { //Se a vida for diferente de 0, ele faz toda a logica do animal

                animais[i]->setVida(animais[i]->getvAnimal() - 1); //A cada instante diminui um do vAnimal
                animais[i]->setFome(animais[i]->getFome() + 1);// A cada instante aumenta a fome do animal

                if (animais[i]->getvAnimal() == constantesReader("VCoelho") - 8) { // se passaram 8 instantes

                    engravida = rand() % 2 + 1;

                    if (engravida == 1) { //engravidou com sucesso

                        pair<int,int> cf = createFilho(animais[i]->getX(), animais[i]->getY(), rand() % 8, rand() % 10 + 1); //apanha as coordenadas para o filho
                        animais.push_back(new Coelho(animais[i]->getTipoAnimal(), constantesReader("SCoelho"), constantesReader("VCoelho"), 0, rand() % 4 + 1, cf.first, cf.second, 0));

                        animais[animais.size() - 1]->setId(totalCoisas++);
                    }

                } // passaram 8 instantes

                an = verificaAnimalRedondeza(animais[i]->getId(), animais[i]->getX(), animais[i]->getY(), 4); // Return true - se tiver | Return false - se não tiver
                pesoPerigoso = checkPeso(animais[i]->getId(), animais[i]->getX(), animais[i]->getY(), 4, 10); // Return true - se tiver algum peso perigoso | Return false - se não tiver nenhum
                achouComida = checkComida(animais[i]->getX(), animais[i]->getY(), 4, "verdura"); // Return true - se tiver algum alimento na redondeza com o cheiro tal | Retruns false se nao tiver

                if (an != nullptr && pesoPerigoso) {  // Return true para ambos - faz Movimentação com animal na redondeza

                    pair<int,
                         int> cordPredador = pegaCoordAni(animais[i]->getId(), animais[i]->getX(), animais[i]->getY(), 4, 10);

                    if (animais[i]->getFome() >= 10) { // se a fome for maior ou igual a 10, ele faz a logica do if
                        animais[i]->setSaude(animais[i]->getSaude() - 1);
                    } else if (animais[i]->getFome() >= 20) { // se a fome for maior ou igual a 20, ele faz a logica do else if
                        animais[i]->setSaude(animais[i]->getSaude() - 2);
                    }
                    animais[i]->fazMovimentacaoComAnimalFoge(cordPredador.first, cordPredador.second); //se move na direcao oposta

                    if (verificaSeEstaFora(animais[i]->getX(), animais[i]->getY(), getLinhas(), getColunas())) {
                        animais[i]->fazDarVolta(animais[i]->getX(), animais[i]->getY(), getLinhas(), getColunas());
                    }

                } else if (achouComida && an != nullptr || an == nullptr && !pesoPerigoso) {

                    pair<int,
                         int> ca = pegaCoordAl(animais[i]->getX(), animais[i]->getY(), 4, "verdura"); // retira coordenadas do alimento com cheiro tal
                    pair<int,
                         int> va = pegaValoresAl(animais[i]->getX(), animais[i]->getY(), 4, "verdura"); // retira valores (nutri e toxi) do alimento com cheiro tal
                    animais[i]->fazMovimentacaoComer(ca.first, ca.second, va.first, va.second);

                    if (verificaSeEstaFora(animais[i]->getX(), animais[i]->getY(), getLinhas(), getColunas())) { //verifica se o animal atual está prestes a sair da reserva
                        animais[i]->fazDarVolta(animais[i]->getX(), animais[i]->getY(), getLinhas(), getColunas());
                    }

                    if (animais[i]->getX() == ca.first || animais[i]->getY() == ca.second) {
                        removeAlimentobyCoord(ca.first, ca.second);
                    }


                } else if (an == nullptr || an != nullptr && !achouComida && !pesoPerigoso) {  // Return false - faz Movimentação sem animal na redondeza


                    if (animais[i]->getFome() >= 10) { // se a fome for maior ou igual a 10, ele faz a logica do if

                        animais[i]->setSaude(animais[i]->getSaude() - 1);
                        animais[i]->fazMovimentacaoSemAnimal_I_F(1, 3);

                        if (verificaSeEstaFora(animais[i]->getX(), animais[i]->getY(), getLinhas(), getColunas())) {
                            animais[i]->fazDarVolta(animais[i]->getX(), animais[i]->getY(), getLinhas(), getColunas());
                        }

                    } else if (animais[i]->getFome() >= 20) { // se a fome for maior ou igual a 20, ele faz a logica do else if

                        animais[i]->setSaude(animais[i]->getSaude() - 2);
                        animais[i]->fazMovimentacaoSemAnimal_I_F(1, 4);

                        if (verificaSeEstaFora(animais[i]->getX(), animais[i]->getY(), getLinhas(), getColunas())) {
                            animais[i]->fazDarVolta(animais[i]->getX(), animais[i]->getY(), getLinhas(), getColunas());
                        }

                    } else { // se a fome for menor que 10, ele faz a logica do else

                        animais[i]->fazMovimentacaoSemAnimal_I_F(1, 2); //faz movimentação inicio fim

                        if (verificaSeEstaFora(animais[i]->getX(), animais[i]->getY(), getLinhas(), getColunas())) {
                            animais[i]->fazDarVolta(animais[i]->getX(), animais[i]->getY(), getLinhas(), getColunas());
                        }
                    }
                }
            } else { // se vAnimal for = 0, ele morre e é eliminado do vetor

                removeAnimalbyId(animais[i]->getId());
            }

        } else if (animais[i]->getTipoAnimal() == "O") {

            if (animais[i]->getvAnimal() != 0) {

                animais[i]->setVida(animais[i]->getvAnimal() - 1);
                animais[i]->setFome(animais[i]->getFome() + 1);

                if (animais[i]->getvAnimal() == constantesReader("VOvelha") - 15){ // após 15 instantes

                    pair<int,int> cf = createFilho(animais[i]->getX(), animais[i]->getY(), rand() % 8, rand() % 12 + 1);

                    animais.push_back(new Ovelha(animais[i]->getTipoAnimal(), animais[i]->getSaude(), constantesReader("VOvelha"), 0, rand() % 5 + 4, cf.first, cf.second, 0));
                    animais[animais.size() - 1]->setId(totalCoisas++);

                }

                an = verificaAnimalRedondeza(animais[i]->getId(), animais[i]->getX(), animais[i]->getY(), 3);
                pesoPerigoso = checkPeso(animais[i]->getId(), animais[i]->getX(), animais[i]->getY(), 3, 15); // Return true - se tiver algum peso perigoso | Return false - se não tiver nenhum
                achouComida = checkComida(animais[i]->getX(), animais[i]->getY(), 3, "erva");

                if (an != nullptr && pesoPerigoso) {   // Return true - faz Movimentação com animal na redondeza


                    pair<int,
                         int> cordPredador = pegaCoordAni(animais[i]->getId(), animais[i]->getX(), animais[i]->getY(), 4, 10);

                    if (animais[i]->getFome() >= 15) { // se a fome for maior ou igual a 10, ele faz a logica do if
                        animais[i]->setSaude(animais[i]->getSaude() - 1);
                    } else if (animais[i]->getFome() >= 20) { // se a fome for maior ou igual a 20, ele faz a logica do else if
                        animais[i]->setSaude(animais[i]->getSaude() - 2);
                    }
                    animais[i]->fazMovimentacaoComAnimalFoge(cordPredador.first, cordPredador.second); //se move na direcao oposta

                    if (verificaSeEstaFora(animais[i]->getX(), animais[i]->getY(), getLinhas(), getColunas())) {
                        animais[i]->fazDarVolta(animais[i]->getX(), animais[i]->getY(), getLinhas(), getColunas());
                    }


                } else if (achouComida && an != nullptr || an == nullptr && !pesoPerigoso) {

                    pair<int,int> ca = pegaCoordAl(animais[i]->getX(), animais[i]->getY(), 4, "erva"); // retira coordenadas do alimento com cheiro tal
                    pair<int,int> va = pegaValoresAl(animais[i]->getX(), animais[i]->getY(), 4, "erva"); // retira valores (nutri e toxi) do alimento com cheiro tal
                    animais[i]->fazMovimentacaoComer(ca.first, ca.second, va.first, va.second);

                    if (verificaSeEstaFora(animais[i]->getX(), animais[i]->getY(), getLinhas(), getColunas())) { //verifica se o animal atual está prestes a sair da reserva
                        animais[i]->fazDarVolta(animais[i]->getX(), animais[i]->getY(), getLinhas(), getColunas());
                    }

                    if (animais[i]->getX() == ca.first || animais[i]->getY() == ca.second) {
                        removeAlimentobyCoord(ca.first, ca.second);
                    }

                } else if (!achouComida && an != nullptr || an == nullptr && !pesoPerigoso) {  // Return false - faz Movimentação sem animal na redondeza


                    if (animais[i]->getFome() >= 15) { // se a fome for maior ou igual a 10, ele faz a logica do if

                        animais[i]->setSaude(animais[i]->getSaude() - 1);
                        animais[i]->fazMovimentacaoSemAnimal_I_F(1, 2);

                        if (verificaSeEstaFora(animais[i]->getX(), animais[i]->getY(), getLinhas(), getColunas())) {
                            animais[i]->fazDarVolta(animais[i]->getX(), animais[i]->getY(), getLinhas(), getColunas());
                        }

                    } else if (animais[i]->getFome() >= 20) { // se a fome for maior ou igual a 20, ele faz a logica do else if

                        animais[i]->setSaude(animais[i]->getSaude() - 2);
                        animais[i]->fazMovimentacaoSemAnimal_I_F(1, 2);

                        if (verificaSeEstaFora(animais[i]->getX(), animais[i]->getY(), getLinhas(), getColunas())) {
                            animais[i]->fazDarVolta(animais[i]->getX(), animais[i]->getY(), getLinhas(), getColunas());
                        }

                    } else { // se a fome for menor que 10, ele faz a logica do else

                        animais[i]->fazMovimentacaoSemAnimal_P(1);

                        if (verificaSeEstaFora(animais[i]->getX(), animais[i]->getY(), getLinhas(), getColunas())) {
                            animais[i]->fazDarVolta(animais[i]->getX(), animais[i]->getY(), getLinhas(), getColunas());
                        }
                    }
                }
            } else {

                pair<int,
                     int> cc = createCorpo(animais[i]->getX(), animais[i]->getY(), rand() % 8); // pegas as coordenadas para criar o corpo

                alimentos.push_back(new Corpo("Corpo", 9999, 10, 0, cc.first, cc.second));
                alimentos[alimentos.size() - 1]->setId(totalCoisas++);
                removeAnimalbyId(animais[i]->getId());
            }


        } else if (animais[i]->getTipoAnimal() == "L") {

            if (animais[i]->getSaude() != 0) {

                animais[i]->setFome(animais[i]->getFome() + 2);

                int nascer = rand() % constantesReader("VLobo") + 5; // gera um número aleatório entre 5 e vAnimal
                bool teveFilho = false;

                if (numInstantes == nascer && !teveFilho) {

                    pair<int,
                         int> cf = createFilho(animais[i]->getX(), animais[i]->getY(), rand() % 8, rand() % 15 + 1);

                    animais.push_back(new Lobo(animais[i]->getTipoAnimal(), constantesReader("SLobo"), constantesReader("VLobo"), 0, 15, cf.first, cf.second, animais[i]->getId()));
                    animais[animais.size() - 1]->setId(totalCoisas++);
                    teveFilho = true;
                }

                an = verificaAnimalRedondeza(animais[i]->getId(), animais[i]->getX(), animais[i]->getY(), 5);
                achouComida = checkComida(animais[i]->getX(), animais[i]->getY(), 5, "carne");

                if (an != nullptr) { // Return true - faz Movimentação com animal na redondeza


                    pair<int,
                         int> coordHunt = pegaCoordCaca(animais[i]->getId(), animais[i]->getX(), animais[i]->getY(), 5); //apanha a coordenada do animal mais pesado

                    if (animais[i]->getFome() >= 15) { // se a fome for maior que 15, ele perde um ponto de saude e caça o animal avançando 3 casa
                        animais[i]->setSaude(animais[i]->getSaude() - 1);
                        animais[i]->fazMovimentacaoComAnimalCaca(coordHunt.first, coordHunt.second, 3);

                        if (verificaSeEstaFora(animais[i]->getX(), animais[i]->getY(), getLinhas(), getColunas())) { //verifica se o animal atual está prestes a sair da reserva
                            animais[i]->fazDarVolta(animais[i]->getX(), animais[i]->getY(), getLinhas(), getColunas());
                        }

                    } else if (animais[i]->getFome() >= 25) { // se a fome for maior que 15, ele perde um ponto de saude e caça o animal avançando 3 casa
                        animais[i]->setSaude(animais[i]->getSaude() - 2);
                        animais[i]->fazMovimentacaoComAnimalCaca(coordHunt.first, coordHunt.second, 3);

                        if (verificaSeEstaFora(animais[i]->getX(), animais[i]->getY(), getLinhas(), getColunas())) { //verifica se o animal atual está prestes a sair da reserva
                            animais[i]->fazDarVolta(animais[i]->getX(), animais[i]->getY(), getLinhas(), getColunas());
                        }
                    }

                    animais[i]->fazMovimentacaoComAnimalCaca(coordHunt.first, coordHunt.second, 2); //vai a caca do animal quando n tem muita fome

                    if (verificaSeEstaFora(animais[i]->getX(), animais[i]->getY(), getLinhas(), getColunas())) { //verifica se o animal atual está prestes a sair da reserva
                        animais[i]->fazDarVolta(animais[i]->getX(), animais[i]->getY(), getLinhas(), getColunas());
                    }

                    if (animais[i]->getX() == coordHunt.first || animais[i]->getY() == coordHunt.second) { //se estiver nas coordenadas do animal que esta caçando

                        int pesoAnimalCaca = pegaPesoAnimalCacado(animais[i]->getId(), animais[i]->getX(), animais[i]->getY(), 5); //apanha o peso do anima caçado

                        if (animais[i]->getPeso() > pesoAnimalCaca) { // se o peso do lobo for maior que o peso do animal caçado, ele mata o animal caçado e se cria um corpo nas coordenadas a sua volta
                            pair<int, int> cc = createCorpo(animais[i]->getX(), animais[i]->getY(), rand() % 8);

                            alimentos.push_back(new Corpo("Corpo", 9999, 10, 0, cc.first, cc.second));
                            alimentos[alimentos.size() - 1]->setId(totalCoisas++);

                            removeAnimalbyCoord(coordHunt.first, coordHunt.second);

                        } else if (animais[i]->getPeso() < pesoAnimalCaca) { // se o peso do animal for maior que o do lobo, ele tira na sorte 50% para cada para ver quem vai morrer
                            int whoDies = rand() % 2 + 1;

                            if (whoDies == 1) { // se tirar um, morre o lobo

                                pair<int, int> cc = createCorpo(animais[i]->getX(), animais[i]->getY(), rand() % 8);

                                alimentos.push_back(new Corpo("Corpo", 9999, 10, 0, cc.first, cc.second));
                                alimentos[alimentos.size() - 1]->setId(totalCoisas++);

                                removeAnimalbyCoord(animais[i]->getX(), animais[i]->getY());
                            } else if (whoDies == 2) { // se tirar 2 morre o animal caçado

                                pair<int, int> cc = createCorpo(animais[i]->getX(), animais[i]->getY(), rand() % 8);

                                alimentos.push_back(new Corpo("Corpo", 9999, 10, 0, cc.first, cc.second));
                                alimentos[alimentos.size() - 1]->setId(totalCoisas++);

                                removeAnimalbyCoord(coordHunt.first, coordHunt.second);
                            }
                        }

                    }

                } else if (achouComida && an == nullptr) {
                    pair<int,
                         int> ca = pegaCoordAl(animais[i]->getX(), animais[i]->getY(), 5, "carne"); // retira coordenadas do alimento com cheiro tal
                    pair<int,
                         int> va = pegaValoresAl(animais[i]->getX(), animais[i]->getY(), 5, "carne"); // retira valores (nutri e toxi) do alimento com cheiro tal
                    animais[i]->fazMovimentacaoComer(ca.first, ca.second, va.first, va.second);

                    if (verificaSeEstaFora(animais[i]->getX(), animais[i]->getY(), getLinhas(), getColunas())) { //verifica se o animal atual está prestes a sair da reserva
                        animais[i]->fazDarVolta(animais[i]->getX(), animais[i]->getY(), getLinhas(), getColunas());
                    }

                    if (animais[i]->getX() == ca.first || animais[i]->getY() == ca.second) {

                        removeAlimentobyCoord(ca.first, ca.second);
                    }
                } else if (an == nullptr && !achouComida) {  // Return false - faz Movimentação sem animal na redondeza


                    if (animais[i]->getFome() >= 15) {

                        animais[i]->setSaude(animais[i]->getSaude() - 1);
                        animais[i]->fazMovimentacaoSemAnimal_P(2);

                        if (verificaSeEstaFora(animais[i]->getX(), animais[i]->getY(), getLinhas(), getColunas())) {
                            animais[i]->fazDarVolta(animais[i]->getX(), animais[i]->getY(), getLinhas(), getColunas());
                        }

                    } else if (animais[i]->getFome() >= 25) {

                        animais[i]->setSaude(animais[i]->getSaude() - 2);
                        animais[i]->fazMovimentacaoSemAnimal_P(2);

                        if (verificaSeEstaFora(animais[i]->getX(), animais[i]->getY(), getLinhas(), getColunas())) {
                            animais[i]->fazDarVolta(animais[i]->getX(), animais[i]->getY(), getLinhas(), getColunas());
                        }

                    } else {
                        animais[i]->fazMovimentacaoSemAnimal_P(1);

                        if (verificaSeEstaFora(animais[i]->getX(), animais[i]->getY(), getLinhas(), getColunas())) {
                            animais[i]->fazDarVolta(animais[i]->getX(), animais[i]->getY(), getLinhas(), getColunas());
                        }
                    }

                }
            } else {

                //Quando morre faz nascer corpo ao seu lado

                pair<int, int> cc = createCorpo(animais[i]->getX(), animais[i]->getY(), rand() % 8);


                alimentos.push_back(new Corpo("Corpo", 9999, 10, 0, cc.first, cc.second));
                alimentos[alimentos.size() - 1]->setId(totalCoisas++);

                removeAnimalbyId(animais[i]->getId());
            }
        } else if (animais[i]->getTipoAnimal() == "G") {

           if (animais[i]->getvAnimal() != 0) {

               animais[i]->setVida(animais[i]->getvAnimal() - 1);

               if (animais[i]->getvAnimal() == constantesReader("VCanguru") - 20) { // apos 20 instantes, set ao peso a 20
                   animais[i]->setPeso(20);
               }

               if (animais[i]->getvAnimal() == constantesReader("VCanguru") - 30) { // apos 30 instantes cria uma novo canguru entre 1 ou 3 casas de distancia

                   pair<int, int> cc = createFilho(animais[i]->getX(), animais[i]->getY(), rand() % 8, rand() % 3 + 1);

                   animais.push_back(new Canguru(animais[i]->getTipoAnimal(), constantesReader("SCanguru"), constantesReader("VCanguru"), 0, 10, cc.first, cc.second, animais[i]->getId()));
                   animais[animais.size() - 1]->setId(totalCoisas++);

               }

               an = verificaAnimalRedondeza(animais[i]->getId(), animais[i]->getX(), animais[i]->getY(), 7);
               bool verificaAlemPai = false;
               verificaAlemPai = verificaAnimalRedondezaAlemPai(animais[i]->getId(), animais[i]->getIdPai(), animais[i]->getX(),animais[i]->getY(), 7);

               if (an != nullptr && verificaAlemPai) {   // Return true - faz Movimentação com animal na redondeza

                    pair<int, int> coordPai = pegaCoordPai(animais[i]->getId(), animais[i]->getIdPai(), animais[i]->getX(),animais[i]->getY(), 7);

                    animais[i]->fazMovimentacaoAtePai(coordPai.first, coordPai.second, 1, 3, 2);  //faz move até o pai com duas casas

                   if (verificaSeEstaFora(animais[i]->getX(), animais[i]->getY(), getLinhas(), getColunas())) {
                       animais[i]->fazDarVolta(animais[i]->getX(), animais[i]->getY(), getLinhas(), getColunas());
                   }

               } else if (animais[i]->getvAnimal() > constantesReader("VCanguru") - 10) { //primeiros 10 instantes da vida dele

                   pair<int, int> coordPai = pegaCoordPai(animais[i]->getId(), animais[i]->getIdPai(), animais[i]->getX(),animais[i]->getY(), 7);

                   animais[i]->fazMovimentacaoAtePai(coordPai.first, coordPai.second, 1, 3, 1);  //faz move até o pai com duas casas

                   if (verificaSeEstaFora(animais[i]->getX(), animais[i]->getY(), getLinhas(), getColunas())) {
                       animais[i]->fazDarVolta(animais[i]->getX(), animais[i]->getY(), getLinhas(), getColunas());
                   }

               } else if(animais[i]->getvAnimal() < constantesReader("VCanguru") -10 ){  // Return false - faz Movimentação sem animal na redondeza


                   animais[i]->fazMovimentacaoSemAnimal_P(1);

                   if (verificaSeEstaFora(animais[i]->getX(), animais[i]->getY(), getLinhas(), getColunas())) {
                       animais[i]->fazDarVolta(animais[i]->getX(), animais[i]->getY(), getLinhas(), getColunas());
                   }

               }
           } else {

               pair<int, int> cc = createCorpo(animais[i]->getX(), animais[i]->getY(), rand() % 8);

               alimentos.push_back(new Corpo("Corpo", 9999, 15, 5, cc.first, cc.second));
               alimentos[alimentos.size() - 1]->setId(totalCoisas++);

               removeAnimalbyId(animais[i]->getId());

           }
       } else if (animais[i]->getTipoAnimal() == "M") {

            if (animais[i]->getvAnimal() != 0) {

                animais[i]->setVida(animais[i]->getvAnimal() - 1);
                animais[i]->setFome(animais[i]->getFome() + 1);


                an = verificaAnimalRedondeza(animais[i]->getId(), animais[i]->getX(), animais[i]->getY(), 9);
                pesoPerigoso = checkPeso(animais[i]->getId(), animais[i]->getX(), animais[i]->getY(), 9, 15);
                achouComida = checkComida(animais[i]->getX(), animais[i]->getY(), 9, "fruta");

                if (an != nullptr && pesoPerigoso) {   // Return true - faz Movimentação com animal na redondeza

                    pair<int,int> cordPredador = pegaCoordAni(animais[i]->getId(), animais[i]->getX(), animais[i]->getY(), 4, 15); //foge do lobo apenas

                    animais[i]->fazMovimentacaoComAnimalFoge(cordPredador.first, cordPredador.second); //se move na direcao oposta

                    if (verificaSeEstaFora(animais[i]->getX(), animais[i]->getY(), getLinhas(), getColunas())) {
                        animais[i]->fazDarVolta(animais[i]->getX(), animais[i]->getY(), getLinhas(), getColunas());
                    }

                } else if (achouComida && an == nullptr || an != nullptr && !pesoPerigoso) {

                    pair<int,int> ca = pegaCoordAl(animais[i]->getX(), animais[i]->getY(), 9, "fruta"); // retira coordenadas do alimento com cheiro tal
                    pair<int,int> va = pegaValoresAl(animais[i]->getX(), animais[i]->getY(), 9, "fruta"); // retira valores (nutri e toxi) do alimento com cheiro tal

                    animais[i]->fazMovimentacaoComer(ca.first, ca.second, va.first, va.second);

                    if (verificaSeEstaFora(animais[i]->getX(), animais[i]->getY(), getLinhas(), getColunas())) { //verifica se o animal atual está prestes a sair da reserva
                        animais[i]->fazDarVolta(animais[i]->getX(), animais[i]->getY(), getLinhas(), getColunas());
                    }

                    if (animais[i]->getX() == ca.first || animais[i]->getY() == ca.second) {
                        removeAlimentobyCoord(ca.first, ca.second);
                    }

                } else if (an == nullptr || an != nullptr && !achouComida && !pesoPerigoso) {  // Return false - faz Movimentação sem animal na redondeza
                    animais[i]->fazMovimentacaoSemAnimal_I_F(2, 7);

                    if (verificaSeEstaFora(animais[i]->getX(), animais[i]->getY(), getLinhas(), getColunas())) { //verifica se o animal atual está prestes a sair da reserva
                        animais[i]->fazDarVolta(animais[i]->getX(), animais[i]->getY(), getLinhas(), getColunas());
                    }
                }
            } else {
                pair<int, int> cc = createCorpo(animais[i]->getX(), animais[i]->getY(), rand() % 8);

                alimentos.push_back(new Corpo("Corpo", 9999, 15, 5, cc.first, cc.second));
                alimentos[alimentos.size() - 1]->setId(totalCoisas++);

                removeAnimalbyId(animais[i]->getId());
            }
        }
    }
}

bool Reserva::checkPeso(const int &id, const int &x, const int &y, const int &valorRedondeza, const int &peso)
{
    for (auto &animal : animais) {

        // Verifica se o animal atual é o mesmo que o animal de referência

        if (animal->getId() == id) {
            continue; // Pula o animal atual e continua iterando pelos demais
        }

        // Verifica se o animal atual está nas redondezas do animal referência

        if (animal->getX() < x + valorRedondeza && animal->getX() > x - valorRedondeza && animal->getY() < y + valorRedondeza && animal->getY() > y - valorRedondeza) {
            if (animal->getPeso() >= peso) {
                return true; // Encontrou um animal com peso perigoso nas redondezas
            }
        }
    }
    return false; // Não encontrou nenhum animal com peso perigoso nas redondezas
}

bool Reserva::checkComida(int x, int y, int valorRedondeza, string comida)
{
    for (auto &alimento : alimentos) {

        if (alimento->getCheiro().size() == 2) {
            if (alimento->getCheiro()[0] == comida || alimento->getCheiro()[1] == comida) {
                if (alimento->getX() < x + valorRedondeza && alimento->getX() > x - valorRedondeza && alimento->getY() < y + valorRedondeza && alimento->getY() > y - valorRedondeza) {

                    return true;
                }
            }
        } else if (alimento->getCheiro().size() == 1) {
            if (alimento->getCheiro()[0] == comida) {
                if (alimento->getX() < x + valorRedondeza && alimento->getX() > x - valorRedondeza && alimento->getY() < y + valorRedondeza && alimento->getY() > y - valorRedondeza) {

                    return true;
                }
            }
        }

    }

    return false;
}

Animais *Reserva::verificaAnimalRedondeza(const int &id, const int &x, const int &y, const int &valorRedondeza)
{
    for (auto &animal : animais) {

        // Verifica se o animal atual é o mesmo que o animal de referência

        if (animal->getId() == id) {
            continue; // Pula o animal atual e continua iterando pelos demais
        }

        // Verifica se o animal atual está nas redondezas do animal referência

        if (animal->getX() < x + valorRedondeza && animal->getX() > x - valorRedondeza && animal->getY() < y + valorRedondeza && animal->getY() > y - valorRedondeza) {
            return animal; // Encontrou um animal nas redondezas
        }
    }
    return nullptr; // Não encontrou nenhum animal nas redondezas
}

bool Reserva::verificaAlimentoRedondeza(const int &id, const int &x, const int &y, const int &valorRedondeza)
{
    for (auto &alimento : alimentos) {
        if (alimento->getId() == id) {
            continue;
        }

        if (alimento->getX() < x + valorRedondeza && alimento->getX() > x - valorRedondeza && alimento->getY() < y + valorRedondeza && alimento->getY() > y - valorRedondeza) {
            return true;
        }
    }
    return false;
}

void Reserva::interacaoAlimento()
{

    bool alimentoRedondeza = false;
    int vNutriInicial = 0;
    int vAlimentoInicial = 0;
    int vToxicidadeInicial = 0;
    bool flag = false;

    for (int i = 0; i < alimentos.size(); i++) { //Percorre os alimentos da reserva

        if (alimentos[i]->getTipoAlimento() == "r") {// Verifica se o tipo é r(relva)

            vNutriInicial = 3;
            vAlimentoInicial = 20;
            vToxicidadeInicial = 0;

            if (alimentos[i]->getValimento() != 0) {// se o alimento ainda tiver vAlimento, faz a logica

                alimentos[i]->setValimento(alimentos[i]->getValimento() - 1); // a cada instante diminui um do vAlimento

                // se o alimento está com saude: 5 então o vAlimentoInicial * 0,75 é 15
                if (alimentos[i]->getValimento() + vAlimentoInicial * 0.75 == vAlimentoInicial) {

                    alimentoRedondeza = verificaAlimentoRedondeza(alimentos[i]->getId(), alimentos[i]->getX(), alimentos[i]->getY(), rand() % 5 + 4);

                    if (!alimentoRedondeza) { // se não tiver um alimento nas redondezas, então vai criar uma nova relva num sitio random
                        alimentos.push_back(new Relva(alimentos[i]->getTipoAlimento(), vAlimentoInicial, vNutriInicial, vToxicidadeInicial, rand() % 5 + 4, rand() % 5 + 4));
                        alimentos[alimentos.size() - 1]->setId(totalCoisas++);
                    }
                }

            } else { // caso o vAlimento for 0, ele remove o alimento do vetor

                removeAlimentobyId(alimentos[i]->getId());
            }

        } else if (alimentos[i]->getTipoAlimento() == "t") { // Verifica se o tipo é t

            if (alimentos[i]->getValimento() != 0) {

                if (numInstantes % 10 == 0 && alimentos[i]->getToxicidade() < 3) {// a cada 10 instantes, aumenta um valor de toxicidade até dar stack em 3

                    alimentos[i]->setToxicidade(alimentos[i]->getToxicidade() + 1);
                }

            }

        } else if (alimentos[i]->getTipoAlimento() == "p") { // Verifica se o tipo é p

            vNutriInicial = alimentos[i]->getValorNutri(); // salva o valorNutri para usar como o valorInicial


            alimentos[i]->setValorNutri(alimentos[i]->getValorNutri() - 1); // diminui o valor nutritivo em 1 unidade a cada instante
            alimentos[i]->setToxicidade(alimentos[i]->getToxicidade() + 1); // aumenta o valor de toxicidade em 1 unidade em cada instante

            if (numInstantes > 2 * vNutriInicial) { // se passaram tantos instantes como duas vezes o valor nutritivo inicial

                alimentos[i]->setToxicidade(alimentos[i]->getToxicidade() - 1); // para de aumentar o valor de toxicidade
            }

        } else if (alimentos[i]->getTipoAlimento() == "b") { // Verifica se o tipo é b

            alimentos[i]->setValimento(alimentos[i]->getValimento() - 1); // diminui um do vAlimento a cada instante

            if (alimentos[i]->getValorNutri() > 0) { // diminui o valor nutri a cada instante até chegar a zero

                alimentos[i]->setValorNutri(alimentos[i]->getValorNutri() - 1);
            }

            if (alimentos[i]->getValimento() == 0) { //se o vAlimento for zero, ele remove o alimento do vetor/reserva

                removeAlimentobyId(alimentos[i]->getId());
            }


        } else if (alimentos[i]->getTipoAlimento() == "a") { // Verifica se o tipo é a

            alimentos[i]->setValimento(alimentos[i]->getValimento() - 5); //a banana fica podre rápido, portanto perde 5
            alimentos[i]->setToxicidade(alimentos[i]->getToxicidade() + 2); // a cada instante ganha 2 de toxicidade

            if (alimentos[i]->getValimento() == 0) { //se o vAlimento for zero, ele remove o alimento do vetor/reserva
                removeAlimentobyId(alimentos[i]->getId());
            }

        }
    }
}

void Reserva::incrementaInstante()
{
    numInstantes++;
}

pair<int, int> Reserva::createCorpo(int x, int y, int direcao)
{

    if (direcao == 0) { //Direito
        x += 1;
    } else if (direcao == 1) { // Direita Cima Diagonal
        x += 1;
        y += 1;
    } else if (direcao == 2) { // Cima
        y += 1;
    } else if (direcao == 3) { // esquerda cima diagonal
        x -= 1;
        y += 1;
    } else if (direcao == 4) { // esquerda
        x -= 1;
    } else if (direcao == 5) { // esquerda baixo diagonal
        x -= 1;
        y -= 1;
    } else if (direcao == 6) { // baixo
        y -= 1;
    } else {  // direita baixo diagonal
        x += 1;
        y -= 1;
    }

    return make_pair(x, y);

}

pair<int, int> Reserva::createFilho(int x, int y, int direcao, int distancia)
{
    for (int i = 0; i < distancia; i++) {

        if (direcao == 0) { //Direito
            x += 1;
        } else if (direcao == 1) { // Direita Cima Diagonal
            x += 1;
            y += 1;
        } else if (direcao == 2) { // Cima
            y += 1;
        } else if (direcao == 3) { // esquerda cima diagonal
            x -= 1;
            y += 1;
        } else if (direcao == 4) { // esquerda
            x -= 1;
        } else if (direcao == 5) { // esquerda baixo diagonal
            x -= 1;
            y -= 1;
        } else if (direcao == 6) { // baixo
            y -= 1;
        } else {  // direita baixo diagonal
            x += 1;
            y -= 1;
        }

    }

    return make_pair(x, y);
}

pair<int, int> Reserva::pegaCoordAl(int x, int y, int valorRedondeza, string comida)
{
    for (auto &al : alimentos) {
        if (al->getX() < x + valorRedondeza && al->getX() > x - valorRedondeza && al->getY() < y + valorRedondeza && al->getY() > y - valorRedondeza) {
            if (al->getCheiro().size() == 2) {
                if (al->getCheiro()[0] == comida || al->getCheiro()[1] == comida)
                    return make_pair(al->getX(), al->getY());
            } else if (al->getCheiro().size() == 1) {
                if (al->getCheiro()[0] == comida)
                    return make_pair(al->getX(), al->getY());
            }
        }
    }
    return make_pair(-1, -1);
}

pair<int, int> Reserva::pegaValoresAl(int x, int y, int valorRedondeza, string comida)
{
    for (auto &al : alimentos) {
        if (al->getX() < x + valorRedondeza && al->getX() > x - valorRedondeza && al->getY() < y + valorRedondeza && al->getY() > y - valorRedondeza) {
            if (al->getCheiro().size() == 2) {
                if (al->getCheiro()[0] == comida || al->getCheiro()[1] == comida)
                    return make_pair(al->getValorNutri(), al->getToxicidade());
            } else if (al->getCheiro().size() == 1) {
                if (al->getCheiro()[0] == comida)
                    return make_pair(al->getValorNutri(), al->getToxicidade());
            }
        }
    }
    return make_pair(-1, -1);
}

pair<int, int> Reserva::pegaCoordAni(int id, int x, int y, int valorRedondeza, int peso)
{
    for (auto &ani : animais) {

        if (ani->getId() == id) {
            continue;
        }

        if (ani->getX() < x + valorRedondeza && ani->getX() > x - valorRedondeza && ani->getY() < y + valorRedondeza && ani->getY() > y - valorRedondeza) {
            if (ani->getPeso() >= peso) {
                return make_pair(ani->getX(), ani->getY());
            }
        }
    }
    return make_pair(-1, -1);
}

pair<int, int> Reserva::pegaCoordCaca(int id, int x, int y, int valorRedondeza)
{

    int maiorPeso = 0;
    int xMaiorPeso = 0;
    int yMaiorPeso = 0;
    for (auto &ani : animais) {

        if (ani->getId() == id) {
            continue;
        }

        if (ani->getX() < x + valorRedondeza && ani->getX() > x - valorRedondeza && ani->getY() < y + valorRedondeza && ani->getY() > y - valorRedondeza) {
            if (ani->getPeso() > maiorPeso) {
                maiorPeso = ani->getPeso();
                xMaiorPeso = ani->getX();
                yMaiorPeso = ani->getY();

                return make_pair(xMaiorPeso, yMaiorPeso);
            }
        }
    }
    return make_pair(-1, -1);
}

int Reserva::pegaPesoAnimalCacado(int id, int x, int y, int valorRedondeza)
{
    for (auto &ani : animais) {

        if (ani->getId() == id) {
            continue;
        }

        if (ani->getX() < x + valorRedondeza && ani->getX() > x - valorRedondeza && ani->getY() < y + valorRedondeza && ani->getY() > y - valorRedondeza) {
            return ani->getPeso();
        }
    }

    return -1;
}

bool Reserva::verificaSeEstaFora(int x, int y, int linhas, int colunas)
{
    if (x < 1) {
        return true;
    }
    if (x >= linhas) {
        return true;
    }
    if (y < 1) {
        return true;
    }
    if (y >= colunas) {
        return true;
    }

    return false;
}

bool Reserva::verificaAnimalRedondezaAlemPai(int id, int idPai, int x, int y, int valorRedondeza)
{
    for (auto &animal : animais) {

        if (animal->getId() == id) {
            continue;
        }

        if (animal->getX() < x + valorRedondeza && animal->getX() > x - valorRedondeza && animal->getY() < y + valorRedondeza && animal->getY() > y - valorRedondeza) {
            if(animal->getId() != idPai){
                return true;
            }
        }
    }
    return false;
}

pair<int, int> Reserva::pegaCoordPai(int id, int idPai, int x, int y, int valorRedondeza)
{
    for (auto &ani : animais) {

        if (ani->getId() == id) {
            continue;
        }

        if (ani->getX() < x + valorRedondeza && ani->getX() > x - valorRedondeza && ani->getY() < y + valorRedondeza && ani->getY() > y - valorRedondeza) {
            if (ani->getId() == idPai) {
                return make_pair(ani->getX(), ani->getY());
            }
        }
    }
    return make_pair(-1, -1);
}






