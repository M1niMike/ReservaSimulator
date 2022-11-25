﻿//
// Created by mikae on 07/11/2022.
//

#include "Simulador.h"
#include "util.h"



Simulador::Simulador(Reserva *r):r(r) {}

void Simulador::runInterface() {

    string opcao;

    do{
        cout << "\n1 - Novo Simulador";
        cout << "\n2 - Sair";

        cout << "\n->";
        cin >> opcao;
        if(opcao == "1"){
            menuSimulador();
        }
        else if(opcao == "2"){
            cout << "\nA Sair";
            exit(1);
        }
        else
            cout << "\n Opcao invalida";

    }while(opcao != "2");

}

void Simulador::menuSimulador() {

    int linhas = 0;
    int colunas = 0;
    string choice;
    string cmd;
    string aux;
    cout << "Simulacao Iniciada" << endl;
    cout << "A criar a Reserva..." << endl;
    cin.ignore();
    do
    {
        cout << "Introduza o tamanho da reserva que pretende: [Linha] [Coluna]" << endl;
        cout << "->";
        cin >> linhas;
        cin.clear();
        cin.ignore(linhas, '\n');

        cout << "->";
        cin >> colunas;
        cin.clear();
        cin.ignore(colunas, '\n');

        if((linhas<3 || colunas<3) || (linhas>500 || colunas>500))
            cout << "O tamanho da reserva deve ser entre 16x16 e 500x500!" << endl;
    }while((linhas<3 || colunas<3) || (linhas>500 || colunas>500));

//  restrições originais
//    if((linhas<16 || colunas<16) || (linhas>500 || colunas>500))
//        cout << "O tamanho da reserva deve ser entre 16x16 e 500x500!" << endl;
//}while((linhas<16 || colunas<16) || (linhas>500 || colunas>500));

    r->setLinhas(linhas);
    r->setColunas(colunas);

    cout << endl;
    buildReserva();


    while (cmd != "exit") {
        cout << "\nComandos:";
        getline(cin, cmd);
        validaComandos(*r,cmd);
        cout << "\nNumero de Animais na Reserva: " << r->getNumberOfAnimals() << endl;
        cout << "\nNumero de Alimentos na Reserva: " << r->getNumberOfFood() << endl;
        cout << "\nNumero total de coisas na Reserva: " << r->getNumberOfAnimals()+r->getNumberOfFood()<< endl;
        cout << endl;
        buildReserva();
    }
}
string Simulador::leFicheiroComandos(Reserva &r, string fileName) {
    string texto;
    ifstream file;
    file.open(fileName);

    if (file){
        while(getline(file, texto)){
            validaComandos(r,texto);
        }
    }
    else
        cout << "O ficheiro nao existe!" << endl;

    file.close();

    return texto;

}

int Simulador::leFicheiroValores(string fileName) {
    string aux;
    int valor;

    //To read from a file, use either the ifstream or fstream
    ifstream file(fileName);

    if(file.good()){
        while(getline(file, aux)){ cout << aux; }
    }else{
        cout << "\nO ficheiro nao existe!" << endl;
    }
    //stoi convert string to int
     valor = stoi(aux);

    return valor;
}

vector<string> Simulador::splitString(const string& cmd) const {
    string aux;
    istringstream ss(cmd);

    vector<string> palavras;

    while(getline(ss, aux, ' ')){
        palavras.push_back(aux); // adicionar a palavra depois de cada espaco para o nosso vetor de palavras
    }

    return palavras;
}


//ALIMENTO
void Simulador::validaComandos(Reserva &res, string cmd){
    vector<string> cmdVector;

    string tipoComando;

    cmdVector = splitString(cmd); // divide o vetor em palavras

    tipoComando = cmdVector[0]; // ir buscar a primeira palavra ao vetor para descobrir qual o comando

    if (tipoComando == "animal" && cmdVector.size() == 4){
        cmdCriaAnimal(res,cmdVector);
    }
    else if (tipoComando == "animal" && cmdVector.size() == 2){
        cmdCriaAnimalRandom(res ,cmdVector);
    }
    else if (tipoComando == "kill" && cmdVector.size() == 3){
        cout << "A ser implementado" << endl;
    }
    else if (tipoComando == "killid" && cmdVector.size() == 2) {
        cout << "A ser implementado" << endl;
    }
    else if (tipoComando == "food" && cmdVector.size() == 4) {
        cmdCriaAlimento(res, cmdVector);
    }
    else if (tipoComando == "food" && cmdVector.size() == 2) {
        cmdCriaAlimentoRandom(res,cmdVector);
    }
    else if (tipoComando == "feed" && cmdVector.size() == 5) {
        cout << "A ser implementado" << endl;
    }
    else if (tipoComando == "feedid" && cmdVector.size() == 4) {
        cout << "A ser implementado" << endl;
    }
    else if (tipoComando == "nofood" && cmdVector.size() == 3) {
        cout << "A ser implementado" << endl;
    }
    else if (tipoComando == "nofood" && cmdVector.size() == 2) {
        cout << "A ser implementado" << endl;
    }
    else if (tipoComando == "empty" && cmdVector.size() == 3) {
        cout << "A ser implementado" << endl;
    }
    else if (tipoComando == "see" && cmdVector.size() == 3) {
        cout << "A ser implementado" << endl;
    }
    else if (tipoComando == "info" && cmdVector.size() == 2) {
        cout << "A ser implementado" << endl;
    }
    else if (tipoComando == "n" && cmdVector.size() == 1) {
        cout << "A ser implementado" << endl;
    }
    else if (tipoComando == "n" && cmdVector.size() == 2) {
        cout << "A ser implementado" << endl;
    }
    else if (tipoComando == "n" && cmdVector.size() == 3) {
        cout << "A ser implementado" << endl;
    }
    else if (tipoComando == "anim" && cmdVector.size() == 1) {
        cmdAnim();
    }
    else if (tipoComando == "visanim" && cmdVector.size() == 1) {
        cout << "A ser implementado" << endl;
    }
    else if (tipoComando == "store" && cmdVector.size() == 2) {
        cout << "A ser implementado" << endl;
    }
    else if (tipoComando == "restore" && cmdVector.size() == 2) {
        cout << "A ser implementado" << endl;
    }
    else if (tipoComando == "load" && cmdVector.size() == 2) {
        cout << "Fixing..." << endl;
        //cmdLoad(cmdVector);
    }
    else if (tipoComando == "slide" && cmdVector.size() == 3) {
        cout << "A ser implementado" << endl;
    }
    else if (tipoComando == "exit" && cmdVector.size() == 1) {
        cmdExit();
    }
    else {
        cout << "\nComando desconhecido!" << endl;
    }
}


void Simulador::cmdExit() {
    cout << "A sair" << endl;
    exit(1);
}

void Simulador::cmdCriaAnimal(Reserva &res, vector<string> comando) { // animal c 0 1
    for (auto it: comando) { // armezenar comandos

        if(it == comando[2]){
            char coordX = comando[2][0];

            if (isdigit(coordX) == 0){
                cout << "\nPor favor insira um numero na coordenada!\n" << endl;
            }

        }else if (it == comando[3]){
            char coordY = comando[3][0];

            if (isdigit(coordY) == 0){
                cout << "\nPor favor insira um numero na coordenada!\n" << endl;
            }

        }else if (it == comando[1]) { // animal \c| 1 1
            it = maiscula(it);
            int x = stoi(comando[2]);
            int y = stoi(comando[3]);
            res.criaAnimal(it, x, y);
        }
    }
}

void Simulador::cmdCriaAnimalRandom(Reserva &res, vector<string> comando) {
    for (auto it: comando){
        if(it == comando[1]){
            it = maiscula(it);
            res.criaAnimalRandom(it);
        }
    }
}

//void Simulador::cmdInfo(vector<string> comando){
//    for (auto it : comando){
//        if (it == comando[1]){
//           for (int i = 0; i )
//        }
//    }
//}

string Simulador::maiscula(std::string palavra) {
    for (int i = 0; i < palavra.size(); i++){
        palavra[i] = toupper(palavra[i]);
    }
    return palavra;
}

void Simulador::cmdCriaAlimento(Reserva &res, vector<string> comando) {
    for (auto it: comando) { // armezenar comandos

        if(it == comando[2]){
            char coordX = comando[2][0];

            if (isdigit(coordX) == 0){
                cout << "\nPor favor insira um numero na coordenada!\n" << endl;
            }

        }else if (it == comando[3]){
            char coordY = comando[3][0];

            if (isdigit(coordY) == 0){
                cout << "\nPor favor insira um numero na coordenada!\n" << endl;
            }

        }else if (it == comando[1]) { // animal \c| 1 1
            it = maiscula(it);
            int x = stoi(comando[2]);
            int y = stoi(comando[3]);
            res.criaAlimento(it, x, y);
        }
    }
}

void Simulador::cmdCriaAlimentoRandom(Reserva &res, vector<string> comando) {
    for (auto it: comando){
        if(it == comando[1]){
            it = maiscula(it);
            res.criaAlimentoRandom(it);
        }
    }
}

/*FIX*/
//void Simulador::cmdLoad(vector<string> comando) {
//    for(auto it : comando ){
//        if(it == comando[1]){
//            leFicheiroComandos(it);
//        }
//    }
//
//}

void Simulador::cmdAnim() {
    cout << r->PrintaAnimal();
}


void Simulador::buildReserva() {
    //Animais *a;
    int linhas = r->getLinhas();
    int colunas = r->getColunas();
    int t = 0;

    for(int i = 0; i < colunas; i++){
        if (i == 0){
            cout << "|-------";
        } else if (i == colunas-1){
            cout << "|-------|";
        } else {
            cout << "|-------";
        }
    }

    for (int i = 0; i<linhas; i++){
        cout << "\n|";
        for (int j = 0; j<colunas; j++){
            cout << " " << "\t|"; //movimentação
        }
        cout << "\n" << "|";

        for (int j = 0; j<colunas; j++){
            for (int x = 0; x < r->getVecAnimal().size(); x++){
                if (r->getVecAnimal()[x]->getY() == i+1 && r->getVecAnimal()[x]->getX() == j+1){
                    cout << r->getVecAnimal()[x]->getTipoAnimal();
                } else{
                    continue;
                }
            }
            cout <<"\t|"; //Primeiro print

        }
        cout << "\n" << "|";
        for(int j = 0; j<colunas; j++){
            for (int k = 0; k < r->getVecAlimento().size(); k++){
                if (r->getVecAlimento()[k]->getY() == i+1 && r->getVecAlimento()[k]->getX() == j+1){
                    cout << r->getVecAlimento()[k]->getTipoAlimento();
                }
            }
            cout <<"\t|"; //Primeiro print
        }
        cout << "\n" << "|";
        for(int j=0; j<colunas; j++){
            cout << " " << "\t|"; // count
        }
        cout << "\n";
        for (int j = 0; j<colunas; j++){
            if (i != linhas-1){
                if(j == colunas-1){
                    cout << "-------|";
                } else if(j == 0){
                    cout << "|-------|";
                } else {
                    cout << "-------|";
                }
            } else{
                if (j == 0){
                    cout << "|-------|";
                } else if(j == colunas-1){
                    cout << "-------|";
                } else {
                    cout << "-------|";
                }
            }
        }
        cout << "\n";
    }
}



