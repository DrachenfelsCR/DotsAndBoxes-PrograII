#include "juegoAleatorio.h"



void juegoAletorio::jugar(puntoCompuesto* c, Maquina* m)
{
    puntoSimple* puntoOrigen = nullptr;
    puntoSimple* puntoDestino = nullptr;

    srand(time(NULL));
    int aleatorizador = rand() % 4 + 1;
    int i=0;
    int j=0;
    int fila=0;
    int columna = 0;
    int fila2 = 0;
    int columna2 = 0;
    ///---------------
    while (puntoOrigen == nullptr)
    {
        i = rand() % c->getMayor();
        j = rand() % 14;
        puntoOrigen = c->buscar(i, j);
        fila = i;
        columna = j;
    }
    //--------------------
    int iDestino = 0;
    int yDestino = 0;
    switch (aleatorizador)
    {
    case 1:
        //Forzar izquierda
         iDestino = i;
         yDestino = j-1;
        break;
    case 2:
        //Forzar arriba
         iDestino = i-1;
         yDestino = j;
        break;
    case 3:
        //Forzar derecha
         iDestino = i;
         yDestino = j+1;
        break;
    case 4:
        //Forzar abajo
         iDestino = i + 1;
         yDestino = j;
        break;
    default:
        break;
    }
    fila2 = iDestino;
    columna2 = yDestino;
    puntoOrigen = c->buscar(i, j);
    puntoDestino = c->buscar(iDestino, yDestino);
           while (puntoDestino == nullptr)
           {
                 switch (aleatorizador)
                 {
                 case 1:
                     //Forzar izquierda
                      iDestino = i;
                      yDestino = j - 1;
                     break;
                 case 2:
                     //Forzar arriba
                      iDestino = i - 1;
                      yDestino = j;
                     break;
                 case 3:
                     //Forzar derecha
                      iDestino = i;
                      yDestino = j + 1;
                     break;
                 case 4:
                     //Forzar abajo
                      iDestino = i + 1;
                      yDestino = j;
                     break;
                 default:
                     break;
                 }      
                 puntoDestino = c->buscar(iDestino, yDestino);
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
                }
                else if (fila2 < fila)
                {
                    puntoOrigen->setArriba(true);
                    puntoDestino->setAbajo(true);
                    c->movimientoArriba(fila2, columna2, m);
                }
                else if (columna2 > columna)
                {
                    puntoOrigen->setDerecha(true);
                    puntoDestino->setIzquierda(true);
                    c->movimientoDerecha(fila2, columna2, m);
                }
                else if (columna2 < columna)
                {
                    puntoOrigen->setIzquierda(true);
                    puntoDestino->setDerecha(true);
                    c->movimientoIzquierda(fila2, columna2, m);
                }
            }
 }
