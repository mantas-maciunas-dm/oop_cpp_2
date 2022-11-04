#include "build_lib.h"
#include "studentas.h";
#include "ivedimas_isvedimas.h";
#include "vidurkiai.h";
#include "rusiavimas.h";
#include "failu_generavimas.h";
#include "studentu_isskirstymas.h";


int main()
{
    char pasirinkimas = '-';
    cout << "Pasirinkite, ar norite sukurti faila(iveskite 'f') ar dirbti su failu(bet koks kitas simbolis): ";
    cin >> pasirinkimas;
    cout << endl;

    if (pasirinkimas == 'f')
    {
        failo_sukurimas(1000);
        failo_sukurimas(10000);
        failo_sukurimas(100000);
        failo_sukurimas(1000000);
        failo_sukurimas(10000000);
    }

    else
    {
        int studentu_skaicius = 1000;

        for (int i = 0; i < 5; i++)
        {
            auto viso_matavimo_pradzia_vector = high_resolution_clock::now();
            vector<studentas> vektorius;
            int pazymiu_skaicius;
            ivedimas_vector(vektorius, "kursiokai" + to_string(studentu_skaicius) + ".txt", &pazymiu_skaicius);
            if (vektorius.size() == 0)
            {
                cout << "Pradiniu duomenu vektorius tuscias." << endl;
            }

            else
            {
                string vardas = "Vardas";
                string pavarde = "Pavarde";
                string galutinis_med = "Galutinis(Med.)";
                string galutinis_vid = "Galutinis(Vid.)";
                auto matavimo_pradzia_vector = high_resolution_clock::now();

                vector<studentas> nelaimeliai_stud_vector;
                vector<studentas> kieti_stud_vector;

                for (auto& kint : vektorius)
                {
                    galutinio_skaiciavimas_vid(kint);
                    galutinio_skaiciavimas_med(kint);

                    if (nelaimeliu_suradimas(kint))
                    {
                        nelaimeliai_stud_vector.push_back(kint);
                    }
                    else
                    {
                        kieti_stud_vector.push_back(kint);
                    }
                }
                vektorius.clear();

                auto matavimo_pabaiga_vector = high_resolution_clock::now();
                duration<double> skirtumas_vector = matavimo_pabaiga_vector - matavimo_pradzia_vector;
                cout << "Studentu suskirstymas uztruko: " << skirtumas_vector.count() << "s" << endl;

                //isvedimas_vector("kieti" + to_string(studentu_skaicius) + "_vector.txt", kieti_stud_vector);
                //isvedimas_vector("nelaimeliai" + to_string(studentu_skaicius) + "_vector.txt", nelaimeliai_stud_vector);

                auto viso_matavimo_pabaiga_vector = high_resolution_clock::now();
                duration<double> viso_skirtumas_vector = viso_matavimo_pabaiga_vector - viso_matavimo_pradzia_vector;
                cout << "\nTestas su " << studentu_skaicius << " studentu naudojant std::vector uztruko: " << viso_skirtumas_vector.count() << "s" << endl;

                cout << endl;
            }

            auto viso_matavimo_pradzia_list = high_resolution_clock::now();
            list<studentas> listas;
            ivedimas_list(listas, "kursiokai" + to_string(studentu_skaicius) + ".txt", &pazymiu_skaicius);
            if (listas.size() == 0)
            {
                cout << "Pradiniu duomenu listas tuscias." << endl;
            }

            else
            {
                string vardas = "Vardas";
                string pavarde = "Pavarde";
                string galutinis_med = "Galutinis(Med.)";
                string galutinis_vid = "Galutinis(Vid.)";
                auto matavimo_pradzia_list = high_resolution_clock::now();

                list<studentas> nelaimeliai_stud_list;
                list<studentas> kieti_stud_list;

                for (auto& kint : listas)
                {
                    galutinio_skaiciavimas_vid(kint);
                    galutinio_skaiciavimas_med(kint);

                    if (nelaimeliu_suradimas(kint))
                    {
                        nelaimeliai_stud_list.push_back(kint);
                    }
                    else
                    {
                        kieti_stud_list.push_back(kint);
                    }
                }
                listas.clear();

                auto matavimo_pabaiga_list = high_resolution_clock::now();
                duration<double> skirtumas_list = matavimo_pabaiga_list - matavimo_pradzia_list;
                cout << "Studentu suskirstymas uztruko: " << skirtumas_list.count() << "s" << endl;

                //isvedimas_list("kieti" + to_string(studentu_skaicius) + "_list.txt", kieti_stud_list);
                //isvedimas_list("nelaimeliai" + to_string(studentu_skaicius) + "_list.txt", nelaimeliai_stud_list);

                auto viso_matavimo_pabaiga_list = high_resolution_clock::now();
                duration<double> viso_skirtumas_list = viso_matavimo_pabaiga_list - viso_matavimo_pradzia_list;
                cout << "\nTestas su " << studentu_skaicius << " studentu naudojant std::list uztruko: " << viso_skirtumas_list.count() << "s" << endl;

                cout << endl;
            }

            studentu_skaicius *= 10;
            cout << endl << endl;
        }
    }
}
