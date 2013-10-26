#ifndef SINGLETON_HPP
#define SINGLETON_HPP

#include <cstdint>

//==================================================================================================
template<typename T> class ISingleton {
public:
    ISingleton();
    ~ISingleton();

    /* Get methods. */
    static T& singleton();
    static T* singletonPtr();

private:
    static T* ms_singleton;
};
//==================================================================================================

template<typename T> T* ISingleton<T>::ms_singleton = nullptr;

template<typename T> inline ISingleton<T>::ISingleton() {
    intptr_t offset = ((intptr_t)(T*)1 - (intptr_t)(ISingleton<T>*)(T*)1);
    ms_singleton = ((T*)((intptr_t)this + offset));
}

template<typename T> inline ISingleton<T>::~ISingleton() {
    ms_singleton = nullptr;
}

template<typename T> inline T& ISingleton<T>::singleton() {
    return *ms_singleton;
}

template<typename T> inline T* ISingleton<T>::singletonPtr() {
    return ms_singleton;
}

#endif
