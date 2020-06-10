#include "puntoCompuesto.h"

puntoCompuesto::puntoCompuesto(int filas, int columnas)
{
	this->nombre = "";
	this->mayor = 0;
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
	for (int i = 0; i < filas; i++)
	{
		for (int j = 0; j < columnas; j++)
		{
			delete m[i][j];
		}
	}
	delete m;
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


 void puntoCompuesto::guardar(string archivo)
 {
	 ofstream outp;
	 outp.open(archivo.c_str(), ofstream::app);
	 for (int i = 0; i < filas; i++)
	 {
		 for (int j = 0; j < columnas; j++)
		 {
			 if (m[i][j] != nullptr)
			 {
				 outp << i << '\t';
				 outp << j << '\t';

				 //----------------------------
				 if (m[i][j]->checkIzq())
				 {
					 outp << "true" << '\t';
				 }
				 else
				 {
					 outp << "false" << '\t';
				 }
				 //----------------------------
				 if (m[i][j]->checkArriba())
				 {
					 outp << "true" << '\t';
				 }
				 else
				 {
					 outp << "false" << '\t';
				 }
				 //----------------------------
				 if (m[i][j]->checkDerecha())
				 {
					 outp << "true" << '\t';
				 }
				 else
				 {
					 outp << "false" << '\t';
				 }
				 //----------------------------
				 if (m[i][j]->checkAbajo())
				 {
					 outp << "true" << '\n';
				 }
				 else
				 {
					 outp << "false" << '\n';
				 }
			 }
			 else if(m[i][j] == nullptr)
			 {
				 outp << i << '\t';
				 outp << j << '\t';
				 outp << "vacio" << '\t';
				 outp << "vacio" << '\t';
				 outp << "vacio" << '\t';
				 outp << "vacio" << '\n';
			 }
		 }
	 }
 }

 void puntoCompuesto::guardarNombre(string archivo)
 {
	 ofstream outp;
	 outp.open(archivo.c_str(), ofstream::app);
	 outp << this->jugador1->getNombre() << '\t';
	 outp << this->jugador2->getNombre() << '\t';
	 outp << this->mayor << '\t';
	 outp << this->columnas1 << '\t';
	 outp << this->columnas2 << '\t';
	 outp << this->columnas3 << '\t';
	 outp << this->nombre << '\n';
 }

 void puntoCompuesto::setNombre(string nombre)
 {
	 this->nombre = nombre;
 }

 void puntoCompuesto::setJugador1(jugador* p1)
 {
	 this->jugador1 = p1;
 }

 void puntoCompuesto::setJugador2(jugador* p2)
 {
	 this->jugador2 = p2;
 }

 void puntoCompuesto::setMayor(int mayor)
 {
	 this->mayor = mayor;
 }

 void puntoCompuesto::setColumnas(int c1, int c2, int c3)
 {
	 this->columnas1 = c1;
	 this->columnas2 = c2;
	 this->columnas3 = c3;
 }

 int puntoCompuesto::getcolumna1()
 {
	 return this->columnas1;
 }

 int puntoCompuesto::getcolumna2()
 {
	 return this->columnas2;
 }

 int puntoCompuesto::getcolumna3()
 {
	 return this->columnas3;
 }

 int puntoCompuesto::getMayor()
 {
	 return this->mayor;
 }

 jugador* puntoCompuesto::getJugador1()
 {
	 return this->jugador1;
 }

 jugador* puntoCompuesto::getJugador2()
 {
	 return this->jugador2;
 }

 string puntoCompuesto::getNombre()
 {
	 return this->nombre;
 }



 