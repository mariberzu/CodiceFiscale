
#include "CodiceFiscale.h"
#include <iostream>


int main()
{
    
    std::string cfinale = returnCodiceFiscale();
    std::cout << "Codice Fiscale: " << cfinale << std::endl;

    return 0;
}