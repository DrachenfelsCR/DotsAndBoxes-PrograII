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
	bool conquista;
	bool arriba; 
	bool abajo;
	bool izquierda;
	bool derecha;
	bool conquistado;

//------GET------------
	string toString();
	string toStringDown();
	bool getConquistado();
	bool getConquista();
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
	void setConquista(bool);
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

