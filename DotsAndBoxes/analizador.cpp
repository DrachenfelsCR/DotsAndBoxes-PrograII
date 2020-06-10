#include "analizador.h"

analizador::analizador()
{
}

analizador::~analizador()
{
}

void analizador::recuperarCampoJuego(puntoCompuesto* matriz, string archivo)
{
	ifstream input;
	string nombre;
	string i;
	string j;
	string izquierda;
	string arriba;
	string derecha;
	string abajo;
	//-------------------------
	bool izquierdaReal;
	bool arribaReal;
	bool derechaReal;
	bool abajoReal;
	//-------------------------
	int iReal;
	int jReal;
	input.open(archivo.c_str());
	while (input.good())
	{
		getline(input, i, '\t');
		getline(input, j, '\t');
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
		if (!input.eof())
		{
			if (izquierda == "vacio")
			{
				(matriz->getArreglo())[iReal][jReal] = nullptr;
			}
			else
			{
					(matriz->getArreglo())[iReal][jReal]->setIzquierda(izquierdaReal);
					(matriz->getArreglo())[iReal][jReal]->setArriba(arribaReal);
					(matriz->getArreglo())[iReal][jReal]->setDerecha(derechaReal);
					(matriz->getArreglo())[iReal][jReal]->setAbajo(abajoReal);
			}
			
		}
	}
	input.close();
}

void analizador::recuperarNombrePartidas(string archivo, string* v, string* nombre1, string* nombre2, int* mayorPtr, int* ptrColumna1, int* ptrColumna2, int* ptrColumna3)
{
	ifstream input;
	string vectorNombres[20];
	string nomJugador1;
	string nomJugador2;
	string mayorStr;
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
	input.open(archivo.c_str());
	while (input.good())
	{
		getline(input, nomJugador1, '\t');
		getline(input, nomJugador2, '\t');
		getline(input, mayorStr, '\t');
		getline(input, columnas1str, '\t');
		getline(input, columnas2str, '\t');
		getline(input, columnas3str, '\t');
		getline(input, vectorNombres[i], '\n');
		mayor = convertirInt(mayorStr);
		columnas1 = convertirInt(columnas1str);
		columnas2 = convertirInt(columnas2str);
		columnas3= convertirInt(columnas3str);
		if (!input.eof())
		{
			v[i] = vectorNombres[i];
			*nombre1 = nomJugador1;
			*nombre2 = nomJugador2;
			*mayorPtr = mayor;
			i++;
		}
	}
	input.close();
}
