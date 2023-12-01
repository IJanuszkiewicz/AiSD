//
// Created by Igor on 28.11.2023.
//

#ifndef KOLEJKI_IPQUEUE_H
#define KOLEJKI_IPQUEUE_H
struct IPQueue{
    virtual void Insert(int i) = 0;
    virtual int Max() const = 0;
    virtual int DeleteMax() = 0;
};
#endif //KOLEJKI_IPQUEUE_H
