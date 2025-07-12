#include <iostream>
#include "CodiceFiscale.cpp"

using namespace std;

int main()
{
    string cogno;
    string name;
    int ann;
    cout << "Inserisci Cognome: " << endl;
    getline(cin, cogno);
    cout << "Inserisci Nome: " << endl;
    getline(cin,name);
    cout << "Inserisci Anno di Nascita" << endl;
    cin >> ann;


    string x1 = Cognome(cogno);
    string x2 = Nome(name);
    string temp = to_string(ann);
    string x3 = temp.substr(temp.length() - 2);
    cout << "Cognome: " << x1 << endl;
    cout << "Nome: " << x2 << endl;
    cout << "Anno di Nascita: " << x3 << endl;
    string tot = x1+x2+x3;
    cout << tot << endl;

}