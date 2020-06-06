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

puntoSimple::puntoSimple()
{
	this->conquistado = true;
	arriba = false;
	abajo = false;
	izquierda= false;
	derecha = false;
	cuadrado = false;
	this->jugadorActual = nullptr;
	x = 0;
	y = 0;
}

puntoSimple::~puntoSimple()
{
}

void puntoSimple::setJugador(jugador* jugadorActual)
{
	this->jugadorActual = jugadorActual;
}

inline void puntoSimple::setArriba(bool Arr)
{
	this->arriba = Arr;
}

inline void puntoSimple::setAbajo(bool Ab)
{
	this->abajo = Ab;
}

inline void puntoSimple::setIzquierda(bool Izq)
{
	this->izquierda = Izq;
}

inline void puntoSimple::setDerecha(bool Der)
{
	this->derecha = Der;
}

inline void puntoSimple::setX(int x)
{
	this->x = x;
}

inline void puntoSimple::setY(int y)
{
	this->y = y;
}

jugador* puntoSimple::getJugador()
{
	return this->jugadorActual;
}

inline bool puntoSimple::checkArriba()
{
	return this->arriba;
}

inline bool puntoSimple::checkAbajo()
{
	return this->abajo;
}

inline bool puntoSimple::checkDerecha()
{
	return this->derecha;
}

inline bool puntoSimple::checkIzq()
{
	return this->izquierda;
}

inline int puntoSimple::getX()
{
	return this->x;
}

inline int puntoSimple::getY()
{
	return this->y;
}

string puntoSimple::toString()
{
	stringstream s;
	if (conquistado)
	{
		
		if (izquierda)
		{
				s << "---o";
			
		}
		else if (derecha)
		{
			s << "\to----";
		}

		else
		{
			s << "\to";
		}
		
	}
	return s.str();
}

inline string puntoSimple::toStringDown()
{
	stringstream p;
	if (abajo)
	{
		p << "|";
	}
	else
	{
		p << "\t";
	}
	return p.str();
}
