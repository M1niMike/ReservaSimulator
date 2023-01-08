cmake_minimum_required(VERSION 3.20)
project(POO_TP_22_23)

set(CMAKE_CXX_STANDARD 14)

add_executable(POO_TP_22_23 main.cpp Reserva.cpp Reserva.h Alimentos.cpp Alimentos.h Animais.cpp Animais.h Simulador.cpp Simulador.h util.h Terminal.cpp Terminal.h curses.h TipoAnimais/Coelho.cpp TipoAnimais/Coelho.h TipoAnimais/Lobo.cpp TipoAnimais/Lobo.h TipoAnimais/Ovelha.cpp TipoAnimais/Ovelha.h TipoAnimais/Canguru.cpp TipoAnimais/Canguru.h TipoAnimais/AnimalMisterioso.cpp TipoAnimais/AnimalMisterioso.h TipoAlimentos/Relva.cpp TipoAlimentos/Relva.h TipoAlimentos/Cenoura.cpp TipoAlimentos/Cenoura.h TipoAlimentos/Corpo.cpp TipoAlimentos/Corpo.h TipoAlimentos/Bife.cpp TipoAlimentos/Bife.h TipoAlimentos/AlimentoMisterioso.cpp TipoAlimentos/AlimentoMisterioso.h Historico.cpp Historico.h)

target_link_libraries(${PROJECT_NAME} C:/ISEC/1Semestre/POO/TP/PDCurses-3.9/PDCurses-3.9/wincon/pdcurses.a)
