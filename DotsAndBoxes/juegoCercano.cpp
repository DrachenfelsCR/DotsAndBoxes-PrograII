#include "juegoCercano.h"

void juegoCercano::jugar(puntoCompuesto*c,Maquina*m, bool* ptrPuntoGanado)
{
    bool opc = false;
    this->puntoOrigen = nullptr;
    this->puntoDestino = nullptr;
    int puntosActuales = m->getPuntos();
    srand(time(NULL));
    int aleatorizador;
    int i = 0;
    int j = 0;
    int fila = 0;
    int columna = 0;
    int fila2 = 0;
    int columna2 = 0;
    int colsMayor = mayorDeTresEnteros(2 * c->getcolumna1(), 3 * c->getcolumna2(), 5 * c->getcolumna3());
    if (jugadaInteligente(c, m, ptrPuntoGanado))
    {
    }
    else
    {
        ///---------------
        while (puntoOrigen == nullptr)
        {

            aleatorizador = rand() % 4 + 1;
            i = (c->getUltimaFil());
            j = (c->getUltimaCol());

            if ((puntoOrigen = c->buscar(i, j)) == nullptr)
            {
                i = i;
                j = j - 1;
                if (j < 0 || colsMayor)
                {
                    j = 666;
                }
                if (puntoOrigen->checkIzq())
                {
                    j = 666;
                }

            }
            else if ((puntoOrigen = c->buscar(i, j)) == nullptr)
            {
                i = i - 1;
                j = j;
                if (i < 0)
                {
                    i = 666;
                }
                if (puntoOrigen->checkArriba())
                {
                    i = 666;
                }

            }
            else if ((puntoOrigen = c->buscar(i, j)) == nullptr)
            {
                i = i;
                j = j + 1;
                if (j > colsMayor)
                {
                    j = 666;
                }
                if (puntoOrigen->checkDerecha())
                {
                    j = 666;
                }

            }
            else if ((puntoOrigen = c->buscar(i, j)) == nullptr)
            {
                i = i + 1;
                j = j;
                if (i > c->getFilasM())
                {
                    i = 666;
                }
                if (puntoOrigen->checkAbajo())
                {
                    i = 666;
                }

            }

            else
            {
                if (jugadaInteligente(c, m, ptrPuntoGanado))
                {
                }
                else
                {
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
            if (i == 666 || j == 666)
            {
                puntoDestino = nullptr;
            }
            else
            {
                puntoOrigen = c->buscar(i, j);
            }



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
        if (opc == false)
        {


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
                if (iDestino > c->getFilasM())
                {
                    iDestino = 666;
                }
                if (puntoOrigen->checkDerecha())
                {
                    iDestino = 666;
                }
                break;
            case 4:
                //Forzar abajo
                iDestino = i + 1;
                yDestino = j;
                if (iDestino > c->getFilasM())
                {
                    iDestino = 666;
                }
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
                    if (iDestino > c->getFilasM())
                    {
                        iDestino = 666;
                    }
                    if (puntoOrigen->checkDerecha())
                    {
                        iDestino = 666;
                    }
                    break;
                case 4:
                    //Forzar abajo
                    iDestino = i + 1;
                    yDestino = j;
                    if (iDestino > c->getFilasM())
                    {
                        iDestino = 666;
                    }
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
