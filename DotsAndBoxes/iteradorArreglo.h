#pragma once

#include "iterador.h"

template <class T>

class iteradorArreglo : public iterador<T> {
private:
    int cursor;
    T** vec;
    int	cantidad;

public:
    iteradorArreglo(T**, int);

    bool isDone(); // retorna true si hay mas elementos
    T* currentItem();// retorna el elemento actual
    void first(); //pone cursor al inicio
    void next();// avanza cursor
};


//------------ iteradorArreglo --------------
template<class T>
iteradorArreglo<T>::iteradorArreglo(T** vec, int k) {
    cursor = 0;
    cantidad = k;
    this->vec = vec;
}

//---------------------------------------------
template<class T>
bool iteradorArreglo<T>::isDone()
{

    return (cursor < cantidad);  // no verifica que haya un elemento en la posicion
}

//---------------------------------------------
template<class T>
T* iteradorArreglo<T>::currentItem()
{
    return vec[cursor];
    //return *(vec + cursor); // esto se denomina aritmetica de operadores y suele verse en progra 1

}
//---------------------------------------------
template<class T>
void iteradorArreglo<T>::next() { cursor++; }

//---------------------------------------------
template<class T>
void iteradorArreglo<T>::first() { cursor = 0; }
