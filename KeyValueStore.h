//
// Created by tg on 26.07.18.
//

#ifndef KEYVALUESTORE_KEYVALUESTORE_H
#define KEYVALUESTORE_KEYVALUESTORE_H
#include <map>


template<typename T1, typename T2>
class KeyValueStore {
public:
    virtual int add(T1 key, T2 value) = 0;

    virtual T2 get(T1 key) = 0;

protected:
    std::map <T1, T2> store;
};

#endif //KEYVALUESTORE_KEYVALUESTORE_H
