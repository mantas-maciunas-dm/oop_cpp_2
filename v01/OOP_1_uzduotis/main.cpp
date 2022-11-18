#include "build_lib.h"
#include "studentas.h"
#include "ivedimas_isvedimas.h"
#include "vidurkiai.h"
#include "rusiavimas.h"
#include "failu_generavimas.h"
#include "studentu_isskirstymas.h"


int main()
{
    int studentu_skaicius = 1000;

    cout << "Pirmoji strategija(dvieju nauju vektoriu/list'u sukurimas)\n\n";

    for (int i = 0; i < 5; i++)
    {
        auto viso_matavimo_pradzia_vector_pirmas = high_resolution_clock::now();
        vector<studentas> vektorius_pirmas;
        int pazymiu_skaicius_pirmas;
        ivedimas_vector(vektorius_pirmas, "kursiokai" + to_string(studentu_skaicius) + ".txt", &pazymiu_skaicius_pirmas);
        if (vektorius_pirmas.size() == 0)
        {
            cout << "Pradiniu duomenu vektorius tuscias." << endl;
        }

        else
        {
            string vardas = "Vardas";
            string pavarde = "Pavarde";
            string galutinis_med = "Galutinis(Med.)";
            string galutinis_vid = "Galutinis(Vid.)";
            auto matavimo_pradzia_vector_pirmas = high_resolution_clock::now();

            vector<studentas> nelaimeliai_stud_vector;
            vector<studentas> kieti_stud_vector;

            for (auto& kint : vektorius_pirmas)
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

            auto matavimo_pabaiga_vector_pirmas = high_resolution_clock::now();
            duration<double> skirtumas_vector_pirmas = matavimo_pabaiga_vector_pirmas - matavimo_pradzia_vector_pirmas;
            cout << "Studentu suskirstymas uztruko: " << skirtumas_vector_pirmas.count() << "s" << endl;

            auto viso_matavimo_pabaiga_vector_pirmas = high_resolution_clock::now();
            duration<double> viso_skirtumas_vector_pirmas = viso_matavimo_pabaiga_vector_pirmas - viso_matavimo_pradzia_vector_pirmas;
            cout << "Testas su " << studentu_skaicius << " studentu naudojant std::vector uztruko: " << viso_skirtumas_vector_pirmas.count() << "s" << endl;

            cout << endl;
        }

        auto viso_matavimo_pradzia_list_pirmas = high_resolution_clock::now();
        list<studentas> listas_pirmas;
        ivedimas_list(listas_pirmas, "kursiokai" + to_string(studentu_skaicius) + ".txt", &pazymiu_skaicius_pirmas);
        if (listas_pirmas.size() == 0)
        {
            cout << "Pradiniu duomenu listas tuscias." << endl;
        }

        else
        {
            string vardas = "Vardas";
            string pavarde = "Pavarde";
            string galutinis_med = "Galutinis(Med.)";
            string galutinis_vid = "Galutinis(Vid.)";
            auto matavimo_pradzia_list_pirmas = high_resolution_clock::now();

            list<studentas> nelaimeliai_stud_list;
            list<studentas> kieti_stud_list;

            for (auto& kint : listas_pirmas)
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

            auto matavimo_pabaiga_list_pirmas = high_resolution_clock::now();
            duration<double> skirtumas_list_pirmas = matavimo_pabaiga_list_pirmas - matavimo_pradzia_list_pirmas;
            cout << "Studentu suskirstymas uztruko: " << skirtumas_list_pirmas.count() << "s" << endl;

            auto viso_matavimo_pabaiga_list_pirmas = high_resolution_clock::now();
            duration<double> viso_skirtumas_list_pirmas = viso_matavimo_pabaiga_list_pirmas - viso_matavimo_pradzia_list_pirmas;
            cout << "Testas su " << studentu_skaicius << " studentu naudojant std::list uztruko: " << viso_skirtumas_list_pirmas.count() << "s" << endl;

            cout << endl;
        }

        studentu_skaicius *= 10;
        cout << endl << endl;
    }
    studentu_skaicius = 1000;

    cout << endl << "Antroji strategija(vieno naujo vektoriaus/list'o sukurimas paliekant sename kietus studentus):\n\n";

    for (int i = 0; i < 5; i++)
    {
        auto viso_matavimo_pradzia_vector_antras = high_resolution_clock::now();
        vector<studentas> vektorius_antras;
        int pazymiu_skaicius_antras;
        ivedimas_vector(vektorius_antras, "kursiokai" + to_string(studentu_skaicius) + ".txt", &pazymiu_skaicius_antras);
        if (vektorius_antras.size() == 0)
        {
            cout << "Pradiniu duomenu vektorius tuscias." << endl;
        }

        else
        {
            string vardas = "Vardas";
            string pavarde = "Pavarde";
            string galutinis_med = "Galutinis(Med.)";
            string galutinis_vid = "Galutinis(Vid.)";
            auto matavimo_pradzia_vector_antras = high_resolution_clock::now();

            vector<studentas> nelaimeliai_stud_vector_antras(vektorius_antras.size());
            remove_copy_if(vektorius_antras.begin(), vektorius_antras.end(), nelaimeliai_stud_vector_antras.begin(), nelaimeliu_suradimas);

            auto matavimo_pabaiga_vector_antras = high_resolution_clock::now();
            duration<double> skirtumas_vector_antras = matavimo_pabaiga_vector_antras - matavimo_pradzia_vector_antras;
            cout << "Studentu suskirstymas uztruko: " << skirtumas_vector_antras.count() << "s" << endl;

            auto viso_matavimo_pabaiga_vector_antras = high_resolution_clock::now();
            duration<double> viso_skirtumas_vector_antras = viso_matavimo_pabaiga_vector_antras - viso_matavimo_pradzia_vector_antras;
            cout << "Testas su " << studentu_skaicius << " studentu naudojant std::vector uztruko: " << viso_skirtumas_vector_antras.count() << "s" << endl;

            cout << endl;
        }

        auto viso_matavimo_pradzia_list_antras = high_resolution_clock::now();
        list<studentas> listas_antras;
        ivedimas_list(listas_antras, "kursiokai" + to_string(studentu_skaicius) + ".txt", &pazymiu_skaicius_antras);
        if (listas_antras.size() == 0)
        {
            cout << "Pradiniu duomenu listas tuscias." << endl;
        }

        else
        {
            string vardas = "Vardas";
            string pavarde = "Pavarde";
            string galutinis_med = "Galutinis(Med.)";
            string galutinis_vid = "Galutinis(Vid.)";
            auto matavimo_pradzia_list_antras = high_resolution_clock::now();

            list<studentas> nelaimeliai_stud_list_antras;
            list<studentas> kieti_stud_list_trecias;

            for (auto& kint : listas_antras)
            {
                galutinio_skaiciavimas_vid(kint);
                galutinio_skaiciavimas_med(kint);

                if (nelaimeliu_suradimas(kint))
                {
                    nelaimeliai_stud_list_antras.push_back(kint);
                }
                else
                {
                    listas_antras.remove_if(nelaimeliu_suradimas);
                }
            }

            auto matavimo_pabaiga_list_antras = high_resolution_clock::now();
            duration<double> skirtumas_list_antras = matavimo_pabaiga_list_antras - matavimo_pradzia_list_antras;
            cout << "Studentu suskirstymas uztruko: " << skirtumas_list_antras.count() << "s" << endl;

            auto viso_matavimo_pabaiga_list_antras = high_resolution_clock::now();
            duration<double> viso_skirtumas_list_antras = viso_matavimo_pabaiga_list_antras - viso_matavimo_pradzia_list_antras;
            cout << "Testas su " << studentu_skaicius << " studentu naudojant std::list uztruko: " << viso_skirtumas_list_antras.count() << "s" << endl;

            cout << endl;
        }

        studentu_skaicius *= 10;
        cout << endl << endl;
    }
    studentu_skaicius = 1000;

    cout << endl << "Trecioji strategija(dvieju nauju vektoriu/list'u sukurimas ir seno panaikinimas):\n\n";

    for (int i = 0; i < 5; i++)
    {
        auto viso_matavimo_pradzia_vector_trecias = high_resolution_clock::now();
        vector<studentas> vektorius_trecias;
        int pazymiu_skaicius_trecias;
        ivedimas_vector(vektorius_trecias, "kursiokai" + to_string(studentu_skaicius) + ".txt", &pazymiu_skaicius_trecias);
        if (vektorius_trecias.size() == 0)
        {
            cout << "Pradiniu duomenu vektorius tuscias." << endl;
        }

        else
        {
            string vardas = "Vardas";
            string pavarde = "Pavarde";
            string galutinis_med = "Galutinis(Med.)";
            string galutinis_vid = "Galutinis(Vid.)";
            auto matavimo_pradzia_vector_trecias = high_resolution_clock::now();

            vector<studentas> nelaimeliai_stud_vector_trecias;
            vector<studentas> kieti_stud_vector_trecias;

            for (auto& kint : vektorius_trecias)
            {
                galutinio_skaiciavimas_vid(kint);
                galutinio_skaiciavimas_med(kint);

                if (nelaimeliu_suradimas(kint))
                {
                    nelaimeliai_stud_vector_trecias.push_back(kint);
                }
                else
                {
                    kieti_stud_vector_trecias.push_back(kint);
                }
            }
            vektorius_trecias.clear();

            auto matavimo_pabaiga_vector_trecias = high_resolution_clock::now();
            duration<double> skirtumas_vector_trecias = matavimo_pabaiga_vector_trecias - matavimo_pradzia_vector_trecias;
            cout << "Studentu suskirstymas uztruko: " << skirtumas_vector_trecias.count() << "s" << endl;

            auto viso_matavimo_pabaiga_vector_trecias = high_resolution_clock::now();
            duration<double> viso_skirtumas_vector_trecias = viso_matavimo_pabaiga_vector_trecias - viso_matavimo_pradzia_vector_trecias;
            cout << "Testas su " << studentu_skaicius << " studentu naudojant std::vector uztruko: " << viso_skirtumas_vector_trecias.count() << "s" << endl;

            cout << endl;
        }

        auto viso_matavimo_pradzia_list_trecias = high_resolution_clock::now();
        list<studentas> listas_trecias;
        ivedimas_list(listas_trecias, "kursiokai" + to_string(studentu_skaicius) + ".txt", &pazymiu_skaicius_trecias);
        if (listas_trecias.size() == 0)
        {
            cout << "Pradiniu duomenu listas tuscias." << endl;
        }

        else
        {
            string vardas = "Vardas";
            string pavarde = "Pavarde";
            string galutinis_med = "Galutinis(Med.)";
            string galutinis_vid = "Galutinis(Vid.)";
            auto matavimo_pradzia_list_trecias = high_resolution_clock::now();

            list<studentas> nelaimeliai_stud_list_trecias;
            list<studentas> kieti_stud_list_trecias;

            for (auto& kint : listas_trecias)
            {
                galutinio_skaiciavimas_vid(kint);
                galutinio_skaiciavimas_med(kint);

                if (nelaimeliu_suradimas(kint))
                {
                    nelaimeliai_stud_list_trecias.push_back(kint);
                }
                else
                {
                    kieti_stud_list_trecias.push_back(kint);
                }
            }
            listas_trecias.clear();

            auto matavimo_pabaiga_list_trecias = high_resolution_clock::now();
            duration<double> skirtumas_list = matavimo_pabaiga_list_trecias - matavimo_pradzia_list_trecias;
            cout << "Studentu suskirstymas uztruko: " << skirtumas_list.count() << "s" << endl;

            auto viso_matavimo_pabaiga_list_trecias = high_resolution_clock::now();
            duration<double> viso_skirtumas_list_trecias = viso_matavimo_pabaiga_list_trecias - viso_matavimo_pradzia_list_trecias;
            cout << "Testas su " << studentu_skaicius << " studentu naudojant std::list uztruko: " << viso_skirtumas_list_trecias.count() << "s" << endl;

            cout << endl;
        }

        studentu_skaicius *= 10;
        cout << endl << endl;
    }
}
