
#include "util.h"
#include "Simulador.h"

int main() {

    Simulador s(new Reserva());
    s.runInterface();

    return 0;
}
