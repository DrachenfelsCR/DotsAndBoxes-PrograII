#pragma once
#include "puntoBase.h"
#include "jugador.h"

class puntoSimple : public puntoBase
{
public:
	puntoSimple();
	~puntoSimple();
	int x;
	int y;
	bool cuadrado;
	bool conquistado;
	bool arriba; 
	bool abajo;
	bool izquierda;
	bool derecha;

//------GET------------
	string toString();
	string toStringDown();
	bool getConquistado();
	int getCodigo();
	jugador* getJugador();
	bool checkArriba();
	bool checkAbajo();
	bool checkDerecha();
	bool checkIzq();
	int getX();
	int getY();
//------SET-------------
	void setConquistado(bool);
	void setCodigo(int);
	void setJugador(jugador*);
	void setArriba(bool);
	void setAbajo(bool);
	void setIzquierda(bool);
	void setDerecha(bool);
	void setX(int);
	void setY(int);
//------------------------
private:
	jugador* jugadorActual;

};

