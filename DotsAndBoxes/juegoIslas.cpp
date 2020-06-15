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

        while (esquinaSupIzq == nullptr || esquinaSupDerecha == nullptr || esquinaInfIzq == nullptr || esquinaInfDerecha == nullptr || esquinaSupIzq->getConquista() || esquinaSupIzq->getConquistado())
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
        else
        {
            this->puntoOrigen = nullptr;
            this->puntoDestino = nullptr;
            ///---------------
            while (puntoOrigen == nullptr)
            {
                aleatorizador = rand() % 4 + 1;
                i = rand() % c->getFilasM();
                j = rand() % colsMayor;
                puntoOrigen = c->buscar(i, j);
                fila = i;
                columna = j;
                if (puntoOrigen != nullptr)
                {
                    if (puntoOrigen->getConquistado())
                    {
                        puntoOrigen = nullptr;
                    }
                }
            }
            //--------------------
            int iDestino = 0;
            int yDestino = 0;
            switch (aleatorizador)
            {
            case 1:
                //Forzar izquierda
                iDestino = i;
                yDestino = j - 1;
                if (yDestino < 0)
                {
                    yDestino = 666;
                }
                if (puntoOrigen->checkIzq())
                {
                    iDestino = 666;
                }
                break;
            case 2:
                //Forzar arriba
                iDestino = i - 1;
                yDestino = j;
                if (iDestino < 0)
                {
                    iDestino = 666;
                }
                if (puntoOrigen->checkArriba())
                {
                    iDestino = 666;
                }
                break;
            case 3:
                //Forzar derecha
                iDestino = i;
                yDestino = j + 1;
                if (puntoOrigen->checkDerecha())
                {
                    iDestino = 666;
                }
                break;
            case 4:
                //Forzar abajo
                iDestino = i + 1;
                yDestino = j;
                if (puntoOrigen->checkAbajo())
                {
                    iDestino = 666;
                }
                break;
            default:
                break;
            }
            if (iDestino == 666 || yDestino == 666)
            {
                puntoDestino = nullptr;
            }
            else
            {
                puntoDestino = c->buscar(iDestino, yDestino);
            }

            while (puntoDestino == nullptr)
            {
                aleatorizador = rand() % 4 + 1;
                switch (aleatorizador)
                {
                case 1:
                    //Forzar izquierda
                    iDestino = i;
                    yDestino = j - 1;
                    if (yDestino < 0)
                    {
                        yDestino = 666;
                    }
                    if (puntoOrigen->checkIzq())
                    {
                        iDestino = 666;
                    }
                    break;
                case 2:
                    //Forzar arriba
                    iDestino = i - 1;
                    yDestino = j;
                    if (iDestino < 0)
                    {
                        iDestino = 666;
                    }
                    if (puntoOrigen->checkArriba())
                    {
                        iDestino = 666;
                    }
                    break;
                case 3:
                    //Forzar derecha
                    iDestino = i;
                    yDestino = j + 1;
                    if (puntoOrigen->checkDerecha())
                    {
                        iDestino = 666;
                    }
                    break;
                case 4:
                    //Forzar abajo
                    iDestino = i + 1;
                    yDestino = j;
                    if (puntoOrigen->checkAbajo())
                    {
                        iDestino = 666;
                    }
                    break;
                default:
                    break;
                }
                if (iDestino == 666 || yDestino == 666)
                {
                    puntoDestino = nullptr;
                }
                else
                {
                    puntoDestino = c->buscar(iDestino, yDestino);
                }
            }
            fila2 = iDestino;
            columna2 = yDestino;
            if ((c->getArreglo()[i][j] != nullptr) && (c->getArreglo()[iDestino][yDestino] != nullptr))
            {
                if (fila2 > fila)
                {
                    puntoOrigen->setAbajo(true);
                    puntoDestino->setArriba(true);
                    c->movimientoAbajo(fila2, columna2, m);
                    if (puntosActuales < m->getPuntos())
                    {
                        *ptrPuntoGanado = true;
                    }
                    else
                    {
                        *ptrPuntoGanado = false;
                    }
                }
                else if (fila2 < fila)
                {
                    puntoOrigen->setArriba(true);
                    puntoDestino->setAbajo(true);
                    c->movimientoArriba(fila2, columna2, m);
                    if (puntosActuales < m->getPuntos())
                    {
                        *ptrPuntoGanado = true;
                    }
                    else
                    {
                        *ptrPuntoGanado = false;
                    }
                }
                else if (columna2 > columna)
                {
                    puntoOrigen->setDerecha(true);
                    puntoDestino->setIzquierda(true);
                    c->movimientoDerecha(fila2, columna2, m);
                    if (puntosActuales < m->getPuntos())
                    {
                        *ptrPuntoGanado = true;
                    }
                    else
                    {
                        *ptrPuntoGanado = false;
                    }
                }
                else if (columna2 < columna)
                {
                    puntoOrigen->setIzquierda(true);
                    puntoDestino->setDerecha(true);
                    c->movimientoIzquierda(fila2, columna2, m);
                    if (puntosActuales < m->getPuntos())
                    {
                        *ptrPuntoGanado = true;
                    }
                    else
                    {
                        *ptrPuntoGanado = false;
                    }
                }
            }
        }
    }
}
