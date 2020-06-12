#include "Maquina.h"



Maquina::Maquina(string nombre,int numero):jugador(nombre,numero)
{
	strategy = nullptr;
}

Maquina::~Maquina()
{
}

Estrategia* Maquina::getStrategy()
{
	return this->strategy;
}

void Maquina::setStrategy(Estrategia* strategy)
{
	this->strategy = strategy;
}
