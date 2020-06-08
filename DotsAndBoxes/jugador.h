#pragma once
#include <iostream>

using namespace std;

class jugador
{
public:
	jugador();
	~jugador();
//-----------
	void setNombre(string);
	void setNumero(int);
//-----------
	string getNombre();
	int getNumero();
//-----------
private:
	string nombre;
	int numero;
};
