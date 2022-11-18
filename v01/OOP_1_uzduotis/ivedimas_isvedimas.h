#pragma once
#include "build_lib.h"
#include "studentas.h"

unsigned int Zodziai_eiluteje(string const& str);
void ivedimas_vector(vector<studentas>& studentai, string failo_pavadinimas, int* nd_skaicius);
void ivedimas_list(list<studentas>& studentai, string failo_pavadinimas, int* nd_skaicius);
void isvedimas_vector(string failo_pav, vector<studentas> vektorius);
void isvedimas_list(string failo_pav, list<studentas> sarasas);
int skaiciaus_patikrinimas(string zinute, bool check);
