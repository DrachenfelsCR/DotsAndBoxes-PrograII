#pragma once
#include "puntoBase.h"
#include "puntoSimple.h"
#include <fstream>
#include "Maquina.h"
#include "estrategia.h"
class Estrategia;
class Maquina;

class puntoCompuesto : public puntoBase
{
public:
	puntoCompuesto(int, int);
	~puntoCompuesto();
	string toString();
	bool conquistadoIzquierdaSup(int,int);
	bool conquistadoAbajoIzquierda(int,int);
	bool consquistadoIzquierdaInf(int,int);
	bool consquitadoAbajoDerecha(int,int);
	bool consquistadoTotal(int, int);
	puntoSimple* buscar(int,int);
//-------------------------
	puntoSimple*** getArreglo();
//------------------------
	void guardar(string);
	void guardarNombre(string);
	void setNombre(string);
	void setJugador1(jugador*);
	void setJugador2(jugador*);
	void setMayor(int);
	void setColumnas(int,int,int);
	void setMaquina(Maquina*);
	void setTurnos(int);
	int getcolumna1();
	int getcolumna2();
	int getcolumna3();
	int getUltimaFil();
	int getUltimaCol();
	int getMayor();
	int getFilasM();
	int getContadorTurnos();
	jugador* getJugador1();
	jugador* getJugador2();
	string getNombre();
	int jugadasMaximas();
	Maquina* getMaquina();
//-----------------------------
	void movimientoAbajo(int,int, jugador*);
	void movimientoArriba(int, int, jugador*);
	void movimientoDerecha(int, int, jugador*);
	void movimientoIzquierda(int, int, jugador*);
	void setFilasM();
	void setUltimafil(int);
	void setUltimaCol(int);
protected:
	string nombre;
	jugador* jugador1;
	jugador* jugador2;
	Maquina* laMaquina;
	puntoSimple*** m;
	int filas;
	int columnas;
	int mayor;
	int filasM;
	int columnas1;
	int columnas2;
	int columnas3;
	int UltimaFil;
	int UltimaCol;
	int contadorTurnos;
};


