#include "puntoCompuesto.h"

puntoCompuesto::puntoCompuesto(int filas, int columnas)
{
	this->filas = filas;
	this->columnas = columnas;
	m = new puntoSimple * *[filas];
	for (int i = 0; i < filas; i++)
	{
		m[i] = new puntoSimple * [columnas];
	}
	for (int i = 0; i < filas; i++)
	{
		for (int j = 0; j < columnas; j++)
		{
			m[i][j] = new puntoSimple;
			m[i][j]->setX(i);
			m[i][j]->setY(j);
		}
	}
}


puntoCompuesto::~puntoCompuesto()
{

}

string puntoCompuesto::toString()
{
	stringstream s;
	stringstream auxabajo;
	int flag;
	for (int i = 0; i < filas; i++)
	{
		int fila = i;
		flag = 0;
		auxabajo << endl;
		for (int j = 0; j < columnas; j++)
		{
			if (m[i][j] != nullptr)
			{
				if (i != filas - 1 && m[i][j]->checkAbajo())
				{
					flag++;
					auxabajo << "\t";
					auxabajo << m[i][j]->toStringDown();
				}
				else
				{
					auxabajo << "\t";
					auxabajo << m[i][j]->toStringDown();
				}
				//-----MEDIO----
				if (fila == i)
				{
					s << i << "|";
					fila++;
				}
				s << m[i][j]->toString();
				//-----------
			}
			else
			{
				s << "\t";
			}
			
		}
		s << auxabajo.str();
		s << endl;
		auxabajo.str("");
	}
	return s.str();
}

bool puntoCompuesto::conquistadoIzquierdaSup(int x, int y)
{
	
	for (int i = 0; i < filas; i++)
	{
		for (int j  = 0;  j< columnas ; j++)
		{
			if ((buscar(x,y)->checkDerecha()==true)|| (buscar(x,y)->checkIzq() == true ) )
			{
				
				cout << "tiene Izquierda Superior" << endl;
				
				return true;
			}
		}
	}
	cout << "no lo encontro" << endl;
	return false;
}

bool puntoCompuesto::conquistadoAbajoIzquierda(int x, int y)
{
	for (int i = 0; i < filas; i++)
	{
		for (int j = 0; j < columnas; j++)
		{
			if ((buscar(x,y)->checkAbajo() == true))
			{

				cout << "tiene Abajo Izquierda" << endl;

				return true;
			}
		}
	}
	cout << "no encontro el nodo abajo izquierda" << endl;
	return false;
}

bool puntoCompuesto::consquistadoIzquierdaInf(int x, int y)
{
	for (int i = 0; i < filas; i++)
	{
		for (int j = 0; j < columnas; j++)
		{
			if ((buscar(x+1,y+1)->checkIzq() == true))
			{

				cout << "tiene inferior derecha" << endl;

				return true;
			}
		}
	}
	cout << "no encontro el " << endl;
	return false;
}

bool puntoCompuesto::consquitadoAbajoDerecha(int x, int y)
{
	for (int i = 0; i < filas; i++)
	{
		for (int j = 0; j < columnas; j++)
		{
			if ((buscar(x , y+1)->checkAbajo() == true)||buscar(x,y)->checkArriba())
			{

				cout << "tiene abajo derecha" << endl;

				return true;
			}
		}
	}
	cout << "no lo encontro" << endl;
	return false;
}

bool puntoCompuesto::consquistadoTotal(int x, int y)
{
	if (conquistadoAbajoIzquierda(x,y)&&conquistadoIzquierdaSup(x,y)&& consquistadoIzquierdaInf(x,y)&&consquitadoAbajoDerecha(x,y))
	{
		cout << "Si tiene cuadro carepicha" << endl;
		return true;
	}
	return false;
}



 puntoSimple* puntoCompuesto::buscar(int x, int y)
{
	return m[x][y];
}
 puntoSimple*** puntoCompuesto::getArreglo()
{
	return this->m;
}
