#include "Simulador.h"
#include "util.h"

Simulador::Simulador(Reserva *r, Terminal &t) : r(r), t(t), cmdW(0, 35, 112, 20), textInterface(113, 0, 112, 55),
                                                reservaPrinter(0, 0, 10, 10) {}


Reserva* Simulador::menuSimulador() {

    int linhas = 0;
    int colunas = 0;
    string choice;
    string cmd;
    string aux;
    string coord;

    leFicheiroConstantes("constantes.txt");

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

        textInterface << "\nInstante da Reserva: " << r->getInstantes();
        textInterface << "\nNumero de Animais na Reserva: " << r->getNumberOfAnimals();
        textInterface << "\nNumero de Alimentos na Reserva: " << r->getNumberOfFood();
        textInterface << "\nNumero total de coisas na Reserva: " << r->getNumberOfAnimals() + r->getNumberOfFood();
        textInterface << "\n";

        //cmdW.clear();
        //textInterface.clear();
    }

    return r;
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
        mapaConstantes[aux] = valor;
    }

    file.ignore('\n');

    return true;
}

int Simulador::constantesReader(string aux) {
    for (auto it: mapaConstantes) {
        if (mapaConstantes.find(aux) != mapaConstantes.end()) {
            return mapaConstantes[aux];
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

void Simulador::cmdStore(vector<string> comando) {
    for (auto it: comando) {
        string nomeSave = comando[1]; // ir buscar o nome do "save" que o user meteu

        if(it == comando[1]){
            if (mapaSave.find(nomeSave) != mapaSave.end()) {
                textInterface << "\nJa existe um store com esse nome, por favor insira outro.\n";
                return;
            }

            Reserva *temp = new Reserva(*r);

            mapaSave.insert(std::pair<string, Reserva*>(nomeSave, temp));
            textInterface << "\nReserva guardada com sucesso\n";
        }
    } //ver melhor esta parte
}

void Simulador::cmdRestore(vector<string> comando) {
    for (auto it : comando) {
        string nomeRestore = comando[1];

        textInterface << comando[1];

        if (it == comando[1]){
            if (mapaSave.find(nomeRestore) != mapaSave.end()) {
                delete r; //apagar onde estamos agora
                r = (mapaSave.find(nomeRestore)->second); //o second vai buscar a segunda "chavE" do mapa, ou seja, o Reserva* e carrega-o

                textInterface << "\n A sua gravacao: " << nomeRestore << " foi restaurada com sucesso!\n";
                return;
            } // se ele encontrar o nome antes de chegar ao fim do mapa
        }
    }
    textInterface << "\nNao encontrei o nome que inseriu...\n";
}

void Simulador::cmdN(vector<string> comando){
    r->incrementaInstante();
}

void Simulador::cmdNPause(vector<string> comando){

}

void Simulador::cmdNN(vector<string> comando){
    r->incrementaInstante(stoi(comando[1]));

    for(int i = 0; i < r->getInstantes(); i++){
        textInterface << "\nInstante:" << i+1;
        textInterface << "AQUI\n";
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
        cmdN(cmdVector);
    }
    else if (tipoComando == "n" && cmdVector.size() == 2)
    {
        cmdNN(cmdVector);
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
        cmdStore(cmdVector);
    }
    else if (tipoComando == "restore" && cmdVector.size() == 2)
    {
        cmdRestore(cmdVector);
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


