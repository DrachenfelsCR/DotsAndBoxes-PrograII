#pragma once
#include "jugador.h"
class Estrategia;

class Maquina : public jugador {
	
private:
	Estrategia* strategy;


public:
	Maquina(string,int);
	~Maquina();
	Estrategia* getStrategy();
	void setStrategy(Estrategia*);



};