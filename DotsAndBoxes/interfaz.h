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
	void turnoDeJuego(jugador*, jugador*, int, puntoCompuesto*);
	void turnoJugador(jugador*, int, puntoCompuesto*);
	void mostrarCampo(int, puntoCompuesto*);





};