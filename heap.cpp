//
// Created by Igor on 28.11.2023.
//

#include "heap.h"

void heap::UpHeap(int i) {
    int v = A[i];

    while(v > A[i/2]){
        A[i] = A[i/2];
        i = i/2;
    }
    A[i] = v;
}
void heap::DownHeap(int i) {
    int v = A[i], k = 2*i;
    while(k <= A.size()) {
        if(k + 1 <= A.size()) {
            if(A[k + 1] > A[k])
                k += 1;
        }
        if(A[k] > v) {
            A[i] = A[k];
            i = k;
            k = 2 * i;
        } else {
            break;
        }
    }
    A[i] = v;
}
void heap::Insert(int i) {
    A.push_back(i);
    UpHeap(A.size() - 1);
}
int heap::Max() const {
    return A[1];
}
int heap::DeleteMax() {
    int v = A[1];
    A[1] = A[A.size() - 1];
    A.pop_back();
    DownHeap(1);
    return v;
}
heap::heap(vector<int> nums) {
    A.push_back(INT_MAX);
    A.insert(A.end(), nums.begin(), nums.end());
    for(int i = A.size()/2; i >= 1; i--){
        DownHeap(i);
    }
}
