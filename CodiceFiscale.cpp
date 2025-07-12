#include <algorithm>
#include <iostream>
#include <cctype>
#include <fstream>
#include <sstream>
#include <unordered_map>
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

int AnnoNascita(const int &anno) {
    int res = anno % 10;
    return res;
}

string MeseNascita(const int &ms) {
    char res;
    if(ms<1 || ms>12) return "null";

    switch (ms) {
        case 1:
            res = 'A';
        break;
        case 2:
            res = 'B';
        break;
        case 3:
            res = 'C';
        break;
        case 4:
            res = 'D';
        break;
        case 5:
            res = 'E';
        break;
        case 6:
            res = 'H';
        break;
        case 7:
            res = 'L';
        break;
        case 8:
            res = 'M';
        break;
        case 9:
            res = 'P';
        break;
        case 10:
            res = 'R';
        break;
        case 11:
            res = 'S';
        break;
        case 12:
            res = 'T';
        break;
        default:
            res = 'X';
        break;
    }
    string res_s(1,res);
    return res_s;
}

int GiornoNascita(const int &giorno, const bool &sesso) {
    if(giorno<1 || giorno >31) return 0;
    int res = 0;
    //SE UOMO
    if(sesso==1) {
        res = giorno;
    }
    else if(sesso==0) {
        res = giorno+40;
    }
    return res;
}

unordered_map<string, string> caricaCodici(const string& nomeFile) {
    unordered_map<string, string> codici;
    ifstream file(nomeFile);
    if(!file.is_open()) {
        cerr << "Errore: impossibile aprire il file " << nomeFile << endl;
        return codici;
    }

    string riga;

    while (getline(file, riga)) {
        istringstream ss(riga);
        string nomeLocalita, codice;
        if (getline(ss, nomeLocalita, ',') && getline(ss, codice)) {
            codici[nomeLocalita] = codice;
        }
    }
    return codici;
}

string normalizzaNome(const string& nome) {
    if (nome.empty()) return nome;
    string risultato = nome;
    transform(risultato.begin(), risultato.end(), risultato.begin(), ::tolower);
    risultato[0] = ::toupper(risultato[0]);
    return risultato;
}

string ZonaNascita(const string& zona) {
    auto codici = caricaCodici("elenco_codici_zone.csv");
    string localita = normalizzaNome(zona);

    auto it = codici.find(localita);
    if (it != codici.end()) {
        return it->second;
    } else {
        return "ND";
    }
}
