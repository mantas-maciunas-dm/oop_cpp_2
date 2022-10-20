#pragma once
#include "build_lib.h";
#include "studentas.h";

unsigned int Zodziai_eiluteje(string const& str);
void ivedimas(vector<studentas>& studentai, string failo_pavadinimas, int *nd_skaicius);
void isvedimas(studentas temp);
void isvedimas(string failo_pav, vector<studentas> vektorius);
int skaiciaus_patikrinimas(string zinute, bool check);