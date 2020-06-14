#pragma once
#include "jugador.h"
#include "puntoCompuesto.h"
class Estrategia;
class puntoCompuesto;

class Maquina : public jugador {
	
private:
	Estrategia* strategy;


public:
	Maquina(string,int);
	~Maquina();
	Estrategia* getStrategy();
	void setStrategy(Estrategia*);



};