#include "build_lib.h";
#include "studentas.h";

bool nelaimeliu_suradimas(studentas stud)
{
	if (stud.galutinis_vid < 5.0)
		return true;

	return false;
}