//
// Created by Igor on 28.11.2023.
//

#ifndef KOLEJKI_HEAP_H
#define KOLEJKI_HEAP_H
using namespace std;
#include <vector>
#include <climits>
#include "IPQueue.h"

class heap : public IPQueue {
    vector<int> A;

public:
    heap(){A.push_back(INT_MAX);}
    heap(vector<int> nums);
    void UpHeap(int i);
    void DownHeap(int i);

    void Insert(int i) override;
    int Max() const override;
    int DeleteMax() override;
};


#endif //KOLEJKI_HEAP_H
