#pragma once
#include <sstream>
#include <string>
#include "iteradorArreglo.h"
using namespace std;

template <class T>
class arregloGenerico {
private:
	int tam;
	T** _v;
	int can;
public:
	arregloGenerico(int);
	~arregloGenerico();
	bool eliminaPorId(string);
	T* buscar(T*);
	T** getV();
	int getTam();
	int getCan();
	string toString();
	void borrarTodo();
	bool agregaFinal(T*);
	T* retornaElemento(string id);
	bool vacio();
	iteradorArreglo<T>* obtenerIterador();
	T* operator[](int);

};

//--------------------------------------------
template <class T>
arregloGenerico <T>::arregloGenerico(int n) : tam(n), can(0), _v(new T* [n]) {

	for (int i = 0; i < tam; i++)
	{
		_v[i] = nullptr;
	}
}

//-------------------------------------------------------
template <class T>
bool arregloGenerico <T>::vacio()
{
	if (can == 0) { return false; }
	else return true;
}

//-----------------------------------------------


template <class T>
iteradorArreglo<T>* arregloGenerico <T>::obtenerIterador()
{
	return new iteradorArreglo<T>(_v, can);
}


//-----------------------------------------------

template <class T>
void arregloGenerico<T>::borrarTodo() {
	for (int i = 0; i < can; i++)
	{
		delete _v[i];
	}
	// no borra el arreglo
}


//--------------------------------

template <class T>
arregloGenerico<T>::~arregloGenerico() {
	borrarTodo();
	delete[] _v;
}


//--------------------------------------------

template <class T>
bool arregloGenerico<T>::agregaFinal(T* x) {

	if (can < tam) {
		_v[can++] = x;
		return true;
	}
	return false;
}


//--------------------------------------------
template <class T>
string arregloGenerico<T>::toString() {
	stringstream r;


	for (int i = 0; i < can; i++) {

		//r << i + 1 << " - ";
		r << _v[i]->toString() << endl;
	}
	return r.str();
}

//----------------------------------------------
template <class T>
T* arregloGenerico<T>::buscar(T* aux) {
	for (int i = 0; i < can; i++)
	{
		if (*(aux) == *(_v[i]))
		{
			return  _v[i];
		}
	}
	return nullptr;
}

//----------------------------------------------
template <class T>

bool arregloGenerico<T>::eliminaPorId(string id)
{
	// si fuera el ultimo
	if (_v[can - 1]->getId() == id)
	{
		delete _v[can - 1];
		_v[can - 1] = nullptr;
		can--;
		return true;
	}
	// si no fuera el ultimo implica corrimiento
	int pos = -1;

	for (int i = 0; i < can - 1; i++)
	{
		if (_v[i]->getId() == id)
		{
			pos = i;
		}
	}

	if (pos != -1)
	{
		// hacemos el corrimiento
		delete _v[pos];
		for (int j = pos; j < can - 1; j++)
		{
			_v[j] = _v[j + 1];
		}
		_v[can - 1] = NULL;
		can--;
		return true;
	}

	return false;
}

//--------------------------------------------
template <class T>
T* arregloGenerico<T>::retornaElemento(string id) {
	for (int j = 0; j < can; j++)
	{
		if (_v[j]->getId() == id)
		{
			return  _v[j];
		}
	}
	return nullptr;
}
//-----------------------------------------------
template <class T>
T** arregloGenerico<T>::getV() {
	return _v;
}


//-----------------------------------------------
template <class T>
int arregloGenerico<T>::getTam() { return tam; }


//-----------------------------------------------
template <class T>
int arregloGenerico<T>::getCan() { return can; }

//--------------------------------------------
template <class T>
T* arregloGenerico<T>::operator[](int n)
{
	if (n <= can)
	{
		return  _v[n];
	}
	return nullptr;
}