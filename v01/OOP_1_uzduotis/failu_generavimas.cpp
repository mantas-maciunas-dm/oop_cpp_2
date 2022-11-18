#include "build_lib.h"
#include "studentas.h"

void failo_sukurimas(int kiekis)
{
	string failo_pavadinimas = "kursiokai" + to_string(kiekis) + ".txt";
	ofstream stud_failas (failo_pavadinimas);

	mt19937 mt(static_cast<long unsigned int>(high_resolution_clock::now().time_since_epoch().count()));
	uniform_int_distribution<int> dist(1, 10);

	auto matavimo_pradzia = high_resolution_clock::now();

	stud_failas << left << setw(25) << "Vardas" << left << setw(25) << "Pavarde";
	for (int j = 1; j < 4; j++)
		stud_failas << right << setw(6) << "ND" + to_string(j);
	stud_failas << setw(6) << "Egz.";
	stud_failas << endl;

	for (int i = 0; i < kiekis; i++)
	{
		string vardas = "Vardas" + to_string(i + 1);
		string pavarde = "Pavarde" + to_string(i + 1);

		stud_failas << left << setw(25) << vardas << setw(25) << pavarde;
		for (int j = 0; j < 4; j++)
			stud_failas << right << setw(6) << dist(mt);
		stud_failas << endl;
	}

	stud_failas.close();

	auto matavimo_pabaiga = high_resolution_clock::now();
	duration<double> skirtumas = matavimo_pabaiga - matavimo_pradzia;
	cout << "Failo " + failo_pavadinimas + " kurimas uztruko: " << skirtumas.count() << "s" << endl;
}