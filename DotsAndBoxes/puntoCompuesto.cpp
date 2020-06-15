#include "puntoCompuesto.h"

puntoCompuesto::puntoCompuesto(int filas, int columnas)
{
	this->nombre = "";
	this->mayor = 0;
	this->filas = filas;
	this->columnas = columnas;
	this->jugador1 = nullptr;
	this->jugador2 = nullptr;
	this->laMaquina = nullptr;
	this->contadorTurnos = 0;
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
			m[i][j]->setX(j);
			m[i][j]->setY(i);
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
		cout << "Si tiene cuadro" << endl;
		return true;
	}
	return false;
}

 puntoSimple* puntoCompuesto::buscar(int y, int x)
{
	return m[y][x];
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
				 if (m[i][j]->getConquista())
				 {
					 outp << "true" << '\t';
				 }
				 else
				 {
					 outp << "false" << '\t';
				 }
				 if (m[i][j]->getJugador() != nullptr)
				 {
					 outp << m[i][j]->getJugador()->getNombre() << '\t';
					 outp << m[i][j]->getJugador()->getNumero() << '\t';
				 }
				 else
				 {
					 outp << "0" <<'\t';
					 outp << "0" <<'\t';
				 }				 
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
	 outp << "persona" << '\t';
	 outp << this->jugador1->getPuntos() << '\t';
	 if (this->jugador2 != nullptr)
	 {
		 outp << this->jugador2->getNombre() << '\t';
		 outp << "persona" << '\t';
		 outp << this->jugador2->getPuntos() << '\t';
	 }
	 else if (this->laMaquina != nullptr)
	 {
		 outp << this->laMaquina->getNombre() << '\t';
		 outp << this->laMaquina->getStrategy()->getNombre() << '\t';
		 outp << this->laMaquina->getPuntos() << '\t';
	 }
	 outp << this->contadorTurnos << '\t';
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

 void puntoCompuesto::setMaquina(Maquina* maquina)
 {
	 this->laMaquina = maquina;
 }

 void puntoCompuesto::setTurnos(int turnos)
 {
	 this->contadorTurnos = turnos;
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

 int puntoCompuesto::getUltimaFil()
 {
	 return UltimaFil;
 }

 int puntoCompuesto::getUltimaCol()
 {
	 return UltimaCol;
 }

 int puntoCompuesto::getMayor()
 {
	 return this->mayor;
 }

 int puntoCompuesto::getFilasM()
 {
	 return this->filasM;
 }

 int puntoCompuesto::getContadorTurnos()
 {
	 return this->contadorTurnos;
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

 int puntoCompuesto::jugadasMaximas()
 {
	 if ( (columnas1 == 1 || columnas1 == 0) && (columnas2 == 1 || columnas2 == 0) && (columnas3 == 1 || columnas3 == 0))
	 {
		if (columnas1 == 1 && columnas2 == 1 && columnas3 == 1)
		{
		 return ((columnas1 * 7) + (columnas2 * 12 + 2) + (columnas3 * 22 + 3));
		}
		else if(columnas1 == 1 && columnas2 == 1)
		{
			return ((columnas1 * 7) + (columnas2 * 12 + 2) + (columnas3 * 22));
		}		 
		 return ((columnas1 * 7) + (columnas2 * 12) + (columnas3 * 22));
	 }
	 //---------------------------------------------------------
	 else if ((columnas1 > 1 ) && (columnas2 == 0 || columnas2 == 1) && (columnas3 == 0 || columnas3 == 1))
	 {
		 return (((columnas1-1) * 3 + columnas1 * 7) + (columnas2 * 12) + (columnas3 * 22));
	 }
	 else if ((columnas2 > 1) && (columnas1 == 0 || columnas1 == 1) && (columnas3 == 0 || columnas3 == 1))
	 {
		 return (((columnas2-1) * 3 + columnas2 * 12) + (columnas1 * 7) + (columnas3 * 22));
	 }
	 else if ((columnas3 > 1) && (columnas1 == 0 || columnas1 == 1) && (columnas2 == 0 || columnas2 == 1))
	 {
		 return (((columnas3-1) * 3 + columnas3 * 22) + (columnas1 * 7) + (columnas2 * 12));
	 }
	 else if ((columnas1 > 1) && (columnas2 == 1 || columnas2 == 0))
	 {
		 return (((columnas1-1) * 7 + columnas1 * 3) + (columnas2 * 12 + columnas2 * 3));
	 }
	 else if ((columnas1 > 1) && (columnas3 == 1 || columnas3 == 0))
	 {
		 return (((columnas1-1) * 7 + columnas1 * 3) + (columnas3 * 22 + columnas3 * 3));
	 }
	 else if ((columnas2 > 1) && (columnas1 == 1 || columnas1 == 0))
	 {
		 return (((columnas2-1) * 12 + columnas2 * 3) + (columnas1 * 7 + columnas1 * 3));
	 }
	 else if ((columnas2 > 1) && (columnas3 == 1 || columnas3 == 0))
	 {
		 return (((columnas2-1) * 12 + columnas2 * 3) + (columnas3 * 7 + columnas3 * 3));
	 }
	 else if ((columnas3 > 1) && (columnas1 == 1 || columnas1 == 0))
	 {
		 return (((columnas3-1) * 22 + columnas3 * 3) + (columnas1 * 7));
	 }
	 else if ((columnas3 > 1) && (columnas2 == 1 || columnas2 == 0))
	 {
		 return (((columnas3-1) * 22 + columnas3 * 3) + (columnas2 * 12));
	 }
	 else if ((columnas1 == 1 || columnas1 == 0) && (columnas2 == 1 || columnas2 == 0))
	 {
		 return (columnas1 * 7) + (columnas2 * 12) + (columnas3 * 3 + columnas3 * 22);
	 }
	 else if ((columnas1 == 1 || columnas1 == 0) && (columnas3 == 1 || columnas3 == 0))
	 {
		 return ((columnas1 * 7) + (columnas3 * 3 + columnas2 * 12) + (columnas3 * 22));
	 }
	 else if ((columnas2 == 1 || columnas2 == 0) && (columnas3 == 1 || columnas3 == 0))
	 {
		 return ((columnas1 * 3 + columnas1 * 7) + (columnas2 * 12) + (columnas3 * 22));
	 }
	 ///-----------------------------------------
	 else if ((columnas1 == 1 || columnas1 == 0))
	 {
		 return (columnas1 * 7);
	 }
	 else if ((columnas2 == 1 || columnas2 == 0))
	 {
		 return (columnas2 * 12);
	 }
	 else if ((columnas3 == 1 || columnas3 == 0))
	 {
		 return (columnas3 * 22);
	 }
	 else
	 {
	 return (((columnas1-1) * 3 + columnas1 * 7) + ((columnas2-1) * 3 + columnas2 * 12) + ((columnas3-1) * 3 + columnas3 * 22));
	 }	
 }

 Maquina* puntoCompuesto::getMaquina()
 {
	 return this->laMaquina;
 }

 void puntoCompuesto::movimientoAbajo(int i, int j, jugador* jugadorAct)
 {
	if (j == 0)
	 {
		 if (m[i][j]->checkDerecha())
		 {
			 if ((m[i][j + 1])->checkArriba())
			 {
				 if ((m[i-1][j + 1])->checkIzq())
				 {
					 if ((m[i - 1][j])->getConquista() == false)
					 {
						 (m[i - 1][j])->setConquista(true);
						 (m[i - 1 ][j])->setJugador(jugadorAct);
						 jugadorAct->aumentarPuntos(1);
					 }					
				 }
			 }
		 }
	 }
	else if (j == columnas)
	{
		if (m[i][j]->checkIzq())
		{
			if ((m[i][j - 1])->checkArriba())
			{
				if ((m[i - 1][j - 1])->checkDerecha())
				{
					if ((m[i - 1][j - 1])->getConquista() == false)
					{
						(m[i - 1][j - 1])->setConquista(true);
						(m[i - 1][j - 1])->setJugador(jugadorAct);
						jugadorAct->aumentarPuntos(1);
					}					
				}
			}
		}
	}
	else 
	{
		if (m[i][j]->checkIzq())
		{
			if ((m[i][j - 1])->checkArriba())
			{
				if ((m[i - 1][j - 1])->checkDerecha())
				{
					if ((m[i - 1][j - 1])->getConquista() == false)
					{
						(m[i - 1][j - 1])->setConquista(true);
						(m[i - 1][j - 1])->setJugador(jugadorAct);
						jugadorAct->aumentarPuntos(1);
					}				
				}
			}
		}
		if (m[i][j]->checkDerecha())
			{
			if ((m[i][j + 1])->checkArriba())
				{
				if ((m[i - 1][j + 1])->checkIzq())
				{
					if ((m[i - 1][j])->getConquista() == false)
					{
						(m[i - 1][j])->setConquista(true);
						(m[i - 1][j])->setJugador(jugadorAct);
						jugadorAct->aumentarPuntos(1);
					}
				}
				}
			}
	}
	 
 }

 void puntoCompuesto::movimientoArriba(int i, int j, jugador* jugadorAct)
 {
	 if (j == 0)
	 {
		 if (m[i][j]->checkDerecha())
		 {
			 if ((m[i][j + 1])->checkAbajo())
			 {
				 if ((m[i + 1][j + 1])->checkIzq())
				 {
					 if ((m[i][j])->getConquista() == false)
					 {
						 (m[i][j])->setConquista(true);
						 (m[i][j])->setJugador(jugadorAct);
						 jugadorAct->aumentarPuntos(1);
					 }
					
				 }
			 }
		 }
	 }
	 else if (j == columnas)
	 {
		 if (m[i][j]->checkIzq())
		 {
			 if ((m[i][j - 1])->checkAbajo())
			 {
				 if ((m[i + 1][j - 1])->checkDerecha())
				 {
					 if ((m[i][j])->getConquista() == false)
					 {
						 (m[i][j])->setConquista(true);
						 (m[i][j])->setJugador(jugadorAct);
						 jugadorAct->aumentarPuntos(1);
					 }
					 
				 }
			 }
		 }
	 }
	 else
	 {
		 if (m[i][j]->checkDerecha())
		 {
			 if ((m[i][j + 1])->checkAbajo())
			 {
				 if ((m[i + 1][j + 1])->checkIzq())
				 {
					 if ((m[i][j])->getConquista() == false)
					 {
						 (m[i][j])->setConquista(true);
						 (m[i][j])->setJugador(jugadorAct);
						 jugadorAct->aumentarPuntos(1);
					 }
								 
				 }			
			 }		
		 }
		 if (m[i][j]->checkIzq())
		 {
			if ((m[i][j - 1])->checkAbajo())
			{
				 if ((m[i + 1][j - 1])->checkDerecha())
				 {
					 if ((m[i][j - 1])->getConquista() == false)
					 {
						 (m[i][j - 1])->setConquista(true);
						 (m[i][j - 1])->setJugador(jugadorAct);
						 jugadorAct->aumentarPuntos(1);
					 }						 		 
				 }
					 
			}	
		}
	 }
 }

 void puntoCompuesto::movimientoDerecha(int i, int j, jugador* jugadorAct)
 {
		 if (m[i][j]->checkArriba())
		 {
			 if (m[i - 1][j]->checkIzq())
			 {
				 if (m[i - 1][j - 1]->checkAbajo())
				 {
					 if (m[i - 1][j - 1]->getConquista() == false)
					 {
						 m[i - 1][j - 1]->setConquista(true);
						 m[i - 1][j - 1]->setJugador(jugadorAct);
						 jugadorAct->aumentarPuntos(1);
					 }					
				 }
			 }
		 }
		 if (m[i][j]->checkAbajo())
		 {
			 if (m[i + 1][j]->checkIzq())
			 {
				 if (m[i + 1][j - 1]->checkArriba())
				 {
					 if (m[i][j - 1]->getConquista() == false)
					 {
						 m[i][j - 1]->setConquista(true);
						 (m[i][j - 1])->setJugador(jugadorAct);
						 jugadorAct->aumentarPuntos(1);
					 }				
				 }
			 }
		 }
 }

 void puntoCompuesto::movimientoIzquierda(int i, int j, jugador* jugadorAct)
 {
		 //------------
		 if (m[i][j]->checkAbajo())
		 {
			 if (m[i + 1][j]->checkDerecha())
			 {
				 if (m[i + 1][j + 1]->checkArriba())
				 {
					 if (m[i][j]->getConquista() == false)
					 {
						 m[i][j]->setConquista(true);
						 (m[i][j])->setJugador(jugadorAct);
						 jugadorAct->aumentarPuntos(1);
					 }
					
				 }
			 }
		 }
		 //------------
		 if (m[i][j]->checkArriba())
		 {
			 if (m[i - 1][j]->checkDerecha())
			 {
				 if (m[i - 1][j + 1]->checkAbajo())
				 {
					 if (m[i - 1][j]->getConquista() == false)
					 {
						 m[i - 1][j]->setConquista(true);
						 m[i - 1][j]->setJugador(jugadorAct);
						 jugadorAct->aumentarPuntos(1);
					 }			 
				 }
			 }
		 }
 }

 void puntoCompuesto::setFilasM()
 {
	 for (int i = 0; i < filas; i++)
	 {
		 if (m[i][0] == nullptr)
		 {
			 this->filasM = i;
			 break;
		 }
		 if (i == 7)
		 {
			 this->filasM = 8;
			 break;
		 }
	 }
 }

 void puntoCompuesto::setUltimafil(int ultimaFil)
 {
	 this->UltimaFil = ultimaFil;
 }

 void puntoCompuesto::setUltimaCol(int ultimaCol)
 {
	 this->UltimaCol = ultimaCol;
 }

 