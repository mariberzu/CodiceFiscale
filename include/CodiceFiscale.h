#ifndef CODICE_FISCALE_H
#define CODICE_FISCALE_H

#include <string>
#include <vector>
#include <unordered_map>

// Character classification functions
bool isVowel(const char& c);
bool isConsonant(const char& c);
int contaConsonanti(const std::string& st);

// Name processing functions
std::string Cognome(const std::string& cgnm);
std::string Nome(const std::string& nom);

// Birth date processing functions
int AnnoNascita(const int& anno);
std::string MeseNascita(const int& ms);
int GiornoNascita(const int& giorno, const bool& sesso);

// Location processing functions
std::string normalizzaNome(const std::string& nome);
std::string ZonaNascita(const std::string& zona);
std::unordered_map<std::string, std::string> caricaCodici(const std::string& nomeFile);

// Control character calculation functions
std::string caratteriPari(const std::string& cf_temp);
std::string caratteriDispari(const std::string& cf_temp);
std::unordered_map<char, int> caricaMappaControllo(const std::string& nomeFile);
std::vector<int> convertiCaratteri(const std::string& input, const std::unordered_map<char, int>& mappa);
std::unordered_map<int, char> caricaConversione(const std::string& nomeFile);
char trovaCarattere(int numero, const std::unordered_map<int, char>& mappa);
std::string CarattereControllo(const std::string& cf_temp);

// Main function to generate fiscal code
std::string returnCodiceFiscale();

#endif // CODICE_FISCALE_H