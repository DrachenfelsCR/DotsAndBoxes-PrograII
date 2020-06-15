#pragma once
#include "utiles.h"
#include "puntoCompuesto.h"
#include "Maquina.h"
#include "incluirEstrategias.h"
#include "analizador.h"

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
	void turnoDeJuegovsMaquina(jugador*, Maquina*,int,puntoCompuesto*);
	void turnoJugador(jugador*, int, puntoCompuesto*, bool*);
	void mostrarCampo(int, puntoCompuesto*);
	void verificaPunto(puntoSimple*, int, int, int, int);
	int columna1Maxima(int,int,int);
	int columna2Maxima(int, int, int);
	int columna3Maxima(int, int, int);
private:
	puntoCompuesto* campoJuegoC;

};