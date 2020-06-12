#pragma once
#include "jugador.h"
#include "Estrategia.h"
class Maquina : public jugador {

private:
	Estrategia* strategy;


public:
	Maquina();
	~Maquina();
	Estrategia* getStrategy();
	void setStrategy(Estrategia*);



};