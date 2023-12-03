//
// Created by igo-j on 03.12.2023.
//

#ifndef KOLEJKI_IDICT_H
#define KOLEJKI_IDICT_H
template<typename access_t>
struct IDict{
    virtual void Insert(int key) =0;
    virtual void Delete(int key) =0;
    virtual access_t Search(int key) =0;
};

#endif //KOLEJKI_IDICT_H
