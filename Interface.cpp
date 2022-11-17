//
// Created by mikae on 07/11/2022.
//

#include "Interface.h"
#include "util.h"


void Interface::runInterface() {

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

void Interface::menuSimulador() {

    int linhas = 0;
    int colunas = 0;
    string choice;
    string cmd;
    string aux;
    Interface i;
    cout << "Simulacao Iniciada" << endl;
    cout << "Criando a Reserva" << endl;
    cin.ignore();
    do
    {
        cout << "Introduza o tamanho da reserva que pretende: [Linha] [Coluna]" << endl;
        cout << "->";
        getline(cin, aux);

        istringstream iss(aux);
        iss >> linhas >> colunas;

        if((linhas<16 || colunas<16) || (linhas>500 || colunas>500))
            cout << "O tamanho da reserva deve ser entre 16x16 e 500x500!" << endl;
    }while((linhas<16 || colunas<16) || (linhas>500 || colunas>500));



    cout << "Deseja inserir um comando por ficheiro ou texto? <ficheiro> <texto>" << endl;
    cin >> choice;
    if(choice == "ficheiro"){
        leFicheiroComandos("comandos.txt");
    }else if(choice == "texto"){
        cin.ignore();
        while (1) {
            cout << "Comandos:" << endl;
            getline(cin, cmd);
            i.validaComandos(cmd);
        }
    }else
        cout << "insira <texto> ou <ficheiro>" << endl;
}



string Interface::leFicheiroComandos(string fileName) {
    string texto;
    Interface i;
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



int Interface::leFicheiroValores(string fileName) {
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

vector<string> Interface::splitString(string cmd) const {
    string aux;
    istringstream ss(cmd);

    vector<string> palavras;

    while(getline(ss, aux, ' ')){
        palavras.push_back(aux); // adicionar a palavra depois de cada espaço para o nosso vetor de palavras
    }

    return palavras;
}



void Interface::validaComandos(string cmd){
    vector<string> cmdVector;

    string tipoComando;

    cmdVector = splitString(cmd); // divide o vetor em palavras

    tipoComando = cmdVector[0]; // ir buscar a primeira palavra ao vetor para descobrir qual o comando

    if (tipoComando == "animal" && cmdVector.size() == 4){
        cout << "A ser implementado" << endl;
    }
    else if(tipoComando == "animal" && cmdVector.size() == 2){
        cout << "A ser implementado" << endl;
    }
    else if (tipoComando == "kill" && cmdVector.size() == 3){
        cout << "A ser implementado" << endl;
    }
    else if (tipoComando == "killid" && cmdVector.size() == 2) {
        cout << "A ser implementado" << endl;
    }
    else if (tipoComando == "food" && cmdVector.size() == 4) {
        cout << "A ser implementado" << endl;
    }
    else if (tipoComando == "food" && cmdVector.size() == 2) {
        cout << "A ser implementado" << endl;
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

