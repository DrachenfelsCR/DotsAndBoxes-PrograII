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
		flag = 0;
		for (int j = 0; j < columnas; j++)
		{
			if (i != filas - 1 && m[i][j]->checkAbajo())
			{
				flag++;
				auxabajo << endl;
				for (int i = 0; i < j; i++)
				{
					auxabajo << "\t";
				}
				auxabajo << m[i][j]->toStringDown();
			}
			//-----MEDIO----
			s << m[i][j]->toString();
			//-----------
		}
		if (flag == 0)
		{
			auxabajo << endl;
		}
		s << auxabajo.str();
		s << endl;
		auxabajo.str("");
	}
	return s.str();
}

 puntoSimple* puntoCompuesto::buscar(int x, int y)
{
	for (int i = 0; i < filas; i++)
	{
		for (int j = 0; j < columnas; j++)
		{
			if (m[i][j]->getX() == x && m[i][j]->getY() == y)
			{
				return (m[i][j]);
			}
		}
	}
	return nullptr;

}
 puntoSimple*** puntoCompuesto::getArreglo()
{
	return this->m;
}
