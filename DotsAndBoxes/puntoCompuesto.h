#pragma once
#include "puntoBase.h"
#include "arreglo.h"
#include "puntoSimple.h"
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

protected:
	puntoSimple*** m;
	int filas;
	int columnas;
};


