#pragma once
#include "puntoSimple.h"
#include "puntoCompuesto.h"
#include "Maquina.h"
#include "utiles.h"

class analizador
{
public:
	analizador();
	~analizador();
	void recuperarCampoJuego(puntoCompuesto*, string, jugador*, jugador*);
	void recuperarNombrePartidas(string, string*, string*, string*, int*, int*, int*, int*, string*, Maquina*);
private:
};

