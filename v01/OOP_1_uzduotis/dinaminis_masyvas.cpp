#include "build_lib.h"

struct studentas
{
    string vardas;
    string pavarde;
    int *pazymiai;
    int egzaminas;
    double galutinis;
    int pazymiu_kiekis = 0;
};

void ivedimas(vector<studentas> &S);
void isvedimas(studentas temp);
int skaiciaus_patikrinimas(string zinute);
void galutinio_skaiciavimas_vid(studentas& stud);
void galutinio_skaiciavimas_med(studentas& stud);

int main() {
    vector<studentas> masyvas;
    ivedimas(masyvas);

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

        char pasirinkimas = '-';
        while (pasirinkimas != 'v' && pasirinkimas != 'm')
        {
            cout << "Pasirinkite, kokio duomenu skaiciavimo norite:\n iveskite 'v' skaiciavimui pagal vidurki arba 'm' skaiciavimui pagal mediana."; cin >> pasirinkimas;
            cout << endl;
        }

        string vardas = "Vardas";
        string pavarde = "Pavarde";
        string galutinis = "Galutinis balas";

        if (pasirinkimas == 'v')
        {
            cout << "Galutinis balas, suskaiciuotas naudojant vidurki:" << endl;
            printf("|%-20s|%-20s|%20s|\n", vardas.c_str(), pavarde.c_str(), galutinis.c_str());
            for (int i = 0; i < masyvas.size(); i++)
            {
                galutinio_skaiciavimas_vid(masyvas[i]);
                printf("|%-20s|%-20s|%20.2f|\n", masyvas[i].vardas.c_str(), masyvas[i].pavarde.c_str(), masyvas[i].galutinis);
            }
        }
        else if (pasirinkimas == 'm')
        {
            cout << "Galutinis balas, suskaiciuotas naudojant mediana:" << endl;
            printf("|%-20s|%-20s|%20s|\n", vardas.c_str(), pavarde.c_str(), galutinis.c_str());
            for (int i = 0; i < masyvas.size(); i++)
            {
                galutinio_skaiciavimas_med(masyvas[i]);
                printf("|%-20s|%-20s|%20.2f|\n", masyvas[i].vardas.c_str(), masyvas[i].pavarde.c_str(), masyvas[i].galutinis);
            }
        }
    }
}


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


void ivedimas(vector<studentas> &S)
{
    char ar_toliau_deti_studenta = 'y';
    int namu_darbas;
    int *namu_darbai_laikinas;
    int i = 0;
    while (true)
    {
        cout << "Ar norite ivesti dar vieno studento duomenis ('y' - taip, 'n' - ne)?: "; cin >> ar_toliau_deti_studenta;
        if (ar_toliau_deti_studenta != 'y' && ar_toliau_deti_studenta != 'n')
        {
            cout << endl;
            continue;
        }
        if (ar_toliau_deti_studenta == 'n')
        {
            break;
        }
        studentas stud;
        cout << "Iveskite varda: ";
        cin >> stud.vardas;
        cout << "Iveskite pavarde: ";
        cin >> stud.pavarde;
        stud.galutinis = 0;

        char pasirinkimas = '-';
        while (pasirinkimas != 'p' && pasirinkimas != 'r')
        {
            cout << "Pasirinkite, ar norite vesti namu darbus ir egzamina patys('p') ar juos sugeneruoti('r'): "; cin >> pasirinkimas;
            cout << endl;
        }

        if (pasirinkimas == 'p')
        {
            int indeksas = 0;
            while (true)
            {
                int ivestas_skaicius = skaiciaus_patikrinimas("Iveskite " + to_string(indeksas++ + 1) + " pazymi(iveskite -1 noredami nutraukti darba): ", false);
                if (ivestas_skaicius == -1)
                {
                    break;
                }
                stud.pazymiu_kiekis += 1;
                namu_darbai_laikinas = new int[stud.pazymiu_kiekis];
                if(stud.pazymiu_kiekis != 1)
                {
                    for(int j = 0; j < stud.pazymiu_kiekis - 1; j++)
                    {
                        namu_darbai_laikinas[j + 1] = stud.pazymiai[j];
                    }
                    delete[] stud.pazymiai;
                }
                namu_darbai_laikinas[0] = ivestas_skaicius;
                stud.pazymiai = namu_darbai_laikinas;
            }
            stud.egzaminas = skaiciaus_patikrinimas("Iveskite egzamino paz.: ", true);
        }

        else if (pasirinkimas == 'r')
        {
            int pazymiu_skaicius = rand() % 10 + 1;
            int indeksas = 0;
            while (true)
            {
                int pazymys = rand() % 10 + 1;
                stud.pazymiu_kiekis += 1;
                namu_darbai_laikinas = new int[stud.pazymiu_kiekis];
                if(stud.pazymiu_kiekis != 1)
                {
                    for(int j = 0; j < stud.pazymiu_kiekis - 1; j++)
                    {
                        namu_darbai_laikinas[j + 1] = stud.pazymiai[j];
                    }
                    delete[] stud.pazymiai;
                }
                namu_darbai_laikinas[0] = pazymys;
                stud.pazymiai = namu_darbai_laikinas;
                if (indeksas++ == pazymiu_skaicius - 1)
                {
                    break;
                }
            }
            stud.egzaminas = rand() % 10 + 1;
        }
        S.push_back(stud);
    }
}


void isvedimas(studentas temp)
{
    printf("|%-20s|%-20s|", temp.vardas.c_str(), temp.pavarde.c_str());
    for (int a = 0; a < temp.pazymiu_kiekis; a++)
    {
        printf("%5d", temp.pazymiai[a]);
    }
    printf("|%*d|\n", 5, temp.egzaminas);
}


void galutinio_skaiciavimas_vid(studentas &stud)
{
    int pazymiu_suma = 0;
    for (int j = 0; j < stud.pazymiu_kiekis; j++)
    {
        pazymiu_suma += stud.pazymiai[j];
    }
    int pazymiu_vidurkis = pazymiu_suma / stud.pazymiu_kiekis;
    stud.galutinis = 0.4 * pazymiu_vidurkis + 0.6 * stud.egzaminas;
}


void galutinio_skaiciavimas_med(studentas& stud)
{
    int masyvo_dydis = stud.pazymiu_kiekis + 1;
    int pazymiu_masyvas[masyvo_dydis];
    for (int i = 0; i < stud.pazymiu_kiekis; i++)
        pazymiu_masyvas[i] = stud.pazymiai[i];
    pazymiu_masyvas[masyvo_dydis - 1] = stud.egzaminas;
    sort(pazymiu_masyvas, pazymiu_masyvas + masyvo_dydis);
    float pazymiu_mediana;
    if (stud.pazymiu_kiekis == 0)
    {
        pazymiu_mediana = 0;
    }
    else if (masyvo_dydis % 2 == 0)
    {
        pazymiu_mediana = (pazymiu_masyvas[masyvo_dydis / 2] + pazymiu_masyvas[masyvo_dydis / 2 - 1]) / 2.0;
    }
    else
    {
        pazymiu_mediana = pazymiu_masyvas[(masyvo_dydis - 1) / 2];
    }
    stud.galutinis = 0.4 * pazymiu_mediana + 0.6 * stud.egzaminas;
}
