#include "Simulador.h"
#include "util.h"

Simulador::Simulador(Reserva *r, Terminal &t) : r(r), t(t), cmdW(0, 35, 112, 20), textInterface(113, 0, 112, 55),
                                                reservaPrinter(0, 0, 10, 10) {}

void Simulador::runInterface() {

    leFicheiroConstantes("constantes.txt");

    string opcao;

    do {
        cmdW << "\n1 - Novo Simulador";
        cmdW << "\n2 - Sair";
        //textInterface << "AQUI\n";

        cmdW << "\n->";
        cmdW >> opcao;
        if (opcao == "1") {
            menuSimulador();
        } else if (opcao == "2") {
            cmdW << "\nA Sair";
            return;
        } else
            cmdW << "\n Opcao invalida";

    } while (opcao != "2");
}

void Simulador::menuSimulador() {

    int linhas = 0;
    int colunas = 0;
    string choice;
    string cmd;
    string aux;
    string coord;
    cmdW << "Simulacao Iniciada\n";
    cmdW << "A criar a Reserva...\n";
    //cin.ignore();
    do {
        cmdW << "Introduza o tamanho da reserva que pretende: [Linha] [Coluna]\n";
        cmdW << "->";

        cmdW >> coord;
        istringstream iss(coord);

        if (iss >> linhas && iss >> colunas) {
            cmdW << linhas << " " << colunas;
        }

        if ((linhas < 16 || colunas < 16) || (linhas > 500 || colunas > 500))
            cmdW << "O tamanho da reserva deve ser entre 16x16 e 500x500!";
    } while ((linhas < 16 || colunas < 16) || (linhas > 500 || colunas > 500));

    r->setLinhas(linhas);
    r->setColunas(colunas);

    buildReserva();

    while (cmd != "exit") {
        cmdW << "\nComandos:";
        cmdW >> cmd;
        validaComandos(cmd);
        cmdW << "\n";
        buildReserva();

        textInterface << "\nNumero de Animais na Reserva: " << r->getNumberOfAnimals();
        textInterface << "\nNumero de Alimentos na Reserva: " << r->getNumberOfFood();
        textInterface << "\nNumero total de coisas na Reserva: " << r->getNumberOfAnimals() + r->getNumberOfFood();

        cmdW.clear();
        textInterface.clear();
    }
}

//Funcs Auxiliares
bool Simulador::leFicheiro(string fileName) {
    string texto;
    ifstream file;
    file.open(fileName);

    if (file) {
        while (getline(file, texto)) {
            //cout << "[ " << texto << " ]" << endl;
            validaComandos(texto);
        }
        file.ignore('\n');
    } else {
        textInterface << "O ficheiro nao existe!" << "\n";
        return false;
    }

    file.close();
    return true;
}

bool Simulador::leFicheiroConstantes(string fileName) {
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
        mapa[aux] = valor;
    }

    file.ignore('\n');

    return true;
}

int Simulador::constantesReader(string aux) {
    for (auto it: mapa) {
        if (mapa.find(aux) != mapa.end()) {
            return mapa[aux];
        }
    }
    return -1;
}

vector<string> Simulador::splitString(const string &cmd) const {
    string aux;
    istringstream ss(cmd);

    vector<string> palavras;

    while (getline(ss, aux, ' ')) {
        palavras.push_back(aux); // adicionar a palavra depois de cada espaco para o nosso vetor de palavras
    }

    return palavras;
}

string Simulador::maiscula(std::string palavra) {
    for (int i = 0; i < palavra.size(); i++) {
        palavra[i] = toupper(palavra[i]);
    }
    return palavra;
}

void Simulador::getInfoAnimal(int x, int y) {
    int linhas = x;
    int colunas = y;
    bool flag = false;

    for (int k = 0; k < r->getVecAnimal().size(); k++) {
        if (r->getVecAnimal()[k]->getX() == x && r->getVecAnimal()[k]->getY() == y) {
            textInterface << "Id: " << r->getVecAnimal()[k]->getId() << " | ";
            textInterface << "Tipo: " << r->getVecAnimal()[k]->getTipoAnimal() << " | ";
            textInterface << "Saude: " << r->getVecAnimal()[k]->getSaude() << "\n";
            flag = true;
        }
    }

    if (!flag) {
        textInterface << "\nNao se encontra nenhum animal nas coordenadas " << x << " e " << y << "\n";
    }

}

void Simulador::getInfoAlimento(int x, int y) {
    int linhas = x;
    int colunas = y;
    bool flag = false;

    for (int k = 0; k < r->getVecAlimento().size(); k++) { //percorre o vector
        if (r->getVecAlimento()[k]->getX() == x &&
            r->getVecAlimento()[k]->getY() == y)  // deu match do x e y inserido pelo user com os do vetor
        {
            textInterface << "Id: " << r->getVecAlimento()[k]->getId() << " | ";
            textInterface << "Tipo: " << r->getVecAlimento()[k]->getTipoAlimento() << " | ";
            textInterface << "Cheiro: " << r->getVecAlimento()[k]->getCheiro() << "\n";
            flag = true;
        }
    }

    if (!flag) // caso nao ache um match, a funcao a cima nao retorna um flag = true entao ele entra nesse if
    {
        textInterface << "\nNao se encontra nenhum alimento nas coordenadas " << x << " e " << y << "\n";
    }

}

bool Simulador::verificaCoord(const int &linha, const int &coluna) {
    int linhas = r->getLinhas();
    int colunas = r->getColunas();

    if ((linha >= 1 && linha <= linhas) && (coluna >= 1 && coluna <= colunas)) {
        return true;
    }
    return false;
}

void Simulador::cmdNoFoodCoord(vector<string> comando) {
    for (auto it: comando) { // armezenar comandos
        char coordX = comando[1][0];
        char coordY = comando[2][0];

        if (it == comando[2]) {

            if (isdigit(coordX) == 0) {
                textInterface << "\nPor favor insira um numero na coordenada!\n" << "\n";
            }

        } else if (it == comando[2]) {
            if (isdigit(coordY) == 0) {
                textInterface << "\nPor favor insira um numero na coordenada!\n" << "\n";
            }

        }
        int x = stoi(comando[1]);
        int y = stoi(comando[2]);

        if (verificaCoord(x, y)) {
            r->removeAlimentobyCoord(x,y);

        } else {
            textInterface << "\nPor favor, insira coordenadas validas!" << "\n";
        }
    }
}

void Simulador::cmdNoFoodId(vector<string> comando) {
    for (auto it: comando) { // armezenar comandos
        char idchar = comando[1][0];

        if (it == comando[1]) {

            if (isdigit(idchar) == 0) {
                textInterface << "\nPor favor insira um numero na coordenada!\n" << "\n";
            }

        }

        int id = stoi(comando[1]);
        r->removeAlimentobyId(id);
    }
}

void Simulador::cmdKillAnimalCoord(vector<string> comando) {
    for (auto it: comando) { // armezenar comandos
        char coordX = comando[1][0];
        char coordY = comando[2][0];

        if (it == comando[2]) {

            if (isdigit(coordX) == 0) {
                textInterface << "\nPor favor insira um numero na coordenada!\n" << "\n";
            }

        } else if (it == comando[2]) {
            if (isdigit(coordY) == 0) {
                textInterface << "\nPor favor insira um numero na coordenada!\n" << "\n";
            }

        }
        int x = stoi(comando[1]);
        int y = stoi(comando[2]);

        if (verificaCoord(x, y)) {
            r->removeAnimalbyCoord(x,y);

        } else {
            textInterface << "\nPor favor, insira coordenadas validas!" << "\n";
        }
    }
}

void Simulador::cmdKillAnimalId(vector<string> comando){
    for (auto it: comando) { // armezenar comandos
        char idchar = comando[1][0];

        if (it == comando[1]) {

            if (isdigit(idchar) == 0) {
                textInterface << "\nPor favor insira um numero na coordenada!\n" << "\n";
            }

        }

        int id = stoi(comando[1]);
        r->removeAnimalbyId(id);
    }
}

void Simulador::cmdEmpty(vector<string> comando) {

    for (auto it: comando) { // armezenar comandos
        char coordX = comando[1][0];
        char coordY = comando[2][0];

        if (it == comando[2]) {

            if (isdigit(coordX) == 0) {
                textInterface << "\nPor favor insira um numero na coordenada!\n" << "\n";
            }

        } else if (it == comando[2]) {
            if (isdigit(coordY) == 0) {
                textInterface << "\nPor favor insira um numero na coordenada!\n" << "\n";
            }

        }
            int x = stoi(comando[1]);
            int y = stoi(comando[2]);

            if (verificaCoord(x, y)) {
                r->removeAlimentobyCoord(x,y);
                r->removeAnimalbyCoord(x,y);

            } else {
                textInterface << "\nPor favor, insira coordenadas validas!" << "\n";
            }
    }
}

//Comandos
void Simulador::validaComandos(string cmd) {
    vector<string> cmdVector;

    string tipoComando;

    cmdVector = splitString(cmd); // divide o vetor em palavras

    tipoComando = cmdVector[0]; // ir buscar a primeira palavra ao vetor para descobrir qual o comando

    if (tipoComando == "animal" && cmdVector.size() == 4)
    {
        cmdCriaAnimal(cmdVector);
    }
    else if (tipoComando == "animal" && cmdVector.size() == 2)
    {
        cmdCriaAnimalRandom(cmdVector);
    }
    else if (tipoComando == "kill" && cmdVector.size() == 3)
    {
        cmdKillAnimalCoord(cmdVector);
    }
    else if (tipoComando == "killid" && cmdVector.size() == 2)
    {
        cmdKillAnimalId(cmdVector);
    }
    else if (tipoComando == "food" && cmdVector.size() == 4)
    {
        cmdCriaAlimento(cmdVector);
    }
    else if (tipoComando == "food" && cmdVector.size() == 2)
    {
        cmdCriaAlimentoRandom(cmdVector);
    }
    else if (tipoComando == "feed" && cmdVector.size() == 5)
    {
        textInterface << "A ser implementado" << "\n";
    }
    else if (tipoComando == "feedid" && cmdVector.size() == 4)
    {
        textInterface << "A ser implementado" << "\n";
    }
    else if (tipoComando == "nofood" && cmdVector.size() == 3)
    {
        cmdNoFoodCoord(cmdVector);
    }
    else if (tipoComando == "nofood" && cmdVector.size() == 2)
    {
        cmdNoFoodId(cmdVector);
    }
    else if (tipoComando == "empty" && cmdVector.size() == 3)
    {
        cmdEmpty(cmdVector);
    }
    else if (tipoComando == "see" && cmdVector.size() == 3)
    {
        cmdSee(cmdVector);
    }
    else if (tipoComando == "info" && cmdVector.size() == 2)
    {
        cmdInfo(cmdVector);
    }
    else if (tipoComando == "n" && cmdVector.size() == 1)
    {
        textInterface << "A ser implementado" << "\n";
    }
    else if (tipoComando == "n" && cmdVector.size() == 2)
    {
        textInterface << "A ser implementado" << "\n";
    }
    else if (tipoComando == "n" && cmdVector.size() == 3)
    {
        textInterface << "A ser implementado" << "\n";
    }
    else if (tipoComando == "anim" && cmdVector.size() == 1)
    {
        cmdAnim();
    }
    else if (tipoComando == "visanim" && cmdVector.size() == 1)
    {
        textInterface << "A ser implementado" << "\n";
    }
    else if (tipoComando == "store" && cmdVector.size() == 2)
    {
        textInterface << "A ser implementado" << "\n";
    }
    else if (tipoComando == "restore" && cmdVector.size() == 2)
    {
        textInterface << "A ser implementado" << "\n";
    }
    else if (tipoComando == "load" && cmdVector.size() == 2)
    {
        cmdLoad(cmdVector);
    }
    else if (tipoComando == "slide" && cmdVector.size() == 3)
    {
        textInterface << "A ser implementado" << "\n";
    }
    else if (tipoComando == "exit" && cmdVector.size() == 1)
    {
        cmdExit();
    }
    else
    {
        textInterface << "\nComando desconhecido!" << "\n";
    }
}

void Simulador::cmdExit() {
    textInterface << "A sair" << "\n";
    return;
}

void Simulador::cmdCriaAnimal(vector<string> comando) {
    for (auto it: comando) { // armezenar comandos
        int saude = constantesReader("SAnimal");
        int vida = constantesReader("VAnimal");
        char coordX = comando[2][0];
        char coordY = comando[3][0];

        if (it == comando[2]) {

            if (isdigit(coordX) == 0) {
                textInterface << "\nPor favor insira um numero na coordenada!\n" << "\n";
            }

        } else if (it == comando[3]) {
            if (isdigit(coordY) == 0) {
                textInterface << "\nPor favor insira um numero na coordenada!\n" << "\n";
            }

        } else if (it == comando[1]) {
            it = maiscula(it);
            int x = stoi(comando[2]);
            int y = stoi(comando[3]);

            if (verificaCoord(x, y)) {
                if(it == "C"){
                    r->criaAnimal(it, constantesReader("SCoelho"), constantesReader("VCoelho"), x, y);
                }else if(it == "L"){
                    r->criaAnimal(it, constantesReader("SLobo"), constantesReader("VLobo"), x, y);
                }else if(it == "G"){
                    r->criaAnimal(it, constantesReader("SCanguru"), constantesReader("VCanguru"), x, y);
                }else if(it == "O"){
                    r->criaAnimal(it, constantesReader("SOvelha"), constantesReader("VOvelha"), x, y);
                }else if(it == "M"){
                    r->criaAnimal(it, constantesReader("SAnimalM"), constantesReader("VAnimalM"), x, y);
                }

            } else {
                textInterface << "\nPor favor, insira coordenadas validas!" << "\n";
            }
        }
    }
}

void Simulador::cmdCriaAnimalRandom(vector<string> comando) {
    for (auto it: comando) {
        if (it == comando[1]) {
            it = maiscula(it);
            if(it == "C"){
                r->criaAnimalRandom(it, constantesReader("SCoelho"), constantesReader("VCoelho"));
            }else if(it == "L"){
                r->criaAnimalRandom(it, constantesReader("SLobo"), constantesReader("VLobo"));
            }else if(it == "G"){
                r->criaAnimalRandom(it, constantesReader("SCanguru"), constantesReader("VCanguru"));
            }else if(it == "O"){
                r->criaAnimalRandom(it, constantesReader("SOvelha"), constantesReader("VOvelha"));
            }else if(it == "M"){
                r->criaAnimalRandom(it, constantesReader("SAnimalM"), constantesReader("VAnimalM"));
            }
        }
    }
}

void Simulador::cmdSee(vector<string> comando) {
    for (auto it: comando) { // armezenar comandos
        char coordX = comando[1][0];
        char coordY = comando[2][0];
        if (it == comando[1]) {
            if (isdigit(coordX) == 0) {
                textInterface << "\nPor favor insira um numero na coordenada!\n" << "\n";
            }

        } else if (it == comando[2]) {
            if (isdigit(coordY) == 0) {
                textInterface << "\nPor favor insira um numero na coordenada!\n" << "\n";
            }

        }

        int x = stoi(comando[1]);
        int y = stoi(comando[2]);
        buildArea(x, y);
        break;
    }
}

void Simulador::cmdInfo(vector<string> comando) {

    for (auto a: r->getVecAnimal()) {
        if (a->getId() == stoi(comando[1])) {
            textInterface << a->PrintaAnimal();
        }
    }

    for (auto al: r->getVecAlimento()) {
        if (al->getId() == stoi(comando[1])) {
            textInterface << al->PrintaAlimento();
        }
    }
}

void Simulador::cmdCriaAlimento(vector<string> comando) {
    for (auto it: comando) { // armezenar comandos
        char coordX = comando[2][0];
        char coordY = comando[3][0];
        if (it == comando[2]) {
            if (isdigit(coordX) == 0) {
                textInterface << "\nPor favor insira um numero na coordenada!\n" << "\n";
            }
        } else if (it == comando[3]) {
            if (isdigit(coordY) == 0) {
                textInterface << "\nPor favor insira um numero na coordenada!\n" << "\n";
            }

        } else if (it == comando[1]) { // animal \c| 1 1
            it = maiscula(it);
            int x = stoi(comando[2]);
            int y = stoi(comando[3]);
            if (verificaCoord(x, y) && !(r->hasAlimento(x, y)))
                r->criaAlimento(it, x, y);
            else if (verificaCoord(x, y) && r->hasAlimento(x, y)) {
                textInterface << "\nPor favor insira um Alimento em outra coordenada!" << "\n";
                textInterface << "[Alimento ja existe na posicao inserida]" << "\n";
            } else
                textInterface << "\nPor favor insira uma coordenada valida" << "\n";
        }
    }
}

void Simulador::cmdCriaAlimentoRandom(vector<string> comando) {
    for (auto it: comando) {
        if (it == comando[1]) {
            it = maiscula(it);
            r->criaAlimentoRandom(it);
        }
    }
}

void Simulador::cmdAnim() {
    for (int i = 0; i < r->getVecAnimal().size(); i++) {
        textInterface << r->getVecAnimal()[i]->PrintaAnimal();
    }
}

void Simulador::cmdLoad(vector<string> comando) {
    if (leFicheiro(comando[1])) {
        textInterface << "\nFicheiro lido com sucesso!" << "\n";
    } else {
        textInterface << "\nErro! Ficheiro invalido!" << "\n";
    }
}

//Prints "Tabuleiro" e "Zona"
void Simulador::buildArea(int x, int y) {

    if (verificaCoord(x, y)) {
        textInterface << "\nA printar info de x = " << x << " e y = " << y << "\n";
        textInterface << "\nAnimais: " << "\n";
        getInfoAnimal(x, y);
        textInterface << "\nAlimentos: " << "\n";
        getInfoAlimento(x, y);
        textInterface << "\n";
    } else {
        textInterface << "\nPor favor, insira coordenadas validas." << "\n";
    }
}

void Simulador::buildReserva() {
    //Animais *a;
    int linhas = r->getLinhas();
    int colunas = r->getColunas();
    int t = 0;
    int cont = 0;


    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            for (int x = 0; x < r->getVecAnimal().size(); x++) {
                if (r->getVecAnimal()[x]->getX() == i + 1 && r->getVecAnimal()[x]->getY() == j + 1) {
                    reservaPrinter << move_to((r->getVecAnimal()[x]->getX()), r->getVecAnimal()[x]->getY());
                    reservaPrinter << r->getVecAnimal()[x]->getTipoAnimal();
                }
            }
        }
        for (int j = 0; j < colunas; j++) {
            for (int k = 0; k < r->getVecAlimento().size(); k++) {
                if (r->getVecAlimento()[k]->getX() == i + 1 && r->getVecAlimento()[k]->getY() == j + 1) {
                    reservaPrinter << move_to((r->getVecAlimento()[k]->getX()), r->getVecAlimento()[k]->getY());
                    reservaPrinter << r->getVecAlimento()[k]->getTipoAlimento();
                }
            }
        }
    }
}



// Notes
//    if(comando[1] == r->getInfoAnimalId(stoi(comando.at(1)))){
//        cout << r->getInfoAnimalId(stoi(comando.at(1))) << endl;
//    }else{
//        cout << "Id: " << comando[1] << " não existe";
//    }


