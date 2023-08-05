cmake_minimum_required(VERSION 3.26)
project(aprendoC C)

set(CMAKE_C_STANDARD 11)

# Añadir la subcarpeta 01_dialogo_con_el_usuario al proyecto
add_subdirectory(src/01_dialogo_con_el_usuario)

# Definir el ejecutable aprendoC después de agregar la subcarpeta
add_executable(aprendoC src/main.c)
