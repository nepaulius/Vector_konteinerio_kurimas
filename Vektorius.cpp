#include <iostream>
#include <iterator>
#include <vector>
#include <chrono>
#include <algorithm>
#include "Vector.h"
using std::cout;
using std::endl;
int main() {
    unsigned int sz = 100000000;
    int k = 0;
    Vector<int> v1 {9, 8, 7, 6, 5, 4, 3, 2, 1};
    for (int i = 0; i < v1.size(); i++)
        cout << v1[i] << endl;
    std::sort(v1.begin(), v1.end());
    for (int i = 0; i < v1.size(); i++)
        cout << v1[i] << endl;
    return 0;
}
