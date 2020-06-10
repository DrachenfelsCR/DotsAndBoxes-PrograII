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
				puntoSimple* coordenada = matriz->buscar(jReal, iReal);
				coordenada->setIzquierda(izquierdaReal);
				coordenada->setArriba(arribaReal);
				coordenada->setDerecha(derechaReal);
				coordenada->setAbajo(abajoReal);
			}
			
		}
	}
	input.close();
}

void analizador::recuperarNombrePartidas(string archivo, string* v, string* nombre1, string* nombre2, int* mayorPtr)
{
	ifstream input;
	string vectorNombres[20];
	string nomJugador1;
	string nomJugador2;
	string mayorStr;
	int mayor = 0;
	int i = 0;
	input.open(archivo.c_str());
	while (input.good())
	{
		getline(input, nomJugador1, '\t');
		getline(input, nomJugador2, '\t');
		getline(input, mayorStr, '\t');
		getline(input, vectorNombres[i], '\n');
		mayor = convertirInt(mayorStr);
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
