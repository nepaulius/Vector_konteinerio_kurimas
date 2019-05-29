# Sukurtas Vektorius
Vykdoma ketvirtoji praktinė užduotis iš objprog/paskaitos2019
### Reikalavimai
* Turėti Codeblocks 17.12 arba vėlesnę versija:
  * Su **GCC GNU Compiler**
  * Pažymėta, kad kompileris vadovaujasi **C++11** kalbos standartu.
* **minGW**, jei rengiatės naudoti **Makefie**
Norint turėti **tik sukurtą Vektorių**:
  * Vector.h
  * Iterator.h
  * (Vektorius.cpp, jei norite testuoti.)
  
Norint patikrinti, kaip veikia sukurtas Vektorius - Turėti visus failus *(Galima išskyrus **Makefile** neturėti, jei nesirengiate naudoti.)* iš **"Trečioji užduotis"** aplankalo.
### Sukurto Vektoriaus naudojimasis
Savo faile - reikia įterpti šias linijas:
```
#include <Iterator.h>
#include <Vector.h>
```
Analizės:
* 5 Vektoriaus funkcijos:
  **pop.back()** funkcija:
```
void pop_back() { dydis = dydis - 1; }
```
   **Reserve** funkcija:
```
void reserve(int cap) { //Reserve funkcija
     if (cap > capacity) {
        T* temp = new T[cap];
        std::copy(elementas, elementas + capacity, temp);
        delete [] elementas;
        elementas = temp;
        capacity = cap;
        }
     else {}
}
```
**At** funkcija:
```
T& at (int i) const {
      if ((i >= 0) && (i < dydis))
           return elementas[i];
      else
           throw std::out_of_range {"Element is out of range.\n"};
}
```
**Swap** funkcija:
```
void swap(Vector& v) {
      Vector<T> temp = v;
      v.elementas = elementas;
      v.dydis = dydis;
      v.capacity = capacity;
      elementas = temp.elementas;
      dydis = temp.dydis;
      capacity = temp.capacity;
}
```
**Resize** funkcija:
```
void resize(int ndydis) { //Resize funkcija
     if (ndydis < 0)
        throw std::length_error("Can't resize it like that.");
     else if (ndydis <= dydis)
        dydis = ndydis;
     else {
        T *temp = new T[ndydis];
        for (int i = 0; i < dydis; i++)
            temp[i] = elementas[i];
        delete [] elementas;
        elementas = temp;
     }
}
```
* Apskaičiuota, kiek vidutiniškai **sukurtas Vektorius** ir **std::vector** trunka, kad užpildytų elementus, naudojant **push_back()** funkciją:
  
|                    |  10000  |  100000 | 1000000 | 10000000 | 100000000 |
|:------------------:|:-------:|:-------:|:-------:|:--------:|:---------:|
| Sukurtas Vektorius | 0,001s. | 0,006s. | 0,076s. |  0,819s. |  5,013s.  |
|     std::vector    | 0,001s. | 0,007s. | 0,072s. |  0,788s. |  4,577s.  |

* Kai reikia užpildyti 100000000 elementų, atminties perskirstymai vyksta:
  * std::vector - 28 kartų.
  * Sukurtas Vektorius - 27 kartų.
* Patikrinta, kiek vidutinškai veikia trečiosios užduoties programa naudojant abu vektoriai, kai yra **100000** studentų:
  * **std::vector** - 20.588s.
  * **Sukurtas Vektorius** - 29.666
