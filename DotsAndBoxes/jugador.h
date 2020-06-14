#pragma once
#include <iostream>
using namespace std;
class jugador
{
public:
	jugador();
	jugador(string, int);
	~jugador();
//-----------
	void setNombre(string);
	void setNumero(int);
	void setPuntos(int);
	void aumentarPuntos(int);
//-----------
	string getNombre();
	int getNumero();
	int getPuntos();
//-----------
protected:
	string nombre;
	int numero;
	int puntos;
};
