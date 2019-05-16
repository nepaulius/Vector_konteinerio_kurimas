#include <time.h>
#include <random>
#include <chrono>
#include <iostream>
#include "Iterator.h"
#include "Vector.h"
#include "Studentas.h"
#include "Funkcijos.cpp"

int main () {
    unsigned int s, n;
    bool skaitymas;
    bool generavimas;
    cout << "Ar sukurti \"kursiokai.txt\" faila? '1' - Taip; '0' - Ne." << endl;
    std::cin >> generavimas;
            while (std::cin.fail()) {
            cout << "Neteisingas ivedimas, pakartokite." << endl;
            std::cin.clear();
            std::cin.ignore(80, '\n');
            std::cin >> generavimas;
        }
    cout << "Ar duomenis skaityti is failo? '1' - Taip; '0' - Ne." << endl;
    std::cin >> skaitymas;
        while (std::cin.fail()) {
            cout << "Neteisingas ivedimas, pakartokite." << endl;
            std::cin.clear();
            std::cin.ignore(80, '\n');
            std::cin >> skaitymas;
        }
    if ((skaitymas == 1) && (generavimas == 0)) { // Vyksta funkcijos ir skaiciavimai, kai pasirinko skaityti faila.
       try { n = 5, s = 0;
        Vector<Studentas> a;
        std::string ilgv, ilgp;
        auto start = std::chrono::high_resolution_clock::now();
        Skaitymas(n, s, a, ilgp, ilgv); cout << "Baigtas skaitymas." << endl;
        MedianaSTD(a, s); cout << "Baigta mediana." << endl;
        SkaiciavimasSTD(s, n, a); cout << "Baigtas skaiciavimas." << endl;
        RusiavimasSTD(a); cout << "Baigtas rusiavimas." << endl;
        GrupuoteSTD(a, s); cout << "Baigtas grupavimas." << endl;
        IsvedimasSTD(s, a, ilgv, ilgp); cout << "Baigtas isvedimas." << endl;
        //RezultataiSTD(a, s, ilgv, ilgp);
        auto ending = std::chrono::high_resolution_clock::now();
        std::chrono::duration<float> laikas = ending - start;
        cout << laikas.count() << endl;
       } catch (const char* msg) {
          cout << msg << endl;
        }

    }
    else if ((skaitymas == 1) && (generavimas == 1)) {
               try { n = 5;
        Vector<Studentas> a;
        std::string ilgv, ilgp;
        Generavimas(n, s, a); cout << "Baigtas generavimas." << endl;
        SkaitymasG(n, s, a, ilgp, ilgv); cout << "Baigtas skaitymas." << endl;
        MedianaSTD(a, s); cout << "Baigta mediana." << endl;
        SkaiciavimasSTD(s, n, a); cout << "Baigtas skaiciavimas." << endl;
        RusiavimasSTDD(a); cout << "Baigtas rusiavimas." << endl;
        GrupuoteSTD(a, s); cout << "Baigtas grupavimas." << endl;
        IsvedimasSTD(s, a, ilgv, ilgp); cout << "Baigtas isvedimas." << endl;
        RezultataiSTD(a, s, ilgv, ilgp);
       } catch (const char* msg) {
          cout << msg << endl;
        }
    }
    else if ((skaitymas == 0) && (generavimas == 1)) {
        Vector<Studentas> a;
        n = 5;
        Generavimas(n, s, a);
        cout << "Baigtas generavimas." << endl;
    }
    else { // Vyksta klausinejimas (kiek studentu; namu darbu rezultatu...)
    cout << "Iveskite studentu skaiciu: " << endl;
        std::cin >> s;
        while ((s <= 0) || (s >= 400000000) || (std::cin.fail())) {
            cout << "Neteisingas skaicius arba simbolis." << endl;
            std::cin.clear();
            std::cin.ignore(80, '\n');
            std::cin >> s;
        }
    cout << "Iveskite namu darbu skaiciu, jeigu nezinomas - rasyti '0' " << endl;
        std::cin >> n;
        while ((n >= 400000000) || (std::cin.fail())) {
            cout << "Neteisingai vedate skaicius." << endl;
            std::cin.clear();
            std::cin.ignore(80, '\n');
            std::cin >> n;
        }
    Studentas a[s];
    bool g;
    cout << "Ar generuoti skaicius? '1' - Taip; '0' - Ne." << endl;
        std::cin >> g;
        while (std::cin.fail()) {
            cout <<"Prasau rasyti taisyklingai, kaip reikia." << endl;
            std::cin.clear();
            std::cin.ignore(80, '\n');
            std::cin >> g;
        }
    cout << "Iveskite studento varda ir pavarde." << endl;
    std::string ilgv, ilgp;
    std::cin.clear();
    std::cin.ignore(80, '\n');
    try {
    Skaiciavimas(a, s, n, g, ilgv, ilgp);
    Mediana(a, s);
    Rusiavimas(a, s);
    Grupuote(a, s);
    Rezultatai(a, s, ilgv, ilgp);
    Isvedimas(s, a, ilgv, ilgp);
    } catch (const char* msg) {
       cout << msg << endl;
        }
    }
    return 0;
}
