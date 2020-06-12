#include "juegoAleatorio.h"



void juegoAletorio::jugar(puntoCompuesto*c,Maquina*m)
{
    puntoSimple* puntoOrigen = new puntoSimple();
    puntoSimple* puntoDestino = new puntoSimple();
	srand(time(NULL));
	int i = rand() % c->getMayor();
    int j = rand() % 14;
    int iDestino= rand() % c->getMayor();
    int yDestino = rand() % 14;
    int fila=i;
    int fila2=iDestino;
    int columna=j;
    int columna2=yDestino;
    puntoOrigen = c->buscar(i, j);
    puntoDestino = c->buscar(iDestino, yDestino);

	
	if (c->getArreglo()[i][j]!=nullptr)
	{
        if (fila2 > fila)
        {
            puntoOrigen->setAbajo(true);
            puntoDestino->setArriba(true);
            c->movimientoAbajo(fila2, columna2,m);
        }
        else if (fila2 < fila)
        {
            puntoOrigen->setArriba(true);
            puntoDestino->setAbajo(true);
            c->movimientoArriba(fila2, columna2,m);
        }
        else if (columna2 > columna)
        {
            puntoOrigen->setDerecha(true);
            puntoDestino->setIzquierda(true);
            c->movimientoDerecha(fila2, columna2,m);
        }
        else if (columna2 < columna)
        {
            puntoOrigen->setIzquierda(true);
            puntoDestino->setDerecha(true);
            c->movimientoIzquierda(fila2, columna2,m);
        }
	}
}
