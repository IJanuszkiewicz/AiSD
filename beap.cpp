//
// Created by Igor on 30.11.2023.
//

#include "beap.h"

pair<int, int> beap::k2ij(int k) const {
    int i = int(ceil(0.5 * (-1 + sqrt((double) (1 + 8 * k)))));
    int j = int(k - 0.5 * i * (i - 1));
    return pair(i, j);
}
void beap::UpBeap(int k) {
    int v = A[k];
    auto p = k2ij(k);
    int i = p.first;
    int j = p.second;
    int toCompare = k;
    while (i > 1) {
        p = k2ij(k);
        i = p.first;
        j = p.second;
        if (j == 1) {
            toCompare = k - i + 1;
        } else if (j == i) {
            toCompare = k - i;
        } else {
            toCompare = A[k - i] < A[k - i + 1] ? k - i : k - i + 1;
        }
        if (v > A[toCompare]) {
            A[k] = A[toCompare];
            k = toCompare;
            continue;
        }
        break;
    }
    A[k] = v;
}
void beap::Insert(int v) {
    A.push_back(v);
    UpBeap(A.size() - 1);
}
void beap::DownBeap(int k) {
    int v = A[k];
    pair<int, int> p = k2ij(k);
    int i = p.first, j = p.second, toCompare = k + i;

    while (toCompare <= A.size()) {
        if (toCompare + 1 <= A.size()) {
            toCompare = A[toCompare] > A[toCompare + 1] ? toCompare : toCompare + 1;
        }
        if (v < A[toCompare]) {
            A[k] = A[toCompare];
            k = toCompare;
            p = k2ij(k);
            i = p.first;
            j = p.second;
            toCompare = k + i;
        } else {
            break;
        }
    }
    A[k] = v;
}
int beap::DeleteMax() {
    int max = A[1];
    A[1] = A[A.size()];
    A.pop_back();
    DownBeap(1);
    return max;
}
int beap::Search(int v) const {
    int k = A.size();
    auto p = k2ij(k);
    int i = p.first, j = p.second;
    if (j != i) {
        i = i - 1;
        j = i;
        k = ij2k(i, j);
    }
    while (k > 1 && A[k] != v) {
        if (A[k] < v) {
            if (j > 1) {
                k = k - i;
            } else {
                break;
            }
        } else if (k + i <= A.size()) {
            k = k + i;
        } else if(j > 1) {
            k--;
        } else {
            break;
        }

        p = k2ij(k);
        i = p.first;
        j = p.second;
    }
    return A[k] == v ? k : -1;
}
