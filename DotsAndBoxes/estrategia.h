#pragma once
#include <iostream>
#include "puntoCompuesto.h"
#include <time.h>
#include "Maquina.h"
class Maquina;
using namespace std;
class Estrategia {

public:
	virtual void jugar (puntoCompuesto*,Maquina*) = 0;


};