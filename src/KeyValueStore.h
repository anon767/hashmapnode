//
// Created by tg on 26.07.18.
//

#ifndef KEYVALUESTORE_KEYVALUESTORE_H
#define KEYVALUESTORE_KEYVALUESTORE_H



template<typename T1, typename T2>
class KeyValueStore {
public:
    virtual void add(T1 key, T2 value) = 0;

    virtual T2 get(T1 key) = 0;


};

#endif //KEYVALUESTORE_KEYVALUESTORE_H
