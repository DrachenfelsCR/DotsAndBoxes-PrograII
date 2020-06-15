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
	void recuperarCampoJuegoMaquina(puntoCompuesto*, string, jugador*, Maquina*);
	void recuperarNombrePartidas(string, string*, string*, string*, string*, int*, int*, int*, int*, string*, Maquina*, int*, int*,int*);
	puntoCompuesto* crearCampoDeJuego(int,int,int);
private:
};

