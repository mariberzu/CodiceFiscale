#ifndef CODICE_FISCALE_H
#define CODICE_FISCALE_H

#include <string>
#include <vector>
#include <unordered_map>

//FUNZIONE CHE CONTROLLA SE UN CARATTERE È UNA VOCALE
bool isVowel(const char& c);

//FUNZIONE CHE CONTA LE CONSONANTI
int contaConsonanti(const std::string& st);

//GESTIONE DEL COGNOME
std::string Cognome(const std::string& cgnm);

//GESTIONE DEL NOME
std::string Nome(const std::string& nom);

//GESTIONE DELL'ANNO DI NASCITA
int AnnoNascita(const int& anno);

//GESTIONE MESE DI NASCITA
std::string MeseNascita(const int& ms);

//GESTIONE DEL GIORNO DI NASCITA
int GiornoNascita(const int& giorno, const bool& sesso);

//FUNZIONE CHE NORMALIZZA IL NOME DELLA LOCALITÀ
std::string normalizzaNome(const std::string& nome);

//GESTIONE DELLA ZONA DI NASCITA
std::string ZonaNascita(const std::string& zona);

//FUNZIONE DI CARICAMENTO DEI CODICI DELLE LOCALITA' DA FILE CSV
std::unordered_map<std::string, std::string> caricaCodici(const std::string& nomeFile);

// Control character calculation functions
std::string caratteriPari(const std::string& cf_temp);

//FUNZIONE CHE OTTIENE I CARATTERI IN POSIZIONE DISPARI
std::string caratteriDispari(const std::string& cf_temp);

//FUNZIONE DI CARICAMENTO DELLA MAPPA DI CONTROLLO
std::unordered_map<char, int> caricaMappaControllo(const std::string& nomeFile);

//FUNZIONE CHE CONVERTE I CARATTERI IN VALORI
std::vector<int> convertiCaratteri(const std::string& input, const std::unordered_map<char, int>& mappa);

//FUNZIONE CHE CARICA LA MAPPA PER LA CONVERSIONE DEL RESTO
std::unordered_map<int, char> caricaConversione(const std::string& nomeFile);

//FUNZIONE CHE TROVA IL CARATTERE CORRISPONDENTE AL RESTO
char trovaCarattere(int numero, const std::unordered_map<int, char>& mappa);

//FUNZIONE PER IL CALCOLO DEL CARATTERE DI CONTROLLO
std::string CarattereControllo(const std::string& cf_temp);

//FUNZIONE PRINCIPALE PER GENERARE IL CODICE FISCALE
std::string returnCodiceFiscale();

#endif // CODICE_FISCALE_H