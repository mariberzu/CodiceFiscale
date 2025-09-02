#include "CodiceFiscale.h"
#include <algorithm>
#include <iostream>
#include <cctype>
#include <fstream>
#include <sstream>
#include <unordered_set>


using std::cin, std::cout, std::endl, std::string, std::vector, std::unordered_map,std::unordered_set, std::ifstream, std::istringstream, std::cerr, std::transform, std::to_string;

// FUNZIONE PER VERIFICARE SE UN CARATTERE È UNA VOCALE
bool vocale(const char& c) {
	static const unordered_set<char> vocali =
	{ 'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U' };
	return vocali.contains(c);
}

//FUNZIONE PER CONTARE LE CONSONANTI
int contaConsonanti(const std::string &st) {
	int n = 0;
	for (char i: st) {
		if (!vocale(i)) {
			++n;
		}
	}
	return n;
}

//GESTIONE DEL COGNOME
string Cognome(const string& cgnm) {
	vector<char> vectCogno;
	for (int i = 0; i < cgnm.size(); ++i) {
		if (!vocale(cgnm[i]) && vectCogno.size() < 3) {
			vectCogno.push_back(cgnm[i]);
		}
	}

	if (vectCogno.size() <= 2) {
		for (int i = 0; i < cgnm.size(); ++i) {
			if (vocale(cgnm[i]) && vectCogno.size() < 3) {
				vectCogno.push_back(cgnm[i]);
			}
		}
		while (vectCogno.size() < 3) {
			if (vectCogno.size() < 3) {
				vectCogno.push_back('X');
			}
		}
	}

	string s(vectCogno.begin(), vectCogno.end());
	return s;
}

//GESTIONE DEL NOME
string Nome(const string &nom) {
	//RIMOZIONE SPAZI
	string processedName;
	copy_if(nom.begin(), nom.end(), back_inserter(processedName), 
			[](char c) { return !isspace(c); });
	
	vector<char> vectNom;
	vector<char> vectNom_def;

	//IDENTIFICAZIONE DELLE CONSONANTI ED AGGIUNTA AL VETTORE VECTNOM;
	for (int i = 0; i < processedName.size(); ++i) {
		if (!vocale(processedName[i])) {
			vectNom.push_back(processedName[i]);
		}
	}

	//SE SONO PIù DI 4 SCELGO SOLO LA 1, 3, 4;
	if (vectNom.size() >= 4) {
		vector<int> cc = {vectNom[0], vectNom[2], vectNom[3]};
		vectNom.clear();
		vectNom.assign(cc.begin(), cc.end());
	}
	//SE SONO MENO DI 3 RIEMPIO CON VOCALI, SE NON CI SONO RIEMPIO CON 'X';
	if (vectNom.size() <= 2) {
		for (int i = 0; i < processedName.size(); ++i) {
			if (vocale(processedName[i]) && vectNom.size() < 3) {
				vectNom.push_back(processedName[i]);
			}
		}
		while (vectNom.size() < 3) {
			if (vectNom.size() < 3) {
				vectNom.push_back('X');
			}
		}
	}

	string s(vectNom.begin(), vectNom.end());
	return s;
}

//GESTIONE DELL'ANNO DI NASCITA	
int AnnoNascita(const int &anno) {
	int res = anno % 10;
	return res;
}

//MAPPATURA DEI MESI
std::unordered_map<int,string> mesi = {
	{1, "A"}, {2, "B"}, {3, "C"}, {4, "D"},
	{5, "E"}, {6, "H"}, {7, "L"}, {8, "M"},
	{9, "P"}, {10, "R"}, {11, "S"}, {12, "T"}
};

//TRANSFORMAZIONE DEL MESE IN LETTERA
string MeseNascita(const int &ms) {
	char res;
	if (ms < 1 || ms > 12) return "null";

	mesi.find(ms) != mesi.end() ? res = mesi[ms][0] : res = 'X';
	string res_s(1, res);
	return res_s;
}

//GESTIONE DEL GIORNO DI NASCITA
int GiornoNascita(const int &giorno, const bool &sesso) {
	if (giorno < 1 || giorno > 31) return 0;
	int res = 0;
	//SE UOMO
	if (sesso == 1) {
		res = giorno;
	} else if (sesso == 0) {
		res = giorno + 40;
	}
	return res;
}

// CARICAMENTO DEI CODICI DELLE LOCALITA' DA FILE CSV
unordered_map<string, string> caricaCodici(const string &nomeFile) {
	unordered_map<string, string> codici;
	ifstream file(nomeFile);
	if (!file.is_open()) {
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

// NORMALIZZAZIONE DEL NOME DELLA LOCALITA'
string normalizzaNome(const string &nome) {
	if (nome.empty()) return nome;
	string risultato = nome;
	transform(risultato.begin(), risultato.end(), risultato.begin(), ::tolower);
	risultato[0] = ::toupper(risultato[0]);
	return risultato;
}

// GESTIONE DELLA ZONA DI NASCITA
string ZonaNascita(const string &zona) {
	auto codici = caricaCodici("resources/elenco_codici_zone.csv");
	string localita = normalizzaNome(zona);

	auto it = codici.find(localita);
	if (it != codici.end()) {
		return it->second;
	} else {
		return "ND";
	}
}

// GESTIONE DEI CARATTERI PARI 
string caratteriPari(const string &cf_temp) {
	vector<char> stringa_pari;
	for (int i = 0; i < cf_temp.size(); ++i) {
		if (i % 2 == 1) {
			stringa_pari.push_back(cf_temp[i]);
		}
	}
	string spari(stringa_pari.begin(), stringa_pari.end());
	return spari;
}

// GESTIONE DEI CARATTERI DISPARI
string caratteriDispari(const string &cf_temp) {
	vector<char> stringa_dispari;
	for (int i = 0; i < cf_temp.size(); ++i) {
		if (i % 2 == 0) {
			stringa_dispari.push_back(cf_temp[i]);
		}
	}
	string sdispari(stringa_dispari.begin(), stringa_dispari.end());
	return sdispari;
}

//CONVERSIONE PER CODICE DI CONTROLLO
unordered_map<char, int> caricaMappaControllo(const string &nomeFile) {
	unordered_map<char, int> mappa;
	ifstream file(nomeFile);
	string riga;
	if (!file.is_open()) {
		cerr << "Errore: impossibile aprire il file " << nomeFile << endl;
		return mappa;
	}

	while (getline(file, riga)) {
		istringstream ss(riga);
		string carattereStr, valoreStr;
		if (getline(ss, carattereStr, ',') && getline(ss, valoreStr)) {
			if (!carattereStr.empty()) {
				char chiave = carattereStr[0];
				int valore = stoi(valoreStr);
				mappa[chiave] = valore;
			}
		}
	}
	return mappa;
}

// CONVERSIONE DEI CARATTERI IN VALORI
vector<int> convertiCaratteri(const string &input, const unordered_map<char, int> &mappa) {
	vector<int> valori;
	for (char c: input) {
		auto it = mappa.find(c);
		if (it != mappa.end()) {
			valori.push_back(it->second);
		} else {
			valori.push_back(-1);
		}
	}
	return valori;
}

// CARICAMENTO DELLA MAPPATURA PER LA CONVERSIONE DEL RESTO
unordered_map<int, char> caricaConversione(const string &nomeFile) {
	unordered_map<int, char> mappa;
	ifstream file(nomeFile);
	string riga;
	if (!file.is_open()) {
		cerr << "Errore: impossibile aprire il file " << nomeFile << endl;
		return mappa;
	}
	while (getline(file, riga)) {
		istringstream ss(riga);
		string valoreStr, carattereStr;
		if (getline(ss, valoreStr, ',') && getline(ss, carattereStr)) {
			if (!valoreStr.empty()) {
				int valore = stoi(valoreStr);
				char carattere = carattereStr[0];
				mappa[valore] = carattere;
			}
		}
	}
	return mappa;
}

// TROVA IL CARATTERE CORRISPONDENTE AL RESTO
char trovaCarattere(int numero, const unordered_map<int, char> &mappa) {
	auto it = mappa.find(numero);
	if (it != mappa.end()) {
		return it->second;
	} else {
		return '?';
	}
}

// CALCOLO DEL CARATTERE DI CONTROLLO
string CarattereControllo(const string &cf_temp) {
	string spari = caratteriPari(cf_temp);
	string sdispari = caratteriDispari(cf_temp);

	auto mappaPari = caricaMappaControllo("resources/codice_controllo_pari.csv");
	auto mappaDispari = caricaMappaControllo("resources/codice_controllo_dispari.csv");

	vector<int> valoriPari = convertiCaratteri(spari, mappaPari);
	vector<int> valoriDispari = convertiCaratteri(sdispari, mappaDispari);

	int sommaTot = 0;
	for (int v = 0; v < valoriPari.size(); ++v) {
		sommaTot = sommaTot + valoriPari[v];
	}
	for (int v = 0; v < valoriDispari.size(); ++v) {
		sommaTot = sommaTot + valoriDispari[v];
	}


	int resto = sommaTot % 26;
	auto mappaConversione = caricaConversione("resources/codice_controllo_resto.csv");
	char carattereFinale = trovaCarattere(resto, mappaConversione);
	string ccfinale(1, carattereFinale);
	return ccfinale;
}

// FUNZIONE PRINCIPALE PER GENERARE IL CODICE FISCALE
string returnCodiceFiscale() {
	string cogno;
	string name;
	string zona;
	bool sesso;
	int mese;
	int giorno;
	int ann;
	cout << "Inserisci Cognome: " << endl;
	getline(cin, cogno);
	transform(cogno.begin(), cogno.end(), cogno.begin(), ::toupper);
	cout << "Inserisci Nome: " << endl;
	getline(cin, name);
	transform(name.begin(), name.end(), name.begin(), ::toupper);
	cout << "Inserisci Anno di Nascita: " << endl;
	cin >> ann;
	cout << "Inserisci Mese di Nascita (1-12): " << endl;
	cin >> mese;
	cout << "Inserisci Giorno di Nascita (1-31): " << endl;
	cin >> giorno;
	cout << "Inserisci Sesso (1=Maschile/0=Femminile): " << endl;
	cin >> sesso;
	cin.ignore();
	cout << "Inserisci Comune di Nascita: " << endl;
	getline(cin, zona);
	zona = normalizzaNome(zona);


	string x1 = Cognome(cogno);
	string x2 = Nome(name);
	string temp = to_string(ann);
	string x3 = temp.substr(temp.length() - 2);
	string x4 = MeseNascita(mese);
	string x5 = to_string(GiornoNascita(giorno, sesso));
	string x6 = ZonaNascita(zona);
	string tot = x1 + x2 + x3 + x4 + x5 + x6;
	string x7 = CarattereControllo(tot);

	string cf_finale = x1 + x2 + x3 + x4 + x5 + x6 + x7;
	return cf_finale;
}