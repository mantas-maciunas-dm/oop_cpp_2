#include "build_lib.h"

struct studentas 
{
    string vardas;
    string pavarde;
    vector<int> pazymiai;
    int egzaminas;
    double galutinis;
};

studentas ivedimas();
void isvedimas(studentas temp);
int skaiciaus_patikrinimas(string zinute);
void galutinio_skaiciavimas_vid(studentas& stud);
void galutinio_skaiciavimas_med(studentas& stud);

int main() {
    vector<studentas> masyvas;

    char ar_toliau_deti_studenta = 'y';
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
        masyvas.push_back(ivedimas());
    }

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


int skaiciaus_patikrinimas(string zinute)
{
    string tikrinamas_skaicius;
    bool ar_skaicius = false;
    while (!ar_skaicius)
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
    }
    return stoi(tikrinamas_skaicius);
}


studentas ivedimas() 
{
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
            int ivestas_skaicius = skaiciaus_patikrinimas("Iveskite " + to_string(indeksas++ + 1) + " pazymi(iveskite -1 noredami nutraukti darba): ");
            if (ivestas_skaicius == -1)
            {
                break;
            }
            stud.pazymiai.push_back(ivestas_skaicius);
        }
        cout << "Iveskite egzamino paz.: ";
        cin >> stud.egzaminas;
    }

    else if (pasirinkimas == 'r')
    {
        int pazymiu_skaicius = rand() % 10 + 1;
        for (int i = 0; i < pazymiu_skaicius; i++)
        {
            stud.pazymiai.push_back(rand() % 10 + 1);
        }
        stud.egzaminas = rand() % 10 + 1;
    }

    return stud;
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


void galutinio_skaiciavimas_vid(studentas &stud)
{
    int pazymiu_suma = 0;
    for (int j = 0; j < stud.pazymiai.size(); j++)
    {
        pazymiu_suma += stud.pazymiai[j];
    }
    int pazymiu_vidurkis = pazymiu_suma / stud.pazymiai.size();
    stud.galutinis = 0.4 * pazymiu_vidurkis + 0.6 * stud.egzaminas;
}


void galutinio_skaiciavimas_med(studentas& stud)
{
    sort(stud.pazymiai.begin(), stud.pazymiai.end());
    float pazymiu_mediana;
    if (stud.pazymiai.size() == 0)
    {
        pazymiu_mediana = 0;
    }
    else if (stud.pazymiai.size() % 2 == 0)
    {
        pazymiu_mediana = (stud.pazymiai[stud.pazymiai.size() / 2] + stud.pazymiai[stud.pazymiai.size() / 2 - 1]) / 2.0;
    }
    else
    {
        pazymiu_mediana = stud.pazymiai[(stud.pazymiai.size() - 1) / 2];
    }
    stud.galutinis = 0.4 * pazymiu_mediana + 0.6 * stud.egzaminas;
}
