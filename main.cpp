
#include "util.h"
#include "Simulador.h"
#include "Terminal.h"

using namespace term;

int main() {

    Terminal &t = Terminal::instance();
    Simulador s(new Reserva(), t);
    s.runInterface();
    return 0;
}
