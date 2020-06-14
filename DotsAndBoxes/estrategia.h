#pragma once
#include <iostream>
#include "puntoCompuesto.h"
#include <time.h>
#include "Maquina.h"
#include "utiles.h"
class Maquina;
class puntoCompuesto;

using namespace std;
class Estrategia {

public:
	virtual void jugar (puntoCompuesto*,Maquina*, bool*) = 0;
	void verificaPunto(puntoSimple*, int, int, int, int);
	puntoSimple* getPuntoOrigen();
	puntoSimple* getPuntoDestino();
	bool jugadaInteligente(puntoCompuesto*, Maquina*, bool*);
	void setPuntoOrigen(puntoSimple*);
	void setPuntoDestino(puntoSimple*);
	string getNombre();
	void setNombre(string);
protected:
	puntoSimple* puntoOrigen = nullptr;
	puntoSimple* puntoDestino = nullptr;
	string nombre;
};