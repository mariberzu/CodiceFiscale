//
// Created by Mari on 11/07/2025.
//

#include "CodiceFiscale.h"
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

string Cognome(const string &cgnm)
{
    pmr::vector<char> cogno;
    for(int i=0; i < cgnm.size(); ++i)
    {
        if(isConsonant(cgnm[i]))
        {

        }
    }
}
