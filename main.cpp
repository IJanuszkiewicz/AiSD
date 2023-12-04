#include <iostream>
#include "heap.h"
#include "beap.h"
#include "Lheap.h"
#include "Sheap.h"
#include "Binheap.h"
#include "Fibheap.h"
#include "Dicts/Bst.h"

#define TEST_SIZE 400

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

   /* Binheap bin;
    for(int i = 0; i < 256; i++) {
        bin.Insert((17 * i + 33) % 100);
    }
    for(int i = 0; i < 256; i++){
        cout << bin.DeleteMax() << ", ";
    }*/

    /*Fibheap fib;
    for(int i = 0; i < TEST_SIZE; i++) {
        fib.Insert((17 * i + 33) % 100);
    }
    for(int i = 0; i < TEST_SIZE; i++){
        int max = fib.DeleteMax();
        cout << max << ", ";
    }*/
    Bst bst;
    int testNums[] = {1, 2, 3, 4, 3, 2, 1, 6 ,5 ,4 ,3, 7};
    int testSerch[] = {1, 4, 88, 99, 2 };
    cout << "Inserted: " << endl;
    for(auto num : testNums){
        cout << num << ", ";
        bst.Insert(num);
    }
    cout << endl;
    for(auto num : testSerch){
        cout << "Searching for: " << num << ". Resoult: " <<
        (*bst.Search(num) ? "Found!" : "Not Found") << endl;
    }
    for(auto num : testNums){
        bst.Delete(num);
    }
    cout << "all removed" << endl;

    for(auto num : testSerch){
        cout << "Searching for: " << num << ". Resoult: " <<
             (*bst.Search(num) ? "Found!" : "Not Found") << endl;
    }
}
