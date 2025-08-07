cmake_minimum_required(VERSION 3.29)
project(untitled2)

set(CMAKE_CXX_STANDARD 26)

add_executable(
    CodiceFiscale.cpp
    src/main.cpp
)


configure_file(${CMAKE_SOURCE_DIR}/resources/elenco_codici_zone.csv ${CMAKE_BINARY_DIR}/elenco_codici_zone.csv COPYONLY)
configure_file(${CMAKE_SOURCE_DIR}/resources/codice_controllo_pari.csv ${CMAKE_BINARY_DIR}/codice_controllo_pari.csv COPYONLY)
configure_file(${CMAKE_SOURCE_DIR}/resources/codice_controllo_dispari.csv ${CMAKE_BINARY_DIR}/codice_controllo_dispari.csv COPYONLY)
configure_file(${CMAKE_SOURCE_DIR}/resources/codice_controllo_resto.csv ${CMAKE_BINARY_DIR}/codice_controllo_resto.csv COPYONLY)