#include "Simulador.h"
#include "util.h"



Simulador::Simulador(Reserva *r):r(r) {}

void Simulador::runInterface() {

    leFicheiroConstantes("constantes.txt");

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

    buildReserva();

    while (cmd != "exit") {
        cout << "\nComandos:";
        getline(cin, cmd);
        validaComandos(cmd);
        buildReserva();

        cout << "\nNumero de Animais na Reserva: " << r->getNumberOfAnimals() << endl;
        cout << "\nNumero de Alimentos na Reserva: " << r->getNumberOfFood() << endl;
        cout << "\nNumero total de coisas na Reserva: " << r->getNumberOfAnimals()+r->getNumberOfFood()<< endl;
        cout << endl;
    }
}

bool Simulador::leFicheiro(string fileName) {
    string texto;
    ifstream file;
    file.open(fileName);

    if (file){
        while(getline(file, texto)){
            //cout << "[ " << texto << " ]" << endl;
            validaComandos(texto);
        }
        file.ignore('\n');
    }
    else {
        cout << "O ficheiro nao existe!" << endl;
        return false;
    }

    file.close();
    return true;
}

bool Simulador::leFicheiroConstantes(string fileName){
    string textoDoFich;

    ifstream file;

    int valor;

    string aux;

    file.open(fileName);

    if(!file){
        return false;
    }

    while (getline(file, textoDoFich)){
        istringstream iss(textoDoFich);
        if (!(iss >> aux >> valor)){
            continue;
        }
        mapa[aux] = valor;
    }

    file.ignore('\n');

    return true;
}

void Simulador::cmdLoad(vector<string> comando) {
    if (leFicheiro(comando[1])){
        cout << "\nFicheiro lido com sucesso!" << endl;
    } else {
        cout << "\nErro! Ficheiro invalido!" << endl;
    }
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
void Simulador::validaComandos(string cmd){
    vector<string> cmdVector;

    string tipoComando;

    cmdVector = splitString(cmd); // divide o vetor em palavras

    tipoComando = cmdVector[0]; // ir buscar a primeira palavra ao vetor para descobrir qual o comando

    if (tipoComando == "animal" && cmdVector.size() == 4){
        cmdCriaAnimal(cmdVector);
    }
    else if (tipoComando == "animal" && cmdVector.size() == 2){
        cmdCriaAnimalRandom(cmdVector);
    }
    else if (tipoComando == "kill" && cmdVector.size() == 3){
        cout << "A ser implementado" << endl;
    }
    else if (tipoComando == "killid" && cmdVector.size() == 2) {
        cout << "A ser implementado" << endl;
    }
    else if (tipoComando == "food" && cmdVector.size() == 4) {
        cmdCriaAlimento(cmdVector);
    }
    else if (tipoComando == "food" && cmdVector.size() == 2) {
        cmdCriaAlimentoRandom(cmdVector);
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
        cmdSee(cmdVector);
    }
    else if (tipoComando == "info" && cmdVector.size() == 2) {
        cmdInfo(cmdVector);
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
        cmdLoad(cmdVector);
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
    exit(0);
}

int Simulador::constantesReader(string aux) {
    for (auto it: mapa){
        if(mapa.find(aux) != mapa.end()){
            return mapa[aux];
        }
    }
    return -1;
}

void Simulador::cmdCriaAnimal(vector<string> comando) {
    for (auto it: comando) { // armezenar comandos
        int peso = constantesReader("Peso");
        int saude = constantesReader("SAnimal");
        int vida = constantesReader("VAnimal");
        char coordX = comando[2][0];
        char coordY = comando[3][0];

        if(it == comando[2]){

            if (isdigit(coordX) == 0) {
                cout << "\nPor favor insira um numero na coordenada!\n" << endl;
            }

        }else if (it == comando[3]){
            if (isdigit(coordY) == 0){
                cout << "\nPor favor insira um numero na coordenada!\n" << endl;
            }

        }else if (it == comando[1]) {
            it = maiscula(it);
            int x = stoi(comando[2]);
            int y = stoi(comando[3]);

            if (verificaCoord(x,y)){
                r->criaAnimal(it, saude, vida, peso, x, y);
            } else {
                cout << "\nPor favor, insira coordenadas validas!" << endl;
            }
        }
    }
}

void Simulador::cmdCriaAnimalRandom(vector<string> comando) {
    for (auto it: comando){
        if(it == comando[1]){
            it = maiscula(it);
            r->criaAnimalRandom(it, constantesReader("SAnimal"),constantesReader("VAnimal"), constantesReader("Peso"));
        }
    }
}


void Simulador::cmdSee(vector<string> comando) {
    for (auto it: comando) { // armezenar comandos
        char coordX = comando[1][0];
        char coordY = comando[2][0];
        if(it == comando[1]){
            if (isdigit(coordX) == 0){
                cout << "\nPor favor insira um numero na coordenada!\n" << endl;
            }

        }else if (it == comando[2]){
            if (isdigit(coordY) == 0){
                cout << "\nPor favor insira um numero na coordenada!\n" << endl;
            }

        }

        int x = stoi(comando[1]);
        int y = stoi(comando[2]);
        buildArea(x,y);
        break;
    }
}


void Simulador::cmdInfo(vector<string> comando){
    int aux = stoi(comando[1]);
    for(int i = 0; i < r->getVecAnimal().size(); i++){
        if(aux == r->getVecAnimal()[i]->getId()){
            cout << r->getVecAnimal()[i]->PrintaAnimal();
        }else
            break;
    }

    for(int i = 0; i < r->getVecAlimento().size(); i++){
        if(aux == r->getVecAlimento()[i]->getId()){
            cout << r->getVecAlimento()[i]->PrintaAlimento();
        }else
            break;
    }

}

string Simulador::maiscula(std::string palavra) {
    for (int i = 0; i < palavra.size(); i++){
        palavra[i] = toupper(palavra[i]);
    }
    return palavra;
}

void Simulador::cmdCriaAlimento(vector<string> comando) {
    for (auto it: comando) { // armezenar comandos
        char coordX = comando[2][0];
        char coordY = comando[3][0];
        if(it == comando[2]){
            if (isdigit(coordX) == 0){
                cout << "\nPor favor insira um numero na coordenada!\n" << endl;
            }
        }else if (it == comando[3]){
            if (isdigit(coordY) == 0){
                cout << "\nPor favor insira um numero na coordenada!\n" << endl;
            }

        }else if (it == comando[1]) { // animal \c| 1 1
            it = maiscula(it);
            int x = stoi(comando[2]);
            int y = stoi(comando[3]);
            if (verificaCoord(x, y) && !(r->hasAlimento(x, y)))
                r->criaAlimento(it, x, y);
            else if(verificaCoord(x, y) && r->hasAlimento(x, y)){
                cout << "\nPor favor insira um Alimento em outra coordenada!" << endl;
                cout << "[Alimento ja existe na posicao inserida]" << endl;
            }
            else
                cout << "\nPor favor insira uma coordenada valida" << endl;
        }
    }
}

void Simulador::cmdCriaAlimentoRandom(vector<string> comando) {
    for (auto it: comando){
        if(it == comando[1]){
            it = maiscula(it);
            r->criaAlimentoRandom(it);
        }
    }
}

void Simulador::cmdAnim() {
    for(int i = 0; i < r->getVecAnimal().size(); i++){
        cout << r->getVecAnimal()[i]->PrintaAnimal();
    }
}

void Simulador::buildArea(int x, int y) {

    if (verificaCoord(x,y)){
        cout << "\nA printar info de x = " << x << " e y = " << y << endl;
        cout << "\nAnimais: "<< endl;
        getInfoAnimal(x, y);
        cout << "\nAlimentos: "<< endl;
        getInfoAlimento(x, y);
        cout << endl;
    } else {
        cout << "\nPor favor, insira coordenadas validas." << endl;
    }
}


void Simulador::buildReserva() {
    //Animais *a;
    int linhas = r->getLinhas();
    int colunas = r->getColunas();
    int t = 0;
    int cont = 0;

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

       // Print 1º espaço
//        cout << "\n|";
//        for (int j = 0; j<colunas; j++){
//            cout << " " << "\t|"; //movimentação
//        }

        cout << "\n" << "|";

        for (int j = 0; j<colunas; j++){
            for (int x = 0; x < r->getVecAnimal().size(); x++){
                if (r->getVecAnimal()[x]->getX() == i+1 && r->getVecAnimal()[x]->getY() == j+1){
                    cout << r->getVecAnimal()[x]->getTipoAnimal();
                } else{
                    continue;
                }
            }
            cout <<"\t|";

        }
        cout << "\n" << "|";
        for(int j = 0; j<colunas; j++){
            for (int k = 0; k < r->getVecAlimento().size(); k++){
                if (r->getVecAlimento()[k]->getX() == i+1 && r->getVecAlimento()[k]->getY() == j+1){
                    cout << r->getVecAlimento()[k]->getTipoAlimento();
                }
            }
            cout <<"\t|";
        }

//    Print 4º espaço
//        cout << "\n" << "|";
//        for(int j=0; j<colunas; j++){
//            cout << " " << "\t|"; // count
//        }

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


void Simulador::getInfoAnimal(int x, int y) {
    int linhas = x;
    int colunas = y;

    for(int k = 0; k < r->getVecAnimal().size(); k++){
        if(r->getVecAnimal()[k]->getX() == x && r->getVecAnimal()[k]->getY() == y){
            cout << "Id: " << r->getVecAnimal()[k]->getId()<< " | ";
            cout << "Tipo: " << r->getVecAnimal()[k]->getTipoAnimal()<< " | ";
            cout << "Saude: "<< r->getVecAnimal()[k]->getSaude() << endl;
        } else if(r->getVecAnimal()[k]->getX() != x && r->getVecAnimal()[k]->getY() != y){
            cout << "\nNao se encontra nenhum animal nas coordenadas " << x << " e " << y << endl;
            break;
        }
    }
}

void Simulador::getInfoAlimento(int x, int y) {
    int linhas = x;
    int colunas = y;

    for(int k = 0; k < r->getVecAlimento().size(); k++){
        if(r->getVecAlimento()[k]->getX() == x && r->getVecAlimento()[k]->getY() == y){
            cout << "Id: " << r->getVecAlimento()[k]->getId() << " | ";
            cout << "Tipo: " << r->getVecAlimento()[k]->getTipoAlimento() << " | ";
            cout << "Cheiro: " << r->getVecAlimento()[k]->getCheiro() << endl;
        }else if(r->getVecAnimal()[k]->getX() != x && r->getVecAnimal()[k]->getY() != y){
            cout << "\nNao se encontra nenhum alimento nas coordenadas " << x << " e " << y << endl;
            break;
        }
    }
}

bool Simulador::verificaCoord(const int& linha, const int& coluna) {
    int linhas = r->getLinhas();
    int colunas = r->getColunas();

    if ((linha >= 1 && linha <= linhas) && (coluna >= 1 && coluna <= colunas)){
        return true;
    }
    return false;
}


