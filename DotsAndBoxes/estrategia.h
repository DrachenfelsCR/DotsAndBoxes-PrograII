#pragma once
#include <iostream>
#include "puntoCompuesto.h"
#include <time.h>
#include "Maquina.h"
#include "utiles.h"
class Maquina;
using namespace std;
class Estrategia {

public:
	virtual void jugar (puntoCompuesto*,Maquina*) = 0;
	void verificaPunto(puntoSimple*, int, int, int, int);
	puntoSimple* getPuntoOrigen();
	puntoSimple* getPuntoDestino();
protected:
	puntoSimple* puntoOrigen = nullptr;
	puntoSimple* puntoDestino = nullptr;

};