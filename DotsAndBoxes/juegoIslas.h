#pragma once

#include "Estrategia.h"
class juegoIslas : public Estrategia {

public:
	virtual void jugar(puntoCompuesto*, Maquina*, bool*);
protected:
	int i = 66;
	int j = 66;

};