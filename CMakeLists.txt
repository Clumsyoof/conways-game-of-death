cmake_minimum_required(VERSION 3.31.11)
project(Conwaygameofdeath)
add_compile_options(-O3 -march=native -Wall -Wextra)
find_package(raylib REQUIRED)
add_executable(Conwaygameofdeath main.c++ gen.c++ cell.c++)
target_link_libraries(Conwaygameofdeath 
    PRIVATE 
    raylib 
    GL 
    m 
    pthread 
    dl 
    rt 
    X11
)
