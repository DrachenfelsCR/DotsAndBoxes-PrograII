#include "puntoSimple.h"

puntoSimple::puntoSimple()
{
	this->conquistado = true;
	arriba = false;
	abajo = false;
	izquierda = false;
	derecha = false;
	cuadrado = false;
	this->jugadorActual = nullptr;
	x = 0;
	y = 0;
}

puntoSimple::~puntoSimple()
{
}

void puntoSimple::setCodigo(int)
{
}

void puntoSimple::setJugador(jugador* jugadorActual)
{
	this->jugadorActual = jugadorActual;
}

 void puntoSimple::setArriba(bool Arr)
{
	this->arriba = Arr;
}

 void puntoSimple::setAbajo(bool Ab)
{
	this->abajo = Ab;
}

 void puntoSimple::setIzquierda(bool Izq)
{
	this->izquierda = Izq;
}

 void puntoSimple::setDerecha(bool Der)
{
	this->derecha = Der;
}

 void puntoSimple::setX(int x)
{
	this->x = x;
}

 void puntoSimple::setY(int y)
{
	this->y = y;
}

jugador* puntoSimple::getJugador()
{
	return this->jugadorActual;
}

 bool puntoSimple::checkArriba()
{
	return this->arriba;
}

 bool puntoSimple::checkAbajo()
{
	return this->abajo;
}

 bool puntoSimple::checkDerecha()
{
	return this->derecha;
}

 bool puntoSimple::checkIzq()
{
	return this->izquierda;
}

 int puntoSimple::getX()
{
	return this->x;
}

 int puntoSimple::getY()
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

 string puntoSimple::toStringDown()
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

bool puntoSimple::getConquistado()
{
	return false;
}

int puntoSimple::getCodigo()
{
	return 0;
}
