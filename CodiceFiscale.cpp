
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


