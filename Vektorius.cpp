#include <iostream>
#include <iterator>
#include <vector>
#include <chrono>
#include <algorithm>
#include <chrono>
#include "Vector.h"
using std::cout;
using std::endl;
int main() {
    int k = 0;
    Vector<int> a {1, 2, 3};
    Vector<int> b(std::move(a));
    for (int i = 0; i < 3; i++)
        cout << b[i] << endl;

    Vector<int> v1;
    std::chrono::high_resolution_clock::time_point start, ending;
    start = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < 100; i++)
        v1.push_back(i);
    ending = std::chrono::high_resolution_clock::now();
    std::chrono::duration<float> laikas = ending - start; //Gaunamas laiko rezultatas
    cout << "Truko: " << laikas.count() << endl;
    Vector<int> v2;
    cout << v2.size() << " " << v2.capa() << endl;
    v2.reserve(100);
    cout << v2.size() << " " << v2.capa() << endl;
    start = std::chrono::high_resolution_clock::now();
        for (int i = 0; i < 100; i++)
        v2.push_back(i);
    ending = std::chrono::high_resolution_clock::now();
    cout << "Truko: " << laikas.count() << endl;
   // for (int i = 0; i < v1.size(); i++)
      //  cout << v2[i] << endl;
    cout << v2.size() << " " << v2.capa() << endl;
    v2.shrink_to_fit();
    cout << v2.size() << " " << v2.capa() << endl;

    Vector<int> v3 {0, 1, 2, 3};
   // cout << v3[5] << endl;
   // cout << v3.at(5) << endl;

   // Vector<int> v(9999999999);
    return 0;
}
