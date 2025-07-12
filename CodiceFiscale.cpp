
#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool isVowel(const char &c)
{
    if(
        c == 'a' ||
        c == 'e' ||
        c == 'i' ||
        c == 'o' ||
        c == 'u' ||
        c == 'A' ||
        c == 'E' ||
        c == 'I' ||
        c == 'O' ||
        c == 'U'
        )
    {
        return true;
    }
    else
    {
        return false;
    }
}
bool isConsonant(const char &c)
{
    if(!isVowel(c))
    {
        return true;
    }
    else
    {
        return false;
    }
}
int contaConsonanti(const string &st) {
    int n = 0;
    for(char i : st) {
        if(isConsonant(i)) {
            ++n;
        }
    }
    return n;
}

string Cognome(const string &cgnm)
{

    vector<char> vectCogno;
    for(int i=0; i < cgnm.size(); ++i)
    {
        if(isConsonant(cgnm[i]) && vectCogno.size() <3)
        {
            vectCogno.push_back(cgnm[i]);
        }
    }

    if(vectCogno.size()<=2) {
        for(int i=0; i < cgnm.size(); ++i)
        {
            if(!isConsonant(cgnm[i]) && vectCogno.size() <3)
            {
                vectCogno.push_back(cgnm[i]);
            }
        }
        while(vectCogno.size()<3) {
            if(vectCogno.size()<3) {
                vectCogno.push_back('X');
            }
        }

    }


    /*for(int i = 0; i<cogno.size(); ++i) {
        cout << cogno[i] << " ";
    }*/

    string s(vectCogno.begin(), vectCogno.end());
    return s;
}

string Nome(const string &nom) {
    vector<char> vectNom;
    vector<char> vectNom_def;

    //IDENTIFICAZIONE DELLE CONSONANTI ED AGGIUNTA AL VETTORE VECTNOM;
    for(int i=0; i < nom.size(); ++i)
    {
        if(isConsonant(nom[i]))
        {
            vectNom.push_back(nom[i]);
        }
    }

    //SE SONO PIù DI 4 SCELGO SOLO LA 1, 3, 4;
    if(vectNom.size()>=4) {
        vector<int> cc = {vectNom[0], vectNom[2], vectNom[3]};
        vectNom.clear();
        vectNom.assign(cc.begin(), cc.end());
    }
    //SE SONO MENO DI 3 RIEMPIO CON VOCALI, SE NON CI SONO RIEMPIO CON 'X';
    if(vectNom.size()<=2) {
        for(int i=0; i < nom.size(); ++i)
        {
            if(!isConsonant(nom[i]) && vectNom.size() <3)
            {
                vectNom.push_back(nom[i]);
            }
        }
        while(vectNom.size()<3) {
            if(vectNom.size()<3) {
                vectNom.push_back('X');
            }
        }

    }




    string s(vectNom.begin(),vectNom.end());
    return s;
}
