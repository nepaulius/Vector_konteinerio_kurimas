#ifndef STRUKTURA_H_INCLUDED
#define STRUKTURA_H_INCLUDED
#include <vector>
#include <array>
class Zmogus {
protected:
    std::string vardas, pavarde;
public:
        std::string setpavarde (std::string x) {pavarde = x;}
        std::string getpavarde () const {return pavarde;}
        std::string setvardas (std::string x) {vardas = x;}
        std::string getvardas () const {return vardas;}
        virtual void testas(int testas) = 0;
        virtual ~Zmogus() {}
};
class Studentas : public Zmogus {
    private:

        int egzaminas;
        float vidurkis;
        float galutinisvid, galutinismed;
        float med;
        std::vector<int> nd; //Saugo rezultatus
        std::array<int, 5> fnd; //Saugo rezultatus, jeigu skaitoma is failo ir kai vyksta generavimas.
        std::string grupe;
    public:
        Studentas() {}
        ~Studentas() {} //Destructor
        void testas(int testas) {
            testas = testas;
            }
        int setegzaminas (int i) {egzaminas = i;}
        int getegzaminas () const {return egzaminas;}
        int setbalas (int j, int i) {fnd[j] = i;}
        int getbalas(int j) const {return fnd[j];}
        void Vsetbalas(int i) {nd.push_back(i);}
        int Vsetnaujabala(int i, int j) {nd[i] = j;}
        int Vgetbalas(int i) const {return nd[i];}
        int Vbaludydis() {return nd.size();}
        float setvidurkis(float i) {vidurkis = i;}
        float getvidurkis() const {return vidurkis;}
        float setmed() {med = nd[nd.size()/2];}
        float setvidmed() {med = (nd[nd.size()/2] + nd[(nd.size()/2) - 1]) / 2;}
        float getmed() const {return med;}
        float pridetividurkiui(int i) {vidurkis += i;}
        float gautasvidurkis() {vidurkis /= Vbaludydis();}
        float galutinisvidurkis() {galutinisvid = vidurkis * 0.4 + egzaminas * 0.6;}
        float getgalutinisvidurkis() const {return galutinisvid;}
        float galutinemediana() {galutinismed = med * 0.4 + egzaminas * 0.6;}
        float getgalutinemediana() const {return galutinismed;}
        std::string setgrupe(std::string i) {grupe = i;}
        std::string getgrupe() const {return grupe;}
        friend std::ostream& operator<<(std::ostream& out, const Studentas& x) {
            out << "Studento vardas: " << x.vardas;
            out << "; Pavarde: "<< x.pavarde;
            out << "; Galutinis Vidurkis: ";
            if ((x.galutinisvid > 0) && (x.galutinisvid <= 10))
                out << x.galutinisvid;
            else
                out << "Neturi.";
            out << "; Medianos Vidurkis: ";
            if ((x.galutinismed > 0) && (x.galutinismed <= 10))
                out << x.galutinismed;
            else
                out << "Neturi.";
            out << "; Grupe: ";
            if ((x.grupe == "Marozas") || (x.grupe == "Darbstuolis"))
                out << x.grupe;
            else
                out << "Nepriklauso grupei.";
            out << std::endl;
            return out;
        }
        friend std::istream& operator>>(std::istream& in, Studentas& x) {
            in >> x.vardas >> x.pavarde;
            return in;
        }
        Studentas& operator=(const Studentas& x) { //Copy assignment operator
            if (&x == this)
                return *this;
            vardas = x.vardas;
            pavarde = x.pavarde;
            egzaminas = x.egzaminas;
            vidurkis = x.vidurkis;
            galutinisvid = x.galutinisvid;
            galutinismed = x.galutinismed;
            grupe = x.grupe;
            nd = x.nd;
            fnd = x.fnd;
            med = x.med;
        }
        Studentas (const Studentas& x) :  egzaminas(x.egzaminas), vidurkis(x.vidurkis), med(x.med), galutinismed(x.galutinismed), galutinisvid(x.galutinisvid), grupe(x.grupe) {//Copy constructor
            vardas = x.vardas;
            pavarde = x.pavarde;
            nd.reserve(x.nd.size());
            nd = x.nd;
            fnd = x.fnd;
        }
        Studentas& operator!=(const Studentas& x) {
            std::cout << "Sie studentai turi:" << std::endl;
            if (vardas != x.vardas)
                std::cout << "Skirtingus vardus;" << std::endl;
            if (pavarde != x.pavarde)
                std::cout << "Skirtingas pavardes;" << std::endl;
            if (med != x.med)
                std::cout << "Skirtingas medianas;" << std::endl;
            if (grupe != x.grupe)
                std::cout << "Skirtingose grupese;" << std::endl;
            if (galutinisvid != x.galutinisvid)
                std::cout << "Skirtingus galutinius vidurkius;" << std::endl;
            if (galutinismed != x.galutinismed)
                std::cout << "Skirtingus medianos vidurkius;" << std::endl;
        }
        Studentas& operator==(const Studentas& x) {
            std::cout << "Sie studentai turi:" << std::endl;
            if (vardas == x.vardas)
                std::cout << "Vienoda varda;" << std::endl;
            if (pavarde == x.pavarde)
                std::cout << "Vienoda pavarde;" << std::endl;
            if (med == x.med)
                std::cout << "Vienoda mediana;" << std::endl;
            if (grupe == x.grupe)
                std::cout << "Vienoje grupeje;" << std::endl;
            if (galutinisvid == x.galutinisvid)
                std::cout << "Vienodus galutinius vidurkius;" << std::endl;
            if (galutinismed == x.galutinismed)
                std::cout << "Vienodus medianos vidurkius;" << std::endl;
        }
        Studentas& operator=(Studentas&& x) {
            vardas = std::move(x.vardas);
            pavarde = std::move(x.pavarde);
            egzaminas = std::move(x.egzaminas);
            galutinismed = std::move(x.galutinismed);
            galutinisvid = std::move(x.galutinisvid);
            med = std::move(x.med);
            vidurkis = std::move(x.vidurkis);
            grupe = std::move(x.grupe);
            nd = std::move(x.nd);
            fnd = std::move(x.fnd);
                    }
};
bool Palyginimas(const Studentas& x, const Studentas& y) {
    if (x.getpavarde() != y.getpavarde())
        return x.getpavarde() < y.getpavarde();
    else
        return x.getvardas() < y.getvardas();
}
#endif
