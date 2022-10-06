#include "build_lib.h";
#include "studentas.h";
#include "ivedimas_isvedimas.h";


int skaiciaus_patikrinimas(string zinute, bool check)
{
    string tikrinamas_skaicius;
    bool ar_skaicius = false;
    bool ar_tarp_vieno_ir_desimt = false;
    int patikrintas_skaicius = 0;
    while (!ar_skaicius && !ar_tarp_vieno_ir_desimt)
    {
        cout << zinute;
        cin >> tikrinamas_skaicius;
        for (int i = 0; i < tikrinamas_skaicius.size(); i++)
        {
            if (isdigit(tikrinamas_skaicius[i]) == false && tikrinamas_skaicius[i] != '-')
            {
                break;
            }
            if (i == tikrinamas_skaicius.size() - 1)
            {
                ar_skaicius = true;
            }
        }
        if (ar_skaicius)
        {
            patikrintas_skaicius = stoi(tikrinamas_skaicius);
        }
        if (!check && patikrintas_skaicius == -1)
        {
            break;
        }
        if (patikrintas_skaicius > 0 && patikrintas_skaicius <= 10)
        {
            ar_tarp_vieno_ir_desimt = true;
        }
        else
        {
            ar_skaicius = false;
        }
    }

    return patikrintas_skaicius;
}


void ivedimas(vector<studentas>& studentai)
{
    char pasirinkimas = '-';
    while (pasirinkimas != 'p' && pasirinkimas != 'r' && pasirinkimas != 'f')
    {
        cout << "Pasirinkite, ar norite vesti namu darbus ir egzamina patys('p'), juos sugeneruoti('r') ar ivesti is failo('f'): "; cin >> pasirinkimas;
        cout << endl;
    }

    if (pasirinkimas == 'p')
    {
        char ar_vesti_toliau = '-';
        while (ar_vesti_toliau != 'n')
        {
            studentas stud;
            stud.galutinis_med = 0;
            stud.galutinis_vid = 0;
            cout << "Iveskite varda: ";
            cin >> stud.vardas;
            cout << "Iveskite pavarde: ";
            cin >> stud.pavarde;
            int indeksas = 0;
            while (true)
            {
                int ivestas_skaicius = skaiciaus_patikrinimas("Iveskite " + to_string(indeksas + 1) + " pazymi(iveskite -1 noredami nutraukti darba): ", false);
                if (ivestas_skaicius == -1 && stud.pazymiai.size() == 0)
                {
                    continue;
                }
                else if (ivestas_skaicius == -1)
                {
                    break;
                }
                indeksas++;
                stud.pazymiai.push_back(ivestas_skaicius);
            }
            stud.egzaminas = skaiciaus_patikrinimas("Iveskite egzamino paz.: ", true);

            studentai.push_back(stud);

            cout << "Jei norite nutraukti ivedima, iveskite 'n', bet koks kitas simbolis tes ivedima: "; cin >> ar_vesti_toliau;
        }
    }

    else if (pasirinkimas == 'r')
    {
        vector<string> v_vardai = { "Vardas1", "Vardas2", "Vardas3", "Vardas4", "Vardas5", "Vardas6", "Vardas7", "Vardas8", "Vardas9", "Vardas10" };
        vector<string> m_vardai = { "Vardaite1", "Vardaite2", "Vardaite3", "Vardaite4", "Vardaite5", "Vardaite6", "Vardaite7", "Vardaite8", "Vardaite9", "Vardaite10" };
        vector<string> v_pavardes = { "Pavardenis1", "Pavardenis2", "Pavardenis3", "Pavardenis4", "Pavardenis5", "Pavardenis6", "Pavardenis7", "Pavardenis8", "Pavardenis9", "Pavardenis10" };
        vector<string> m_pavardes = { "Pavardaite1", "Pavardaite2", "Pavardaite3", "Pavardaite4", "Pavardaite5", "Pavardaite6", "Pavardaite7", "Pavardaite8", "Pavardaite9", "Pavardaite10" };

        int studentu_kiekis = rand() % 100 + 1;
        for (int i = 0; i < studentu_kiekis; i++)
        {
            studentas stud;
            stud.galutinis_med = 0;
            stud.galutinis_vid = 0;

            int vardas_pavarde = rand() % 10;
            if (vardas_pavarde % 2 == 0)
            {
                stud.vardas = v_vardai[vardas_pavarde];
                stud.pavarde = v_pavardes[vardas_pavarde];
            }
            else
            {
                stud.vardas = m_vardai[vardas_pavarde];
                stud.pavarde = m_pavardes[vardas_pavarde];
            }

            int pazymiu_skaicius = rand() % 10 + 1;
            for (int i = 0; i < pazymiu_skaicius; i++)
            {
                stud.pazymiai.push_back(rand() % 10 + 1);
            }
            stud.egzaminas = rand() % 10 + 1;

            studentai.push_back(stud);
        }
    }

    else if (pasirinkimas == 'f')
    {
        string eilute;
        ifstream studentu_failas("kursiokai.txt");
        if (studentu_failas.is_open())
        {
            getline(studentu_failas, eilute);
            while (getline(studentu_failas, eilute))
            {
                studentas stud;
                stud.galutinis_med = 0;
                stud.galutinis_vid = 0;
                vector<string> dalys{};

                stringstream sstream(eilute);
                string dalis;
                while (getline(sstream, dalis, ' '))
                {
                    dalis.erase(remove_if(dalis.begin(), dalis.end(), ispunct), dalis.end());
                    if (dalis == "")
                        continue;
                    dalys.push_back(dalis);
                }
                stud.vardas = dalys[0];
                stud.pavarde = dalys[1];
                for (int i = 2; i < dalys.size() - 1; i++)
                    stud.pazymiai.push_back(stoi(dalys[i]));
                stud.egzaminas = stoi(dalys[dalys.size() - 1]);

                studentai.push_back(stud);
            }
            studentu_failas.close();

            if (studentai.size() == 0)
            {
                cout << "Failas tuscias." << endl;
            }
        }
        if (studentai.size() == 0)
        {
            cout << "Negalima atidaryti failo arba jis tuscias." << endl;
        }
    }
}


void isvedimas(studentas temp)
{
    printf("|%-20s|%-20s|", temp.vardas.c_str(), temp.pavarde.c_str());
    for (int a = 0; a < temp.pazymiai.size(); a++)
    {
        printf("%5d", temp.pazymiai[a]);
    }
    printf("|%*d|\n", 5, temp.egzaminas);
}
