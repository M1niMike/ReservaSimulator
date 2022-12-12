cmake_minimum_required(VERSION 3.20)
project(POO_TP_22_23)

set(CMAKE_CXX_STANDARD 14)

add_executable(POO_TP_22_23 main.cpp Reserva.cpp Reserva.h Alimentos.cpp Alimentos.h Animais.cpp Animais.h Simulador.cpp Simulador.h util.h Terminal.cpp Terminal.h curses.h)

target_link_libraries(${PROJECT_NAME} C:/ISEC/1Semestre/POO/TP/PDCurses-3.9/PDCurses-3.9/wincon/pdcurses.a)
