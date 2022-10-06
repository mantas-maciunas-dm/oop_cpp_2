#include "build_lib.h";
#include "studentas.h";
#include "vidurkiai.h";


void galutinio_skaiciavimas_vid(studentas& stud)
{
    int pazymiu_suma = 0;
    for (int j = 0; j < stud.pazymiai.size(); j++)
    {
        pazymiu_suma += stud.pazymiai[j];
    }
    int pazymiu_vidurkis = pazymiu_suma / stud.pazymiai.size();
    stud.galutinis_vid = 0.4 * pazymiu_vidurkis + 0.6 * stud.egzaminas;
}


void galutinio_skaiciavimas_med(studentas& stud)
{
    vector<int> pazymiu_masyvas;
    for (int i = 0; i < stud.pazymiai.size(); i++)
        pazymiu_masyvas.push_back(stud.pazymiai[i]);
    pazymiu_masyvas.push_back(stud.egzaminas);
    sort(pazymiu_masyvas.begin(), pazymiu_masyvas.end());
    float pazymiu_mediana;
    if (pazymiu_masyvas.size() == 0)
    {
        pazymiu_mediana = 0;
    }
    else if (pazymiu_masyvas.size() % 2 == 0)
    {
        pazymiu_mediana = (pazymiu_masyvas[pazymiu_masyvas.size() / 2] + pazymiu_masyvas[pazymiu_masyvas.size() / 2 - 1]) / 2.0;
    }
    else
    {
        pazymiu_mediana = pazymiu_masyvas[(pazymiu_masyvas.size() - 1) / 2];
    }
    stud.galutinis_med = 0.4 * pazymiu_mediana + 0.6 * stud.egzaminas;
}