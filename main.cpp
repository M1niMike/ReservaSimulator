
#include "util.h"
#include "Simulador.h"
#include "Terminal.h"

using namespace term;

int main() {

    Terminal &t = Terminal::instance();
    Reserva* reserva = new Reserva();
    Simulador* simulador = new Simulador(reserva, t);
    reserva = simulador->menuSimulador();


    delete reserva;
    delete simulador;

    return 0;
}
