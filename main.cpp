#include <iostream>
#include "heap.h"
#include "beap.h"
#include "Lheap.h"
#include "Sheap.h"
#include "Binheap.h"

int main() {
    vector<int> v;
    heap h;
/*
    for(int i = 0; i < 256; i++){
        h.Insert((17*i + 33) % 100);
        v.push_back((17*i + 33) % 100);
    }
    for(int i = 0; i < 256; i++){
        cout << h.DeleteMax() << ", ";
    }
    cout << endl;
    heap h1(v);
    for(int i = 0; i < 256; i++){
        cout << h1.DeleteMax() << ", ";
    }
*/
/*    beap b;
    for(int i = 0; i < 256; i++) {
        b.Insert((17 * i + 33) % 100);
    }

    cout << "szukanie 60: " << b.Search(60) << "\nszukanie 100: " << b.Search(100) << "\n szukanie -1: " <<
        b.Search(-1) << endl;

    for(int i = 0; i < 256; i++){
        cout << b.DeleteMax() << ", ";
    }*/

    /*Lheap l;
    for(int i = 0; i < 256; i++) {
        l.Insert((17 * i + 33) % 100);
    }
    for(int i = 0; i < 256; i++){
        cout << l.DeleteMax() << ", ";
    }*/

    /*Sheap s;
    for(int i = 0; i < 256; i++) {
        s.Insert((17 * i + 33) % 100);
    }
    for(int i = 0; i < 256; i++){
        cout << s.DeleteMax() << ", ";
    }*/

    Binheap bin;
    for(int i = 0; i < 256; i++) {
        bin.Insert((17 * i + 33) % 100);
    }
    for(int i = 0; i < 256; i++){
        cout << bin.DeleteMax() << ", ";
    }

}
