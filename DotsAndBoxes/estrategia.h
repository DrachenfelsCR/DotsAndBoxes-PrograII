#pragma once
#include <iostream>
#include "puntoCompuesto.h"
using namespace std;
class Estrategia {

public:
	virtual void jugar (puntoCompuesto*) = 0;


};