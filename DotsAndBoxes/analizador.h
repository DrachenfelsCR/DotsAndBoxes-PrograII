#pragma once
#include "puntoSimple.h"
#include "puntoCompuesto.h"
#include "utiles.h"

class analizador
{
public:
	analizador();
	~analizador();
	void recuperarCampoJuego(puntoCompuesto*, string);
	void recuperarNombrePartidas(string, string*, string*, string*, int*);
private:
};

