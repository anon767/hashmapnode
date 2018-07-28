//
// Created by tg on 26.07.18.
//


#ifndef KEYVALUESTOREIMPL_H
#define KEYVALUESTOREIMPL_H


#include "KeyValueStore.h"
#include <string>


template<typename T1, typename T2>
struct KeyValueStoreImpl : public KeyValueStore<T1, T2> {

    void add(T1 key, T2 value) override;

    T2 get(T1 key) override;
};


#endif //KEYVALUESTOREIMPL_H
