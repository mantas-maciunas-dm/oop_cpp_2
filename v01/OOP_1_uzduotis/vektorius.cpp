#include "build_lib.h"
#include "studentas.h";
#include "ivedimas_isvedimas.h";
#include "vidurkiai.h";
#include "rusiavimas.h";
#include "failu_generavimas.h";
#include "studentu_isskirstymas.h";


int main()
{
    int studentu_skaicius = 1000;
    for(int i = 0; i < 5; i++)
    {
        auto viso_matavimo_pradzia = high_resolution_clock::now();
        failo_sukurimas(studentu_skaicius);
        vector<studentas> masyvas;
        int pazymiu_skaicius;
        ivedimas(masyvas, "kursiokai" + to_string(studentu_skaicius) + ".txt", &pazymiu_skaicius);
        if (masyvas.size() == 0)
        {
            cout << "Pradiniu duomenu masyvas tuscias." << endl;
        }

        else
        {
            string vardas = "Vardas";
            string pavarde = "Pavarde";
            string galutinis_med = "Galutinis(Med.)";
            string galutinis_vid = "Galutinis(Vid.)";
            auto matavimo_pradzia = high_resolution_clock::now();

            vector<studentas> nelaimeliai_stud;
            vector<studentas> kieti_stud;

            for (int i = 0; i < masyvas.size(); i++)
            {
                studentas dab_stud = masyvas[i];
                galutinio_skaiciavimas_vid(dab_stud);
                galutinio_skaiciavimas_med(dab_stud);

                if (nelaimeliu_suradimas(dab_stud))
                    nelaimeliai_stud.push_back(dab_stud);
                else
                    kieti_stud.push_back(dab_stud);
            }

            auto matavimo_pabaiga = high_resolution_clock::now();
            duration<double> skirtumas = matavimo_pabaiga - matavimo_pradzia;
            cout << "Studentu suskirstymas uztruko: " << skirtumas.count() << "s" << endl;

            isvedimas("kieti" + to_string(studentu_skaicius) + ".txt", kieti_stud);
            isvedimas("nelaimeliai" + to_string(studentu_skaicius) + ".txt", nelaimeliai_stud);

            auto viso_matavimo_pabaiga = high_resolution_clock::now();
            duration<double> viso_skirtumas = viso_matavimo_pabaiga - viso_matavimo_pradzia;
            cout << "\nTestas su " << studentu_skaicius << " studentu uztruko: " << viso_skirtumas.count() << "s" << endl;

            studentu_skaicius *= 10;
        }

        cout << endl;
    }
}
