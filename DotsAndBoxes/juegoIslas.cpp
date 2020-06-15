#include "juegoIslas.h"

void juegoIslas::jugar(puntoCompuesto*c,Maquina*m, bool* ptrPuntoGanado)
{
    this->puntoOrigen = nullptr;
    this->puntoDestino = nullptr;
    int puntosActuales = m->getPuntos();
    srand(time(NULL));
    int aleatorizador;
    int fila = 0;
    int columna = 0;
    int fila2 = 0;
    int columna2 = 0;
    int colsMayor = mayorDeTresEnteros(2 * c->getcolumna1(), 3 * c->getcolumna2(), 5 * c->getcolumna3());
    //////////////////////////////////////////////////
    puntoSimple* esquinaSupIzq = nullptr;
    puntoSimple* esquinaSupDerecha = nullptr;
    puntoSimple* esquinaInfIzq = nullptr;
    puntoSimple* esquinaInfDerecha = nullptr;
    bool puntoAcceso = false;
    int filasMaximas = c->getFilasM();
    int columnasMaximo = c->getMayor();
    if (i == 66 && j == 66)
    {
        i = rand() % c->getFilasM();
        j = rand() % colsMayor;
    }
    //////////////////////////////////////////////////
    if (jugadaInteligente(c, m, ptrPuntoGanado))
    {
    }
    else
    {
        esquinaSupIzq = c->buscar(i, j);
        esquinaSupDerecha = c->buscar(i, j + 1);
        esquinaInfIzq = c->buscar(i + 1, j);
        esquinaInfDerecha = c->buscar(i + 1, j + 1);
    //-------------------------------------------------
        while (esquinaSupIzq == nullptr || esquinaSupDerecha == nullptr || esquinaInfIzq == nullptr || esquinaInfDerecha == nullptr || esquinaSupIzq->getConquista())
        {
            i = rand() % c->getFilasM();
            j = rand() % colsMayor;
            esquinaSupIzq = c->buscar(i, j);
            esquinaSupDerecha = c->buscar(i, j + 1);
            esquinaInfIzq = c->buscar(i + 1, j);
            esquinaInfDerecha = c->buscar(i + 1, j + 1);
        }
        if (esquinaSupIzq->checkDerecha() == false)
        {
            //-------------------------------------
            esquinaSupIzq->setDerecha(true);
            esquinaSupDerecha->setIzquierda(true);
            c->movimientoDerecha(i, j + 1, m);
            this->puntoOrigen = c->buscar(i, j);
            this->puntoDestino = c->buscar(i, j + 1);
            if (puntosActuales < m->getPuntos())
            {
                *ptrPuntoGanado = true;
            }
            else
            {
                *ptrPuntoGanado = false;
            }
            ///-------------------------------------
        }
        else if (esquinaSupIzq->checkAbajo() == false)
        {
            //-------------------------------------
            esquinaSupIzq->setAbajo(true);
            esquinaInfIzq->setArriba(true);
            c->movimientoAbajo(i + 1, j, m);
            this->puntoOrigen = c->buscar(i, j);
            this->puntoDestino = c->buscar(i + 1, j);
            if (puntosActuales < m->getPuntos())
            {
                *ptrPuntoGanado = true;
            }
            else
            {
                *ptrPuntoGanado = false;
            }
            //-------------------------------------
        }
        else if (esquinaSupDerecha->checkAbajo() == false)
        {
            //-------------------------------------
            esquinaSupDerecha->setAbajo(true);
            esquinaInfDerecha->setArriba(true);
            c->movimientoAbajo(i + 1, j + 1, m);
            this->puntoOrigen = (c->buscar(i, j + 1));
            this->puntoDestino = (c->buscar(i + 1, j + 1));
            if (puntosActuales < m->getPuntos())
            {
                *ptrPuntoGanado = true;
            }
            else
            {
                *ptrPuntoGanado = false;
            }
            //-------------------------------------
        }
        else if (esquinaInfIzq->checkDerecha() == false)
        {
            //-------------------------------------
            esquinaInfIzq->setDerecha(true);
            esquinaInfDerecha->setIzquierda(true);
            c->movimientoDerecha(i + 1, j + 1, m);
            this->puntoOrigen = (c->buscar(i + 1, j));
            this->puntoDestino = (c->buscar(i + 1, j + 1));
            if (puntosActuales < m->getPuntos())
            {
                *ptrPuntoGanado = true;
            }
            else
            {
                *ptrPuntoGanado = false;
            }
            //-------------------------------------
        }

    }
}
