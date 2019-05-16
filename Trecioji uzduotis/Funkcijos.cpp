#include "Funkcija.h"
#include "Studentas.h"
void Generavimas (unsigned int n, unsigned int& s, Vector<Studentas>& a) {
    std::mt19937 generator;
    generator.seed(std::time(0));
    std::uniform_int_distribution<int> dist(1,10);
    std::ofstream fr("kursiokai.txt"); //Sukuriamas failas
    int k;
    cout << "Iveskite kiek studentu reikia sugeneruoti." << endl;
    std::cin >> k; // k - skaicius, iki kiek reikia generuoti studentus.
    while ((k <= 0) || (std::cin.fail())) {
        cout << "Neteisingas ivedimas. Iveskite is naujo skaiciu." << endl;
        std::cin.clear();
        std::cin.ignore(80, '\n');
        std::cin >> k;
    }
    s = k;
    int length;
    for (length = 0; k > 0; length++)
        k = k / 10;
    std::string p, v;
    for (int i = 0; i < s; i++) { //Kuriamas studentas.
        a.push_back(Studentas());
        p = "Pavarde" + std::to_string(i);
        a[i].setpavarde(p);
        v = "Vardas" + std::to_string(i);
        a[i].setvardas(v);
        int sk;
        for (int j = 0; j < n; j++) {
            a[i].setbalas(j, dist(generator));
        }
        a[i].setegzaminas(dist(generator));
    }

    fr << std::left << std::setw(length+10) << "Pavarde" << std::setw(length+5) << "Vardas" << std::right << std::setw(length+6) << "ND1" << std::right << std::setw(length+5) << "ND2" << std::right << std::setw(length+5) << "ND3" << std::right << std::setw(length+5) << "ND4" << std::right << std::setw(length+5) << "ND5" << std::right << std::setw(length+9) << "Egzaminas" << endl;
    for (int i = 0; i < s; i++) {
        fr << std::left << std::setw(length+10) << a[i].getpavarde() << std::setw(length+6) << a[i].getvardas();

        for (int j = 0; j < n; j++)
            fr << std::right << std::setw(length+4) << a[i].getbalas(j) << " ";
         fr << std::right << std::setw(length+5) << a[i].getegzaminas() << endl;
    } // I faila irasomi studentai, ju 5 namu darbu rezultatai ir egzamino rezultatas.

    fr.close();
}
void SkaitymasG(unsigned int n, unsigned int s, Vector<Studentas>& a, std::string& ilgp, std::string& ilgv) {
    std::ifstream fd("kursiokai.txt"); //Skaito duomenis is failo
    if (!fd) {
        throw "Skaitymas neimanomas. Failas neegzistuoja.\n"; //Tikrina, ar failas egzistuoja.
    }
    fd.ignore(255, '\n');
    if (!fd) {
        throw "Failas yra tuscias.\n"; //Tikrina, ar failas egzistuoja.
    }
    std::string v, p;
    int b, e;
    for (int i = 0; i < s; i++) { //Ivedami studento duomenys po generavimo.
        fd >> p >> v;
        ilgv.length() < v.length() ? ilgv = v : ilgv = ilgv;
        ilgp.length() < p.length() ? ilgp = p : ilgp = ilgp;
        a[i].setpavarde(p);
        a[i].setvardas(v);
        for (int j = 0; j < n; j++) {
            fd >> b;
            a[i].setbalas(j, b);
            a[i].Vsetbalas(b);
        }
        fd >> e;
        a[i].setegzaminas(e);
    }
    fd.close();
}
void Skaitymas (unsigned int n, unsigned int& s, Vector<Studentas>& a, std::string& ilgp, std::string& ilgv) {
    std::ifstream fd("kursiokai.txt"); //Skaito duomenis is failo
    if (!fd) {
        throw "Skaitymas neimanomas. Failas neegzistuoja.\n"; //Tikrina, ar failas egzistuoja.
    }
    fd.ignore(255, '\n');
    if (!fd) {
        throw "Failas yra tuscias.\n"; //Tikrina, ar failas egzistuoja.
    }
    std::string v, p;
    int b, e;
    while (fd) { //Vedami studento duomenys, jei nebuvo generuotes.
       a.push_back(Studentas());
        fd >> p >> v;
        ilgv.length() < v.length() ? ilgv = v : ilgv = ilgv;
        ilgp.length() < p.length() ? ilgp = p : ilgp = ilgp;
        a[s].setpavarde(p);
        a[s].setvardas(v);
        for (int j = 0; j < n; j++) {
            fd >> b;
            a[s].setbalas(j, b);
            a[s].Vsetbalas(b);
        }
        fd >> e;
        a[s].setegzaminas(e);
        s++;
    }
    s--;
    fd.close();
}
void Skaiciavimas(Studentas a[], unsigned int s, unsigned int n, unsigned int g, std::string& ilgv, std::string& ilgp) {
    unsigned k, sk, e;
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_int_distribution<int> dist(1,10);
    std::string v, p;
    for (int i = 0; i < s; i++) {
        std::cin >> a[i];
        ilgv.length() < a[i].getvardas().length() ? ilgv = a[i].getvardas() : ilgv = ilgv; //Iesko ilgiausio vardo
        ilgp.length() < a[i].getpavarde().length() ? ilgp = a[i].getpavarde() : ilgp = ilgp; //Iesko ilgiausios pavardes, jie bus reikalingi, kad lygiai isvestu rezultata.
        a[i].setvidurkis(0);
        if ((n == 0) && (g > 0)) { //Kai nezinom, kiek bus namu darbu rezultatu + pasirinko generavima.
            cout << "Veskite kiek norite, kad sugeneruotu namu darbu rezultatus." << endl;
            std::cin >> k;
            while (std::cin.fail()) {
                cout << "Toks ivedimas negalimas, veskite is naujo." << endl;
                std::cin.clear();
                std::cin.ignore(80, '\n');
                std::cin >> k;
            }
            n = k;
            if (n == 0)
            {
                throw "Nesuvesta jokiu namu darbu rezultatu. Programa nutraukiama.";
            }
            for (int j = 0; j < k; j++) {
                    sk = dist(rd); // Generuoja skaicius
                    a[i].Vsetbalas(sk);
                    a[i].pridetividurkiui(sk);
            }
            a[i].gautasvidurkis();
            a[i].setegzaminas(dist(rd));
        }
        else if ((n > 0) && (g > 0)) { //Kai zinoma, kiek bus namu darbu rezultatu + pasirinko generavima.
                for (int j = 0; j < n; j++) {
                    sk = dist(rd);
                    a[i].Vsetbalas(sk);
                    a[i].pridetividurkiui(sk);
            }

            a[i].gautasvidurkis();
            a[i].setegzaminas(dist(rd));
        }
        else if ((n > 0) && (g == 0)) { //Kai zinoma, kiek bus namu darbu rezultatu, bet nesirinko generavimo.
                cout << "Veskite namu darbu rezultatus ";
                n == 1 ? cout << "viena karta." << endl : cout << n << " kartus." << endl;
                for (int j = 0; j < n; j++) { //Vyksta ciklas tol, kol pasiekia namu darbu kieki.
                        std::cin >> sk;
                       while ((std::cin.fail()) || (sk == 0)) {
                        cout << "Neteisingai vedate, pakartokite." << endl;
                        std::cin.clear();
                        std::cin.ignore(80, '\n');
                        std::cin >> sk;
                       }
                    sk >= 11 ? sk = sk % 10 : sk = sk;
                    a[i].Vsetbalas(sk);
                    a[i].pridetividurkiui(sk);
            }
            a[i].gautasvidurkis();
            cout << "Iveskite egzamino ivertinina." << endl;
            try {
            std::cin >> e;
            if (std::cin.fail() || (e == 0)) {
                throw "Neteisingas rezultatas. Pakartokite.";
                }
            } catch (const char* msg) {
                while (std::cin.fail() || (e == 0)) {
                    cout << msg << endl;
                        std::cin.clear();
                        std::cin.ignore(80, '\n');
                        std::cin >> e;
                }
            }
            e >= 11 ? e = e % 10 : e = e; //Jei vartotojas ivede daugiau nei 10 - imama % 10 liekana
            a[i].setegzaminas(e);
        }
        else { // Kai nezinom, kiek bus namu darbu rezultatu ir nepasirinko generavimo.
                int p = 0;
                cout << "Veskite tiek rezultatu, kiek reikia. Baigti - rasykite '0'." << endl;
            do { //Vyksta tol, kol nepasirinko '0', kaip pabaigos
                try {
                    std::cin >> sk;
                    if (std::cin.fail()) {
                        throw "Neteisingai vedate. Pakartokite.";
                    }
                } catch (const char* msg) {
                   while (std::cin.fail()) {
                        cout << msg << endl;
                        std::cin.clear();
                        std::cin.ignore(80, '\n');
                        std::cin >> sk;
                       }
                }
                if (sk != 0) { // Tikrina, ar buvo ivestas nulis.
                    p++;
                    sk >= 11 ? sk = sk % 10 : sk = sk;
                    a[i].Vsetbalas(sk);
                    a[i].pridetividurkiui(sk);
                    n++;
                }
            } while (sk != 0);
            if (p == 0) {
                throw "Nesuvesta jokiu namu darbu rezultatu. Programa nutraukiama.";
            }
            a[i].gautasvidurkis();
            cout << "Iveskite egzamino ivertinina." << endl;
            try {
                std::cin >> e;
                if (std::cin.fail() || (e == 0)) {
                throw "Neteisingas rezultatas. Pakartokite.";
                }
            } catch (const char* msg) {
                while (std::cin.fail() || (e == 0)) {
                    cout << msg << endl;
                        std::cin.clear();
                        std::cin.ignore(80, '\n');
                        std::cin >> e;
                }
            }
            e >= 11 ? e = e % 10 : e = e;
            a[i].setegzaminas(e);
        }
        a[i].galutinisvidurkis();

        i != s - 1 ? cout << "Veskite kita studenta." << endl : cout << endl; // Tikrina, ar reikia ivesti kito studento varda ir pavarde.
    }
}
void SkaiciavimasSTD (unsigned int s, unsigned int n, Vector<Studentas>& a) { //Skaiciuojama is failo duomenu
    for (int i = 0; i < s; i++) {
        a[i].setvidurkis(0);
        for (int j = 0; j < n; j++) {
            a[i].pridetividurkiui(a[i].Vgetbalas(j));
        }
        a[i].gautasvidurkis();
        a[i].galutinisvidurkis();
        a[i].galutinemediana();
    }
}
void Mediana (Studentas a[], unsigned int s) { //Skaiciuojama Mediana, kai neskaitoma is failo.
    int laik;
    for (int i = 0; i < s; i++) {
        for (int j = 0; j < a[i].Vbaludydis(); j++) { // Vyksta burbulo rikiavimas pagal mazejimo tvarka.
            for (int c = 1; c < a[i].Vbaludydis(); c++)
                if (a[i].Vgetbalas(c) > a[i].Vgetbalas(c-1)) {
                    laik = a[i].Vgetbalas(c-1);
                    a[i].Vsetnaujabala(c-1, a[i].Vgetbalas(c));
                    a[i].Vsetnaujabala(c, laik);
                }
            }
        if (a[i].Vbaludydis() % 2 == 0) { //Tikrina ar vektoriaus ilgis yra lyginis
            a[i].setvidmed();
        }
        else {
            a[i].setmed();
        }
        a[i].galutinemediana(); //Apskaiciuojama mediana studento.
    }
}
void MedianaSTD (Vector<Studentas>& a, unsigned int s) { //Skaiciuoja mediana, kai buvo skaitytas failas.
    int laik;
    for (int i = 0; i < s; i++) {
        for (int j = 0; j < a[i].Vbaludydis(); j++) { // Vyksta burbulo rikiavimas pagal mazejimo tvarka.
            for (int c = 1; c < a[i].Vbaludydis(); c++)
                if (a[i].Vgetbalas(c) > a[i].Vgetbalas(c-1)) {
                    laik = a[i].Vgetbalas(c-1);
                    a[i].Vsetnaujabala(c-1, a[i].Vgetbalas(c));
                    a[i].Vsetnaujabala(c, laik);
                }
            }
        if (a[i].Vbaludydis() % 2 == 0) { //Tikrina ar vektoriaus ilgis yra lyginis
            a[i].setvidmed();
        }
        else {
            a[i].setmed();
        }
    }
}
void Rusiavimas (Studentas a[], unsigned int s) { //Rusiuoja pagal abeceles tvarka pagal varda. Naudojama, jei neskaite failo.
        Studentas laik;
        for (int i = 0; i < s; i++)
        for (int j = 1; j < s; j++) {
            if (a[j].getvardas() < a[j-1].getvardas()) {
                laik = a[j-1];
                a[j-1] = a[j];
                a[j] = laik;
            }
            else if ((a[j].getvardas() == a[j-1].getvardas()) && (a[j].getpavarde() < a[j-1].getpavarde())) { //Jei vardas toks pats, ziurima pagal pavarde.
                laik = a[j-1];
                a[j-1] = a[j];
                a[j] = laik;
            }
        }
}
void RusiavimasSTD(Vector<Studentas>& a) { //Rusiavimas, kai nuskaite faila.
        std::sort(a.begin(), a.end() - 1, Palyginimas);
}
void RusiavimasSTDD(Vector<Studentas>& a) { //Rusiavimas, kai nuskaite faila.
        std::sort(a.begin(), a.end(), Palyginimas);
}
void Grupuote(Studentas a[], unsigned int s) { //Studentai kategarizuojami.
    for (int i = 0; i < s; i++) {
        if ((a[i].getgalutinemediana() >= 5) || (a[i].getgalutinisvidurkis()>= 5)) { //Jei studentas gavo Medianos arba Vidurki >= 5, priskiriamas 'Darbstuolio' kategorijai.
            a[i].setgrupe("Darbstuolis");
        }
        else {
            a[i].setgrupe("Marozas"); //Kitu atveju - studentas priklauso 'Marozas' kategorijai.
            }
    }
}
void GrupuoteSTD(Vector<Studentas>& a, unsigned int s) { //Studentai kategarizuojami is failo.
    for (int i = 0; i < s; i++) {
        if ((a[i].getgalutinemediana() >= 5) || (a[i].getgalutinisvidurkis()>= 5)) {
            a[i].setgrupe("Darbstuolis");
        }
        else {
            a[i].setgrupe("Marozas");
        }
    }
}
void Rezultatai(Studentas a[], unsigned int s, std::string ilgv, std::string ilgp) {
    cout << std::left << std::setw(ilgp.length()+3) << "Pavarde" << std::setw(ilgv.length()+3) << "Vardas" << "Galutinis (Vid.) / Galutinis (Med.)" << std::right << std::setw(9) << "Grupe" << endl;
    for (int i = 0; i < (ilgp.length() + ilgv.length() + 52); i++)
        cout << "-";
    cout << endl;
    for (int i = 0; i < s; i++) {
          cout << std::left << std::setw(ilgp.length()+3) << a[i].getpavarde() << std::setw(ilgv.length()+6) << a[i].getvardas() << std::fixed << std::setprecision(2) << a[i].getgalutinisvidurkis() << std::right << std::setw(19) << a[i].getgalutinemediana() << std::right << std::setw(12) << "" << a[i].getgrupe() << endl;
    }
}
void RezultataiSTD(Vector<Studentas> a, unsigned int s, std::string ilgv, std::string ilgp) {
        cout << std::left << std::setw(ilgp.length()+3) << "Pavarde" << std::setw(ilgv.length()+3) << "Vardas" << "Galutinis (Vid.) / Galutinis (Med.)" << std::right << std::setw(10) << "Grupe"  << endl;
    for (int i = 0; i < (ilgp.length() + ilgv.length() + 55); i++)
        cout << "-";
    cout << endl;
    for (int i = 0; i < s; i++) {
          cout << std::left << std::setw(ilgp.length()+3) << a[i].getpavarde() << std::setw(ilgv.length()+6) << a[i].getvardas() << std::fixed << std::setprecision(2) << a[i].getgalutinisvidurkis() << std::right << std::setw(19) << a[i].getgalutinemediana() << std::right << std::setw(12) << "" << a[i].getgrupe() << endl;
        }
}
void Isvedimas(unsigned int s, Studentas a[], std::string ilgv, std::string ilgp) { //Isvedami studentu kategorijos
    std::ofstream fr("Marozai.txt");
    std::ofstream frr("Darbstuoliai.txt");
    for (int i = 0; i < s; i++) {
        if (a[i].getgrupe() == "Marozas") {
            fr << std::left << std::setw(ilgp.length()+3) << a[i].getpavarde() << std::setw(ilgv.length()+6) << a[i].getvardas() << endl;
        }
        else {
            frr << std::left << std::setw(ilgp.length()+3) << a[i].getpavarde() << std::setw(ilgv.length()+6) << a[i].getvardas() << endl;
        }
    }
    fr.close();
    frr.close();
}
void IsvedimasSTD(unsigned int s, Vector<Studentas> a, std::string ilgv, std::string ilgp) {
    std::ofstream fr("Marozai.txt");
    std::ofstream frr("Darbstuoliai.txt");
    for (int i = 0; i < s; i++) {
        if (a[i].getgrupe() == "Marozas") {
            fr << std::left << std::setw(ilgp.length()+3) << a[i].getpavarde() << std::setw(ilgv.length()+6) << a[i].getvardas() << endl;
        }
        else {
            frr << std::left << std::setw(ilgp.length()+3) << a[i].getpavarde() << std::setw(ilgv.length()+6) << a[i].getvardas() << endl;
        }
    }
    fr.close();
    frr.close();
}

