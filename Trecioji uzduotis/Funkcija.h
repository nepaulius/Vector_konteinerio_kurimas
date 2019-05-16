#ifndef FUNKCIJA_H_INCLUDED
#define FUNKCIJA_H_INCLUDED
#include <fstream>
#include <iomanip>
#include <algorithm>
using std::endl;
using std::cout;
void Generavimas (unsigned int, unsigned int&, Vector<Studentas>&);
void SkaitymasG(unsigned int, unsigned int, Vector<Studentas>);
void Skaitymas (unsigned int, unsigned int&, Vector<Studentas>&, std::string&, std::string&);
void Skaiciavimas(Studentas [], unsigned int, unsigned int, unsigned int, std::string&, std::string&);
void SkaiciavimasSTD (unsigned int, unsigned int, Vector<Studentas>&);
void Mediana (Studentas [], unsigned int);
void MedianaSTD (Vector<Studentas>&, unsigned int );
void Rusiavimas (Studentas [], unsigned int);
void RusiavimasSTD(Vector<Studentas>&);
void RusiavimasSTDD(Vector<Studentas>&);
void Grupuote(Studentas [], unsigned int);
void GrupuoteSTD(Vector<Studentas>&, unsigned int);
void Rezultatai(Studentas [], unsigned int, std::string, std::string);
void RezultataiSTD(Vector<Studentas>, unsigned int, std::string, std::string);
void Isvedimas(unsigned int, Studentas [], std::string, std::string);
void IsvedimasSTD(unsigned int, Vector<Studentas>, std::string, std::string);
#endif // FUNKCIJA_H_INCLUDED
