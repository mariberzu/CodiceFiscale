#include <iostream>
#include "CodiceFiscale.cpp"

using namespace std;

int main()
{
    string cogno;
    string name;
    cout << "Inserisci Cognome: " << endl;
    getline(cin, cogno);
    cout << "Inserisci Nome: " << endl;
    getline(cin,name);


    string x1 = Cognome(cogno);
    string x2 = Nome(name);
    cout << "Cognome: " << x1 << endl;
    cout << "Nome: " << x2 << endl;

}