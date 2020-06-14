#include "estrategia.h"

puntoSimple* Estrategia::getPuntoOrigen()
{
	return this->puntoOrigen;
}

puntoSimple* Estrategia::getPuntoDestino()
{
	return this->puntoDestino;
}

bool Estrategia::jugadaInteligente(puntoCompuesto* p, Maquina* m, bool* ptrPuntoGanado)
{
    int puntosActuales = m->getPuntos();
    puntoSimple* esquinaSupIzq = nullptr;
    puntoSimple* esquinaSupDerecha = nullptr;
    puntoSimple* esquinaInfIzq = nullptr;
    puntoSimple* esquinaInfDerecha = nullptr;
    bool puntoAcceso = false;
    int filasMaximas = p->getFilasM();
    int columnasMaximo = p->getMayor();
    for (int i = 0; i < filasMaximas; i++)
    {
        for (int j = 0; j < columnasMaximo; j++)
        {
            esquinaSupIzq = p->buscar(i, j);
            esquinaSupDerecha = p->buscar(i, j+1);
            esquinaInfIzq = p->buscar(i+1, j);
            esquinaInfDerecha = p->buscar(i + 1, j + 1);
            //-------------------VERIFICA SI SE PUEDO FOMAR UN CUADRO DESDE LA ESQUINA SUPIZQ-------------
            if (esquinaSupIzq != nullptr && esquinaSupDerecha != nullptr && esquinaInfDerecha != nullptr && esquinaInfIzq != nullptr)
            {
                //VERIFICA SI TIENE PARED IZQUIERDA Y TECHO
                    if (esquinaSupIzq->checkAbajo() && esquinaSupIzq->checkDerecha())
                    {
                        //VERIFICA QUE NO TENGA PISO
                        if (esquinaSupDerecha->checkAbajo() && esquinaInfDerecha->checkIzq() == false)
                        {
                            if (esquinaInfDerecha->checkIzq() == false && esquinaInfIzq->checkDerecha() == false)
                            {
                                esquinaInfDerecha->setIzquierda(true);
                                esquinaInfIzq->setDerecha(true);
                                //
                                esquinaInfDerecha->setJugador(m);
                                esquinaInfIzq->setJugador(m);
                                p->movimientoIzquierda(i+1,j, m);
                                m->getStrategy()->setPuntoOrigen(esquinaInfDerecha);
                                m->getStrategy()->setPuntoDestino(esquinaInfIzq);
                                if (puntosActuales < m->getPuntos())
                                {
                                    *ptrPuntoGanado = true;
                                }
                                else
                                {
                                    *ptrPuntoGanado = false;
                                }
                                return true;
                            }
                        }
                        //VERIFICA QUE NO TENGA PARED DERECHA
                        else if (esquinaInfIzq->checkDerecha() == true && esquinaInfDerecha->checkArriba() == false)
                        {
                            if (esquinaSupDerecha->checkAbajo() == false)
                            {
                                esquinaSupDerecha->setAbajo(true);
                                esquinaInfDerecha->setArriba(true);
                                //
                                esquinaSupDerecha->setJugador(m);
                                esquinaInfDerecha->setJugador(m);
                                m->getStrategy()->setPuntoOrigen(esquinaSupDerecha);
                                m->getStrategy()->setPuntoDestino(esquinaInfDerecha);
                                p->movimientoAbajo(i+1, j+1, m);
                                if (puntosActuales < m->getPuntos())
                                {
                                    *ptrPuntoGanado = true;
                                }
                                else
                                {
                                    *ptrPuntoGanado = false;
                                }
                                return true;
                            }
                        }
                    }
                    //VERIFICA QUE NO TENGA PARED IZQUIERDA
                    else if (esquinaSupIzq->checkAbajo() == false)
                    {
                        if (esquinaSupIzq->checkDerecha() && esquinaSupDerecha->checkAbajo() && esquinaInfDerecha->checkIzq())
                        {
                            if (esquinaSupIzq->checkAbajo() == false  && esquinaInfIzq->checkArriba() == false)
                            {
                                esquinaSupIzq->setAbajo(true);
                                esquinaInfIzq->setArriba(true);
                                //
                                esquinaSupIzq->setJugador(m);
                                esquinaInfIzq->setJugador(m);
                                m->getStrategy()->setPuntoOrigen(esquinaSupIzq);
                                m->getStrategy()->setPuntoDestino(esquinaInfIzq);
                                p->movimientoAbajo(i+1, j, m);
                                if (puntosActuales < m->getPuntos())
                                {
                                    *ptrPuntoGanado = true;
                                }
                                else
                                {
                                    *ptrPuntoGanado = false;
                                }
                                return true;
                            }
                        }
                    }
                    //VERIFICA QUE LE FALTA TECHO
                    else if (esquinaSupIzq->checkDerecha() == false)
                    {
                        if (esquinaSupIzq->checkAbajo() && esquinaInfIzq->checkDerecha() && esquinaInfDerecha->checkArriba())
                        {
                            if (esquinaSupIzq->checkDerecha() == false && esquinaSupDerecha->checkIzq() == false)
                            {
                                esquinaSupIzq->setDerecha(true);
                                esquinaSupDerecha->setIzquierda(true);
                                m->getStrategy()->setPuntoOrigen(esquinaSupIzq);
                                m->getStrategy()->setPuntoDestino(esquinaSupDerecha);
                                p->movimientoDerecha(i,j+1,m);
                                if (puntosActuales < m->getPuntos())
                                {
                                    *ptrPuntoGanado = true;
                                }
                                else
                                {
                                    *ptrPuntoGanado = false;
                                }
                                return true;
                            }
                        }
                    }
            }
            //-------------------------------------------------------------------
        }
    }
    return false;
}

void Estrategia::setPuntoOrigen(puntoSimple* po)
{
    this->puntoOrigen = po;
}

void Estrategia::setPuntoDestino(puntoSimple*pd)
{
    this->puntoDestino = pd;
}

string Estrategia::getNombre()
{
    return this->nombre;
}

void Estrategia::setNombre(string nombre)
{
    this->nombre = nombre;
}
