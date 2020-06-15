#include "analizador.h"

analizador::analizador()
{
}

analizador::~analizador()
{
}

void analizador::recuperarCampoJuego(puntoCompuesto* matriz, string archivo, jugador* jugadorN1, jugador* jugadorN2)
{
	ifstream input;
	string nombre;
	string jugadorA;
	string numJugadorStr;
	string i;
	string j;
	string izquierda;
	string arriba;
	string derecha;
	string abajo;
	string conquistaStr;
	//-------------------------
	bool izquierdaReal;
	bool arribaReal;
	bool derechaReal;
	bool abajoReal;
	bool conquista;
	//-------------------------
	int iReal;
	int jReal;
	int numJugador;
	input.open(archivo.c_str());
	while (input.good())
	{
		getline(input, i, '\t');
		getline(input, j, '\t');
		getline(input, conquistaStr, '\t');
		getline(input, jugadorA, '\t');
		getline(input, numJugadorStr, '\t');
		getline(input, izquierda, '\t');
		getline(input, arriba, '\t');
		getline(input, derecha, '\t');
		getline(input, abajo, '\n');
		if (izquierda != "vacio")
		{
			izquierdaReal = convertirBool(izquierda);
			arribaReal = convertirBool(arriba);
			derechaReal = convertirBool(derecha);
			abajoReal = convertirBool(abajo);
		}
		else
		{
			izquierdaReal = false;
			arribaReal = false;
			derechaReal = false;
			abajoReal = false;
		}
		iReal = convertirInt(i);
		jReal = convertirInt(j);
		conquista = convertirBool(conquistaStr);
		numJugador = convertirInt(numJugadorStr);
		if (!input.eof())
		{
			if ((matriz->getArreglo())[iReal][jReal] == nullptr)
			{

			}
			else
			{
				(matriz->getArreglo())[iReal][jReal]->setIzquierda(izquierdaReal);
				(matriz->getArreglo())[iReal][jReal]->setArriba(arribaReal);
				(matriz->getArreglo())[iReal][jReal]->setDerecha(derechaReal);
				(matriz->getArreglo())[iReal][jReal]->setAbajo(abajoReal);
				if (numJugador != 0)
				{
					if (jugadorA == jugadorN1->getNombre())
					{
						(matriz->getArreglo())[iReal][jReal]->setJugador(jugadorN1);
						if (conquista == true)
						{
							(matriz->getArreglo())[iReal][jReal]->setConquista(true);
						}
					}
					else if (jugadorA == jugadorN2->getNombre())
					{
						(matriz->getArreglo())[iReal][jReal]->setJugador(jugadorN2);
						if (conquista == true)
						{
							(matriz->getArreglo())[iReal][jReal]->setConquista(true);
						}
					}
				}
			}

		}
	}
	input.close();
}

void analizador::recuperarCampoJuegoMaquina(puntoCompuesto* matriz, string archivo, jugador* jugadorN1, Maquina* jugadorN2)
{
	ifstream input;
	string nombre;
	string jugadorA;
	string numJugadorStr;
	string i;
	string j;
	string izquierda;
	string arriba;
	string derecha;
	string abajo;
	string conquistaStr;
	//-------------------------
	bool izquierdaReal;
	bool arribaReal;
	bool derechaReal;
	bool abajoReal;
	bool conquista;
	//-------------------------
	int iReal;
	int jReal;
	int numJugador;
	input.open(archivo.c_str());
	while (input.good())
	{
		getline(input, i, '\t');
		getline(input, j, '\t');
		getline(input, conquistaStr ,'\t');
		getline(input, jugadorA, '\t');
		getline(input, numJugadorStr, '\t');
		getline(input, izquierda, '\t');
		getline(input, arriba, '\t');
		getline(input, derecha, '\t');
		getline(input, abajo, '\n');
		if (izquierda != "vacio")
		{
			izquierdaReal = convertirBool(izquierda);
			arribaReal = convertirBool(arriba);
			derechaReal = convertirBool(derecha);
			abajoReal = convertirBool(abajo);
		}
		else
		{
			izquierdaReal = false;
			arribaReal = false;
			derechaReal = false;
			abajoReal = false;
		}
		iReal = convertirInt(i);
		jReal = convertirInt(j);
		conquista = convertirBool(conquistaStr);
		numJugador = convertirInt(numJugadorStr);
		if (!input.eof())
		{
			if ((matriz->getArreglo())[iReal][jReal] == nullptr)
			{
				
			}
			else
			{
				(matriz->getArreglo())[iReal][jReal]->setIzquierda(izquierdaReal);
				(matriz->getArreglo())[iReal][jReal]->setArriba(arribaReal);
				(matriz->getArreglo())[iReal][jReal]->setDerecha(derechaReal);
				(matriz->getArreglo())[iReal][jReal]->setAbajo(abajoReal);
				if (numJugador != 0)
				{
					if (jugadorA == jugadorN1->getNombre())
					{
						(matriz->getArreglo())[iReal][jReal]->setJugador(jugadorN1);
						if (conquista == true)
						{
							(matriz->getArreglo())[iReal][jReal]->setConquista(true);
						}	
					}
					else if (jugadorA == jugadorN2->getNombre())
					{
						(matriz->getArreglo())[iReal][jReal]->setJugador(jugadorN2);
						if (conquista == true)
						{
							(matriz->getArreglo())[iReal][jReal]->setConquista(true);
						}
					}
				}
			}

		}
	}
	input.close();
}


void analizador::recuperarNombrePartidas(string archivo, string* v, string* estrategias, string* nombre1, string* nombre2, int* mayorPtr, int* ptrColumna1, int* ptrColumna2, int* ptrColumna3, string* estrategia, Maquina* m, int* ptrTurnos, int* ptrPuntos1, int* ptrPuntos2)
{
	ifstream input;
	string vectorNombres[20];
	string vectorEstrategias[20];
	string nomJugador1;
	string nomJugador2;
	string estrategia1;
	string estrategia2;
	string turnosStr;
	string mayorStr;
	string puntosJ1Str;
	string puntosJ2Str;
	//-----------------
	string columnas1str;
	string columnas2str;
	string columnas3str;
	//-------------
	int columnas1;
	int columnas2;
	int columnas3;
	int mayor = 0;
	int i = 0;
	int turnos = 0;
	int puntosJ1 = 0;
	int puntosJ2 = 0;
	input.open(archivo.c_str());
	while (input.good())
	{
		getline(input, nomJugador1, '\t');
		getline(input, estrategia1, '\t');
		getline(input, puntosJ1Str, '\t');
		getline(input, nomJugador2, '\t');
		getline(input, vectorEstrategias[i], '\t');
		getline(input, puntosJ2Str, '\t');
		getline(input, turnosStr, '\t');
		getline(input, mayorStr, '\t');
		getline(input, columnas1str, '\t');
		getline(input, columnas2str, '\t');
		getline(input, columnas3str, '\t');
		getline(input, vectorNombres[i], '\n');
		turnos = convertirInt(turnosStr);
		mayor = convertirInt(mayorStr);
		columnas1 = convertirInt(columnas1str);
		columnas2 = convertirInt(columnas2str);
		columnas3= convertirInt(columnas3str);
		puntosJ1 = convertirInt(puntosJ1Str);
		puntosJ2 = convertirInt(puntosJ2Str);
		if (!input.eof())
		{
			v[i] = vectorNombres[i];
			estrategias[i] = vectorEstrategias[i];
			*nombre1 = nomJugador1;
			*nombre2 = nomJugador2;
			*estrategia = estrategia2;
			*ptrTurnos = turnos;
			*mayorPtr = mayor;
			*ptrColumna1 = columnas1;
			*ptrColumna2 = columnas2;
			*ptrColumna3 = columnas3;
			*ptrPuntos1 = puntosJ1;
			*ptrPuntos2 = puntosJ2;
			i++;
		}
	}
	input.close();
}

puntoCompuesto* analizador::crearCampoDeJuego(int tresXdos, int tresXtres, int tresXcinco)
{
	//--------------------------------------
	int columnas1 = 2 * tresXdos;
	int columnas2 = 3 * tresXtres;
	int columnas3 = 5 * tresXcinco;
	//--------------------------------------
	int filas1 = 3;
	int filas2 = 6;
	int filas3 = 9;
	//--------------------------------------
	puntoCompuesto* campoJuego = new puntoCompuesto(9, 14);
	campoJuego->setColumnas(tresXdos, tresXtres, tresXcinco);
	//////////////////////////////////////////////////////////////////////
	if (tresXdos == 0)
	{
		for (int i2 = 0; i2 < 3; i2++)
		{
			for (int j2 = columnas2; j2 < 14; j2++)
			{
				(campoJuego->getArreglo())[i2][j2] = nullptr;
			}

		}
		for (int i3 = 3; i3 < 6; i3++)
		{
			for (int j3 = columnas3; j3 < 14; j3++)
			{
				(campoJuego->getArreglo())[i3][j3] = nullptr;
			}
		}
		for (int i = 6; i < 9; i++)
		{
			for (int j = 0; j < 14; j++)
			{
				(campoJuego->getArreglo())[i][j] = nullptr;
			}
		}
	}
	else if (tresXtres == 0)
	{
		for (int i = 0; i < 3; i++)
		{
			for (int j = columnas1; j < 14; j++)
			{
				(campoJuego->getArreglo())[i][j] = nullptr;
			}
		}
		for (int i3 = 3; i3 < 6; i3++)
		{
			for (int j3 = columnas3; j3 < 14; j3++)
			{
				(campoJuego->getArreglo())[i3][j3] = nullptr;
			}

		}
		for (int ii = 6; ii < 9; ii++)
		{
			for (int jj = 0; jj < 14; jj++)
			{
				(campoJuego->getArreglo())[ii][jj] = nullptr;
			}
		}
	}
	else if (tresXcinco == 0)
	{
		for (int i = 0; i < 3; i++)
		{
			for (int j = columnas1; j < 14; j++)
			{
				(campoJuego->getArreglo())[i][j] = nullptr;
			}
		}
		for (int i2 = 3; i2 < 6; i2++)
		{
			for (int j2 = columnas2; j2 < 14; j2++)
			{
				(campoJuego->getArreglo())[i2][j2] = nullptr;
			}

		}
		for (int i3 = 6; i3 < 9; i3++)
		{
			for (int j3 = 0; j3 < 14; j3++)
			{
				(campoJuego->getArreglo())[i3][j3] = nullptr;
			}
		}
	}
	//////////////////////////////////////////////////////////////////////
	else if (tresXdos == 0 && tresXtres == 0)
	{
		for (int i = 0; i < 3; i++)
		{
			for (int j = columnas3; j < 14; j++)
			{
				(campoJuego->getArreglo())[i][j] = nullptr;
			}
		}
		for (int i = 3; i < 9; i++)
		{
			for (int j = 0; j < 14; j++)
			{
				(campoJuego->getArreglo())[i][j] = nullptr;
			}
		}
	}
	else if (tresXdos == 0 && tresXcinco == 0)
	{
		for (int i = 0; i < 3; i++)
		{
			for (int j = columnas2; j < 14; j++)
			{
				(campoJuego->getArreglo())[i][j] = nullptr;
			}
		}
		for (int i = 3; i < 9; i++)
		{
			for (int j = 0; j < 14; j++)
			{
				(campoJuego->getArreglo())[i][j] = nullptr;
			}
		}
	}
	else if (tresXtres == 0 && tresXcinco == 0)
	{
		for (int i = 0; i < 3; i++)
		{
			for (int j = columnas1; j < 14; j++)
			{
				(campoJuego->getArreglo())[i][j] = nullptr;
			}
		}
		for (int i = 3; i < 9; i++)
		{
			for (int j = 0; j < 14; j++)
			{
				(campoJuego->getArreglo())[i][j] = nullptr;
			}
		}
	}
	else
	{
		for (int i = 0; i < 3; i++)
		{
			for (int j = columnas1; j < 14; j++)
			{
				(campoJuego->getArreglo())[i][j] = nullptr;
			}
		}
		for (int i2 = 3; i2 < 6; i2++)
		{
			for (int j2 = columnas2; j2 < 14; j2++)
			{
				(campoJuego->getArreglo())[i2][j2] = nullptr;
			}

		}
		for (int i3 = 6; i3 < 9; i3++)
		{
			for (int j3 = columnas3; j3 < 14; j3++)
			{
				(campoJuego->getArreglo())[i3][j3] = nullptr;
			}
		}


	}

	campoJuego->setFilasM();
	return campoJuego;
}


