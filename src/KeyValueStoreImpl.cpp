//
// Created by tg on 26.07.18.
//
#include <iostream>
#include "KeyValueStoreImpl.h"


template<typename T1, typename T2>

T2 KeyValueStoreImpl<T1, T2>::get(T1 key) {
    auto got = store.find(key);
    if (got == store.end())
        return T2();
    else
        return got->second;
}

template<typename T1, typename T2>
void KeyValueStoreImpl<T1, T2>::add(T1 key, T2 value) {
    auto it = store.find(key);
    if (it != store.end())
        it->second = value;
    else
        store.insert(std::make_pair(key, value));
}





