//
// Created by mikae on 07/11/2022.
//

#include "Simulador.h"
#include "util.h"
#include <sstream>
#include <string>
#include <fstream>
#include <iostream>
#include <random>
#include <cstdlib>


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
       // getline(cin, aux);
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
    buildReserva(*r);

    cout << "Deseja inserir um comando por ficheiro ou texto? <ficheiro> <texto>" << endl;
    cin >> choice;
    if(choice == "ficheiro"){
        leFicheiroComandos("comandos.txt");
    }else if(choice == "texto"){
        cin.ignore();
        while (1) {
            cout << "Comandos:" << endl;
            getline(cin, cmd);
            validaComandos(cmd);
            cout << "\nNumero de Animais na Reserva: " << r->getNumberOfAnimals() << endl;
            cout << "\nNumero de Alimentos na Reserva: " << r->getNumberOfFood() << endl;
            cout << endl;
            buildReserva(*r);
        }
    }else
        cout << "Insira <texto> ou <ficheiro>" << endl;
}



string Simulador::leFicheiroComandos(string fileName) {
    string texto;
    Simulador i(new Reserva());
    ifstream file;

    file.open(fileName);

    if (file){
        while(getline(file, texto)){
            i.validaComandos(texto);
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
//void Reserva::criaAlimento(const string &tipo, const int &x, const int &y) {
//
//    if (tipo != "r" && tipo != "t" && tipo != "p" && tipo != "b" && tipo != "g"){
//        cout << "\nPor favor insira um alimento valido!" << endl;
//    } else {
//        if (x < 0 || x > getLinhas() * getColunas() || y < 0 || y > getLinhas() * getColunas())
//            cout << "\nPor favor insira um numero valido de colunas/linhas!" << endl;
//
//        else{
//            if(tipo == "r"){
//                alimentos.push_back(new Alimentos(tipo, getAlimento().getValimento(), getAlimento().getValorNutri(),getAlimento().getToxicidade() ,getAlimento().getCheiro(), x, y, 1));
//            }
//            else if (tipo == "t"){
//                alimentos.push_back(new Alimentos(tipo, x, y));
//            }
//            else if (tipo == "p"){
//                alimentos.push_back(new Alimentos(tipo, x, y));
//            }
//            else if (tipo == "b"){
//                alimentos.push_back(new Alimentos(tipo, x, y));
//            }
//            else if (tipo == "g"){
//                alimentos.push_back(new Alimentos(tipo, x, y));
//            }
//        }
//    }
//
//}

void Simulador::cmdCriaAnimal(vector<string> comando) { // animal c 0 1
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
                int x = stoi(comando[2]);
                int y = stoi(comando[3]);
                r->criaAnimal(it, x, y);
            }
        }
    }
/* else {
            int coordX = stoi(comando[2]);
            int coordY = stoi(comando[3]);

            if (comando[1] == "c"){
                r->getVecAnimal().push_back(new Animais(comando[1], 20, 0, 0, false, 1, coordX, coordY));
            } else if(comando[1] == "o"){
                r->getVecAnimal().push_back(new Animais(comando[1], 30, 0, 0, false, 1, coordX, coordY));
            } else if (comando[1] == "l"){
                r->getVecAnimal().push_back(new Animais(comando[1], 25, 15, 0, false, 1, coordX, coordY));
            } else if(comando[1] == "g"){
                r->getVecAnimal().push_back(new Animais(comando[1], 20, 10, 70, false, 1, coordX, coordY));
            } else if (comando[1] == "m"){
                r->getVecAnimal().push_back(new Animais(comando[1], 0, 0, 0, false, 1, coordX, coordY));
            }
        }*/

void Simulador::validaComandos(string cmd){
    vector<string> cmdVector;

    string tipoComando;

    cmdVector = splitString(cmd); // divide o vetor em palavras

    tipoComando = cmdVector[0]; // ir buscar a primeira palavra ao vetor para descobrir qual o comando

    if (tipoComando == "animal" && cmdVector.size() == 4){
        cmdCriaAnimal(cmdVector);
    }
    else if (tipoComando == "animal" && cmdVector.size() == 2){
//        r->criaAnimalRandom(cmdVector[1]);
//        cout << r->PrintaAnimal();
    }
    else if (tipoComando == "kill" && cmdVector.size() == 3){
        cout << "A ser implementado" << endl;
    }
    else if (tipoComando == "killid" && cmdVector.size() == 2) {
        cout << "A ser implementado" << endl;
    }
    else if (tipoComando == "food" && cmdVector.size() == 4) {
//        r->criaAlimento(cmdVector[1], stoi(cmdVector[2]), stoi(cmdVector[3]));
//        cout << r->PrintaAlimento();
    }
    else if (tipoComando == "food" && cmdVector.size() == 2) {
//        r->criaAlimentoRandom(cmdVector[1]);
//        cout << r->PrintaAlimento();
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
        cout << "A ser implementado" << endl;
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
        cout << "A ser implementado" << endl;
    }
    else if (tipoComando == "slide" && cmdVector.size() == 3) {
        cout << "A ser implementado" << endl;
    }
    else if (tipoComando == "exit" && cmdVector.size() == 1) {
        cout << "a sair" << endl;
        exit(1);
    }
    else {
        cout << "\nComando desconhecido!" << endl;
    }
}


void Simulador::buildReserva(Reserva &r) {
    //Animais *a;
    int linhas = r.getLinhas();
    int colunas = r.getColunas();
//
//    /*for (int i = 0; i < linhas; i ++) {
//        for (int j = 0; j < colunas; j++) {
//            if(board[i][j] == r->getTipoAnimal("c"))
//                board[i][j] = "c";
//            else if(board[i][j]== r->getTipoAnimal("o")){
//                board[i][j] = "o";
//            }else if(board[i][j]== r->getTipoAnimal("l")){
//                board[i][j] = "l";
//            }else if(board[i][j]== r->getTipoAnimal("g")){
//                board[i][j] = "g";
//            }else if(board[i][j]== r->getTipoAnimal("m")){
//                board[i][j] = "m";
//            }else{
//                board[i][j] = "_____";
//            }
//        }
//    }*/
//
    //Quadrado
        // print the first character as part of the opener.
        for (int o = 0; o < colunas; o++) {
            if (o == 0)
                cout << "T-------"; // ┌───────
            else if (o == colunas - 1)
                cout << "|-------T"; // ┬───────┐
            else
                cout << "|-------"; // ┬───────
        }

    for (int i = 0; i < linhas; i++) {
            cout << "\n|";
       for (int j = 0; j < colunas; j++){
            cout << "\t|";
       }

       cout << "\n" << "|";

       for (int j = 0; j < colunas; j++) {
           if (!r->hasAnimal(i, j)) {
               cout << "\t\t|";
           } else {
               cout << r->getAnimalIn(i, j) << "\t|";
           }
           cout << "\n" << "|";

           for (int j = 0; j < colunas; j++) {
               if (!r->hasAnimal(i, j)) {
                   cout << "\t\t|";
               }else {
                   cout << r->getAnimalIn(i, j) << "\t|";
               }
       }
           cout << "\n" << "|";

           for(int j=0; j<colunas; j++)
           {
               if(i != linhas-1)
               {
                   if(j == colunas-1)
                       cout << "-------|";
                   else if (j == 0)
                       cout  << "|-------|";
                   else
                       cout  << "-------|";
               }
               else
               {
                   if(j == 0)
                       cout << "L_______|";
                   else if(j == colunas-1)
                       cout << "_______|";
                   else
                       cout << "-------|";

               }
           }
       }
        cout <<"\n";
    }
}
