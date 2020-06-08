#pragma once
#include "utiles.h"
#include "puntoCompuesto.h"
class interfaz {
	int opc;
public:
	interfaz();
	~interfaz();
	void menuPrincipal();
	void jugadorVrsPersona();
	void jugadorVrsMaquina();
	void cargarPartida();
	puntoCompuesto* crearCampoDeJuego(int,int,int);





};