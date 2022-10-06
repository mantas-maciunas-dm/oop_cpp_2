#include "build_lib.h";
#include "studentas.h";
#include "rusiavimas.h";


void rusiavimas(vector<studentas>& studentai)
{
    for (int i = 0; i < studentai.size() - 1; i++)
    {
        for (int j = i + 1; j < studentai.size(); j++)
        {
            if (studentai[i].vardas.compare(studentai[j].vardas) > 0)
                iter_swap(studentai.begin() + i, studentai.begin() + j);

            else if (studentai[i].vardas.compare(studentai[j].vardas) == 0)
                if (studentai[i].pavarde.compare(studentai[j].pavarde) > 0)
                    iter_swap(studentai.begin() + i, studentai.begin() + j);
        }
    }
}