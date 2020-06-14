#include "jugador.h"

jugador::jugador()
{
	this->nombre = "";
	this->numero = 0;
	this->puntos = 0;
}

jugador::jugador(string nombre, int numero)
{
	this->nombre = nombre;
	this->numero = numero;
	this->puntos = 0;
}

jugador::~jugador()
{
}

void jugador::setNombre(string nombre)
{
	this->nombre = nombre;
}

void jugador::setNumero(int numero)
{
	this->numero = numero;
}

void jugador::setPuntos(int puntos)
{
	this->puntos = puntos;
}

void jugador::aumentarPuntos(int puntos)
{
	this->puntos = this->puntos + puntos;
}

string jugador::getNombre()
{
return this->nombre;
}

int jugador::getNumero()
{
	return this->numero;
}

int jugador::getPuntos()
{
	return this->puntos;
}
