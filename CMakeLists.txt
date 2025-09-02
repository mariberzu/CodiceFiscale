cmake_minimum_required(VERSION 3.29)
project(CodiceFiscale VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 26)




add_executable(codice_fiscale
    src/CodiceFiscale.cpp
    src/main.cpp)

target_include_directories(codice_fiscale PRIVATE include)

set(RESOURCE_FILES
    resources/elenco_codici_zone.csv
    resources/codice_controllo_pari.csv
    resources/codice_controllo_dispari.csv
    resources/codice_controllo_resto.csv
)

foreach(RESOURCE ${RESOURCE_FILES})
    configure_file(${CMAKE_SOURCE_DIR}/${RESOURCE} ${CMAKE_BINARY_DIR}/${RESOURCE} COPYONLY)
endforeach()