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
	puntoSimple* buscar(int,int);
//-------------------------
	puntoSimple*** getArreglo();
//------------------------

protected:
	puntoSimple*** m;
	int filas;
	int columnas;
};


