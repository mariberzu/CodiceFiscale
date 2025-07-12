#include <iostream>
#include "CodiceFiscale.cpp"

using namespace std;

int main()
{
    string cogno;
    cout << "Inserisci Cognome" << endl;
    getline(cin, cogno);

    int x2 = contaConsonanti(cogno);
    int x1 = cogno.size() - x2;

    cout << "Vocali: " << x1 << endl;
    cout << "Consonanti: " << x2 << endl;

    string x3 = Cognome(cogno);
    cout << x3 << endl;

}