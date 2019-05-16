#ifndef ITERATOR_H_INCLUDED
#define ITERATOR_H_INCLUDED
#include <math.h>
#include <iterator>
template <class T>
class Iterator : public std::iterator<std::random_access_iterator_tag, T> {
private:
    T *pointer;
public:
    Iterator() : pointer(nullptr) {}
    Iterator(T *el) : pointer(el) {}
    ~Iterator() = default;
    ptrdiff_t operator-(const Iterator &it) { return pointer - it.pointer; }
    bool operator==(const Iterator<T>& other) const {
        return pointer == other.pointer;
    }
    bool operator!=(const Iterator<T>& other) const {
        return pointer != other.pointer;
    }
    bool operator<(const Iterator<T>& other) const {
        return pointer < other.pointer;
    }
    bool operator<=(const Iterator<T>& other) const{
        return pointer <= other.pointer;
    }
    bool operator>(const Iterator<T>& other) const{
        return pointer > other.pointer;
    }
    bool operator>=(const Iterator<T>& other) const{
        return pointer >= other.pointer;
    }
    Iterator<T> operator+(int prideti) {
        Iterator<T> temp = (pointer + prideti);
        return temp;
    }
    Iterator<T> operator-(int atimti) {
        Iterator<T> temp = (pointer - atimti);
        return temp;
    }
   // Iterator<T> operator-(Iterator<T>& other) {
    //    return other;
   // }
    Iterator<T> operator++() {
        pointer++;
        return *this;
    }
    Iterator<T> operator--() {
        pointer--;
        return *this;
    }
    T& operator*() {
        return *pointer;
    }
    Iterator<T> operator--(int){
        Iterator<T> temp = *this;
        pointer--;
        return temp;
    }
    Iterator<T> operator++(int){
        Iterator<T> temp = *this;
        pointer++;
        return temp;
    }
    T& operator[](int n) {
    return *(pointer + n);
    }
};
template <class T>
Iterator<T> operator+(int prideti, const Iterator<T>& other) {
        return other + prideti;
}
template <class T>
Iterator<T> operator-(int atimti, const Iterator<T>& other) {
        return other - atimti;
    }
#endif // ITERATOR_H_INCLUDED
