#include "puntoSimple.h"

puntoSimple::puntoSimple()
{
	this->conquistado = false;
	this->conquista = false;
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

void puntoSimple::setConquistado(bool estado)
{
	this->conquistado = estado;
}

void puntoSimple::setCodigo(int)
{
}

void puntoSimple::setConquista(bool c)
{
	this->conquista = c;
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

		if (izquierda && derecha)
		{
			s << "---o----";
		}
		else if (izquierda)
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
	return s.str();
}

 string puntoSimple::toStringDown()
{
	stringstream p;
	 if (conquista)
	{
		p << "| " << this->jugadorActual->getNumero();
	}
	else if (abajo)
	{
		 p << "|";
	}
	else
	{
		p << "";
	}
	return p.str();
}

bool puntoSimple::getConquistado()
{
	return this->conquistado;
}

bool puntoSimple::getConquista()
{
	return this->conquista;
}

int puntoSimple::getCodigo()
{
	return 0;
}
