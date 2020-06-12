#include "Maquina.h"



Maquina::Maquina()
{
}

Maquina::~Maquina()
{
}

Estrategia* Maquina::getStrategy()
{
	return nullptr;
}

void Maquina::setStrategy(Estrategia* strategy)
{
	this->strategy = strategy;
}
