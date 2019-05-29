#ifndef VECTOR_H_INCLUDED
#define VECTOR_H_INCLUDED
#include "Iterator.h"
#include <stdexcept>
#include <algorithm>
#include <exception>
template <class T>
class Vector {
    private:
        int dydis;
        int capacity;
        T* elementas;
    public:
        Vector() : dydis(0), capacity(0), elementas(nullptr) {} //Default konstruktorius
        Vector(int x) : dydis(x), capacity(x), elementas(new T [dydis]) {std::fill_n(elementas, x, 0);} //Konstruktorius is objekto
        Vector(int x, T value) : dydis(x), capacity(x), elementas(new T [dydis]) {std::fill_n(elementas, x, value);} //Konstruktorius is 2 objektu
        Vector(std::initializer_list<T> il) : dydis{static_cast<int>(il.size())}, capacity{static_cast<int>(il.size())}, elementas{new T [il.size()]} {std::copy(il.begin(), il.end(), elementas);}
        ~Vector() {delete [] elementas;} //Destruktorius
        Vector (const Vector& v) : dydis{v.dydis}, capacity{v.capacity}, elementas{new T [v.dydis]} { //Copy konstruktorius
            std::cout << "Copy Constructor\n";
            for (int i = 0; i < v.dydis; i++)
                elementas[i] = v.elementas[i];
        }
        Vector(Vector &&v) : dydis(v.dydis), capacity(v.capacity) { //Move kondtruktorius
            std::cout << "Move Constructor\n";
            elementas = v.elementas;
            v.elementas = nullptr;
            v.dydis = 0;
            v.capacity = 0;
        }
        Vector& operator=(const Vector& v) { //Copy Assign operatorius
            std::cout << "Copy Assign operator\n";
            if (&v == this)
                return *this;
            T* p = new T [v.dydis];
            for (int i = 0; i < v.dydis; i++)
                p[i] = v.elementas[i];
            delete [] elementas;
            elementas = p;
            dydis = v.dydis;
            capacity = v.capacity;
            return *this;
        }
        Vector& operator=(Vector &&v) { //Move Assign operatorius
            std::cout << "Move Assign operator\n";
            if (this == &v)
                return *this;
            delete[] elementas;
            dydis = v.dydis;
            capacity = v.capacity;
            elementas = v.elementas;
            v.dydis = 0;
            v.capacity = 0;
            v.elementas = nullptr;
            return *this;
}
        int size() const {return dydis;} //Dydzio getteris
        T& operator[](int i) { //[] operatorius
            if ((i < 0) || (i >= capacity))
                throw std::out_of_range {"Vector::operator[]"};
            return elementas[i];
        }
        const T& operator[](int i) const {
                if ((i < 0) || (i >= capacity))
                throw std::out_of_range {"Vector::operator[]"};
            return elementas[i];} //Irgi [] operatorius
        T assign(int sz, T elem) { //Assign funkcija
            if (sz < 0)
                throw std::out_of_range("Can't assign like that.");
            else if (sz < dydis)
                for (int i = 0; i < sz; i++)
                    elementas[i] = elem;
            else if (sz > dydis) {
                delete [] elementas;
                elementas = new T[sz];
                dydis = sz;
                capacity = dydis;
                for (int i = 0; i < dydis; i++)
                    elementas[i] = elem;
                }
       }
       T& at (int i) const { //At funkcija
           if ((i >= 0) && (i < dydis))
                return elementas[i];
           else
                throw std::out_of_range {"Element is out of range.\n"};
       }
       T& front() const { //Front funkcija
           if (dydis > 0)
            return elementas[0];
           else
            throw std::logic_error("Vector is empty.");
            }
       T& back() const { //Back funkcija
           if (dydis > 0)
           return elementas[dydis - 1];
           else
           throw std::logic_error("Vector is empty.");
           }
       bool empty() const noexcept { //Tikrina, ar tuscias
           return (dydis == 0);
       }
       bool operator==(const Vector<T>& v) { //Operatoriaus == persidenginimas
           if (dydis == v.dydis) {
            for (int i = 0; i < dydis; i++)
               if (elementas[i] != v.elementas[i])
                  return false;
            return true;
           }
           return false;
       }
       bool operator!=(const Vector<T>& v) {return !operator==(v);} // != operatoriaus persidenginimas
       void pop_back() { //Isima paskutni elementa
           dydis = dydis - 1;
       }
       bool operator<(const Vector<T>& v) { //< Operatoriaus persidenginimas
           int counter = 0;
           if (dydis == v.dydis) {
            for (int i = 0; i < dydis; i++)
                if (elementas[i] < v.elementas[i])
                    counter++;
            if (counter * 2 > dydis)
                return true;
            else
                return false;
           }
           return false;
       }
       bool operator>(const Vector<T>& v) {return !operator<(v);} //Operatoriaus > persidenginimas
       bool operator<=(const Vector<T>& v) { //Operatoriaus <= persidenginimas
           int counter = 0;
           if (dydis == v.dydis) {
            for (int i = 0; i < dydis; i++)
                if (elementas[i] <= v.elementas[i])
                    counter++;

            if (counter * 2 > dydis)
                return true;
            else
                return false;
           }
           return false;
       }
       bool operator>=(const Vector<T>& v) {return !operator<=(v);} //Operatoriaus >= persidenginimas
       void swap(Vector& v) { //Swap funkcija, du vektoriai apsikeicia
           Vector<T> temp = v;
           v.elementas = elementas;
           v.dydis = dydis;
           v.capacity = capacity;
           elementas = temp.elementas;
           dydis = temp.dydis;
           capacity = temp.capacity;
       }
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
       int capa() {return capacity;} //Grazina Capacity
        T* data() noexcept {
            if (dydis != 0)
                return elementas;
            else
                return nullptr;
       }
       void shrink_to_fit() {capacity = dydis;} //Sumazina vektoriaus dydi
       void push_back (const T& el) { //Push_back funkcija
           if (capacity == dydis) {
            capacity == 0 ? capacity++ : capacity = capacity * 2;
            T *temp = new T[capacity];
            for (int i = 0; i < dydis; i++)
                temp[i] = elementas[i];
           temp[dydis] = el;
           delete [] elementas;
           elementas = temp;
           dydis++;
           }
            else {
               elementas[dydis] = el;
               dydis++;
           }
       }
       void clear() noexcept { //Clear funkcija
           delete [] elementas;
           dydis = 0;
       }
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
       void erase (const T el) {
           bool truth = false;
           int vieta;
           for (vieta = 0; vieta < dydis; vieta++)
            if (elementas[vieta] == el) {
                truth = true;
                break;
            }
            if(truth) {
                for(int i = vieta; i < dydis - 1; i++)
                    elementas[i] = elementas[i+1];
                dydis--;
    }
    else {
        std::cout << "Element not found" << std::endl;
        }
       }
    T max_size() const noexcept {
    return std::numeric_limits<T>::max();
}
       void insert(int vieta, const T& el) {
    if(dydis != capacity) {
        int i;
        for(i = dydis; i > vieta; i--) {
            elementas[i] = elementas[i-1];
        }
        elementas[i] = el;
        dydis++;
    }
    else {
        capacity == 0 ? capacity++ : capacity = capacity * 2;
        T *temp = new T[capacity];
        for (int i = 0; i < dydis; i++)
            temp[i] = elementas[i];
        delete [] elementas;
        elementas = temp;
        int i;
        for(i = dydis; i > vieta; i--) {
            elementas[i] = elementas[i-1];
        }
        elementas[i] = el;
        dydis++;
    }
}
    friend class Iterator<T>;
    typedef class Iterator<T> iterator;
    Iterator<T> begin() noexcept {
        Iterator<T> temp(elementas);
        return temp;
}
    Iterator<T> end() noexcept {
        Iterator<T> temp(elementas + dydis);
        return temp;
}
    Iterator<T> cbegin() const noexcept {
        Iterator<T> temp(elementas);
        return temp;
    }
    Iterator<T> cend() const noexcept {
        Iterator<T> temp(elementas + dydis);
        return temp;
    }
    Iterator<T> rbegin() noexcept {
        Iterator<T> temp(elementas + dydis - 1);
        return temp;
    }
    Iterator<T> rend() noexcept {
        Iterator<T> temp(elementas - 1);
        return temp;
    }
    Iterator<T> crbegin() const noexcept {
        Iterator<T> temp(elementas + dydis - 1);
        return temp;
    }
    Iterator<T> crend() const noexcept {
        Iterator<T> temp(elementas - 1);
        return temp;
    }
    void emplace_back(const T value) {
        push_back(value);
    }
};
template <class T>
       void swap(Vector<T>& x, Vector<T>& y) {
           Vector<T> temp = x;
           x = y;
           y = temp;
       }
//template <class T>
//bool Palyginimas(const Iterator<T>& x, const Iterator<T>& y) {
 //       return x < y;
//}
template <class T>
void erase (Vector<T>& x, const T value) {
    for (int i = 0; i < x.size(); i++) {
        bool truth = false;
           int vieta;
           for (vieta = 0; vieta < x.size(); vieta++)
            if (x[vieta] == value) {
                truth = true;
                break;
            }
            if(truth) {
                for(int i = vieta; i < x.size() - 1; i++)
                    x[i] = x[i+1];
                x.resize(x.size() - 1);
            }
    }
}

#endif // VECTOR_H_INCLUDED
