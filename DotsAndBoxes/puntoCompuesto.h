#pragma once
#include "puntoBase.h"
#include "arreglo.h"
#include "puntoSimple.h"
#include <fstream>
class puntoCompuesto : public puntoBase
{
public:
	puntoCompuesto(int, int);
	~puntoCompuesto();
	string toString();
	bool conquistadoIzquierdaSup(int,int);
	bool conquistadoAbajoIzquierda(int,int);
	bool consquistadoIzquierdaInf(int,int);
	bool consquitadoAbajoDerecha(int,int);
	bool consquistadoTotal(int, int);
	puntoSimple* buscar(int,int);
//-------------------------
	puntoSimple*** getArreglo();
//------------------------
	void guardar(string);
	void guardarNombre(string);
	void setNombre(string);
	void setJugador1(jugador*);
	void setJugador2(jugador*);
	void setMayor(int);
	void setColumnas(int,int,int);
	int getcolumna1();
	int getcolumna2();
	int getcolumna3();
	int getMayor();
	jugador* getJugador1();
	jugador* getJugador2();
	string getNombre();
	int jugadasMaximas();
//-----------------------------
	void movimientoAbajo(int,int, jugador*);
	void movimientoArriba(int, int, jugador*);
	void movimientoDerecha(int, int, jugador*);
	void movimientoIzquierda(int, int, jugador*);
	void setFilasM();
protected:
	string nombre;
	jugador* jugador1;
	jugador* jugador2;
	puntoSimple*** m;
	int filas;
	int columnas;
	int mayor;
	int filasM;
	int columnas1;
	int columnas2;
	int columnas3;
};


