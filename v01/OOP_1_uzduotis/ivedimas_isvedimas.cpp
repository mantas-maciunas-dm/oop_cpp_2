#include "build_lib.h";
#include "studentas.h";
#include "ivedimas_isvedimas.h";


unsigned int Zodziai_eiluteje(string const& str)
{
    stringstream stream(str);
    return std::distance(istream_iterator<string>(stream), istream_iterator<string>());
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


void ivedimas_vector(vector<studentas>& studentai, string failo_pavadinimas, int* nd_skaicius)
{
    auto matavimo_pradzia = high_resolution_clock::now();
    string eilute;
    ifstream studentu_failas(failo_pavadinimas);

    int studentu_skaicius = 0;
    int temp;

    string buff;
    ifstream r;
    try {
        r.open(failo_pavadinimas);
        if (!r)
            throw std::runtime_error("Failo tokiu pavadinimu nera.");

        getline(r >> std::ws, buff);
        *nd_skaicius = Zodziai_eiluteje(buff) - 3;
        while (true)
        {
            studentai.resize(studentai.size() + 1);
            r >> studentai.at(studentu_skaicius).vardas;
            if (r.eof())
            {
                studentai.pop_back();
                break;
            }
            r >> studentai.at(studentu_skaicius).pavarde;
            for (int i = 0; i < *nd_skaicius; i++)
            {
                r >> temp;
                studentai.at(studentu_skaicius).pazymiai.push_back(temp);
            }
            r >> studentai.at(studentu_skaicius).egzaminas;
            studentu_skaicius += 1;
        }
        r.close();
    }
    catch (int e) {}

    auto matavimo_pabaiga = high_resolution_clock::now();
    duration<double> skirtumas = matavimo_pabaiga - matavimo_pradzia;
    cout << "Failo nuskaitymas uztruko: " << skirtumas.count() << "s" << endl;

    if (studentai.size() == 0)
    {
        cout << "Negalima atidaryti failo arba jis tuscias." << endl;
    }
}


void ivedimas_list(list<studentas>& studentai, string failo_pavadinimas, int* nd_skaicius)
{
    auto matavimo_pradzia = high_resolution_clock::now();
    int studentu_skaicius = 0;
    int laikinas_nd;
    string buff, eilute;
    ifstream studentu_failas;

    try
    {
        studentu_failas.open(failo_pavadinimas);

        if (!studentu_failas.is_open()) throw 0;

        getline(studentu_failas >> ws, buff);
        *nd_skaicius = Zodziai_eiluteje(buff) - 3;

        while (true)
        {
            if (studentu_failas.eof())
            {
                studentai.pop_back();
                break;
            }
            studentas dab_stud;
            studentu_failas >> dab_stud.vardas >> dab_stud.pavarde;

            for (int i = 0; i < *nd_skaicius; i++)
            {
                studentu_failas >> laikinas_nd;
                dab_stud.pazymiai.push_back(laikinas_nd);
            }

            studentu_failas >> dab_stud.egzaminas;

            studentai.push_back(dab_stud);
            studentu_skaicius++;
        }

        studentu_failas.close();
    }
    catch (int e)
    {
        cout << "Failas nerastas arba jis tuscias." << endl;
    }

    auto matavimo_pabaiga = high_resolution_clock::now();
    duration<double> skirtumas = matavimo_pabaiga - matavimo_pradzia;
    cout << "Failo nuskaitymas uztruko: " << skirtumas.count() << "s" << endl;
}


void isvedimas_vector(string failo_pav, vector<studentas> vektorius)
{
    ofstream stud_failas(failo_pav);

    auto matavimo_pradzia = high_resolution_clock::now();

    stud_failas << left << setw(25) << "Vardas" << setw(25) << "Pavarde" << setw(15) << "Gal.(vid)" << setw(15) << "Gal.(med)" << endl;

    for (int i = 0; i < vektorius.size(); i++)
    {
        studentas dab_stud = vektorius[i];
        stud_failas << left << setw(25) << dab_stud.vardas << setw(25) << dab_stud.pavarde << setw(15) << dab_stud.galutinis_vid <<
            setw(15) << dab_stud.galutinis_med << endl;
    }

    stud_failas.close();

    auto matavimo_pabaiga = high_resolution_clock::now();
    duration<double> skirtumas = matavimo_pabaiga - matavimo_pradzia;
    cout << "Failo " + failo_pav + " kurimas uztruko: " << skirtumas.count() << "s" << endl;
}


void isvedimas_list(string failo_pav, list<studentas> sarasas)
{
    ofstream stud_failas(failo_pav);

    auto matavimo_pradzia = high_resolution_clock::now();

    stud_failas << left << setw(25) << "Vardas" << setw(25) << "Pavarde" << setw(15) << "Gal.(vid)" << setw(15) << "Gal.(med)" << endl;
    for (auto dab_stud : sarasas)
    {
        stud_failas << left << setw(25) << dab_stud.vardas << setw(25) << dab_stud.pavarde << setw(15) << dab_stud.galutinis_vid <<
            setw(15) << dab_stud.galutinis_med << endl;
    }

    stud_failas.close();

    auto matavimo_pabaiga = high_resolution_clock::now();
    duration<double> skirtumas = matavimo_pabaiga - matavimo_pradzia;
    cout << "Failo " + failo_pav + " kurimas uztruko: " << skirtumas.count() << "s" << endl;
}
