#include "build_lib.h"
#include "studentas.h";
#include "ivedimas_isvedimas.h";
#include "vidurkiai.h";
#include "rusiavimas.h";


int main() {
    vector<studentas> masyvas;
    ivedimas(masyvas);
    srand((unsigned) time(0));

    if (masyvas.size() == 0)
    {
        cout << "Pradiniu duomenu masyvas tuscias." << endl;
    }

    else
    {
        cout << "Pradiniai duomenys:" << endl;
        for (int i = 0; i < masyvas.size(); i++)
        {
            isvedimas(masyvas[i]);
        }
        cout << endl;

        string vardas = "Vardas";
        string pavarde = "Pavarde";
        string galutinis_med = "Galutinis(Med.)";
        string galutinis_vid = "Galutinis(Vid.)";

        rusiavimas(masyvas);
        cout << "Rezultatai, suskaiciavus galutini bala tiek mediana, tiek vidurkiu:" << endl;
        printf("|%-20s|%-20s|%20s|%20s|\n", vardas.c_str(), pavarde.c_str(), galutinis_med.c_str(), galutinis_vid.c_str());
        for (int i = 0; i < masyvas.size(); i++)
        {
            galutinio_skaiciavimas_vid(masyvas[i]);
            galutinio_skaiciavimas_med(masyvas[i]);
            printf("|%-20s|%-20s|%20.2f|%20.2f|\n", masyvas[i].vardas.c_str(), masyvas[i].pavarde.c_str(), masyvas[i].galutinis_med, masyvas[i].galutinis_vid);
        }
    }
}