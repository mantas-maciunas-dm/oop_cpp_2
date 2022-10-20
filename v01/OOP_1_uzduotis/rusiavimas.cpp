#include "build_lib.h";
#include "studentas.h";
#include "rusiavimas.h";


bool palyginimas(studentas stud1, studentas stud2)
{
    if (stud1.vardas.compare(stud2.vardas) == 0)
        return (stud1.pavarde.compare(stud2.pavarde) < 0);

    return (stud1.vardas.compare(stud2.vardas) < 0);
}