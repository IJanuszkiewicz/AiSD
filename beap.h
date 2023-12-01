//
// Created by Igor on 30.11.2023.
//

#ifndef KOLEJKI_BEAP_H
#define KOLEJKI_BEAP_H
#include "IPQueue.h"
#include <vector>
#include <cmath>
using namespace std;

class beap : public IPQueue{
    vector<int> A;

    pair<int, int> k2ij(int k) const;
    int ij2k(int i, int j) const {return i*(i - 1)/2 + j;};
    void UpBeap(int k);
    void DownBeap(int k);
public:
    beap(){A.push_back(INT_MAX);}
    void Insert(int v) override;
    int Max() const override{return A[1];}
    int DeleteMax() override;
    int Search(int v) const;
};


#endif //KOLEJKI_BEAP_H
